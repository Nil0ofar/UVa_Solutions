#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 25
#define ll long long

string s[N];
int mat[N][N];
int n , m;

int idx_x[] = {1 , -1 , 0 , 0};
int idx_y[] = {0 , 0 , -1 , 1};

int bfs(int x , int y){
    mat[x][y] = 0;
    int ans = 1;
    queue<pii> q;
    q.push(pii(x , y));
    int xo , yo;

    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            xo = x + idx_x[i];
            yo = y + idx_y[i];

            if(yo ==  m)
                yo = 0;
            else if(yo == -1)
                yo = m - 1;

            if(xo >= n || xo < 0)
                continue;

            if(mat[xo][yo] == 1){
                mat[xo][yo] = 0;
                ans++;
                q.push(pii(xo , yo));
            }
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);

    int x ,  y;

    while(cin >> n){
        cin >> m;
        for(int i = 0 ; i < n ; i++)
            cin >> s[i];

        cin >> x >> y ;
        char land = s[x][y];

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(s[i][j] == land)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        bfs(x , y);

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(mat[i][j] == 1)
                    ans = max(ans , bfs(i , j));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

