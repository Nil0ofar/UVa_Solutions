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

int source = 1 , destination ;
const int INF = 1e9;
vector<int> edge[105];
int cap[105][105];
int flow[105][105];
bool mark[105];
int par[105];

int find_mn(){
    int mn = INF;
    int node = destination;
    int p;
    while(node != source){
        p = par[node];
        mn = min(mn , cap[p][node] - flow[p][node]);
        node = p;

    }
    return mn;
}

void update_flow(int mn){
    int node = destination;
    int p;
    while(node != source){
        p = par[node];
        flow[p][node] += mn;
        flow[node][p] -= mn;
        node = p;
    }
}

int augmentation_path(){
    memset(mark, false ,sizeof mark);
    queue<int> q;
    mark[source] = true;
    q.push(source);
    int node , other ;

    while(!q.empty()){
        node = q.front() ;
        q.pop();

        for(int i = 0 ; i < edge[node].size() ; i++){
            other = edge[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    int mn = find_mn();
                    update_flow(mn);
                    return mn;
                }
                q.push(other);
            }
        }
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int n , m;
    int x , y , w , id;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i <= 100 ; i++)
            edge[i].clear();
        destination = n + 50;

        edge[1].pb(51);
        edge[n].pb(n + 50);
        cap[1][51] = cap[n][n + 50] = INF;
        for(int i = 0 ; i < n - 2 ; i++){
            cin >> id >> w;
            edge[id].pb(id + 50);
            edge[id + 50].pb(id);
            cap[id][id + 50] = cap[id + 50][id] = w;
        }

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> w;
            edge[x + 50].pb(y);
            edge[y + 50].pb(x);
            cap[x + 50][y] = cap[y + 50][x] = w;
            edge[x].pb(y + 50);
            edge[y].pb(x + 50);
            cap[x][y + 50] = cap[y][x + 50] = 0;
        }

        int mxFlow = 0;
        int temp;

        while(true){
            temp = augmentation_path();
            if(temp == 0)
                break;
            mxFlow += temp;
        }

        cout << mxFlow << endl;
    }

    return 0;
}
