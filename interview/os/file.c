#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    FILE *fptr;
    fptr = fopen("text.txt","w");
    if(!fptr)
    {
        printf("ERROR creating file1.txt");
        return 0;
    }
    printf("Enter the number :\t");
    scanf("%d",&number);

    fprintf(fptr, "%d\n",number);

    fclose(fptr);
    return 0;
}
