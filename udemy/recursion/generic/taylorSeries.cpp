#include "../../lib/commonImport.hpp"

double e(int x, int n)
{
    static double num = 1, den = 1; // num for multiplying numerator with x, den for denominator factorial
    if(n < 1) return 1;

    double ans = 0;
    ans = e(x, n-1);
    num = num * x;
    den = den * n;

    return ans + num/den;    
}

double loophorner(int x, int n)
{
    double ans = 1.0f;
    while(n >= 1)
    {
        ans = 1 + ((double)x/n) * ans;
        n--;
    }
    return ans;
}

double horner(int x, int n)
{
    static double ans = 1.0f;
    if(n < 1) return ans;

    ans = 1 + ans * (double)x/n;// * ans;
    return horner(x,n-1);
}

int main()
{
    int precisionTerms, power;
    LOG("Enter the power");
    std::cin >> power;
    LOG("Enter the number of terms");
    std::cin >> precisionTerms;
    LOG("e ^ " << power << " (" << precisionTerms << " terms) : " << e(power, precisionTerms));
    LOG("Horner : e ^ " << power << " (" << precisionTerms << " terms) : " << horner(power, precisionTerms));
    LOG("Loop Horner : e ^ " << power << " (" << precisionTerms << " terms) : " << loophorner(power, precisionTerms));
    return 0;
}
