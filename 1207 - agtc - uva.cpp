#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

string s, t;
int len_s , len_t;
vector<vector< int > > dp;

int f(int i , int j){
    if(i == len_s && j == len_t)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == len_s){
        dp[i][j] = 1 + f(i , j + 1);
        return dp[i][j];
    }

    if(j == len_t){
        dp[i][j] = 1 + f(i + 1 , j);
        return dp[i][j];
    }

    if(s[i] == t[j])
        dp[i][j] = f(i + 1 , j + 1);
    else{
        dp[i][j] = 1 + f(i , j + 1) ; // insert
        dp[i][j] = min(dp[i][j] , 1 + f(i + 1 , j + 1)); // change
        dp[i][j] = min(dp[i][j] , 1 + f(i + 1 , j)); // delete
    }
    return dp[i][j];
}


int main()
{
    vector<int > temp ;
    while(cin >> len_s){
        cin >> s >> len_t >> t;
        dp.clear();
        temp.clear();
        for(int i = 0 ; i <= len_t ; i++)
            temp.pb(-1);
        for(int i = 0 ; i <= len_s ; i++){
            dp.pb(temp);
        }
        cout<<f(0 , 0)<<endl;

    }
    return 0;
}
