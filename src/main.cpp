#include <iostream>

namespace
{
constexpr auto message = "Hello, World!";
constexpr auto endl = '\n';
} // namespace

int main()
{
    std::cout << message << endl;
    return EXIT_SUCCESS;
}