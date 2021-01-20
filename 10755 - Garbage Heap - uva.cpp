#include <bits/stdc++.h>

using namespace std;

#define pii pair<int , int>
#define ll long long
#define pb push_back
#define pli pair<long long , int >

int A , B , C;
bool mark[25];
ll dp[25];
ll a[25];
ll g[25][25][25];

void set_g(){
    for(int i = 1 ; i <= C ; i++){
        for(int j = 1 ; j <= A ; j++){
            for(int k = 1 ; k <= B ; k++){
                g[j][k][i] += g[j][k-1][i];
            }
        }

        for(int j = 1 ; j <= B ; j++){
            for(int k = 1 ; k <= A ; k++){
                g[k][j][i] += g[k - 1][j][i];
            }
        }
    }
}

void set_a(int a1 , int a2 ,int b1 ,int b2){
    for(int i = 1 ; i <= C ; i++){
        a[i] = g[a2][b2][i] - g[a1 - 1][b2][i] - g[a2][b1 - 1][i] + g[a1 - 1][b1 - 1][i];
    }
}

ll f(int idx){
    if(idx == C)
        return a[idx];
    if(mark[idx])
        return dp[idx];
    ll ans = max(a[idx] , a[idx] + f(idx + 1));
    mark[idx] = true;
    dp[idx] = ans;
    return ans;
}

int main(){
    int testcase;
    cin >> testcase;
    memset(g , 0 , sizeof g);
    while(testcase--){
        cin >> A >> B >> C;
        for(int i = 1 ; i <= A ; i++){
            for(int j = 1 ; j <= B ; j++){
                for(int k = 1 ; k <= C ; k++){
                    cin >> g[i][j][k];
                }
            }
        }

        set_g();
        bool first = true;
        ll ans;

        for(int a1 = 1 ; a1 <= A ; a1 ++){
            for(int a2 = a1 ; a2 <= A ; a2 ++){
                for(int b1 = 1 ; b1 <= B ; b1 ++){
                    for(int b2 = b1 ; b2 <= B ; b2 ++){
                        set_a(a1 , a2 , b1 , b2);
                        memset(mark, false, sizeof mark);
                        for(int i = 1 ; i <= C ; i++){
                            if(first){
                                first = false;
                                ans = f(i);
                            }
                            else
                                ans = max(ans, f(i));
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
        if(testcase != 0)
            cout<<endl;

    }
    return 0;
}
