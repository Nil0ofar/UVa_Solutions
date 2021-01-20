#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 1005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

ll dp[30][30][3];

ll f(int ns, int nt , int turn){
    if(ns == 0 && nt == 0)
        return 1;
    if(turn == 1 && nt == 0)
        return 0;
    if(turn == 0 && ns == 0)
        return 0;
    if(dp[ns][nt][turn] != -1)
        return dp[ns][nt][turn];

    ll ans = 0;
    if(turn == 0){
        for(int i = 0 ; i < ns ; i++)
            ans += f(ns - i - 1, nt + i , 1);
    }
    else{
        for(int i = 0 ; i < nt ; i++)
            ans += f(ns + i , nt - i - 1 , 0);
    }
    dp[ns][nt][turn] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n, m;
    memset(dp , - 1 , sizeof dp);
    while(cin >> n >> m){
        if(n <= 3){
            cout << 1 << endl;
            continue;
        }
        if(m == 1){
            n--;
            m = 2;
        }
        cout << f(m - 1 , n - m , 0) << endl;
    }
    return 0;
}
