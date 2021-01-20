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
#define N 200005
#define mod 1000000007
#define Base 100001
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int const INF = 1e8;
int n , m;
int p[35];
int dp[35][105];
int mx;

int f(int idx , int need){
    if(need <= 0)
        return 0;

    if(idx == m)
        return INF;

    if(dp[idx][need] != -1)
        return dp[idx][need];

    int ans = min(INF , p[idx] + f(idx + 1 , need - p[idx] / mx));
    ans = min(f(idx + 1 , need) , ans);
    dp[idx][need] = ans;
    return ans;
}

bool ok(int num){
    if(num == 0)
        return true;
    int cnt = 0;
    for(int i = 0 ; i < m ; i++){
        cnt += p[i]/num;
    }
    if(cnt >= n)
        return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    while(cin >> n >> m  && (n | m) != 0){
        for(int i = 0 ; i < m ; i++)
            cin >> p[i];

        int ii = 0 , jj = 1000 ;

        while(jj > ii){
            if(ii == jj - 1){
                if(ok(jj))
                    ii = jj;
                else
                    jj = ii;
            }
            int mid = (ii + jj) / 2;
            if(ok(mid))
                ii = mid;
            else
                jj = mid - 1;
        }
        mx = ii;
        cout << mx << ' ';
        if(mx == 0)
            cout << 0 << endl;
        else{
            memset(dp , -1 , sizeof dp);
            cout << f(0 , n) << endl;
        }
    }
}
