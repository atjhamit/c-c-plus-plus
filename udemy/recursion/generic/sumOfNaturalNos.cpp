#include "../../lib/commonImport.hpp"

int sum(int n)
{
    if (n < 1) return 0;

    return n + sum(n-1);
}

int main()
{
    int val = 5;
    LOG("sum of first 5 natural nos : " << sum(val));
    return 0;
}
