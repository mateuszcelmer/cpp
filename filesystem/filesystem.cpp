#include <iostream>
#include <filesystem>

using namespace std;

int main()
{
    const auto bigFilePath{"/home/user/test.wav"};
    if (std::filesystem::exists(bigFilePath))
    {
        const auto bigFileSize{std::filesystem::file_size(bigFilePath)};
        std::filesystem::path tmpPath{"/tmp"};
        if (std::filesystem::space(tmpPath).available > bigFileSize)
        {
            std::filesystem::create_directory(tmpPath.append("example"));
            std::filesystem::copy_file(bigFilePath, tmpPath.append("newFile"));
        }
        std::cout << "copied!" << std::endl;
    }
    else
    {
        std::cout << "source file doens't exist" << std::endl;
    }

    return 0;
}