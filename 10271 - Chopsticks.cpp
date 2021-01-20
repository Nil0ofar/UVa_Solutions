#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define ll long long
#define pll pair<ll , ll>
#define pii pair<int , int>
#define pb push_back
#define N 5005
#define mod 1000000007
#define Base 100001
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int INF = 1e9;
int n ;
int a[N];
ll dp[N][1024];

inline ll p2(ll x){return x * x;}

ll f(int idx , int need){
    if(need == 0)
        return 0;

    if(need * 3 > n - idx)
        return INF;

    if(dp[idx][need] != -1)
        return dp[idx][need];

    ll ans = f(idx + 1 , need);
    ans = min(ans , f(idx + 2 , need - 1) + p2(a[idx + 1] - a[idx]));
    dp[idx][need] = ans;
    return ans;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    int k ;
    while(t--){
        cin >> k >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];

        memset(dp  , - 1 , sizeof dp);

        cout << f(0 , k + 8) << endl;
    }
    return 0;
}
