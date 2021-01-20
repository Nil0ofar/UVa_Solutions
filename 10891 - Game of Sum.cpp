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
#define N 1000000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>
#define double long double

int n ;
ll dp[105][105];
bool mark[105][105];
ll a[105];

ll f(int l , int r){
    if(l == r)
        return a[l];

    if(l > r)
        return 0;

    if(mark[l][r])
        return dp[l][r];

    ll &ans = dp[l][r];
    ans = a[l] - f(l + 1 , r) ;
    ll sum = 0 ;
    for(int i = l ; i <= r ; i++){
        sum += a[i];
        ans = max(ans , sum - f(i + 1 , r));
    }
    sum = 0 ;
    for(int j = r ; j >= l ; j--){
        sum += a[j];
        ans = max(ans , sum - f(l , j - 1));
    }
    mark[l][r] = true;
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    while(cin >> n && n != 0){
        memset(mark ,false  , sizeof mark);

        for(int i = 0 ; i < n ; i++)
            cin >> a[i];

        cout << f(0 , n - 1) << endl;
    }
    return 0;
}


