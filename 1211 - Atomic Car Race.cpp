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

int n ;
int p[105];
int mark[10005];
double b , v , e , f;
int r;
double dp[10005][105];

double func(int idx , int last){
    if(idx == p[n])
        return 0;

    if(dp[idx][last] != -1.0)
        return dp[idx][last];

    double ans , temp;
    int x = idx - p[last];

    if(x >= r)
        ans = 1.0 / (double)(v - e * (x - r));
    else
        ans = 1.0 / (double)(v - f * (r - x));

    ans += func(idx + 1 , last);

    if(mark[idx] != -1){
        temp = (double)b + func(idx + 1 , mark[idx]);
        temp += (1.0 / (double)(v - f * r));
        ans = min(ans , temp);
    }

    dp[idx][last] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    while(cin >> n && n != 0){
        memset(mark , -1 , sizeof mark);

        for(int i = 1 ; i <= n ; i++){
            cin >> p[i];
            mark[p[i]] = i;
        }

        cin >> b >> r >> v >> e >> f;

        for(int i = 0 ; i <= p[n] ; i ++)
            for(int j = 0 ; j <= n ; j++)
                dp[i][j] = -1.0;

        cout << fixed << setprecision(4) << func(0 , 0) << endl;
    }
    return 0;
}
