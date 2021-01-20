#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

int k ;
const int MAX = 20000;
string s;
int dp[1001][28];
bool mark[1001][28];
vector<int> vec[1005];
int cnt[1005];

int f(int c , int idx){
    if(idx == s.size() / k)
        return 0;
    if(dp[idx][c] != -1){
        return dp[idx][c];
    }
    int ans = MAX;
    int num = cnt[idx];
    if(mark[idx][c])
        num --;
    for(int i = 0 ; i < vec[idx].size() ; i++){
        if(vec[idx][i] == c)
            continue;
        else{
            ans = min (ans, num + f(vec[idx][i] , idx + 1));
        }
    }

    if(num == 0){
        ans = f(c , idx + 1);
    }
    dp[idx][c] = ans;
    return ans;
}

int main()
{
    int testcase;
    cin >> testcase;
    while( testcase -- ){
        memset(dp , -1 , sizeof dp);
        memset(mark, false , sizeof mark);
        memset(cnt , 0 , sizeof cnt);
        cin >> k >> s;

        for(int i = 0 ; i < s.size()  ; i ++)
            vec[i].clear();

        int j ;
        for(int i = 0 ; i < s.size() / k ; i++){
            for(j = 0 ; j < k ; j++){
                if(!mark[i][s[i * k + j] - 'a']){
                    mark[i][s[i * k + j] - 'a'] = true;
                    cnt[i]++;
                    vec[i].pb(s[i * k + j] - 'a');
                }
            }
        }

        cout<<f('z' - 'a' + 1 , 0)<<endl;

    }
    return 0;
}
