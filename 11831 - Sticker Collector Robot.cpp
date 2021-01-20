#include<bits/stdc++.h>

using namespace std;

#define N 105
#define INF 1000000007
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pll pair<ll, ll >
#define pb push_back

string mat[N];
string path;
int n , m;

int f(int x , int y , int d){
    int cnt = 0;

    for(int i = 0 ; i < (int)path.size() ; i++){
        //cout << x << ' ' << y << ' ' << d << endl;
        if(path[i] == 'D')
            d = (d + 1) % 4 ;
        else if(path[i] == 'E'){
            d = (d - 1 + 4) % 4;
        }
        else{
            if(d == 2){
                if(x == n - 1)
                    continue;
                if(mat[x + 1][y] == '#')
                    continue;
                x++;
                if(mat[x][y] == '*'){
                    mat[x][y] = '.';
                    cnt++;
                }
            }

            else if(d == 1){
                if(y == m - 1)
                    continue;
                if(mat[x][y + 1] == '#')
                    continue;
                y++;
                if(mat[x][y] == '*'){
                    mat[x][y] = '.';
                    cnt++;
                }
            }

            else if(d == 0){
                if(x == 0)
                    continue;
                if(mat[x - 1][y] == '#')
                    continue;
                x--;
                if(mat[x][y] == '*'){
                    mat[x][y] = '.';
                    cnt++;
                }
            }

            else if(d == 3){
                if(y == 0)
                    continue;
                if(mat[x][y - 1] == '#')
                    continue;
                y--;
                if(mat[x][y] == '*'){
                    mat[x][y] = '.';
                    cnt++;
                }
            }
        }
    }

    return cnt;
}


int main(){
    int r;
    int xs , ys , dir;
    while(cin >> n >> m >> r){
        if(n == 0 && m == 0 && r == 0)
            break;
        for(int i = 0 ; i < n ; i++)
            cin >> mat[i];
        cin >> path;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                switch (mat[i][j]){
                    case 'N' :
                        xs = i , ys = j;
                        dir = 0;
                        break;
                    case 'S' :
                        xs = i , ys = j;
                        dir = 2;
                        break;
                    case 'L' :
                        xs = i , ys = j;
                        dir = 1;
                        break;
                    case 'O' :
                        xs = i , ys = j;
                        dir = 3;
                        break;
                }

            }
        }
        //cout << xs << ' ' << ys << ' ' << dir << endl;
        cout << f(xs , ys , dir) << endl;
    }
}
