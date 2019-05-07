#include <bits/stdc++.h>

using namespace std;
string reverseWords(string s) {
        reverse(s.begin(), s.end());
        cout << s;
        int start = 0, end = 0;
        while ((end = s.find(" ", start)) != string::npos) {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        reverse(s.begin() + start, s.end());
        cout << s;
        return s;
}

int main() {
    string str = "sky is blue";
    reverseWords(str);
    cout << str;
}