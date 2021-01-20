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
#define N 1000 * 1000 + 5
#define mod 1000000007
#define Base 100001
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int dp[25][55][105];
int cost[55] , val[55];
int k , n , m ;
const int INF = 1e9;

int f(int idx , int last , int remain){
    if(idx == k)
        return 0;

    int &ans = dp[idx][last][remain];

    if(ans != -1)
        return ans;

    ans = -INF;

    for(int i = 0 ; i < n ; i++){
        if(i != last){
            if(cost[i] <= remain)
                ans = max(ans , val[i] + f(idx + 1 , i , remain - cost[i]));
            if(cost[i] * 2 <= remain && idx + 2 <= k)
                ans = max(ans , val[i] * 3 / 2 + f(idx + 2 , i , remain - cost[i] * 2));
        }
        else if(cost[i] <= remain){
            ans = max(ans , f(idx + 1 , i , remain - cost[i]));
        }
    }
    return ans;
}

void trace(int idx , int last , int remain){
    if(idx == k)
        return ;

    for(int i = 0 ; i < n ; i++){
        if(i != last){
            if(cost[i] <= remain){
                if(val[i] + f(idx + 1 , i , remain - cost[i]) == f(idx , last , remain)){
                    cout << i + 1 << ' ' ;
                    trace(idx + 1 , i , remain - cost[i]);
                    return;
                }
            }
            if(cost[i] * 2 <= remain && idx + 2 <= k){
                if(val[i] * 3 / 2 + f(idx + 2 , i , remain - 2 * cost[i]) == f(idx  , last , remain)){
                    cout << i + 1 << ' ' << i + 1 << ' ' ;
                    trace(idx + 2 , i , remain - cost[i] * 2);
                    return ;
                }
            }
        }
        else if(cost[i] <= remain){
            if(f(idx + 1 , i , remain - cost[i]) == f(idx , last , remain)){
                cout << i + 1 << ' ' ;
                trace(idx + 1 , i , remain - cost[i]);
                return;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    while(cin >> k >> n >> m){
        if(n + k + m == 0)
            break;

        for(int i = 0 ; i <= k ; i++)
            for(int j = 0 ; j <= n ; j++)
                for(int h = 0 ; h <= m ; h++)
                    dp[i][j][h] = -1;

        for(int i = 0 ; i < n ; i++){
            cin >> cost[i] >> val[i];
            val[i] *= 2;
        }

        int max_val = 0;
        int c = 0;

        for(int i = 1 ; i <= m ; i++){
            if(f(0 , n , i) > max_val){
                max_val = f(0 , n , i);
                c = i;
            }
        }

        cout << fixed << setprecision(1) << (double)max_val / 2.0 << endl;
        trace(0 , n , c) ;
        cout << endl;
    }
    return 0;
}
