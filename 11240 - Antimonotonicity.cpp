#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 10005
#define mod 1000000007
#define double long double
#define INF 1e9 + 7


int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int n;
    int a[30005];
    int last;
    bool smaller;
    int cnt ;
    while(testcase--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];

        last = a[0];
        smaller = true;
        cnt = 1;

        for(int i = 1 ; i < n ; i++){
            if(smaller){
                if(a[i] < last){
                    smaller = false;
                    cnt++;
                }

                last = a[i];
            }

            else{
                if(a[i] > last){
                    smaller = true;
                    cnt++;
                }

                last = a[i];
            }
        }

        cout << cnt << endl;
    }
}
