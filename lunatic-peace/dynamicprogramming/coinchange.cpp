#include <stdio.h>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
        int coin[] = {1,5,6,8};
        int total = 11;
        int size = sizeof(coin)/sizeof(coin[0]);
        int lookup[size][total+1] = {0};
 
        for (int i = 0; i < total+1 ; i++)
                lookup[0][i] = i;
 
        for (int i = 0; i < size ; i++)
                lookup[i][0] = 0;

        for (int i = 1 ; i<size;i++) {
                for (int j = 0 ;j <total+1;j++) {
                        if (j >= coin[i]) {
                                lookup[i][j] = min(lookup[i-1][j], 1 + lookup[i][j - coin[i]]);
                        }
                        else {
                                lookup[i][j] = lookup[i-1][j];
                        }
                }
        }
 
        for (int i = 0 ; i<size;i++) {
                for (int j = 0 ; j<total+1;j++) {
                        printf("%d\t",lookup[i][j]);
                }
                printf("\n");
        }
 
        printf("MAX sum is %d\n",lookup[size][total+1]);
 
 }

