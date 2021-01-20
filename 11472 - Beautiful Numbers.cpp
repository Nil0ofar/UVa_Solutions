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
#define N 200000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>

int dp[1025][101][11];
int n , m ;

int f(int mask , int rem , int last){
    if(rem == 0){
        if(mask == (1 << n) - 1)
            return 1;
        return 0;
    }

    int &ans = dp[mask][rem][last];

    if(ans != -1)
        return ans;

    ans = (mask == (1 << n) - 1 ? 1 : 0);
    if(last == -1){
        for(int i = 1 ; i < n ; i++){
            ans += f((mask | (1 << i)) , rem - 1 , i);
            ans %= mod;
        }
    }

    else{
        if(last + 1 < n ){
            ans += f((mask | (1 << (last + 1))) , rem - 1 , last + 1);
            ans %= mod;
        }

        if(last - 1 >= 0){
            ans += f((mask | (1 << (last - 1))) , rem - 1 , last - 1);
            ans%= mod;
        }
    }
    //cout << mask << ' ' << rem << ' ' << last << ' ' << ans << endl;
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        memset(dp , - 1 , sizeof dp);
        cin >> n >> m ;
        cout << f(0 , m , -1) << endl;
    }
    return 0;
}
