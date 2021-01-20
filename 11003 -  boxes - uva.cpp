#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
const int N = 1005;
//const ll INF;
//const ll NINF;
const int MAX = 1e9;
//const int MIN = - 1e9;

int n;
int w[N];
int l[N];
int dp[N][3*N];

int f(int idx , int load){
    if(load < 0)
        return -1;
    if(idx == n || load == 0)
        return 0;
    if(load != MAX){
        if(dp[idx][load] != -1)
            return dp[idx][load];
    }
    int ans = f(idx + 1 , load  );
    ans = max(ans , f(idx + 1 , min(load - w[idx] , l[idx])) + 1);
    if(load != MAX)
        dp[idx][load] = ans;
    return ans;
}

int main(){
    while(cin >> n , n!=0){
        for( int i = 0 ; i < n ; i++ ){
            cin >> w[i] >> l[i];
        }
        memset(dp, -1 , sizeof dp);
        cout<<f(0 , MAX)<<endl;

    }
    return 0;
}
