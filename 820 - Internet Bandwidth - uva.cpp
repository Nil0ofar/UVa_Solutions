#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 105
#define mod 998244353
#define MAX 1000000

int cap[N][N];
int flow[N][N];
bool mark[N];
int par[N];
vector<int> adj[N];
int source , destination ;


int find_min(){
    int node = destination;
    int ans = MAX;
    int other;
    while(node != source){
        other = par[node];
        ans = min(ans , cap[other][node] - flow[other][node]);
        //cout << node <<' ' << other << ' '<<cap[other][node] <<' ' << flow[other][node]<<endl;
        node = par[node];
    }
    return ans;
}


void update_flow(int mn){
    int node = destination;
    int other;
    while(node != source){
        other = par[node];
        flow[other][node] += mn;
        flow[node][other] -= mn;
        node = par[node];
    }
}


int bfs(){
    memset(mark , false , sizeof mark);
    queue<int> q;
    mark[source] = true;
    par[source] = source;
    q.push(source);
    int node , other;

    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node == destination){
            int mn = find_min();
            update_flow(mn);
            return mn;
        }

        for(int i = 0 ; i < adj[node].size() ; i++){
            other = adj[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                par[other] = node;
                mark[other] = true;
                q.push(other);
            }
        }
    }
    return -1;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int n;
    int m;
    int x, y , w;
    int temp;
    int testcase = 1;
    while(cin >> n && n != 0){
        cin >> source >> destination >> m;
        for(int i = 0 ; i <= n ; i++)
            adj[i].clear();

        memset(cap , 0 , sizeof cap);

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> w;
            adj[x].pb(y);
            adj[y].pb(x);
            cap[x][y] += w;
            cap[y][x] += w;
        }

        memset(flow , 0 , sizeof flow);

        int ans = 0;
        while(true){
            temp = bfs();
            if(temp == -1)
                break;
            ans += temp;
        }
        cout << "Network " << testcase++ << endl;
        cout << "The bandwidth is " << ans << '.' << endl << endl;
    }
    return 0;
}
