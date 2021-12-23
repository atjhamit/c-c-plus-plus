#include "common.h"

int main()
{
    std::vector<int> arr1(5,2);

    for(const int& val : arr1)
        LOG(val);
}
