#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pii pair<ll , ll>
#define pli pair<ll, int >
#define pb push_back
#define N 2005



int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    string s;
    int n;
    int idx;
    bool flag = true;
    while(t--){
        cin >> s;
        n = (int)s.size() / 3;
        n++;
        for(int i = n ;  ; i++){
            flag = true;
            for(int j = 0 ; j < i ; j++){
                if(s[j] == s[i + j])
                    continue;
                flag = false;
                break;
            }

            if(flag){
                n = i;
                break;
            }
        }

        idx = (int)s.size() % n;
        for(int i = 0 ; i < 8 ; i++){
            cout << s[idx] ;
            idx++;
            idx %= n;
        }
        cout << "...\n";

    }
    return 0;
}
