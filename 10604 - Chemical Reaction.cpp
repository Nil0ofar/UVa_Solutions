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

int n , m;
const ll INF = 1e18;
ll dp[8][1040];
int tube[12];
ll heat[12][12];
int reaction[12][12];

//  Be careful
// new resulting chemical type and the amount of energy emitted from mixing 'a' and 'b'
// could be different from mixing 'b' and 'a' !!

int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    string s;
    int x;

    cin >> t;
    while(t--){
        cin >> n ;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> reaction[i][j] >> heat[i][j];
            }
        }
        cin >> m ;

        for(int i = 1 ; i <= n ; i++)
            for(int j = 0 ; j < (1 << m) ; j++)
                dp[i][j] = INF;

        for(int i = 0 ; i < m ; i++){
            cin >> tube[i];
            dp[tube[i]][(1 << i)] = 0;
        }
        cin >> s;

        for(int mask = 2 ; mask < (1 << m) ; mask++){
            for(int nmask = 1 ; nmask < mask ; nmask++){
                if((mask & nmask) == 0){
                    for(int a = 1 ; a <= n ; a++){
                        for(int b = 1 ; b <= n ; b++){
                            // a + b --> c
                            int c = reaction[a][b] ;
                            dp[c][mask + nmask] = min(dp[c][mask + nmask] ,
                                                      dp[a][mask] + dp[b][nmask] + heat[a][b]);
                            // b + a --> c
                            c = reaction[b][a];
                            dp[c][mask + nmask] = min(dp[c][mask + nmask] ,
                                                      dp[a][mask] + dp[b][nmask] + heat[b][a]);

                        }
                    }
                }
            }
        }

        ll ans = INF;

        for(int i = 1 ; i <= n ; i++)
            ans = min(ans , dp[i][(1 << m) - 1]);

        cout << ans << endl;
    }
    return 0;
}
