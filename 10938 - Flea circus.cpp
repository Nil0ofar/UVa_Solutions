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

int n ;
vector<int> edge[N];
int level[N];
int dp[N][20];

void dfs(int node , int p){
    for(auto other : edge[node]){
        if(other != p){
            level[other] = level[node] + 1;
            dp[other][0] = node;
            dfs(other , node);
        }
    }
}

void set_dp(){
    for(int i = 1 ; i < 18 ; i++)
        for(int j = 0 ; j <= n ; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

int go_up(int node , int num){
    for(int i = 17 ; i >= 0 ; i--){
        if((num & (1 << i)))
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

void find_ans(int x , int y){
    if(level[x] > level[y])
        swap(x , y);

    int lca = LCA(x , y);
    int dis = level[x] + level[y] - 2 * level[lca];

    if(dis % 2 == 0){
        int a = go_up(y , dis / 2);
        cout << "The fleas meet at " << a << ".\n";
    }
    else{
        int a = go_up(y , dis / 2);
        int b = go_up(y , dis / 2 + 1);
        if(b < a)
            swap(a , b);
        cout << "The fleas jump forever between " << a << " and " << b << ".\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);

    while(cin >> n && n != 0){

        for(int i = 0 ; i <= n ; i++)
            edge[i].clear();

        int x , y ;
        for(int i = 0 ; i < n - 1 ; i++){
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        dfs(1 , 1);
        set_dp();
        int q;
        cin >> q;
        while(q--){
            cin >> x >> y ;
            find_ans(x , y);
        }
    }
}
