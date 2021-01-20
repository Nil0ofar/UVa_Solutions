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
#define N 100005
#define mod 1000000007
#define Base 100001
#define ordered_set tree<pll, null_type,greater<pll>, rb_tree_tag,tree_order_statistics_node_update>

vector<pll> vec;
int dp[6000];

int main(){
    ios_base :: sync_with_stdio(false);
    ll w , p;
    int n = 0;
    while(cin >> w >> p){
        if(w == -1)
            break;
        vec.pb({w , p});
        n++;
    }

    memset(dp , -1 , sizeof dp);
    dp[0] = 0;
    sort(vec.begin() , vec.end());
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = cnt ; j >= 0 ; j--){
            if(dp[j] + vec[i].fi <= vec[i].se){
                if(dp[j + 1] == -1){
                    dp[j + 1] = dp[j] + vec[i].fi;
                    cnt++;
                }
                else{
                    if(dp[j + 1] > dp[j] + vec[i].fi)
                        dp[j + 1] = dp[j] + vec[i].fi;
                }
            }
        }
    }
    for(int i = 0 ; i < 5 ; i++)
        cout << dp[i] << ' ';
    cout << cnt << endl;
}
