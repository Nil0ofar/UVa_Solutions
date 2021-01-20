#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll , int>
#define pb push_back

//const int mod;
const int N = 20005;
//const ll INF;
//const ll NINF = - 1e9;
//const int MAX = 1e9;
//const int MIN = - 1e9;

int n;
int a[N];
pii dp[N] ;
bool mark[N];

pii f(int idx){
    if(idx == n)
        return pii(0, idx);
    if(mark[idx])
        return dp[idx];
    ll sum = 0;
    int ending = idx;
    if(f(idx + 1).first + a[idx] >= sum){
        sum = f(idx + 1).first + a[idx];
        ending = f(idx + 1).second;
    }
    mark[idx] = true;
    dp[idx] = pii(sum, ending);
    return dp[idx];
}

int main(){
    int testcase;
    cin >> testcase;
    int ans, start, ending;
    for(int t = 1 ; t <= testcase ; t++){
        cin >> n;
        for(int i = 1 ; i < n ; i++)
            cin >> a[i];
        ll ans = 0;
        start = ending = 0;
        memset(mark , false, sizeof mark);

        for(int i = 1 ; i < n ; i++){
            if(f(i).first > ans){
                ans = f(i).first;
                start = i;
                ending = f(i).second;
            }
            else if(f(i).first == ans){
                if(f(i).second - i > ending - start){
                    start = i;
                    ending = f(i).second;
                }
            }
        }
        if(ans == 0){
           cout<<"Route "<<t<<" has no nice parts\n";
        }
        else{
            cout<<"The nicest part of route "<<t<<" is between stops "<<start<<" and "<<ending<<endl;
        }
    }
    return 0;
}
