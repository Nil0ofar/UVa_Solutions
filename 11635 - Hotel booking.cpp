#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define ll long long
#define pll pair<ll , ll>
#define pii pair<int , int>
#define pbl pair<bool , ll>
#define pb push_back
#define pdd pair<double , double>
#define N 10000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define pci pair<char , int>

int dis[N][601];
bool mark[N][601];
bool hotel[N];
int n ;
vector<pii> edge[N];

int f(){
    priority_queue<pair<int , pii> > pq;
    pq.push({0 , {1 , 0}});
    int num , node , t ;
    while(!pq.empty()){
        num = -pq.top().fi;
        node = pq.top().se.fi;
        t = pq.top().se.se;
        pq.pop();

        if(node == n)
            return num ;

        if(mark[node][t])
            continue;
        mark[node][t] = true;

        for(auto other : edge[node]){
            if(t + other.se <= 600 && num < dis[other.fi][t + other.se]){
                dis[other.fi][t + other.se] = num ;
                pq.push({-num , {other.fi , t + other.se}});
            }

            if(hotel[node]){
                if(num + 1 < dis[other.fi][other.se]){
                    dis[other.fi][other.se] = num + 1;
                    pq.push({-num - 1 , other});
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    while(cin >> n && n != 0){

        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= 600 ; j++){
                dis[i][j] = 1e9;
                mark[i][j] = false;
            }
            edge[i].clear();
            hotel[i] = false;
        }

        int h , m , x , y , t;
        cin >> h ;
        for(int i = 0 ; i < h ; i++){
            cin >> x;
            hotel[x] = true;
        }

        cin >> m ;
        for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> t ;
            edge[x].pb({y , t});
            edge[y].pb({x , t});
        }

        cout << f() << endl;
    }
    return 0;
}


