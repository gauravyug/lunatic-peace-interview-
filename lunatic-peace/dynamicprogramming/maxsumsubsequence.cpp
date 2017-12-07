#include <stdio.h>
#include <iostream>
#include <algorithm> 

using namespace std;

int main()
{
        int arr[] = {4,6,1,3,8,4,6};
        int size = sizeof(arr)/sizeof(arr[0]);
        int temp[size] = {0};
        int order[size] = {0};

        int maxsum = 0;
        for (int i = 0; i < size ; i++)
                temp[i] = arr[i];

        for (int i =1 ; i<size;i++) {
                for (int j =0 ;j <i;j++) {
                        if (arr[j] < arr[i]) {
                                temp[i] = max(temp[i], temp[j] + arr[i]);
                                order[i] = j;
                        }
                }
        }

        for (int i=0;i<size;i++) {
                printf("temp[%d] - %d\n",i,temp[i]);
                printf("order[%d] - %d\n",i,order[i]);
                
                if (temp[i] >maxsum)
                        maxsum = temp[i];
        }

        printf("MAX sum is %d\n",maxsum);
        
 }
