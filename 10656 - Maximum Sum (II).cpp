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
    int n;
    int x;
    vector<int> vec;
    while(cin >> n && n != 0){
        vec.clear();
        for(int i = 0 ; i < n ; i++){
            cin >> x;
            if(x != 0)
                vec.pb(x);
        }
        if(vec.size() == 0)
            vec.pb(0);

        for(int i = 0 ; i < (int)vec.size() ; i++){
            if(i != 0)
                cout << ' ' ;
            cout << vec[i];
        }
        cout << endl;
    }
    return 0;
}
