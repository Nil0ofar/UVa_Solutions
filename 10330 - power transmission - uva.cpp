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

ll INF = 1e18;

ll cap[205][205];
ll flow[205][205];
vector<int> edge[205];
int source , destination;
int par[205];
bool mark[205];

ll find_mn(){
    int node = destination;
    int p;
    ll mn = INF;
    while(node != source){
        p = par[node];
        mn = min(mn , cap[p][node] - flow[p][node]);
        node = p;
    }
    return mn;
}

void update_flow(ll mn){
    int node , p;
    node = par[destination];
    while(true){
        p = par[node];
        if(p == source)
            break;
        flow[p][node] += mn;
        flow[node][p] -= mn;
        node = p;
    }
}

ll augmentation_path(){
    memset(mark , false , sizeof mark);
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
                if(other == destination){
                    ll mn = find_mn();
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
    int x ,y;
    ll w;
    ll mxFlow;
    ll temp;

    while(cin >> n){
        source = 0 , destination = 204 ;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i <= 204 ; i++)
            edge[i].clear();

        for(int i = 1 ; i <= n ; i++){
            cin >> w;
            cap[i][i + 100] = w;
            edge[i + 100].pb(i);
            edge[i].pb(i + 100);
        }

        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> w;
            x += 100;
            cap[x][y] = w;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        cin >> x >> y;

        for(int i = 0 ; i < x ; i++){
            cin >> w;
            cap[source][w] = INF;
            edge[source].pb(w);
        }

        for(int i = 0 ; i < y ; i++){
            cin >> w;
            w += 100;
            cap[w][destination] = INF;
            edge[w].pb(destination);
        }

        mxFlow = 0;
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
