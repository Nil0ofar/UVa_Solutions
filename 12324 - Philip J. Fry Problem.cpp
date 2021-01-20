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
#define Base 16005

int n ;
int val[105];
int spell[105];
int dp[105][105];

int f(int idx , int m){
    if(idx == n)
        return 0;

    if(dp[idx][m] != -1)
        return dp[idx][m];

    int ans = val[idx] + f(idx + 1 , min(100 , m + spell[idx]));
    if(m > 0){
        int p = min(100 , m - 1 + spell[idx]);
        int temp = (val[idx] / 2) + f(idx + 1 , p);
        ans = min(ans , temp);
    }
    dp[idx][m] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    while(cin >> n && n != 0){
        memset(dp , -1 , sizeof dp);
        for(int i = 0 ; i < n ; i++)
            cin >> val[i] >> spell[i] ;
        cout << f(0 , 0) << endl;
    }
}
