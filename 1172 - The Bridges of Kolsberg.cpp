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
#define mod 1000000007
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define double long double

pii dp[N][N];
string os_1[N] , os_2[N];
int val_1[N] , val_2[N];

int main()
{
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    int n , m ;
    string s;
    int temp;

    while(t--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> s >> os_1[i] >> val_1[i];

        cin >> m;
        for(int i = 0 ; i < m ; i++)
            cin >> s >> os_2[i] >> val_2[i];

        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++)
                dp[i][j] = {0 , 0};
        }

        for(int j = m - 1 ; j >= 0 ; j --){
            for(int i = n - 1 ; i >= 0 ; i--){

                dp[i][j] = dp[i + 1][j];
                if(dp[i][j + 1].fi > dp[i][j].fi)
                    dp[i][j] = dp[i][j + 1];
                if(dp[i][j + 1].fi == dp[i + 1][j].fi)
                    dp[i][j].se = min(dp[i][j + 1].se , dp[i + 1][j].se);

                if(os_1[i] == os_2[j]){
                    temp = val_1[i] + val_2[j] + dp[i + 1][j + 1].fi;
                    if(dp[i][j].fi < temp)
                        dp[i][j] = {temp , dp[i + 1][j + 1].se + 1};

                    else if(dp[i][j].fi == temp)
                        dp[i][j].se = min(dp[i][j].se , dp[i + 1][j + 1].se + 1);
                }
            }
        }

        cout << dp[0][0].fi << ' ' << dp[0][0].se << endl;

    }
    return 0;
}
