#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 3000
#define mod 998244353
#define MAX 1000000

int source , destination;
vector<int> adj[80];
int cap[80][80];
int flow[80][80];
bool mark[80];
int par[80];

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
    memset(mark, false , sizeof mark);
    queue<int> q;
    mark[source] = true;
    q.push(source);
    int node , other;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i = 0 ; i < adj[node].size() ; i++){
            other = adj[node][i];
            if(mark[other] == false && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    update_flow();
                    return true;
                }
                q.push(other);
            }
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int n , m;
    int cnt[30];
    int num ,x;
    for(int t = 1 ; t <= testcase ; t++){
        cin >> n >> m;
        source = 0 ;
        destination = 2 * m + n ;
        for(int i = 0 ; i <= destination; i++)
            adj[i].clear();
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        memset(cnt , 0 , sizeof cnt);

        cin >> num ;
        for(int i = 0 ; i < num ; i++){
            cin >> x ;
            cnt[x]++;
        }

        int ans = 0;

        for(int i = 1 ; i <= m ; i++){
            if(cnt[i] > 0)
                ans++;
            if(cnt[i] > 1){
                adj[source].pb(i + n - 1);
                cap[source][i + n - 1] = cnt[i] - 1;
            }

            if(cnt[i] == 0){
                adj[n + m + i - 1].pb(destination);
                cap[n + m + i - 1][destination] = 1;
            }
        }

        for(int i = 1 ; i < n ; i++){
            cin >> num ;
            memset(cnt , 0 , sizeof cnt);
            for(int j = 0 ; j < num ; j++){
                cin >> x;
                cnt[x]++;
            }

            for(int j = 1 ; j <= m ; j++){
                if(cnt[j] > 1){
                    adj[i].pb(n + m + j - 1);
                    adj[n + m + j - 1].pb(i);
                    cap[i][n + m + j - 1] = cnt[j] - 1;
                }

                if(cnt[j] == 0){
                    adj[n + j - 1].pb(i);
                    adj[i].pb(n + j - 1);
                    cap[n + j - 1][i] = 1;
                }
            }
        }

        for(int i = m + n ; i < 2 * m + n ; i++){
            cap[i][i - m] = 100;
            adj[i].pb(i - m);
        }

        int maxFlow = 0;
        while(augmentation_path())
            maxFlow++;

        cout << "Case #" << t << ": " << ans + maxFlow << endl;
    }
    return 0;
}
