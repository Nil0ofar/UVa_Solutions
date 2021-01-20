#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 1000005
#define mod 998244353
#define MAX 100000000000000000

const int INF = 2e9 + 5;
int source = 1 , destination = 2;
int cap[55][55];
int flow[55][55];
vector<int> edge[55];
bool mark[55];
int par[55];

int find_mn(){
    int node = destination;
    int p;
    int mn = INF;
    while(node != source){
        p = par[node];
        mn = min(mn , cap[p][node] - flow[p][node]);
        node = p;
    }
    return mn;
}

void update_flow(int mn){
    int node = destination;
    int p ;
    while(node != source){
        p = par[node];
        flow[node][p] -= mn;
        flow[p][node] += mn;
        node = p;
    }
}
bool augmentation_path(){
    queue<int> q;
    memset(mark, false , sizeof mark);
    mark[source] = true;
    q.push(source);
    int node , other ;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i = 0 ; i < edge[node].size() ; i++){
            other = edge[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    int mn = find_mn();
                    update_flow(mn);
                    return true;
                }
                q.push(other);
            }
        }
    }
    return false;
}

void dfs(int node){
    int other;
    mark[node] = true;
    for(int i = 0 ; i < edge[node].size() ; i++){
        other = edge[node][i];
        if(!mark[other] && cap[node][other] > flow[node][other]){
            dfs(other);
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    int n , m;
    int x, y , w;
    while( cin >> n >> m ){
        if(n == 0 && m == 0 )
            break;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0, sizeof flow);
        for(int i = 0 ; i < 55 ; i++)
            edge[i].clear();

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> w;
            cap[x][y] = cap[y][x] = w;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        while(augmentation_path());

        memset(mark, false, sizeof mark);
        dfs(1);

        for(int i = 1 ; i <= n ; i++){
            if(!mark[i])
                continue;
            for(int j = 0 ; j < edge[i].size() ; j++){
                if(!mark[edge[i][j]])
                    cout << i << ' ' << edge[i][j] << endl;
            }
        }
        cout << endl;

    }
    return 0;
}
