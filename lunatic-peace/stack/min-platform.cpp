// Program to find minimum number of platforms 
// required on a railway station
#include<iostream>
#include<algorithm>
using namespace std;
 
// Returns minimum number of platforms reqquired
/*
Code:
1. Sort both the arrays holding arrival time and departure time.
2. After sorting use the merging logic (without doing the actual merge). 
   Compare the current element in arrival and departure array and pick which ever 
   is smaller and increment the pointer of that array whose value is picked.
3. If time is picked from the arrival array, increment the total number of trains on 
   the station and if time is picked from the departure array decrease the total number 
   of trains on the station.
4. While doing the above process, we keep the count of maximum value reached till now. At the end this maximum value is returned
*/
int findPlatform(int arr[], int dep[], int noOfTrains)
{
   // Sort arrival and departure arrays
   sort(arr, arr + noOfTrains);
   sort(dep, dep + noOfTrains);
 
   // plat_needed indicates number of platforms
   // needed at a time
   int maxPlatforms = 0;
   int platformsRequired = 0;
   int i = 0, j = 0;
   
   // Logic simlar to Merging of two arrays
   while (i < noOfTrains && j < noOfTrains)
   {
      if (arr[i] < dep[j])
      {
         // New train has arrived.
         platformsRequired++;
         i++;
         if (platformsRequired > maxPlatforms)
				maxPlatforms = platformsRequired;
      }
      else
      {
         // Train left the platform.
         platformsRequired--;
         j++;
      }
   }
 
   return maxPlatforms;
}
 
int findPlatform_1(int arr[], int dep[], int n)
{
	int maxOverlaps = 0; 
	for (int i = 0; i < n-1; i++)
	{
		int numberOfOverLaps  = 0; 
		for (int j =  1; j < n-1; j++) {
			if (arr[i] < dep[j]) {
				numberOfOverLaps++;
				if  (numberOfOverLaps > maxOverlaps)
					maxOverlaps = numberOfOverLaps;
			}
			else {
				numberOfOverLaps--;
			}
			
		}
		
	}
	return maxOverlaps;
	
}
// Driver program to test methods of graph class
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800,2000};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	//int arr[] = {900,  958,  975, 1100, 1400, 1800};
	//int dep[] = {925, 1175, 1108, 1200, 1825, 1900};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
	
	cout << "\n O(n)2 Solution \nMinimum Number of Platforms Required = "
         << findPlatform_1(arr, dep, n);	
		 
    return 0;
}
