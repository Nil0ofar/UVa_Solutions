#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define N 62
#define pii pair< int , int >
#define ll long long

int source = 0 , destination = 60;
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

bool used[N];

bool hasCycle(int node , int start){
    int other;
    for(int i = 0 ; i < edge[node].size() ; i++){
        other = edge[node][i];
        if(other == source)
            continue;
        if(cap[node][other] > flow[node][other]){
            if(mark[other]){
                if(other == start)
                    return true;
                continue;
            }
            mark[other] = true;
            if(hasCycle(other , start)){
                return true;
            }
            mark[other] = false;
        }
    }
    return false;
}

int main(){
    ios :: sync_with_stdio(false);
    int Xmin[N] , Xmax[N] , Ymin[N] , Ymax[N];
    int x, y;
    int maxFlow;
    int n;

    for(int testcase = 1 ; ; testcase++){
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            edge[i].clear();

        cin >> n;
        if(n == 0)
            break;
        for(int i = 1 ; i <= n ; i++){
            cin >> Xmin[i] >> Xmax[i] >> Ymin[i] >> Ymax[i] ;
            edge[source].pb(i);
            cap[source][i] = 1;
        }

        for(int i = 30 ; i < n + 30 ; i++){
            cin >> x >> y;

            for(int j = 1 ; j <= n ; j++){
                if(x >= Xmin[j] && x <= Xmax[j] && y >= Ymin[j] && y <= Ymax[j]){
                    edge[i].pb(j);
                    edge[j].pb(i);
                    cap[j][i] = 1;
                }
            }

            edge[i].pb(destination);
            cap[i][destination] = 1;
        }

        maxFlow = 0;
        while(augmentation_path())
            maxFlow++;

        memset(used, false, sizeof used);
        int other;
        for(int i = 0 ; i < edge[source].size() ; i++){
            memset(mark , false , sizeof mark);
            other = edge[source][i];
            mark[other] = true;
            if(hasCycle(other , other))
                used[other] = true;
        }

        cout << "Heap " << testcase << endl;
        bool flag = false;
        for(int i = 1 ; i <= n ; i++){
            if(used[i])
                continue;
            for(int j = 0 ; j < edge[i].size() ; j++){
                other = edge[i][j];
                if(flow[i][other] == 1){
                    if(flag == true)
                        cout << ' ' ;
                    cout << "(" << char('A' + i - 1) << ',' << other - 29 << ")";
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
            cout << "none" ;
        cout << endl << endl;
    }
    return 0;
}
