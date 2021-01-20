#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 505
#define mod 1000000007
#define double long double
#define INF 1e18 + 7


int main(){
    int testcase;
    cin >> testcase;
    ll sum;
    ll x;
    int n;
    int cnt = 0;
    int a[10005];
    while(testcase--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sum = a[0];
        cnt = 1;

        for(int i = 1 ; i < n - 1 ; i++){
            if(sum + a[i] < a[i + 1]){
                sum += a[i];
                cnt++;
            }
        }
        cnt++;
        cout << cnt << endl;
    }
    return 0;
}
