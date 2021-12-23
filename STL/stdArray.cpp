#include <iostream>
#include <array>

#define LOG(x) std::cout << x << std::endl;

int main()
{
    std::array<int, 5> arr;

    arr = {2,3,5,6,9};

    for(int& val: arr)
        LOG(val);

//    LOG(arr.at(5));  //terminate called after throwing an instance of 'std::out_of_range'
}


/* to access elements 
    at()
    []
    front()
    back()
    data() // gives access to the underlying array
*/