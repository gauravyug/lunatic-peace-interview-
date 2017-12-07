#include <iostream>                                                                                                                                                                                                
using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}
int longestCommonSubsequence(string str1, string str2)
{
        int len = 0;
        if (str1.length() == 0 || str2.length() == 0)
                return 0;


        int lookup[str1.length() + 1][str2.length() + 1] = {0};
        
        for (int i = 0; i <= str1.length(); i++)
                lookup[0][i] = 0;
        
        for (int i = 0; i <= str2.length(); i++)
                lookup[i][0] = 0;

        for (int i = 1; i<= str1.length(); i++) {
                for (int j = 1; j <=str2.length(); j++)
                {
                        if (str1.at(i-1) == str2.at(j-1))
                                lookup[i][j] = lookup[i-1][j-1] + 1;
                        else

                                lookup[i][j] = max(lookup[i][j-1], lookup[i-1][j]);
                }
        }
        return lookup[str1.length()][str2.length()];
}

int main()
{
        string str1 = "abcdaf";
        string str2 = "acbcf";

        cout << "Longest Common Subsequence :" << longestCommonSubsequence (str1, str2) << "\n";
        cout << "Longest Common Subsequence :" << longestCommonSubsequence ("AGGTAB", "GXTXAYB") << "\n";

}
