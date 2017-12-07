#include <stdio.h>                        
#include <iostream>                       
#include <algorithm>                      
                                          
using namespace std;                      
                                          
int main()                                
{                                         
        int arr[] = {2,3,7,8,10};           
        int total = 11;                   
        int size = sizeof(arr)/sizeof(arr[0]);
        bool lookup[size+1][total+1] = {0};  
                                          
        for (int i = 0; i < size ; i++)
                lookup[i][0] = true;         
                                          
        for (int i = 1 ; i<=size;i++) {    
                for (int j = 1 ;j <=total;j++) {
                        if (j - arr[i-1] >=0) {
                                lookup[i][j] = lookup[i-1][j] || lookup[i-1][j - arr[i-1]];
                        }                 
                        else {            
                                lookup[i][j] = lookup[i-1][j];
                        }                 
                }                         
        }                                 
                                          
        for (int i = 0 ; i<size;i++) {    
                for (int j = 0 ; j<total+1;j++) { 
                        if (lookup[i][j])                        
                                printf("T\t");
                        else        
                               printf("F\t");
                }                         
                printf("\n");             
        }                                 
                                          
        printf("MAX sum is %d\n",lookup[size][total+1]);
                                          
 }                                        
    
