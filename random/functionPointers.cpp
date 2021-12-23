#include <iostream>
#include <stdio.h>
#include <string>

void routine(const void* args)
{
    std::cout << *((const char*)args) << std::endl;
}

int main()
{
    const char* abc = "abc";

    void(*ptr)(const void*) = routine;
    ptr(abc);
    ptr(abc);

    return 0;
}
