#include <bits/stdc++.h>

using namespace std;

/**************************************************************************
*  Given a string containing only digits, restore it by returning all possible 
*  valid IP address combinations.
*
*  For example:
*  Given "25525511135",
*  
*  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
***************************************************************************/
//This is a typical search problem and it can be solved by using DFS.
void dfs(string s,int start,int step,string ip,vector<string>& result){
    cout << ip << endl;
    if(start == s.size() && step == 4){
        ip.erase(ip.end()-1); //remove the last '.' from the last decimal number
        result.push_back(ip);
        return;
    }
    cout << s.size() << " " << start << " " << step << endl;
    if(s.size() - start > (4 - step) * 3) 
        return;
    if(s.size() - start < (4-step)) 
        return;

    int num = 0;
    for(int i = start;i < start + 3; i++){
        cout << s[i] << " - " << '0' << " = "<< s[i] - '0' <<endl;
        num = num * 10 + (s[i] - '0');
        cout << num <<"---------------------------------------------" << endl;
        if(num <= 255){
            ip += s[i];
            cout << "ip = " << ip << endl;
            dfs(s, i+1, step+1, ip +'.', result);
        }
        if(num == 0) 
            break;
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string ip;
    dfs(s,0,0,ip,result); //paras:string s,start index of s,step(from0-3),intermediate ip,final result
    return result;
}

int main()
{
    string ip_addr = "25525511135";
    vector<string> ips = restoreIpAddresses(ip_addr);
    for (auto ip : ips)
        cout << ip << endl;    
    return 0;
}