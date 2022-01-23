#include "../../lib/commonImport.hpp"

int fiboLoop(int n)
{
    if(n <= 1) return n;

    int ans = 0;
    int a = 0;
    int b = 1;

    while(n > 1)
    {
        ans = a + b;
        a = b;
        b = ans;
        n--;
    }
    return ans;
}

static int answers[10];

int improvedFibo(int n)
{
    LOG(__FUNCTION__);
    if(n <= 1) return n;

    if(answers[n-2] < 0)
        answers[n-2]  = improvedFibo(n-2);
    if(answers[n-1] < 0)
        answers[n-1] = improvedFibo(n-1);
    return answers[n-2] + answers[n-1];
}

int fibo(int n)
{    
    LOG(__FUNCTION__);
    if(n <= 1) return n;

    return fibo(n-2) + fibo(n-1);
}

int main()
{
    LOG("Enter the term < 10");

    int n;
    std::cin >> n;

    for(int i = 0; i < 10; i++)
        answers[i] = -1;

    LOG("fibo(" << n << ") = " << fibo(n));
    LOG("fiboLoop(" << n << ") = " << fiboLoop(n));
    LOG("improvedFibo(" << n << ") = " << improvedFibo(n));

    return 0;    
}
