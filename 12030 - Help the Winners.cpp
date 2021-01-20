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
#define pbl pair<bool , ll>
#define pb push_back
#define pdd pair<double , double>
#define N 300000 + 5
#define mod 998244353
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>

int n ;
int mat[16][16];
ll dp[16][40000][2];
ll fact[16];

ll f(int idx , int mask , bool must){
    if(idx == n)
        return !must;

    ll &ans = dp[idx][mask][must];
    if(ans != -1)
        return ans;

    ans = 0;
    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) != 0){
            if(mat[idx][i] == 1)
                ans += f(idx + 1 , (mask ^ (1 << i)) , must);
            else if(mat[idx][i] == 2)
                ans += fact[n - idx - 1];
            else
                ans += f(idx + 1 , (mask ^ (1 << i)) , true);
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    fact[0] = 1;
    for(int i = 1 ; i < 16 ; i++)
        fact[i] = fact[i - 1] * i;

    int tc;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        cin >> n ;
        for(int i = 0 ; i < n; i++)
            for(int j = 0 ; j < n ; j++)
                cin >> mat[i][j];

        memset(dp , -1 , sizeof dp);

        cout <<"Case " << t << ": " << f(0 , (1 << n) - 1 , false) << endl;
    }
    return 0;
}
