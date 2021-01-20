#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, long long>
#define pb push_back
#define fi first
#define se second
#define N 105
#define ll long long
#define mod 998244353
#define double long double
#define INF 1e9

int n;
string mat[N];
bool mark[N][N];

bool dfs(int i , int j){
    bool ans = false;
    if(mat[i][j] == 'x')
        ans = true;
    mark[i][j] = true;
    if(i + 1 < n && mat[i + 1][j] != '.')
        ans |= dfs(i + 1 , j);
    else if(j + 1 < n && mat[i][j + 1] != '.')
        ans |= dfs(i , j + 1);
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;

    for(int t = 1 ; t <= testcase ; t++){

        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> mat[i];
        memset(mark, false , sizeof mark);

        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] != '.' && !mark[i][j]){
                    if(dfs(i , j))
                        cnt++;
                }
            }
        }

        cout << "Case " << t << ": " << cnt << endl;
    }

    return 0;
}

