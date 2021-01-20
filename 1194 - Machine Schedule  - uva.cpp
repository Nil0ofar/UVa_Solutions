#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define N 210
#define pii pair< int , int >
#define ll long long

int source = 0 , destination = 205;
int cap[N][N];
int flow[N][N];
int par[N];
bool mark[N];
vector<int> edge[N];

void update_flow(){
    int node = destination;
    int p;
    while(node != source){
        p = par[node];
        flow[p][node] += 1;
        flow[node][p] -= 1;
        node = p;
    }
}

bool augmentation_path(){
    memset(mark, false ,sizeof mark);
    queue<int> q;
    mark[source] = true;
    q.push(source);
    int node , other;

    while(!q.empty()){
        node = q.front();
        q.pop();

        for(int i = 0 ; i < edge[node].size() ; i++){
            other = edge[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] =node;
                q.push(other);

                if(other == destination){
                    update_flow();
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    ios :: sync_with_stdio(false);
    int maxFlow;
    int n , m , k;
    int id , x , y;
    while(cin >> n && n != 0){
        cin >> m >> k;

        memset(cap , 0 , sizeof cap);
        memset(flow, 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            edge[i].clear();

        for(int i = 0 ; i < k ; i++){
            cin >> id >> x >> y;
            if(x == 0 || y == 0)
                continue;
            y += 100;
            edge[x].pb(y);
            edge[y].pb(x);
            cap[x][y] = 1;
        }

        for(int i = 1 ; i <= n ; i++){
            edge[source].pb(i);
            cap[source][i] = 1;
        }

        for(int i = 101 ; i <= m + 100 ; i++){
            edge[i].pb(destination);
            cap[i][destination] = 1;
        }

        maxFlow = 0;
        while(augmentation_path())
            maxFlow++;

        cout << maxFlow << endl;
    }
    return 0;
}
