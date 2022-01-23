#include "../../lib/commonImport.hpp"

int factorial(int n)
{
    if (n <= 1) return 1;

    return n * factorial(n - 1);
}

int main()
{
    int input;
    LOG("Enter n");
    std::cin >> input;
    LOG(input << "! = " << factorial(input));
    return 0;
}
