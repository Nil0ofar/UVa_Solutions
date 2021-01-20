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
#define Base 3002
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int d;
int ans ;
int n ;
int dig[12];
int dp[10050][1050];

int f(int num , int mask){
    if(mask == 0){
        if(num == 0)
            return 1;
        return 0;
    }

    if(dp[num][mask] != -1)
        return dp[num][mask];

    dp[num][mask] = 0;

    for(int i = 0 ; i < n ; i++)
        if((mask & (1 << i)) != 0)
            dp[num][mask] += f((num * 10 + dig[i]) % d , mask ^ ( 1 << i ));

    return dp[num][mask];
}


int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    string s ;
    cin >> testcase;

    while(testcase--){
        cin >> s >> d;
        n = s.size();
        for(int i = 0 ; i < n ; i++)
            dig[i] = s[i] - '0';

        int rep = 1;
        int temp;
        for(int i = 0 ; i < 10 ; i++){
            temp = 1;
            for(int j = 0 ; j < (int)count(s.begin() , s.end() , char('0' + i)) ; j++){
                temp *= (j + 1);
            }
            rep *= temp;
        }

        memset(dp , -1 ,sizeof dp);
        ans = f(0 , (1 << n) - 1);
        ans /= rep;
        cout << ans << endl;
    }
    return 0;
}
