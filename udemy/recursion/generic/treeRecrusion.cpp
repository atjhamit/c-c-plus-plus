#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void func(int n)
{
    if(n > 0)
    {
        LOG(n);
        func(n - 1);
        func(n - 1);
    }
}

int main()
{
    func(3);
}
