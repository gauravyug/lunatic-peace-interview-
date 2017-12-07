#include <iostream>
#include <deque>

using namespace std;

void maxslidingwinsum(int arr[], int n, int k)
{
        std::deque<int> Q(k);
        int temparr[n];
        int i;
        for (i=0; i<k;i++){
                while ((!Q.empty()) && arr[i] > arr[Q.back()])
                        Q.pop_back();
                Q.push_back(i);
        }

        for (;i<n;i++) {
                temparr[i-k] = Q.front() ;
                cout << arr[Q.front()] <<" ";
                 while ((!Q.empty()) && Q.front() <= i - k )
                        Q.pop_front();

                 while ((!Q.empty()) && arr[i] > arr[Q.back()])
                        Q.pop_back();

                Q.push_back(i);
        }
        cout << "\n Print max element of last window \n"<< arr[Q.front()];
        temparr[i-k] = arr[Q.front()] ;
        for (int j=0;j<i-k;j++)
                cout << "\nPrint from array:" << arr[temparr[j]];
}

int main()
{
        int arr[] = {12,1,78,90,57,89,56};
        int n = sizeof(arr)/sizeof(arr[0]);
        int k = 3;
        maxslidingwinsum(arr, n , k);
        cout << "\n";
        return 0;
}
