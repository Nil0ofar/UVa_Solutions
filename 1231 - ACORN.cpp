#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 2005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 1000000007
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define double long double

int dp[N][N];

int main()
{
    ios_base :: sync_with_stdio(false);
    int t , n , f , h;
    int a , x , mx;
    cin >> t;
    while(t--){
        cin >> n >> h >> f;

        memset(dp , 0 , sizeof dp);

        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            for(int j = 0 ; j < a ; j++){
                cin >> x;
                dp[x][i]++;
            }
        }

        for(int i = 1 ; i <= h ; i++){
            if(i - f >= 0)
                mx = *max_element(dp[i - f] , dp[i - f] + n);
            else
                mx = 0;

            for(int j = 0 ; j < n ; j++){
                dp[i][j] += max(dp[i - 1][j] , mx);
            }
        }

        cout << *max_element(dp[h] , dp[h] + n) << endl;

    }
    cin >> t;
    return 0;
}


