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

int dp[105][105][12];

inline int num(int x){
    return (x * (x + 1) / 2);
}

int f(int i , int j , int k){
    if(i > j)
        return 0;
    if(i == j)
        return i;
    if(k == 1)
        return (num(j) - num(i - 1));

    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    int ans = 2e9;
    for(int p = i ; p <= j ; p++){
        int temp = f(p + 1 , j , k) + p;
        temp = max(temp , f(i , p - 1 , k - 1) + p);
        ans = min(ans , temp);
    }

    dp[i][j][k] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    memset(dp , -1 , sizeof dp);
    int t;
    cin >> t;
    int k , m ;
    while(t--){
        cin >> k >> m ;
        cout << f(1 , m , k) << endl;
    }
    return 0;
}
