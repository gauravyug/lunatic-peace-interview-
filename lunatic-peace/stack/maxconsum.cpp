#include <stdio.h>
#define size 8

int sum(int *a, int j, int i)
{
       int sum = 0;
//      printf("j=%d a[j]=%d\n", j, a[j]);

       for ( ; j<= i;j++)
       {
               sum += a[j];
       }
//      printf("SUM=%d\n", sum);
       return sum;
}


int main()
{
       int arr[size] =  {-2, -3, 4, -1, -2, 1, 5, -3};
       int largest = 0, ret, i, j, k;
       for ( j = 0; j< size-1; j++){
			for ( k=size-1; k>j; k--){
               ret = sum(&arr[0], j, k);
               if (ret > largest)
                       largest = ret;
			}
//      	printf("\n");
       }
       if ((arr[size-1] + arr[size-2] ) > largest)
               largest = arr[size-1] + arr[size-2];

       printf("%d\n", largest);
	   return 0;
}