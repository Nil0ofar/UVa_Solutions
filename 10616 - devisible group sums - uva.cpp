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
//const int MIN = - 1e9;

int n , q;
int a[205];
int d , m;
ll dp[205][12][24];

ll f(int idx, int mm , int dd){
    if(mm == m){
        if(dd == 0)
            return 1;
        return 0;
    }
    if(idx == n)
        return 0;

    if(dp[idx][mm][dd] != -1 )
        return dp[idx][mm][dd] ;

    ll ans = f(idx + 1 , mm , dd);
    ans += f(idx + 1 , mm + 1 , (dd + a[idx] ) % d );
    dp[idx][mm][dd] = ans;
    return ans;
}

int main(){
    int testcase = 1;
    int temp[205];
    while(cin >> n >> q){
        if(n == 0 && q == 0)
            break;
        cout<< "SET " << testcase++ <<":\n";
        for( int i = 0 ; i < n ; i++ )
            cin >> temp[i];
        int q_num = 1;
        for(int i = 0 ; i < q ; i++){
            cin >> d >> m ;
            for(int i = 0 ; i < n ; i++){
                a[i] = ((temp[i] % d) + d)%d;
            }
            memset(dp, -1 , sizeof dp);
            cout<<"QUERY " << q_num << ": " << f(0 , 0 , 0)<<endl;
        }
    }
    return 0;
}
