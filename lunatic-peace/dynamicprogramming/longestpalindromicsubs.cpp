#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

int main()
{
        char* str = "AGBDBA";
        
        int arr[5][5] = {0};
        int len = str.length();
         for (int i =0; i< len;i++)
                 arr[i][i] = 1;
         for (int curr_len = 2; curr_len <= len;curr_len++){
                for (int i = 0; i <curr_len; i++){
                        int j = i + curr_len -1;

                        if (strcmp(str, str)){
                                arr[i][j] = 2 + arr[i+1][j-1];
                        }
                        else {
                                arr[i][j] = arr[i+1][j] > arr[i][j+1] ? arr[i+1][j] : arr[i][j+1];
                        }
                }
                printf("%dlength is:\n",arr[0][len-1]);
         }

        return 0;
}
