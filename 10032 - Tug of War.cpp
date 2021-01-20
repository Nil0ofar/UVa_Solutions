#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pll pair<ll , ll>
#define pii pair<int , int>
#define pb push_back
#define N 450 * 100 + 5
#define mod 1000000007
#define Base 100001
#define ordered_set tree<pll, null_type,greater<pll>, rb_tree_tag,tree_order_statistics_node_update>

ll dp[N];
int val[105];

int main(){
    ios_base :: sync_with_stdio(false);
    int n ;
    int t;
    cin >> t;
    while(t--){
        cin >> n ;
        int sum = 0 , need = n / 2 - 1;
        for(int i = 0 ; i < n ; i++){
            cin >> val[i];
            sum += val[i];
        }
        memset(dp , 0 , sizeof dp);

        for(int i = 0 ; i < n ; i++){
            for(int j = sum - val[i] ; j >= 1 ; j--)
                dp[j + val[i]] |= (dp[j] << 1);
            dp[val[i]] |= 1;
        }
        int ans = 0;
        for(int i = sum/2 ; i >= 0 ; i--){
            if(n % 2 == 1){
                if((dp[i] & (1LL << need)) || (dp[i] & (1LL << (need + 1)))){
                    ans = i;
                    break;
                }
            }
            else{
                if((dp[i] & (1LL << need))){
                    ans = i;
                    break;
                }
            }
        }
        cout << min(ans , sum - ans) << ' ' << max(ans , sum - ans) << '\n';
        if(t)
            cout << '\n';
    }
    return 0;
}
