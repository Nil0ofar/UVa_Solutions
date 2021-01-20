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

int source = 0 , destination = 1801;
int cap[1805][1805];
int flow[1805][1850];
vector<int> edge[1805];
const int INF = 1e9;
int idx_x[] = {1 , -1 , 0 , 0};
int idx_y[] = {0 , 0 , -1 , 1};
int par[1805];
bool mark[1805];

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
    int n , m , p;
    int xo , yo , node , other;
    string s[32];
    while(cin >> n >> m >> p){
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i <= 1801 ; i++)
            edge[i].clear();

        for(int i = 0 ; i < n ; i++)
            cin >> s[i];

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(s[i][j] == '~')
                    continue;

                node = i * m + j + 1;
                if(s[i][j] == '*'){
                    edge[source].pb(node);
                    cap[source][node] = 1;
                }

                if(s[i][j] == '#'){
                    edge[node + 900].pb(destination);
                    cap[node + 900][destination] = p;
                }

                edge[node].pb(node + 900);
                edge[node + 900].pb(node);

                if(s[i][j] == '*' || s[i][j] == '.')
                    cap[node][node + 900] = 1;

                else
                    cap[node][node + 900] = INF;

                for(int k = 0 ; k < 4 ; k++){
                    xo = i + idx_x[k];
                    yo = j + idx_y[k];

                    if(xo >= n || yo >= m || xo < 0 || yo < 0)
                        continue;

                    if(s[xo][yo] == '*' || s[xo][yo] == '~')
                        continue;

                    other = xo * m + yo + 1;

                    edge[node + 900].pb(other);
                    edge[other].pb(node + 900);
                    cap[node + 900][other] = INF;
                }
            }
        }

        int mxFlow = 0;
        while(augmentation_path())
            mxFlow++;

        cout << mxFlow << endl;
    }
    return 0;
}
