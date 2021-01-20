#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 70005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 1000000007
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define double long double

double dp[N];
int n;
int x[N];
int y[N];

double dis(int i , int j){
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double f(int mask){
    if(mask == 0)
        return 0;
    if(dp[mask] != -1.0)
        return dp[mask];

    double ans = 10000000.0;
    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) != 0){
            mask ^= (1 << i);
            for(int j = i + 1 ; j < n ; j++){
                if((mask & (1 << j)) != 0)
                    ans = min(ans , dis(i , j) + f(mask ^ ( 1 << j )));
            }
            break;
        }
    }

    dp[mask] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    string s;
    int t = 1;

    while(cin >> n && n != 0){
        n *= 2;
        int mask = (1 << n ) - 1;
        for(int i = 0 ; i <= mask ; i++)
            dp[i] = -1.0;

        for(int i = 0 ; i < n ; i++){
            cin >> s >> x[i] >> y[i];
        }
        cout <<"Case " << t++ << ": " <<fixed << setprecision(2) << f(mask) << endl;
    }

    return 0;
}
