#include <iostream>
#include <tuple>

using namespace std;

enum UserInfoFields // unscoped enum
{
    uiName,
    uiEmail,
    uiReputation
};

enum class Scoped // scoped
{
    address,
    telephone,
    salary
};

template <typename E> // C++14
constexpr auto
toUType(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

using UserInfo = std::tuple<std::string, std::string, std::size_t>;

int main()
{
    UserInfo uInfo;
    uInfo = std::make_tuple<std::string, std::string, std::size_t>("name", "email", 123);

    // unscoped enum
    auto val = std::get<uiEmail>(uInfo);
    std::cout << val << std::endl;

    // scoped enum option 1
    auto val2 = std::get<static_cast<std::size_t>(Scoped::salary)>(uInfo);
    std::cout << val2 << std::endl;

    // scped enum option 2
    auto val3 = std::get<toUType(Scoped::address)>(uInfo);
    std::cout << val3 << std::endl;
    return 0;
}