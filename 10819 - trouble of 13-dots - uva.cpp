#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int , int>
#define pb push_back

//const int mod;
//const int N = 1005;
//const ll INF;
//const ll NINF;
//const int MAX = 1e9;
const int MIN = - 1e9;

int n;
int money;
int dp[105][10005][3];
vector<pii> vec;


int f(int idx, int spent , int use){
    if(spent > 2000 && use == 0){
        use = 1;
        spent-=200;
    }
    if(spent > money){
        if(idx == n)
            return MIN;
        if(use == 1)
            return MIN;
    }
    if(idx == n)
        return 0;
    if(dp[idx][spent][use] != -1)
        return dp[idx][spent][use];
    int ans = f(idx + 1 , spent , use);
    ans = max( ans , f(idx + 1, spent + vec[idx].first , use) + vec[idx].second);
    dp[idx][spent][use] = ans;
    return ans;

}

int main(){
    int p , fa;
    while(cin >> money >> n ){
        memset(dp, -1  , sizeof dp);
        vec.clear();
        for( int i = 0 ; i < n ; i++ ){
            cin >> p >> fa;
            vec.pb(pii(p, fa));
        }
        cout<<f(0 , 0 , 0)<<endl;
    }
    return 0;
}
