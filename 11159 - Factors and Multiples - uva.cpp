#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int source, destination = 201;
vector<int> edge[205];
int val[205];
int cap[205][205];
int flow[205][205];
bool mark[205];
int par[205];

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
    memset(mark , false , sizeof mark);
    queue<int> q;
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
    int n , m;
    int mxFlow;
    cin >> testcase;
    for(int t = 1 ; t <= testcase ; t++){
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i < 205 ; i++)
            edge[i].clear();
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> val[i];
            edge[source].pb(i);
            edge[i].pb(source);
            cap[source][i] = 1;
        }

        cin >> m;
        for(int i = n + 1 ; i <= m + n ; i++){
            cin >> val[i];
            edge[i].pb(destination);
            edge[destination].pb(i);
            cap[i][destination] = 1;

            for(int j = 1 ; j <= n ; j++){
                if(val[j] == 0 && val[i] != 0)
                    continue;
                if(val[j] == 0  || val[i] % val[j] == 0){
                    edge[j].pb(i);
                    edge[i].pb(i);
                    cap[j][i] = 1;
                }
            }
        }

        mxFlow = 0;
        while(augmentation_path())
            mxFlow++;

        cout << "Case " << t << ": " << mxFlow << endl;
    }
    return 0;
}
