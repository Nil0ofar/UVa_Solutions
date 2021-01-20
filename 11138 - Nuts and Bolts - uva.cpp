#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int source = 0 , destination;
vector<int> edge[1005];
int cap[1005][1005];
int flow[1005][1005];
int par[1005];
bool mark[1005];

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
    memset(mark, 0 , sizeof mark);
    queue<int> q;
    mark[source] = true;
    q.push(source);
    int node, other;

    while(!q.empty()){
        node = q.front();
        q.pop();

        for(int i = 0 ; i < edge[node].size() ; i++){
            other = edge[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
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

int main()
{
    int testcase;
    cin >> testcase;
    int n , m;
    int x;
    for(int t = 1 ; t <= testcase ; t++){
        cin >> n >> m;
        destination = n + m + 1;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i <= destination ; i++)
            edge[i].clear();

        for(int i = 1 ; i <= n ; i++){
            edge[i].pb(source);
            edge[source].pb(i);
            cap[source][i] = 1;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = n + 1 ; j <= m + n ; j++){
                cin >> x;
                if(x == 1){
                    edge[i].pb(j);
                    edge[j].pb(i);
                    cap[i][j] = 1;
                }
            }
        }

        for(int i = n + 1 ; i <= n + m ; i++){
            edge[i].pb(destination);
            edge[destination].pb(i);
            cap[i][destination] = 1;
        }

        int maxFlow = 0;

        while(augmentation_path())
            maxFlow++;

        cout <<"Case " << t << ": a maximum of " << maxFlow << " nuts and bolts can be fitted together\n";
    }
    return 0;
}
