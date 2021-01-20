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
#define N 200005
#define mod 1000000007
#define Base 100001
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int dp[256][256];
int sum[256];
int a[256];

int f(int i , int j){
    if(i >= j)
        return 0;
    int &ref = dp[i][j];

    if(ref != -1)
        return ref;

    ref = 1e9;

    for(int k = i ; k <= j ; k++)
        ref = min(ref , sum[j] - sum[i - 1] - a[k] + f(i , k - 1) + f(k + 1 , j));

    return ref;
}

int main(){
    ios_base :: sync_with_stdio(false);
    int n;
    while(cin >> n){
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }

        memset(dp , -1 , sizeof dp);
        cout << f(1 , n ) << endl;
    }

    return 0;
}
