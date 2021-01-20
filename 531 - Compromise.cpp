#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

vector<string> s1 , s2;
int dp[105][105];

int f(int i , int j){
    if(i == s1.size() || j == s2.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = f(i + 1 , j);
    ans = max(ans , f(i , j + 1));
    if(s1[i] == s2[j]){
        ans = max(ans , 1 + f(i + 1 , j + 1));
    }
    dp[i][j] = ans;
    return ans;
}


void print(int i , int j){
    if(i == s1.size() || j == s2.size()){
        cout<<endl;
        return;
    }
    if(f(i , j) == f(i + 1 , j)){
        return print(i + 1 , j);
    }
    if(f(i , j) == f(i , j + 1))
        return print(i , j + 1);
    cout<<s1[i];
    if(f(i , j + 1) != 0)
        cout<<' ';
    else{
        cout<<endl;
        return;
    }
    print(i + 1 , j + 1);
}

int main(){
    bool first = true;
    string s;
    memset(dp , -1 , sizeof dp);
    while(getline(cin , s)){
        stringstream ss(s);
        if(first){
            while(ss >> s){
                if(s == "#")
                    first = false;
                else
                    s1.pb(s);
            }
        }
        else{
            while(ss >> s){
                if(s == "#"){
                    first = true;
                    f(0 , 0);
                    print(0 , 0);
                    memset(dp, -1 , sizeof dp);
                    s1.clear();
                    s2.clear();
                }
                else
                    s2.pb(s);
            }
        }
    }
    return 0;
}
