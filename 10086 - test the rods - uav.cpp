#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

int T1 , T2;
int site ;
int n[35];
vector<int> c1[35] , c2[35];
int dp[35][305][305];
const int MAX = 1e9;

ll f(int idx , int t1 , int t2){
    if(t1 < 0 || t2 < 0)
        return MAX;
    if(idx == site){
        if(t1 == 0 && t2 == 0)
            return 0;
        return MAX;
    }

    if(dp[idx][t1][t2] != -1)
        return dp[idx][t1][t2];

    ll ans = MAX;

    for(int i = 0 ; i <= n[idx] ; i++){
        ans = min (ans , c1[idx][i] + c2[idx][n[idx] - i] + f(idx + 1 , t1 - i , t2 - (n[idx] - i)));
    }
    dp[idx][t1][t2] = ans;
    return ans;
}

void print(int idx, int t1, int t2){
    if(idx == site)
        return;
    for(int i = 0 ; i <= n[idx] ; i++){
        if(f(idx , t1 , t2) == c1[idx][i] + c2[idx][n[idx] - i] + f(idx + 1 , t1 - i , t2 - (n[idx] - i))){
            cout<<i<<' ';
            print(idx + 1 , t1 - i , t2 - (n[idx] - i));
            return;
        }
    }
}

int main(){
    int temp;
    while(cin >> T1 >> T2){
        if(T1 == 0 && T2 == 0)
            break;

        cin >> site;
        for(int i = 0 ; i < site ; i++){
            c1[i].clear();
            c2[i].clear();
            cin >> n[i];
            c1[i].pb(0);
            for(int j = 0 ; j < n[i] ; j++){
                cin >> temp;
                c1[i].pb(temp);
            }
            c2[i].pb(0);
            for(int j = 0 ; j < n[i] ; j++){
                cin >> temp;
                c2[i].pb(temp);
            }
        }

        memset(dp, -1 , sizeof dp);

        cout<<f(0 , T1 , T2)<<endl;
        print(0 , T1 , T2);
        cout<<endl<<endl;
    }
    return 0;
}
