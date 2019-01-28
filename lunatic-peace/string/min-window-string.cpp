#include <iostream>
#include <string>

using namespace std;

string minWindow(string S, string T) 
{
    if (S.length() == 0 || T.length() == 0)
        return "";
    int minWindowBegin;
    int minWindowEnd;
    int sLen = S.length();
    int tLen = T.length();
    int needToFind[256] = {0};

    for (int i = 0; i < tLen; i++)
        needToFind[T[i]]++; // take the count of text to be searched in given string

    int hasFound[256] = {0};
    int minWindowLen = 0xffff;
    int count = 0;
    for (int begin = 0, end = 0; end < sLen; end++) {

        if (needToFind[S[end]] == 0) continue;
            hasFound[S[end]]++;
        if (hasFound[S[end]] <= needToFind[S[end]])
            count++;

        // if window constraint is satisfied
        if (count == tLen) {
                // advance begin index as far right as possible,
                // stop when advancing breaks window constraint.
            while (needToFind[S[begin]] == 0 ||
                hasFound[S[begin]] > needToFind[S[begin]]) {
                if (hasFound[S[begin]] > needToFind[S[begin]])
                    hasFound[S[begin]]--;
                begin++;
            }

            // update minWindow if a minimum length is met
            int windowLen = end - begin + 1;
            if (windowLen < minWindowLen) {
                minWindowBegin = begin;
                minWindowEnd = end;
                minWindowLen = windowLen;
            } // end if
        } // end if
    } // end for
    return S.substr(minWindowBegin, minWindowEnd);
}

int main ()
{
    cout << minWindow( "babb", "baba");
    return 0;
}