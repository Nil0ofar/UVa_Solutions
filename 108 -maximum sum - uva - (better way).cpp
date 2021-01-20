#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
const int N = 105;
//const ll INF;
//const ll NINF = - 1e9;
//const int MAX = 1e9;
//const int MIN = - 1e9

int n;
int a[N][N];
int sum[N];
int dp[N];

int f(int idx){
    if(idx == n)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    int ans = max(sum[idx]  , sum [idx] + f(idx + 1));
    dp[idx] = ans ;
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < n ; j++)
            cin >> a[i][j];
    }
    int ans;
    bool first = true;
    for(int i = 0 ; i < n ; i++){
        memset(sum , 0 , sizeof sum);

        for(int j = i ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                sum[k] += a[j][k];
            }
            memset(dp, -1 ,sizeof dp);
            for(int i = 0 ; i < n ; i++){
                if(first){
                    ans = f(i);
                    first = false;
                }
                else
                    ans = max(ans, f(i));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
