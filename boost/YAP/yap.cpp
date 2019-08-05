#include <boost/yap/algorithm.hpp>

#include <algorithm>
#include <vector>

// An enum to represent all the standard algorithms we want to adapt.  In this
// example, we only care about std::sort() and std::unique().
enum class algorithm_t
{
    sort,
    unique
};

// Just about the simplest range template you could construct.  Nothing fancy.
template <typename Iter>
struct simple_range
{
    Iter begin() const { return first_; }
    Iter end() const { return last_; }

    Iter first_;
    Iter last_;
};

// This simply calls the standard algorithm that corresponds to "a".  This
// certainly won't work for all the algorithms, but it works for many of them
// that just take a begin/end pair.
template <typename Range>
auto call_algorithm(algorithm_t a, Range &r)
{
    simple_range<decltype(r.begin())> retval{r.begin(), r.end()};
    if (a == algorithm_t::sort)
    {
        std::sort(r.begin(), r.end());
    }
    else if (a == algorithm_t::unique)
    {
        retval.last_ = std::unique(r.begin(), r.end());
    }
    return retval;
}

// This is the transform that evaluates our piped expressions.  It returns a
// simple_range<>, not a Yap expression.
struct algorithm_eval
{
    // A pipe should always have a Yap expression on the left and an
    // algorithm_t terminal on the right.
    template <typename LExpr>
    auto operator()(
        boost::yap::expr_tag<boost::yap::expr_kind::bitwise_or>,
        LExpr &&left,
        algorithm_t right)
    {
        // Recursively evaluate the left ...
        auto const left_result =
            boost::yap::transform(std::forward<LExpr>(left), *this);
        // ... and use the result to call the function on the right.
        return call_algorithm(right, left_result);
    }

    // A call operation is evaluated directly.  Note that the range parameter
    // is taken as an lvalue reference, to prevent binding to a temporary and
    // taking dangling references to its begin and end.  We let the compiler
    // deduce whether the lvalue reference is const.
    template <typename Range>
    auto operator()(
        boost::yap::expr_tag<boost::yap::expr_kind::call>,
        algorithm_t a,
        Range &r)
    {
        return call_algorithm(a, r);
    }
};

// This is the expression template we use for the general case of a pipable
// algorithm expression.  Terminals are handled separately.
template <boost::yap::expr_kind Kind, typename Tuple>
struct algorithm_expr
{
    static boost::yap::expr_kind const kind = Kind;

    Tuple elements;

    // This is how we get the nice initializer semantics we see in the example
    // usage below.  This is a bit limited though, because we always create a
    // temporary.  It might therefore be better just to create algorithm_expr
    // expressions, call yap::evaluate(), and then use the sequence containers
    // assign() member function to do the actual assignment.
    template <typename Assignee>
    operator Assignee() const
    {
        // Exercise left for the reader: static_assert() that Assignee is some
        // sort of container type.
        auto const range = boost::yap::transform(*this, algorithm_eval{});
        return Assignee(range.begin(), range.end());
    }
};

// This is a bit loose, because it allows us to write "sort(v) | unique(u)" or
// similar.  It works fine for this example, but in production code you may
// want to write out the functions generated by this macro, and add SFINAE or
// concepts constraints on the right template parameter.
BOOST_YAP_USER_BINARY_OPERATOR(bitwise_or, algorithm_expr, algorithm_expr)

// It's useful to specially handle terminals, because we want a different set
// of operations to apply to them.  We don't want "sort(x)(y)" to be
// well-formed, for instance, or "sort | unique" either.
struct algorithm
{
    static boost::yap::expr_kind const kind = boost::yap::expr_kind::terminal;

    boost::hana::tuple<algorithm_t> elements;

    BOOST_YAP_USER_CALL_OPERATOR_N(::algorithm_expr, 1)
};

// Here are ready-made Yap terminals, one for each algorithm enumerated in
// algorithm_t.
constexpr algorithm sort{{algorithm_t::sort}};
constexpr algorithm unique{{algorithm_t::unique}};

int main()
{
    {
        std::vector<int> v1 = {0, 2, 2, 7, 1, 3, 8};
        std::sort(v1.begin(), v1.end());
        auto it = std::unique(v1.begin(), v1.end());
        std::vector<int> const v2(v1.begin(), it);
        assert(v2 == std::vector<int>({0, 1, 2, 3, 7, 8}));
    }
    {
        std::vector<int> v1 = {0, 2, 2, 7, 1, 3, 8};
        std::vector<int> const v2 = sort(v1) | unique;
        assert(v2 == std::vector<int>({0, 1, 2, 3, 7, 8}));
    }
}