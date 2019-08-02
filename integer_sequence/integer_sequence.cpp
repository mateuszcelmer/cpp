#include <iostream>
#include <utility>
#include <array>
#include <tuple>

using namespace std;

// Convert an array into a tuple

template <typename Array, std::size_t... I>
decltype(auto) a2t_impl(const Array &a, std::integer_sequence<std::size_t, I...>)
{
    return std::make_tuple(a[I]...);
}

template <typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
decltype(auto) a2t(const std::array<T, N> &a)
{
    return a2t_impl(a, Indices());
}

int main()
{

    return 0;
}