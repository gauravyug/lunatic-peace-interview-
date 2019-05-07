#include <stdio.h>

int main()
{
    int i;
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;     // same as int*p = &a[0]
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *p);
        p++;
    }
    p = &a[2];
        printf("%d", *p);

    p = &a[2];
    p++;
        printf("%d", *p);
    
    return 0;
}