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
#define N 1000 * 1000 + 5
#define mod 1000000007
#define Base 3002
#define double long double
#define ret(x) return cout << x << endl , 0
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> adj[405];
bool mark[405];
int Rmatch[405];
int idx_x[] = {1 , 0 , -1 , 0};
int idx_y[] = {0 , 1 , 0 , -1};

bool bpm(int node){
    for(auto other : adj[node]){
        if(mark[other])
            continue;

        mark[other] = true;
        if(Rmatch[other] == -1 || bpm(Rmatch[other])){
            Rmatch[other] = node;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    int h , w;
    string mat[45];
    while(t--){
        cin >> h >> w;
        for(int i = 0 ; i < h ; i++)
            cin >> mat[i];

        memset(Rmatch , -1 , sizeof Rmatch);
        for(int i = 0 ; i < w * h ; i++)
            adj[i].clear();

        int ii , jj ;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if((i + j) % 2 == 1 || mat[i][j] == 'o')
                    continue;
                for(int k = 0 ; k < 4 ; k++){
                    ii = i + idx_x[k];
                    jj = j + idx_y[k];
                    if(ii >= 0 && jj >= 0 && ii < h && jj < w && mat[ii][jj] == '*'){
                        adj[i * w + j].pb(ii * w + jj);
                        adj[ii * w + jj].pb(i * w + j);
                    }
                }
            }
        }

        int cnt = 0 ;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if((i + j) % 2 == 1 || mat[i][j] == 'o')
                    continue;

                memset(mark , false , sizeof mark);
                bpm(i * w + j) ;
                cnt++;
            }
        }
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if((i + j) % 2 == 1 && mat[i][j] == '*' && Rmatch[i * w + j] == -1)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
