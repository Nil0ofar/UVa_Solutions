#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pii pair<ll , ll>
#define pli pair<ll, int >
#define pb push_back
#define N 1005

int mat[55][55];
int n ;
int deg[55];

void dfs(int node){
    for(int other = 1 ; other <= 50 ; other++){
        if(mat[node][other] > 0){
            mat[node][other]--;
            mat[other][node]--;
            dfs(other);
            cout << other << ' ' << node << endl;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int c1 , c2;
    bool flag ;
    for(int t = 1 ; t <= testcase ; t++){
        if(t != 1)
            cout << endl;
        cout << "Case #" << t << endl;
        cin >> n;

        memset(mat , 0 , sizeof mat);
        memset(deg , 0 , sizeof deg);

        for(int i = 0 ; i < n ; i++){
            cin >> c1 >> c2;
            mat[c1][c2]++;
            mat[c2][c1]++;
            deg[c1]++ ;
            deg[c2]++;
        }

        flag = true;
        for(int i = 1 ; i <= 50 ; i++){
            if(deg[i] % 2 == 1){
                flag = false;
                break;
            }
        }

        if(!flag)
            cout << "some beads may be lost\n";

        else
            dfs(c1);


    }
    return 0;
}
