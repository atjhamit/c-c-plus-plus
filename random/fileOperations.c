#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    int num = 0;
    FILE *fptr;
    fptr = fopen("text.txt","r");
    if(!fptr)
    {
        printf("ERROR creating file1.txt");
        return 0;
    }
    printf("Enter the number :\t");
    scanf("%d",&number);

//    fprintf(fptr, "%d\n",number);
    fscanf(fptr, "%d", &num);
    printf("Number = %d\n",num);
    fclose(fptr);
    exit(1);
}
