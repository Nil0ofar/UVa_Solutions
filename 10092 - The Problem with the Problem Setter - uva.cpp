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
int cap[2000][2000];
int flow[2000][2000];
bool mark[2000];
int par[2000];
vector<int> adj[2000];


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

int augmentation_path(){
    queue<int> q;
    memset(mark , false , sizeof mark);
    mark[source] = true;
    q.push(source);
    int node , other;

    while(!q.empty()){
        node = q.front();
        q.pop();
        //cout << node << endl;
        for(int i = 0 ; i < adj[node].size() ; i++){
            other = adj[node][i];
            if(cap[node][other] > flow[node][other] && mark[other] == false){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    update_flow();
                    return 1;
                }
                q.push(other);
            }
        }
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int cat , ques;
    int temp , num , x;
    int sum , maxFlow;
    vector<int> output;
    while(cin >> cat >> ques){
        if(cat == 0 && ques == 0)
            break;
        //initializing
        source = cat + ques + 1;
        destination = 0;
        sum = 0 , maxFlow = 0;
        memset(cap , 0 , sizeof mark);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i <= source ; i++)
            adj[i].clear();

        for(int i = 1 ; i <= cat ; i++){
            cin >> cap[i][destination];
            adj[i].pb(destination);
            sum += cap[i][destination];
        }

        for(int i = cat + 1 ; i < cat + ques + 1 ; i++){
            cap[source][i] = 1;
            adj[source].pb(i);
            adj[i].pb(source);
        }

        for(int i = cat + 1 ; i < cat + ques + 1 ; i++){
            cin >> num ;
            for(int j = 0 ; j < num ; j++){
                cin >> x;
                adj[x].pb(i);
                adj[i].pb(x);
                cap[i][x] = 1;
            }
        }


        while(true){
            temp = augmentation_path();
            if(temp == 0)
                break;
            maxFlow += temp;
        }

        if(maxFlow == sum){
            cout << 1 << endl;
            for(int i = 1 ; i <= cat ; i++){
                output.clear();
                for(int j = cat + 1 ; j < ques + cat + 1 ; j++){
                    if(flow[i][j] == -1)
                        output.pb(j - cat);
                }
                for(int j = 0 ; j < output.size() ; j++){
                    cout << output[j] ;
                    if(j != output.size() -1)
                        cout << ' ' ;
                }
                cout << endl;
            }
        }
        else
            cout << 0 << endl;
    }
    return 0;
}
