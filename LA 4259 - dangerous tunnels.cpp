#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 405
#define INF 1000000007

int source = 0, destination;
vector<int> edge[N];
int dan[N][N];
int flow[N][N];
int cap[N][N];
int mx;
int par[N];
bool mark[N];
int dis[N];

void update_flow(){
    int node = destination;
    int p;
    while(node != source){
        p = par[node];
        flow[p][node]++;
        flow[node][p]--;
        node = p;
    }
}

bool augmentation_path(){
    memset(mark , false , sizeof mark);
    memset(dis  , 1 , sizeof dis);
    priority_queue<pii> pq;
    dis[0] = 0;
    pq.push(pii(0 , source));
    int d , node , other;

    while(!pq.empty()){
        node = pq.top().se;
        pq.pop();
        if(mark[node])
            continue;
        mark[node] = true;

        if(node == destination){
            mx = max(mx , dis[node]);
            update_flow();
            return true;
        }

        for(int i = 0 ; i < edge[node].size() ; i++){
            other = edge[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                if(dis[other] > max(dis[node] , dan[node][other])){
                    dis[other] = max(dis[node], dan[node][other]);
                    par[other] = node;
                    pq.push(pii(-dis[other] , other));
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    int n , m;
    int x, y , d;
    int testcase = 1;
    while(cin >> n && n != 0){
        destination = n + 1;
        memset(dan , 0 , sizeof dan);
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        mx = 0;
        for(int i = 0 ; i <= n + 1 ; i++){
            edge[i].clear();
            edge[i + 200].clear();
        }

        for(int i = 0 ; i <= n + 1 ; i++){
            edge[i].pb(i + 200);
            edge[i + 200].pb(i);
            cap[i][i + 200] = 1;
        }
        cap[0][200] = cap[destination][destination + 200] = INF;

        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> d;
            if(x > y)
                swap(x , y);
            edge[x + 200].pb(y);
            dan[x + 200][y] = d;
            cap[x + 200][y] = 1;
            edge[y].pb(x + 200);
        }

        int k;
        cin >> k;
        bool flag = true;
        while(k--){
            if(!augmentation_path()){
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "Case " << testcase++ << ": " << mx << endl;
        else
            cout << "Case " << testcase++ << ": " << "no solution\n";
    }
    return 0;
}



