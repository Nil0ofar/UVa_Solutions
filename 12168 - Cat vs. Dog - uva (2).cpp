#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define N 510
#define pii pair< int , int >
#define ll long long

int source = 0 , destination = 505;
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
    int testcase;
    int c , d , v;
    string love[N] , hate[N];
    string music, sport;
    int idx;
    cin >> testcase;
    while(testcase--){
        memset(cap , 0 , sizeof cap);
        memset(flow, 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            edge[i].clear();

        cin >> c >> d >> v;
        for(int i = 1 ; i <= v ; i++){
            cin >> love[i] >> hate[i];

            if(love[i][0] == 'D'){
                edge[source].pb(i);
                edge[i].pb(source);
                cap[source][i] = 1;
            }

            else{
                edge[i].pb(destination);
                edge[destination].pb(i);
                cap[i][destination] = 1;
            }

            for(int j = 1 ; j < i ; j++){
                if(love[i] == hate[j] || love[j] == hate[i]){
                    edge[i].pb(j);
                    edge[j].pb(i);
                    if(love[i][0] == 'D')
                        cap[i][j] = 1;
                    else
                        cap[j][i] = 1;
                }
            }
        }
        maxFlow = 0;
        while(augmentation_path()){
            maxFlow++;
        }

        cout << v - maxFlow <<endl;

    }
    return 0;
}
