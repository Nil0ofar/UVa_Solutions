#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define N 205
#define ll long long
#define pii pair<int , int>
#define fi first
#define se second
#define mod 998244353LL
#define INF 2000000007
#define pci pair<char , int>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>

map<string , int> mp;
vector<int> edge[N];
int par[N];
pii dp[N][2];

pii f(int node , bool can){
    if(dp[node][can].fi != -1)
        return dp[node][can];

    int sum = 0 ;
    pii temp;
    bool flag = false;
    for(auto other : edge[node]){
        temp = f(other , true);
        sum += temp.fi;
        flag |= temp.se;
    }

    dp[node][can] = {sum , flag};

    if(can){
        sum = 1 , flag = false;
        for(auto other : edge[node]){
            temp = f(other , false);
            sum += temp.fi;
            flag |= temp.se;
        }

        if(sum == dp[node][can].fi)
            dp[node][can].se = true;

        else if(sum > dp[node][can].fi)
            dp[node][can] = {sum , flag};
    }
    return dp[node][can];

}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n ;
    int idx;
    string s , t;
    while(cin >> n && n != 0){
        cin >> s;
        mp.clear();
        idx = 1;
        mp[s] = idx++;

        for(int  i = 0 ; i <= n ; i++){
            edge[i].clear();
            dp[i][0] = dp[i][1] = {-1 , 0};
        }


        for(int i = 0 ; i < n - 1 ; i++){
            cin >> s >> t;
            if(mp[s] == 0)
                mp[s] = idx++;
            if(mp[t] == 0)
                mp[t] = idx++;

            edge[mp[t]].pb(mp[s]);
            par[mp[s]] = mp[t];
        }

        pii ans = f(1 , 1);
        cout << ans.fi << ' ' ;
        if(!ans.se)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
