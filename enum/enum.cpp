#include <iostream>
#include <tuple>

using namespace std;

enum UserInfoFields
{
    uiName,
    uiEmail,
    uiReputation
};

using UserInfo = std::tuple<std::string, std::string, std::size_t>;

int main()
{
    UserInfo uInfo;
    auto val = std::get<uiEmail>(uInfo);

    return 0;
}