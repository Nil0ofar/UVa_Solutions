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

vector<int> adj[50];
int source = 0 , destination;
int cap[50][50];
int flow[50][50];
bool mark[50];
int par[50];

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
    queue<int> q;
    memset(mark , false , sizeof mark);
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
    map<string , int> mp;
    mp["XS"] = 1 , mp["S"] = 2 , mp["M"] = 3 , mp["L"] = 4  , mp["XL"] = 5 , mp["XXL"] = 6;
    int testcase;
    cin >> testcase;
    int n , m;
    string s;
    while(testcase--){
        cin >> n >> m;
        destination = m + 7;
        for(int i = 0 ; i <= destination ; i++)
            adj[i].clear();
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        n /= 6;

        for(int i = 7 ; i < 7 + m ; i++){
            cap[source][i] = 1 ;
            adj[source].pb(i);

            for(int j = 0 ; j < 2 ; j++){
                cin >> s;
                cap[i][mp[s]] = 1;
                adj[i].pb(mp[s]);
                adj[mp[s]].pb(i);
            }
        }

        for(int i = 1 ; i <= 6 ; i++){
            cap[i][destination] = n;
            adj[i].pb(destination);
        }

        int maxFlow = 0;
        while(augmentation_path())
            maxFlow++;

        if(maxFlow == m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
