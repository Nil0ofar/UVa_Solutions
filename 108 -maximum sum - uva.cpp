#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
const int N = 105;
//const ll INF;
//const ll NINF = - 1e9;
//const int MAX = 1e9;
//const int MIN = - 1e9

int n;
int a[N][N];

int main(){
    cin >> n;
    memset(a , 0 , sizeof a);
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
            a[i][j] += a[i][j-1];
        }
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++)
            a[i][j] += a[i - 1][j];
    }
    int ans;
    bool first = true;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<= n ; j++){
            for(int h = i ; h <=n ; h++){
                for(int k = j ; k <=n ; k++){
                    if(first){
                        ans = a[h][k] - a[h][j-1] - a[i-1][k] + a[i-1][j-1];
                        first = false;
                    }
                    else{
                        //cout<<a[h][k]<<' '<<a[h][j-1]<<' '<<a[i-1][k]<<endl;
                        if(ans < a[h][k] - a[h][j-1] - a[i-1][k] + a[i-1][j-1]){
                            ans = a[h][k] - a[h][j-1] - a[i-1][k] + a[i-1][j-1];
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
