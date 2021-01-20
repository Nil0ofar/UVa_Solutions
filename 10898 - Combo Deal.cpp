#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 10000005
#define ll long long
#define pii pair<ll , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

vector<pii> vec;

bool ok(int x , int y){
    int a , b;
    while(x != 0 && y != 0){
        a = x % 10;
        b = y % 10;
        if(a + b >= 10)
            return false;
        y /= 10;
        x /= 10;
    }
    return true;
}

ll dp[N];

int main()
{
    ios_base :: sync_with_stdio(false);
    int n ;
    while(cin >> n){
        vec.clear();
        int val , x = 1, y;
        for(int i = 0 ; i < n - 1 ; i++)
            x *= 10;

        for(int i = n - 1 ; i >= 0 ; i--){
            cin >> val ;
            vec.pb({val , x});
            x /= 10;
        }

        int m;
        cin >> m ;
        for(int i = 0 ; i < m ; i++){
            y = 0;
            for(int j = 0 ; j < n ; j++){
                cin >> x;
                y *= 10;
                y += x;

            }
            cin >> val;
            vec.pb({val , y});
        }


        int q;
        cin >> q;
        while(q--){
            y = 0;
            for(int i = 0 ; i < n ; i++){
                cin >> x;
                y *= 10;
                y += x;
            }

            memset(dp , -1 , sizeof dp);

            dp[0] = 0;

            for(int i = 0 ; i < y ; i++){
                for(auto p : vec){
                    if(p.se + i >= N)
                        break;
                    if(ok(p.se , i)){
                        if(dp[p.se + i] == -1)
                            dp[p.se + i] = dp[i] + p.fi;
                        else
                            dp[p.se + i] = min(dp[p.se + i] , dp[i] + p.fi);
                    }
                }

            }

            cout << dp[y] << endl;
        }
    }
}


