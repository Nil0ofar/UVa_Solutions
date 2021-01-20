#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define N 510
#define pii pair< int , int >
#define ll long long

int source = 0 , destination = 505;
int cap[N][N];
int flow[N][N];
int par[N];
bool mark[N];
vector<int> edge[N];

struct Node{
    int h ;
    string sport , music;
    int idx;
    Node(int _h , string _m , string _s , int _idx){
        h = _h ;
        sport = _s;
        music = _m;
        idx = _idx;
    }
};

vector<Node> female , male;

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

int main(){
    ios :: sync_with_stdio(false);
    int maxFlow;
    int testcase;
    int n;
    int h ;
    char ch;
    string music, sport;
    int idx;
    cin >> testcase;
    while(testcase--){
        memset(cap , 0 , sizeof cap);
        memset(flow, 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            edge[i].clear();
        male.clear();
        female.clear();
        idx = 1;

        cin >> n ;
        for(int i = 0 ; i < n ; i++){
            cin >> h >> ch >> music >> sport;
            if(ch == 'M'){
                male.pb(Node(h , music , sport , idx));

                edge[source].pb(idx);
                edge[idx].pb(source);
                cap[source][idx] = 1;

                for(int j = 0 ; j < female.size() ; j++){
                    if(abs(female[j].h - h) <= 40 && female[j].music == music && female[j].sport != sport){
                        edge[idx].pb( female[j].idx );
                        edge[ female[j].idx ].pb(idx);
                        cap[idx][ female[j].idx ] = 1;
                    }
                }

                idx++;
            }

            else{
                female.pb(Node(h , music , sport , idx));

                edge[destination].pb(idx);
                edge[idx].pb(destination);
                cap[idx][destination] = 1;

                for(int j = 0 ; j < male.size() ; j++){
                    if(abs(male[j].h - h) <= 40 && male[j].music == music && male[j].sport != sport){
                        edge[idx].pb( male[j].idx );
                        edge[ male[j].idx ].pb(idx);
                        cap[ male[j].idx ][ idx ] = 1;
                    }
                }

                idx++;
            }
        }


        maxFlow = 0;
        while(augmentation_path())
            maxFlow++;

        cout << n - maxFlow << endl;
    }
    return 0;
}
