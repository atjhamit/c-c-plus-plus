#include <stdio.h>
#include <stdlib.h>

void swap(char *val1, char* val2)
{
    char temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void permute(char a[], int l, int r)
{
    int i;
    if(l==r)
        printf("%s\n", a);
    else
    {
        for(i = l; i <= r; i++)
        {
            swap((a+l),(a+i));
            permute(a, l+1, r);
            swap((a+l),(a+i)); // back track
        }
    }
}

int main()
{
    char str[] = "abc";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
