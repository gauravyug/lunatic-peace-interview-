// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

bool wildcardmatcher(string str, string pattern)
{
        int strLen = str.length();
        int patternLen = pattern.length();
        bool lookup[strLen +1][patternLen +1] = {false};
        for (int i = 0; i <= patternLen; i++)
        {
                lookup[0][i] = false;
        }
        
        for (int i = 0; i <= strLen; i++)
        {
                lookup[i][0] = false;
        }
        
        lookup[0][0] = true;

        for (int j = 1; j <= patternLen; j++)
                if (pattern[j - 1] == '*')
                        lookup[0][j] = lookup[0][j - 1];

        int i, j = 0;
        for(i = 1; i<=strLen; i++) {
                for (j = 1; j<=patternLen;j++) {
                        if (pattern.at(j-1) == '?' || str.at(i-1) == pattern.at(j-1))
                                lookup[i][j] = lookup[i-1][j-1];
                        else if(pattern.at(j-1) == '*')
                                lookup[i][j] = lookup[i-1][j] || lookup[i][j-1]; 

                }
        }
        return lookup[strLen][patternLen];
}

int main()
{
        std::string str = "xaylmz";
        std::string pat = "x?y*z";
        cout << "wildcard matcher ::"<<wildcardmatcher(str, pat) << "\n";

        cout << "wildcard matcher ::"<<wildcardmatcher("baaabab","*****ba*****ab") << "\n";
        return 0;
}
