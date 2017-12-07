#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longestIncSubsequence(int arr[], int size)

{

   //int arr[] = {5,6,2,3,4,1,9,9,8,9,5};

    //int arr[] = {10, 25, 36, 40, 59, 48, 34, 20, 5};


    int arrSize = size;//of(arr)/sizeof(arr[0]);

    int LIStable[100] = {0};

    

    int i=0 ,j = 0;

    int max = 0;

    int index = 0;

    for (i = 0;i<arrSize;i++) {

        LIStable[i] = 1;

    }

    for (i = 0;i<arrSize;i++) {

        for (j=0;j<i;j++) {

            if (arr[i] > arr[j] )//&& LIStable[i] < LIStable[j] + 1)

            {

                int v = LIStable[i] < LIStable[j] + 1;

               

                LIStable[i] = std::max(LIStable[i],LIStable[j] + 1);

            }

        }

    }

    

    for (i = 0;i<arrSize;i++) {

        if (max < LIStable[i]) {

            max = LIStable[i];

            index = i;

        }

    }

    

    printf("Longest Increasing Subsequence Length is : %d  @ index : %d\n", max,index);

    

    printf("Longest Increasing Subsequence Elements Are :\n");

    std::vector<int> items;

    int temp = max ;

    for (i = index  ;i >= 0; i--) {

        if (LIStable[i] == temp) {

            items.push_back(arr[i]);

            temp--;

        }

    }

    

    std::reverse(items.begin(), items.end());

    for (i = 0  ;i < items.size(); i++) {

        printf("%d ",items[i]);

    }

    return 0;

}



int main()

{

    int p1[] = {1,2,3,4,5,6,7,8};

    int p2[] = {5,1,8,3,4,2,6,7};

    

    int size = sizeof(p1)/sizeof(p1[0]);

    

    vector<pair<int , int>> vec;

    

    for (int i = 0; i < size; i++)

        vec.push_back(make_pair(p2[i], p1[i]));

    

    cout<<"Before Sorting Pairs:" << endl;

    for (int i=0; i<size; i++)

    {

        // "first" and "second" are used to access

        // 1st and 2nd element of pair respectively

        std::cout << vec[i].first << " "

        << vec[i].second << endl;

    }

    std::sort(vec.begin(), vec.end());

    

    cout<<"After Sorting Pairs:" << endl;

    for (int i=0; i<size; i++)

    {

        // "first" and "second" are used to access

        // 1st and 2nd element of pair respectively

        std::cout << vec[i].first << " "

        << vec[i].second << endl;

    }

    

    for (int i = 0; i < size; i++)

        p2[i] = vec[i].second;

    

    printf("Maximum Bridges can be : %d\n",longestIncSubsequence(p2, size));

    return 0;

}
