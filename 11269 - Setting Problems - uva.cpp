#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 200005
#define mod 1000000007
#define double long double
#define INF 1e18 + 7

struct Problem{
    int a , b;
    const bool operator<(const Problem &problem)const{
        int mn = min(a , min(b , min(problem.a , problem.b)));
        if(mn == a || mn == problem.b)
            return true;
        return false;
    }
};

int main(){
    int n ;
    int a , b;
    Problem pro[25];
    int ans ;
    while(cin >> n ){
        for(int i = 0 ; i < n ; i++){
            cin >> a;
            pro[i].a = a;
        }

        for(int i = 0 ; i < n ; i++){
            cin >> b;
            pro[i].b = b;
        }

        sort(pro , pro + n);

        pro[n].a = 0;
        for(int i = 1 ; i <= n ; i++){
            pro[i].a += pro[i - 1].a;
        }

        ans = pro[0].a;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans + pro[i].b , pro[i + 1].a);
        }
        cout << ans << endl;
    }
}
