#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 50005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

int dp[85][515];
int a[85] , b[85] , c[85] , s[85];
int n;

int f(int idx , int mask){
    if(mask == 0)
        return 0;

    if(idx == n)
        return -100;

    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    int ans = f(idx + 1 , mask);
    int temp;
    if((mask & (1 << a[idx])) != 0 && (mask & (1 << b[idx])) != 0 && (mask & (1 << c[idx])) != 0){
        mask ^= (1 << a[idx]);
        mask ^= (1 << b[idx]);
        mask ^= (1 << c[idx]);
        temp = f(idx + 1 , mask);
        if(temp >= 0)
            ans = max(ans , temp + s[idx]);
        mask ^= (1 << a[idx]);
        mask ^= (1 << b[idx]);
        mask ^= (1 << c[idx]);
    }
    //cout << idx << ' '<< mask << ' ' <<ans << endl;
    dp[idx][mask] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int tc = 1;
    while(cin >> n && n != 0){
        for(int i = 0 ; i < n ; i++){
            cin >> a[i] >> b[i] >> c[i] >> s[i];
            a[i]-- , b[i]-- , c[i]--;
        }
        memset(dp, -1 , sizeof dp);
        int mask = (1 << 9) - 1;
        cout << "Case " << tc++ << ": " << max(-1 , f(0 , mask)) << endl;
    }
}
