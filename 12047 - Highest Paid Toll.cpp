#include<bits/stdc++.h>

using namespace std;

#define N 105
#define INF 100000000000000
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pli pair<ll, int >
#define pb push_back
#define Edge pair<ll , pii>

vector<pii> adj[N];
vector<pii> adj_222[N];
vector<Edge> edge;
ll dis[N] , dis_222[N];
int s , t ;

void dij_s(){
    dis[s] = 0;
    priority_queue<pli> pq;
    pq.push(pli(0 , s));
    int node , other;
    ll c;
    while(!pq.empty()){
        node = pq.top().se;
        pq.pop();

        for(int i = 0 ; i < (int)adj[node].size() ; i++){
            other = adj[node][i].fi;
            c = adj[node][i].se;

            if(dis[other] > dis[node] + c){
                dis[other] = dis[node] + c;
                pq.push(pii(-dis[other] , other));
            }
        }
    }
}

void dij_t(){
    dis_222[t] = 0;
    priority_queue<pli> pq;
    pq.push(pli(0 , t));
    int node , other;
    ll c;
    while(!pq.empty()){
        node = pq.top().se;
        pq.pop();

        for(int i = 0 ; i < (int)adj_222[node].size() ; i++){
            other = adj_222[node][i].fi;
            c = adj_222[node][i].se;

            if(dis_222[other] > dis_222[node] + c){
                dis_222[other] = dis_222[node] + c;
                pq.push(pii(-dis_222[other] , other));
            }
        }
    }
}

int main(){
    int testcase;
    cin >> testcase;
    int n , m , p;
    int x , y ;
    ll c;
    ll temp;

    while(testcase--){
        cin >> n >> m >> s >> t >> p;
        for(int i = 0 ; i <= n ; i++){
            adj[i].clear();
            adj_222[i].clear();
            dis[i] = dis_222[i] = INF;
        }

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> c;
            edge.pb(Edge(-c , pii(x , y)));

            adj[x].pb(pii(y , c));
            adj_222[y].pb(pii(x , c));
        }

        sort(edge.begin() , edge.end());

        dij_s();
        dij_t();

        bool flag = false;
        for(int i = 0 ; i < m ; i++){
            c = -edge[i].fi;
            x = edge[i].se.fi;
            y = edge[i].se.se;

            temp = c + dis[x] + dis_222[y];
            if(temp <= p){
                cout << c << endl;
                flag = true;
                break;
            }
        }

        if(!flag)
            cout << -1 << endl;

    }
}
