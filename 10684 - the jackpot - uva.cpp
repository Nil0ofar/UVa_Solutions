#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
const int N = 10005;
//const ll INF;
//const ll NINF = - 1e9;
//const int MAX = 1e9;
//const int MIN = - 1e9;

int n;
int a[N];
int dp[N];

int f(int idx){
    if(idx == n)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    dp[idx] = max(0 , a[idx] + f(idx + 1));
    return dp[idx];
}

int main(){
    int ans;
    while(cin >> n , n!= 0){
        for(int i = 0 ; i < n; i++){
            cin >> a[i];
            dp[i] = -1;
        }
        ans = 0;
        for(int i = 0 ;i < n ; i++){
            ans = max(ans, f(i));
        }
        if(ans > 0)
            cout<<"The maximum winning streak is "<<ans<<".\n";
        else
            cout<<"Losing streak.\n";
    }
    return 0;
}
