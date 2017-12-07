#include<stdio.h>
 
/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a1[], int  a2[])
{
    int i;
    int result = a1[0]; /* For xor of all the elements in array */
    int x2 = 1; /* For xor of all the elements from 1 to n+1 */
     
    for (i = 1; i< 9; i++)
        result = result^a1[i];
            
    for ( i = 0; i < 8; i++)
        result = result^a2[i];         
    
    return result;
}
 
/*program to test above function */
int main()
{
    int a1[] = {9, 7, 8, 5, 4, 6, 2, 3, 1};
    int a2[] = {2, 3, 4, 9, 1, 8, 5, 6};
    int miss = getMissingNo(a1,a2);
    printf("%d", miss);
    getchar();
}
