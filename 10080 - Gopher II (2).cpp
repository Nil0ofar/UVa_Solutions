#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int source = 0 , destination = 1;
int cap[205][205];
int flow[205][205];
int par[205];
bool mark[205];
vector<int> edge[205];

long double dis(long double x , long double y , long double xx , long double yy){
    return sqrt((x - xx)*(x - xx) + (y - yy)*(y - yy));
}

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
    memset(mark , false, sizeof mark);
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
    ios_base :: sync_with_stdio(false);
    long double X[205] , Y[205];
    int n , m , s , v;
    int idx;
    long double x , y;
    int mxFlow = 0;
    while(cin >> n){
        cin >> m >> s >> v;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i < 205 ; i++)
            edge[i].clear();
        long double limit = s * v;
        idx = 2;
        for(int i = 0 ; i < n ; i++){
            cin >> X[i] >> Y[i];
            edge[source].pb(idx);
            edge[idx].pb(source);
            cap[source][idx] = 1;
            idx++;
        }

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y ;
            edge[idx].pb(destination);
            edge[destination].pb(idx);
            cap[idx][destination] = 1;

            for(int j = 0 ; j < n ; j++){
                if(dis(X[j] , Y[j] , x , y) <= limit){
                    edge[j + 2].pb(idx);
                    edge[idx].pb(j + 2);
                    cap[j + 2][idx] = 1;
                }
            }
            idx++;
        }
        mxFlow = 0;
        while(augmentation_path())
            mxFlow++;
        cout << n - mxFlow << endl;
    }
    return 0;
}
