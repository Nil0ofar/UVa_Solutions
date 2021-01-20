#include<bits/stdc++.h>

using namespace std;

#define INF 2000000005
#define fi first
#define se second
#define ll unsigned long long
#define pii pair<int , int>
#define pic pair<int , char>
#define pb push_back
#define N 66000
#define mod 1000000007


int main(){
    ios::sync_with_stdio(false);
    ll n ;
    ll x;
    while(cin >> n && n != 0){
        x = sqrt(n);
        if(x * x == n)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
