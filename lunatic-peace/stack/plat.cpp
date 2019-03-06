
#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int findPlatform_1(int arr[], int dep[], int n)
{

	int maxOverlaps = 0;
	int i = 0;
	int  j = 0;
	sort(arr, arr + n);
	sort(dep, dep + n);
	int numberOfOverLaps  = 0;
	while (i < n-1 && j < n-1) {
		if (arr[i] < dep[j]) {
			i++;
            numberOfOverLaps++;
           	if  (numberOfOverLaps > maxOverlaps)
               		maxOverlaps = numberOfOverLaps;
        }
		else {
			j++;
			numberOfOverLaps--;
		}	
    }
   return maxOverlaps;
}


int main()
{
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1000, 1050, 1200, 1900, 2000};
	//int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
       int ret;
       ret = findPlatform_1(arr, dep, 6);
       printf("%d\n", ret);
	   return 0;
}