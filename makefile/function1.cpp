#include "functions.h"

int factorial(int n)
{
    if(n < 0)
        return -1;
    if(n <= 1)
        return 1;
    int fact = 1;

    while(n != 1)
    {
        fact *= n;
        n--;
    }
    return fact;
} 
