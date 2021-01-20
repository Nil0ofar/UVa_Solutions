#include <bits/stdc++.h>

using namespace std;
#define double long double
#define pdi pair<double , int>
#define fi first
#define se second
#define pb push_back
#define N 305
#define MAX 1000000007LL
#define ll long long
#define INF 2e18
#define pii pair<int,int>

int name[N] , last[N];

int main(){
    int n ;
    string s , p;
    int ans;
    int temp;
    int ones;
    int cnt;
    bool mark[30];
    while(cin >> n && n != 0){
        for(int i = 0 ; i < n ; i++){
            cin >> s >> p;
            name[i] = (s[0] - 'A');
            last[i] = (p[0] - 'A');
        }

        ans = 1e9;

        for(int i = 0 ; i < (1 << 18) ; i++){
            memset(mark , false , sizeof mark);
            ones = 0;
            cnt = 0;
            for(int j = 0 ; j < n ; j++){
                if((i & (1 << last[j])) == 0)
                    mark[name[j]] = true;
            }

            for(int j = 0 ; j <= 18 ; j++){
                if(((1 << j) & i) != 0)
                    ones++;
            }

            for(int i = 0 ; i < 30 ; i++){
                if(mark[i])
                    cnt++;
            }

            ans = min(ans , ones + cnt);
        }
        cout << ans << endl;
    }

    return 0;
}
