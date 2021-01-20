#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 10005
#define mod 1000000007
#define double long double
#define INF 1e9 + 7


int main(){
    ios_base :: sync_with_stdio(false);
    int n , m , r , c;
    string mat[105];
    string ans[105];
    while(cin >> n >> m >> r >> c){
        if(n == 0 && m == 0 && r == 0 && c == 0)
            break;

        for(int i = 0 ; i < n ; i++)
            cin >> mat[i];

        for(int i = 0 ; i < n ; i++){
            ans[i] = "";
            for(int j = 0; j < m ; j++)
                ans[i] += '0';
        }
        int cnt = 0;
        bool flag = true;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] != ans[i][j]){
                    if(i + r > n || j + c > m){
                        flag = false;
                        break;
                    }
                    cnt++;
                    for(int h = i ; h < i + r ; h++){
                        for(int k = j ; k < j + c ; k++){
                            if(ans[h][k] == '0')
                                ans[h][k] = '1';
                            else
                                ans[h][k] = '0';
                        }
                    }
                }
            }
            if(flag == false)
                break;
        }

        if(!flag)
            cout << -1 << endl;
        else
            cout << cnt << endl;
    }
}
