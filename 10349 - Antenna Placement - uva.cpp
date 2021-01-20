#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define N 810
#define pii pair< int , int >
#define ll long long

int source = 0 , destination = 805;
int cap[N][N];
int flow[N][N];
vector<int> edge[N];
int par[N];
bool mark[N];
string mat[N];


int idx_x[] = {1 , - 1 , 0 , 0};
int idx_y[] = {0 , 0 , - 1 , 1};

void update_flow(){
    int node = destination;
    int p ;
    while(source != node){
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
    int node , other ;

    while(!q.empty()){
        node = q.front();
        q.pop();

        for(int i = 0 ; i < edge[node].size() ; i++){
            other = edge[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
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
    int testcase;
    cin >> testcase;
    int w , h;
    int xo , yo , node , other;
    int total;
    while(testcase--){
        cin >> h >> w;
        for(int i = 0 ; i < h ; i++){
            cin >> mat[i];
            mat[i] = '$' + mat[i];
        }

        total = 0;
        memset(cap, 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            edge[i].clear();

        for(int x = 0 ; x < h ; x++){
            for(int y = 1 ; y <= w ; y++){
                if(mat[x][y] == 'o')
                    continue;
                total++;
                node = x * w + y;

                if((x + y) % 2 == 0){
                    edge[source].pb(node);
                    edge[node].pb(source);
                    cap[source][node] = 1;

                    for(int i = 0 ; i < 4 ; i++){
                        int xo = x + idx_x[i];
                        int yo = y + idx_y[i];
                        if(xo < 0 || xo >= h || yo <= 0 || yo > w)
                            continue;
                        if(mat[xo][yo] == '*'){
                            other = xo * w + yo;
                            edge[node].pb(other);
                            edge[other].pb(node);
                            cap[node][other] = 1;
                        }
                    }
                }

                else{
                    edge[node].pb(destination);
                    edge[destination].pb(node);
                    cap[node][destination] = 1;
                }

            }
        }

        int mx_flow = 0;
        while(augmentation_path())
            mx_flow++;
        cout << total - mx_flow << endl;
    }
    return 0;
}


/*

2 7 9
ooo**oooo
**oo*ooo*
o*oo**o**
ooooooooo
*******oo
o*o*oo*oo
*******oo
10 1
*
*
*
o
*
*
*
*
*
*

*/
