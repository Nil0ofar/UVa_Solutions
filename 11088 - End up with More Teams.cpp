#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 50005
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

int n;
int dp[N];
int a[16];

int f(int mask){
    if(dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    int temp = 0;
    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) != 0){
            mask ^= (1 << i);
            temp += a[i];
            for(int j = i + 1 ; j < n ; j++){
                if((mask & (1 << j)) != 0){
                    mask ^= (1 << j);
                    temp += a[j];
                    for(int k = j + 1 ; k < n ; k++){
                        if((mask & (1 << k)) != 0){
                            mask ^= (1 << k);
                            temp += a[k];
                            if(temp >= 20){
                                ans = max(1 + f(mask) , ans);
                            }
                            mask ^= (1 << k);
                            temp -= a[k];
                        }
                    }
                    mask ^= (1 << j);
                    temp -= a[j];
                }
            }
            mask ^= (1 << i);
            temp -= a[i];
        }
    }
    dp[mask] = ans;
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int tc = 1;
    while(cin >> n && n != 0){
        memset(dp , -1 , sizeof dp);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int mask = (1 << n) - 1;
        cout << "Case " << tc++ << ": " << f(mask) << endl;
    }
}
