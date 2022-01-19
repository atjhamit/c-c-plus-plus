#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define LOG(x) std::cout << x << std::endl

void powerOf2(int a)
{
    if(a == 0)
        LOG(a << " : No.");
    if(ceil(log2(a)) == floor(log2(a)))
        LOG(a << " : Yes.");
    else
        LOG(a << " : No.");    
}

int main()
{
    powerOf2(34);
    return 0;
}
