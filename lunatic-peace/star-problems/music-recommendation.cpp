/*
    User_1 : A B C D 
    User_2 : B C D
    User_3 : A C
A  B   C  D
U1 U1 U1 U1
    Input:
    B C

    Output:
    D
    A
*/

#include <bits/stdc++.h>

using namespace std;

void print_songs(vector<string> songs)
{
    for (int i = 0; i < songs.size(); i++) 
        cout << songs[i] << endl;
}
void find_songs(vector<string> songs, vector<string> input, map<string, int> &loc_map)
{
    int idx = 0;
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i] == input[idx] && idx < input.size()) {
            idx++;
        }
        else if (songs[i] != input[i]) {
            loc_map[songs[i]]++; 
        }
    }
}

vector<string> recommend_songs(map<int, vector<string>> dbase, vector<string> input)
{
    vector<string> songs_recommended;
    map<string, int> loc_map;
    map<int, vector<string>>::iterator it;
    for (it = dbase.begin(); it != dbase.end(); it++) {
        cout << "For user " << it->first << endl;
        print_songs(it->second);
        find_songs(it->second, input, loc_map);
    }
    map<string, int>::iterator it1;
    cout << "Output" << endl;
    for (it1 = loc_map.begin(); it1 != loc_map.end(); it1++) {
        cout << it1->first << endl;
        songs_recommended.push_back(it1->first);
    }
    return songs_recommended; 
}

int main()
{
    map<int, vector<string>> songs_dbase;
    songs_dbase[1] = { "Challa","Dangal","Ram Lakhan","Soorma"}; 
    songs_dbase[2] = {"Dangal", "Ram Lakhan", "Soorma"}; 
    songs_dbase[3] = {"Challa", "Ram Lakhan"};
    string str = "\"EsxiHealthService:\"";
    cout << str;
    string lotName = "esx";
int bid = 0;
    cout << "\"" << lotName << "\" at a price of $" << bid;
    vector<string> input_songs;
    vector<string> output;
    input_songs.push_back("Dangal");
    input_songs.push_back("Ram Lakhan");
    output = recommend_songs(songs_dbase, input_songs);
    cout << "inside main \n";
    for (int i = 0; i<= output.size(); i++) {
        cout << output.back() << endl;
        output.pop_back();
    }
    return 0;
}