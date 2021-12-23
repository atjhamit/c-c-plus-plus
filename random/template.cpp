#include <iostream>

template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Print<int>(4);
    Print<std::string>("Hey there");
    return 0;
}
