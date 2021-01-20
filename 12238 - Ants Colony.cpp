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
#define N 100005
#define mod 1000000007
#define Base 100001
#define ordered_set tree<pll, null_type,greater<pll>, rb_tree_tag,tree_order_statistics_node_update>

int n;
vector<pii> edge[N];
int level[N];
int dp[N][20];
ll dis[N];

void dfs(int node){
    for(auto p : edge[node]){
        level[p.fi] = level[node] + 1;
        dp[p.fi][0] = node;
        dis[p.fi] = dis[node] + p.se;
        dfs(p.fi);
    }
}

void set_dp(){
    for(int i = 1 ; i < 18 ; i++)
        for(int j = 0 ; j < n ; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

int go_up(int node , int d){
    for(int i = 17 ; i >= 0 ; i--){
        if((d & (1 << i)) != 0)
            node = dp[node][i];
    }
    return node;
}

int LCA(int x , int y){
    if(level[x] > level[y])
        swap(x , y);
    y = go_up(y , level[y] - level[x]);

    if(x == y)
        return x;

    for(int i = 17 ; i >= 0 ; i--){
        if(dp[x][i] != dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

ll find_dis(int x , int y){
    int lca = LCA(x , y);

    return dis[x] + dis[y] - 2 * dis[lca];
}

int main(){
    ios_base :: sync_with_stdio(false);
    int p , d;

    while(cin >> n && n != 0){
        for(int i = 0 ; i <= n ; i++)
            edge[i].clear();

        for(int i = 1 ; i < n ; i++){
            cin >> p >> d;
            edge[p].pb({i , d});
        }

        dfs(0);
        set_dp();

        int q;
        cin >> q;
        int x , y;
        while(q--){
            cin >> x >> y ;
            cout << find_dis(x , y);
            if(q)
                cout << ' ' ;
        }
        cout << '\n';
    }
}
