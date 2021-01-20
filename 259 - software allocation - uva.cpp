#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 300
#define mod 998244353
#define MAX 1000000

char task[N];
int flow[N][N];
int cap[N][N];
vector<int> adj[N];
int source , destination;
bool mark[N];
int par[N];
int node;

bool bfs(){
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
            if(cap[node][other] > flow[node][other] && mark[other] == false){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    return true;
                }
                q.push(other);
            }
        }
    }
    return false;
}

void update_flow(){
    int x ;
    int y = destination;
    while(y != source){
        x = par[y];
        flow[x][y] += 1;
        flow[y][x] -= 1;
        y = par[y];
    }
}

string find_ans(){
    string ans = "";
    for(int i = 0 ; i < 10 ; i++){
        ans += '_';
        for(int j = 10 ; j < node ; j++){
            if(flow[i][j] == -1){
                ans[i] = task[j];
                break;
            }
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    string s;
    int n ;

    while(getline(cin , s)){
        node = 10;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        do{
            n = s[1] - '0';
            for(int i = 0 ; i < n ; i++){
                task[node++] = s[0];
            }

            for(int i = node - n ; i < node ; i++){
                for(int j = 3 ; j < s.size() - 1 ; j ++){
                    adj[i].pb(s[j] - '0');
                    adj[s[j] - '0'].pb(i);
                    cap[i][s[j] - '0'] = 1;
                }
            }
        }while(getline(cin , s) && s != "");


        source = node;
        for(int i = 10 ; i < node ; i++){
            adj[source].pb(i);
            adj[i].pb(source);
            cap[source][i] = 1;
        }

        destination = ++node;
        node++;
        for(int i = 0 ; i < 10 ; i++){
            adj[i].pb(destination);
            adj[destination].pb(i);
            cap[i][destination] = 1;
        }

        int num = 0;
        while(bfs()){
            num++;
            update_flow();
        }

        if(num == node - 12){
            cout << find_ans() << endl;
        }
        else
            cout << '!' << endl ;
    }
    return 0;
}
