#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
//const int N = 1005;
//const ll INF;
const ll NINF = - 1e9;
//const int MAX = 1e9;
//const int MIN = - 1e9;

int n , m;
int t[15][105];
int dp[15][105];

int f(int les, int tim){
    //cout <<les<<' ' << tim<<endl;

    if(tim < 0)
        return NINF;
    if(les == n)
        return 0;
    if(dp[les][tim] != -1)
        return dp[les][tim];
    int ans = NINF;
    for(int i = 1 ; i <= tim ; i++){
        if(t[les][i] < 5)
            continue;
        ans = max(ans , f(les +1, tim - i) + t[les][i]);
    }
    dp[les][tim] = ans;
    return ans;
}

int main(){
    int testcase ;
    cin >> testcase;
    while(testcase--){
        cin >> n >> m;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 1 ; j <= m ; j++){
                cin >> t[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        // i don't know why but apparently this is the only way to get accepted output :
        int ans = f(0 , m);
        double res = ans*100.0;
        res/=(n*1.0);
        res = round(res);
        res/=100.0;
        if(ans < 0)
            cout<<"Peter, you shouldn't have played billiard that much.\n";
        else
            cout<<"Maximal possible average mark - "<<fixed<<setprecision(2)<<res<<".\n";
    }
    return 0;
}
