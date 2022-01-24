#include "../lib/commonImport.hpp"

int count = 0;

void TOH(int disks, int A, int B, int C)
{
    if(disks < 1) return;
    count++;

    TOH(disks - 1, A, C, B);
    LOG("Move " << A << " to " << C);
    TOH(disks - 1, B, A, C);
}

int main()
{
    LOG_T("Tower of Hanoi. Enter Disks :");
    int disks;
    std::cin >> disks;
    TOH(disks, 1,2,3); // disks, source, using, destination
    LOG("===== Steps taken : " << count << "=======");
    return 0;
}
