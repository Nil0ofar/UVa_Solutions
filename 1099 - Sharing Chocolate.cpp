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
#define N 1000 * 1000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>
#define double long double
#define all(x) (x).begin() , (x).end()

int dp[1 << 15][105];
int sum[1 << 15];
int a[16];

bool f(int r , int mask){
    //cout << r << ' ' << mask << endl;
    if((mask & (mask - 1)) == 0)
        return 1;

    if(dp[r][mask] != -1)
        return dp[r][mask];
    int c = sum[mask] / r ;
    dp[r][mask] = 0;
    for(int m1 = mask ; m1 ; m1 = (mask & (m1 - 1))){
       // cout << m1 << ' ' << sum[m1] << endl;
        if(sum[m1] % r == 0){
            if(f(min(r , sum[m1] / r) , m1) == 1 && f(min(r ,sum[mask ^ m1] / r), mask ^ m1) == 1)
                dp[r][mask] = 1;
        }

        if(sum[m1] % c == 0){
            if(f(min(c , sum[m1] / c) , m1) == 1 && f(min(r ,sum[mask ^ m1] / c), mask ^ m1) == 1)
                dp[r][mask] = 1;
        }
    }
    return dp[r][mask];
}

int main(){
    ios_base :: sync_with_stdio(false);

    int tc = 1;
    int p , n , m ;
    while(cin >> p && p != 0){
        cin >> n >> m;
        for(int i = 0 ; i < p ; i++)
            cin >> a[i];

        memset(sum , 0 , sizeof sum);
        for(int i = 1 ; i < (1 << p) ; i++){
            for(int j = 0 ; j < p ; j++){
                if((i & (1 << j)))
                    sum[i] += a[j];
            }
        }
        memset(dp , -1 , sizeof dp);

        cout << "Case " << tc++ << ": " ;
        if(sum[(1 << p) - 1] != n * m || f(min(n , m) , (1 << p) - 1) == 0)
            cout << "No\n";
        else
            cout << "Yes\n";

    }
    return 0;
}
