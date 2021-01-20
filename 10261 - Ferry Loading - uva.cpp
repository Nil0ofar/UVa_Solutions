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

int dp[10001][10001];
int len ;
vector < int > car;

int f(int idx, int l , int r){
    if(idx == car.size()){
        dp[l][r] = 0;
        return 0;
    }

    if(dp[l][r] != -1)
        return dp[l][r];

    int ans = 0;
    if(car[idx] <= r)
        ans = f(idx + 1 , l , r - car[idx]) + 1;
    if(car[idx] <= l)
        ans = max(ans , f(idx + 1 , l - car[idx] , r ) + 1 );

    dp[l][r] = ans;
    return ans;
}

void print(int idx, int l , int r){
    if( f( idx, l , r) == 0)
        return;
    if(car[idx] <= r){
        if(f(idx, l , r) == 1 + f(idx , l , r - car[idx])){
            cout<<"starboard\n";
            print(idx + 1 , l , r - car[idx]);
            return;
        }
    }
    cout<<"port\n";
    print(idx + 1 , l - car[idx] , r);
    return;
}


int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int temp;
        car.clear();
        memset(dp, -1 , sizeof dp);

        cin >> len ;
        len*=100;
        while(cin >> temp, temp != 0)
            car.pb(temp);

        cout<<f(0, len , len)<<endl;
        print(0 , len, len);
        if(testcase != 0)
            cout<<endl;


    }

    return 0;
}
