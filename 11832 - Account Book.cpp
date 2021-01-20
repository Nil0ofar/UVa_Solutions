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
#define Base 16005

int n ;
int dp[80000][45];
bool neg[45] , pos[45];
int val[45];

bool f(int sum , int idx){
    if(sum < 0)
        return false;

    if(idx == n){
        if(sum == Base)
            return true;
        return false;
    }

    if(dp[sum][idx] != -1)
        return (dp[sum][idx] == 1);

    bool flag = false;

    if(f(sum - val[idx] , idx + 1)){
        pos[idx] = true;
        flag = true;
    }

    if(f(sum + val[idx] , idx + 1)){
        neg[idx] = true;
        flag = true;
    }

    if(flag)
        dp[sum][idx] = 1;
    else
        dp[sum][idx] = 0;
    return flag;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int sum;
    while(cin >> n >> sum && (n || sum)){
        sum += Base;
        for(int i = 0 ; i < n ; i++)
            cin >> val[i];

        memset(dp , -1 , sizeof dp);
        memset(neg , false , sizeof neg);
        memset(pos , false , sizeof pos);

        f(sum , 0);

        string ans = "";

        for(int i = 0 ; i < n ; i++){
            if(pos[i] && neg[i])
                ans += '?';

            else if(pos[i])
                ans += '+' ;

            else if(neg[i])
                ans += '-';

            else{
                ans = '*';
                break;
            }
        }

        cout << ans << endl;
    }
}
