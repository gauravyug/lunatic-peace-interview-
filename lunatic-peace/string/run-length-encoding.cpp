#include <iostream>

using namespace std;

void run_length_encoding(string str)
{
    int count = 0;
    bool flag = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == str[i+1]) {
            count = count + 1;
        }
        if (str[i] != str[i+1]) {
            flag = true;
        }
        if (flag) {
            cout << str[i] << count +1;
            flag = false;
            count = 0;
        }
    }
}

string decoding(const string  &s) {
    int count = 0;
    string result;
    for (const char &c : s) {
        if (isdigit(c)) {
            count = count * 10 + c - '0';
        }
        else {
            result.append(count, c);
            count = 0;
        }
    }
    return result;
}

string encoding(const string &s) {
    string result;
    for (int i = 1, count = 1; i <= s.size(); i++) {
        if (i == s.size() || s[i] != s[i-1]) { // Found new character, so write the count of previous char
            //result += to_string(count) + s[i-1];
            result += s[i-1] + to_string(count);// + s[i-1];
            count = 1;
        }
        else { // s[i] == s[i-1]
            ++count;
        }
    }
    return result;
}

int main()
{
    string str = "wwwwaaadexxxxxxywww"; //w4a3d1e1x6y1w3

    //string str = "abc"; //w4a3d1e1x6y1w3
    //run_length_encoding(str);
    cout << str << endl;
    string res = encoding(str);
    cout << res << endl;
    res = decoding(res);
    cout << res;

    return 0;

}