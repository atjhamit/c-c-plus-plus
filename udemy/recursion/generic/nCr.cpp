#include "../../lib/commonImport.hpp"

int nCr(int n, int r)
{
    if(!r || n == r) return 1;

    return nCr(n-1,r-1) + nCr(n-1,r);
}

int main()
{
    LOG("Enter n and r");

    int n, r;
    std::cin >> n >> r;

    LOG(n << "C" << r << " : " << nCr(n, r));

    return 0;
}
