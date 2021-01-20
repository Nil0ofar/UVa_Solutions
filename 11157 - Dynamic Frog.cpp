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
    int n , d;
    int dis[105];
    bool big[105] , used[105];
    string s;
    int ans;
    int testcase;
    cin >> testcase;
    for(int t = 1 ; t <= testcase; t++){
        cin >> n >> d;
        big[0] = true;
        dis[0] = 0;
        big[n + 1] = true;
        dis[n + 1] = d;

        for(int i = 1 ; i <= n ; i++){
            cin >> s;
            big[i] = (s[0] == 'B');
            stringstream ss(s.substr(2 , s.size() - 2));
            ss >> dis[i];
        }

        ans = 0;
        memset(used, false, sizeof used);

        for(int i = 0 ; i <= n ; i++){
            used[i] = true;
            if(big[i] == false && big[i + 1] == false){
                ans = max(ans , dis[i + 2] - dis[i]);
                i++;
            }
            else
                ans = max(ans , dis[i + 1] - dis[i]);
        }

        for(int i = 0 ; i <= n ; i++){
            if(big[i + 1] == false && used[i + 1]){
                ans = max(ans , dis[i + 2] - dis[i]);
                i++;
            }
            else
                ans = max(ans , dis[i + 1] - dis[i]);
        }

        cout << "Case " << t <<": " << ans << endl;
    }

    return 0;
}
