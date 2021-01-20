#include<bits/stdc++.h>

using namespace std;

#define N 300005
#define INF 1000000007
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pll pair<ll, ll >
#define pb push_back
#define N 300005

vector<int> edge[N];
vector<pii> ans;
int tim ;
int par[N];
int low[N] , num[N];

void dfs(int node){
    low[node] = num[node] = ++tim;
    int other;

    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];

        if(par[node] == other)
            continue;

        if(par[other] != -1){// it's a back edge
            low[node] = min(low[node] , num[other]);
            continue;
        }

        par[other] = node;
        dfs(other);

        if(low[other] > num[node]){
            ans.pb(pii(min(node , other) , max(node , other)));
        }
        else
            low[node] = min(low[node] , low[other]);
    }
}

int main()
{
    int n , m ;
    int x , y;
    char c;

    while(cin >> n ){
        for(int i = 0 ; i <= n ; i++){
            edge[i].clear();
            par[i] = -1;
        }

        for(int i = 0 ; i < n ; i++){
            cin >> x;
            cin >> c >> m >> c;
            for(int j = 0 ; j < m ; j++){
                cin >> y ;
                edge[x].pb(y);
            }
        }

        tim = 0;
        ans.clear();
        for(int i = 0 ; i < n ; i++){
            if(par[i] == -1){
                par[i] = -2;
                dfs(i);
            }
        }

        sort(ans.begin() , ans.end());

        cout << (int)ans.size() << " critical links\n";
        for(int i = 0 ; i < (int)ans.size() ; i++){
            cout << ans[i].fi << ' ' << '-' << ' ' << ans[i].se << endl;
        }
        cout << endl;
    }
}
