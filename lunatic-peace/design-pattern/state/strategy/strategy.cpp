/*
Strategy design pattern
*/

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class SortStrategy{
public:
	virtual void Sort(vector<int> &v){
		cout << "Default Sort\n";
	}
};


class BubbleSort: public SortStrategy{
	
	public:
    virtual void Sort(vector<int> &v){
        int i, j; 
        bool is_swap; 
        int n = v.size();
        cout << "Bubblesort" << endl;
        for (i = 0; i < n-1; i++) 
        { 
            is_swap = false; 
            for (j = 0; j < n-i-1; j++) 
            { 
                if (v[j] > v[j+1]) 
                { 
                    swap (v[j], v[j+1]);
                    is_swap = true; 
                } 
            } 
            if (is_swap == false) 
            break; 
        } 
		}
};


class ShellSort: public SortStrategy{
public:
		virtual void Sort(vector<int> &arr){
			int n = arr.size();
			cout << "Shell Sort\n";
			for (int gap = n / 2; gap > 0; gap /= 2) { 
				// Do a gapped insertion sort for this gap size. 
				// The first gap elements a[0..gap-1] are already in gapped order 
				// keep adding one more element until the entire array is 
				// gap sorted 
				for (int i = gap; i < n; i += 1) { 
					// add a[i] to the elements that have been gap sorted 
					// save a[i] in temp and make a hole at position i 
					int temp = arr[i]; 
			
					// shift earlier gap-sorted elements up until the correct 
					// location for a[i] is found 
					int j; 
					for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
						arr[j] = arr[j - gap]; 
			
					// put temp (the original a[i]) in its correct location 
					arr[j] = temp; 
				} 
			} 
		}
				
};

class Sort{
	SortStrategy *sst;
	
public:
	Sort(SortStrategy *sst){
		this->sst = sst;
	}
	void sort(vector<int> &v){
		sst->Sort(v);
	}

};

int main(){
	vector<int>v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	v.push_back(4);
	v.push_back(9);
	
	Sort d = Sort(new BubbleSort());
	d.sort(v);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " " ;
	cout << endl;
	return 0;
}