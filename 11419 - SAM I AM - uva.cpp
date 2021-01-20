#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define N 2010
#define pii pair< int , int >
#define ll long long

int source = 0 , destination = 2005;
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

bool row[N] , col[N];

void dfs(int node , int p){
    mark[node] = true;
    int other;
    for(int i = 0 ; i < edge[node].size() ; i++){
        other = edge[node][i];
        if(other == p || mark[other])
            continue;
        if(cap[node][other] > flow[node][other]){
            mark[other] = true;
            row[other] = !row[other];
            col[other] = !col[other];
            dfs(other , node);
        }
    }
}

int main(){
    int R , C , n ;
    int r , c;

    while(cin >> R >> C >> n){
        if(R == 0 && C == 0 && n == 0)
            break;

        memset(cap, 0 , sizeof cap);
        memset(flow, 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            edge[i].clear();
        memset(mark, false , sizeof mark);
        for(int i = 0 ; i < n ; i++){
            cin >> r >> c;
            c += 1000;
            edge[r].pb(c);
            edge[c].pb(r);
            cap[r][c] = 1;

            if(!mark[r]){
                edge[source].pb(r);
                cap[source][r] = 1;
                mark[r] = true;
            }

            if(!mark[c]){
                edge[c].pb(destination);
                cap[c][destination] = 1;
                mark[c] = true;
            }
        }
        int max_flow = 0;
        while(augmentation_path())
            max_flow++;

        memset(row , false , sizeof row);
        memset(col , false , sizeof col);
        memset(mark , false, sizeof mark);

        for(int i = 1 ; i <= R ; i++){
            if(cap[source][i] == flow[source][i]){
                if(flow[source][i] == 1)
                    row[i] = true;
            }
        }

        for(int i = 1 ; i <= R ; i++){
            if(row[i] == false)
                dfs(i , source);
        }

        /*for(int i = 1 + 1000 ; i <= C + 1000 ; i++){
            if(col[i]){
                for(int j = 0 ; j < edge[i].size() ; j++){
                    if(flow[edge[i][j]][i] == 1){
                        row[edge[i][j]] = false;
                        break;
                    }
                }
            }
        }*/

        cout << max_flow ;
        for(int i = 0 ; i < edge[source].size() ; i++){
            if(row[edge[source][i]] ){
                cout <<' ' << 'r' << edge[source][i];
            }
        }

        for(int i = 1 + 1000 ; i <= C + 1000 ; i++){
            if(col[i]){
                cout <<' ' << 'c' << (i - 1000) ;
            }
        }
        cout << endl;

    }
    return 0;
}
