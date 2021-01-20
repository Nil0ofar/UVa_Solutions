#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 500005
#define ll long long
#define pii pair<ll , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

int n = 12;
int dp[N];

int ones(int x){
    int cnt = 0;
    for(int i = 0 ; i < 12 ; i++)
        if((x & (1 << i)) != 0)
            cnt++;
    return cnt;
}

int f(int mask){
    if(dp[mask] != -1)
        return dp[mask];

    int ans = ones(mask);

    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) != 0){
            if(i + 2 < n && (mask & (1 << (i + 2))) == 0 && (mask & (1 << (i + 1))) != 0){
                mask ^= (1 << (i + 2));
                mask ^= (1 << (i + 1));
                mask ^= (1 << i);
                ans = min(ans , f(mask));
                mask ^= (1 << (i + 2));
                mask ^= (1 << (i + 1));
                mask ^= (1 << i);
            }

            if(i - 2 >= 0 && (mask & (1 << (i - 2))) == 0 && (mask & (1 << (i - 1))) != 0){
                mask ^= (1 << (i - 2));
                mask ^= (1 << (i - 1));
                mask ^= (1 << i);
                ans = min(ans , f(mask));
                mask ^= (1 << (i - 2));
                mask ^= (1 << (i - 1));
                mask ^= (1 << i);
            }
        }
    }
    dp[mask] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    string s;
    memset(dp , -1 , sizeof dp);
    while(t--){
        cin >> s;
        int mask = 0;
        for(int i = 0 ; i < n ; i++){
            mask *= 2;
            if(s[i] == 'o')
                mask += 1;
        }
        cout << f(mask) << endl;
    }
}


