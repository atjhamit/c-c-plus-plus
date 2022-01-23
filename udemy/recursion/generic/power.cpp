#include "../../lib/commonImport.hpp"

int pow(int number, int power)
{
    if(power < 1) return 1;

    return number * pow(number, power - 1);
}

int enhPow(int number, int power)
{
    if(power < 1) return 1;

    if(!(power % 2))
        return enhPow(number * number, power/2);
    else
        return number * enhPow(number * number, (power - 1)/2);
}

int main()
{
    int number; int power;
    LOG("Enter number and power");
    std::cin >> number >> power;
    LOG(number << "^" << power << " = " << enhPow(number, power));
    return 0;
}
