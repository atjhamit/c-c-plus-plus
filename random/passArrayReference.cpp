#include <iostream>

#define LOG(x) std::cout << x ;

void print(int& (*arr))
{
//    int size = sizeof(arr)/sizeof(arr[0]);
//   LOG("size in print : " << size << "\n");
}

int main()
{
    int arr[5] = {1,2,3,4,5};//new int[5];
    LOG("size of " << sizeof(arr)/sizeof(arr[0]) << "\n");


    print(&arr);

    return 0;
}
