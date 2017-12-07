// A Dynamic Programming based C++ program to find the
// number of times the second string occurs in the first
// string, whether continuous or discontinuous
#include <iostream>
// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;

// Iterative DP function to find the number of times
// the second string occurs in the first string,
// whether continuous or discontinuous
//
int smallest(int x, int y, int z){
  return x < y ? (x < z ? x : z) : (y < z ? y : z);
}
int editdistance(string a, string b)
{
	int m = a.length();
	int n = b.length();
      int min;
	// Create a table to store results of sub-problems
	int lookup[m + 1][n + 1] = { { 0 } };

	// If first string is empty
	for (int i = 0; i <= n; ++i)
		lookup[0][i] = i;

	// If second string is empty
	for (int i = 0; i <= m; ++i)
		lookup[i][0] = i;

	// Fill lookup[][] in bottom up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// If last characters are same, we have two 
			// options -
			// 1. consider last characters of both strings
			// in solution
			// 2. ignore last character of first string
			if (a[i - 1] == b[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] ; 
						
				
			else
                        {				// If last character are different, ignore
				// last character of first string
		       	lookup[i][j] = 1 + smallest( lookup[i - 1][j], lookup[i-1][j-1],lookup[i][j-1]);
			//printf("%d\t",lookup[i][j ]);
		        }
                }
		
	}
    for (int i =0;i<m+1;i++) {
        for (int j=0;j<n+1;j++)
            printf("%d\t",lookup[i][j]);
        printf("\n");
    }
	return lookup[m][n];
}
int count(string a, string b)
{
	int m = a.length();
	int n = b.length();

	// Create a table to store results of sub-problems
	int lookup[m + 1][n + 1] = { { 0 } };

	// If first string is empty
	for (int i = 0; i <= n; ++i)
		lookup[0][i] = 0;

	// If second string is empty
	for (int i = 0; i <= m; ++i)
		lookup[i][0] = 1;

	// Fill lookup[][] in bottom up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// If last characters are same, we have two 
			// options -
			// 1. consider last characters of both strings
			// in solution
			// 2. ignore last character of first string
			if (a[i - 1] == b[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 
							lookup[i - 1][j];
				
			else
				// If last character are different, ignore
				// last character of first string
				lookup[i][j] = lookup[i - 1][j];
			//printf("%d\t",lookup[i][j ]);
		}
		
	}
    for (int i =0;i<m+1;i++) {
        for (int j=0;j<n+1;j++)
            printf("%d\t",lookup[i][j]);
        printf("\n");
    }
	return lookup[m][n];
}





// Driver code
int main()
{
	string a = "abadcb";
	string b = "ab";

	cout << count(a, b);
	string p = "abcdef";
        string q = "azced";
        printf("EDINT DISTANCE COUNT: \n");
        cout << editdistance(q, p);

	return 0;
}

