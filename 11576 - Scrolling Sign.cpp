#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define N 105

int lps[N];
int n;

void set_lps(string s){
    int ii = 0 , jj = 1 ;
    lps[0] = 0;
    while(jj < (int)s.size() ){
        if(s[ii] == s[jj]){
            lps[jj] = ii + 1;
            ii++ , jj++;
        }
        else{
            if(ii == 0){
                lps[jj] = 0;
                jj++;
            }

            else
                ii = lps[ii - 1];
        }
    }
}

int kmp(string s , string t){
    int i = 0 , j = 0;

    while(i < n){
        if(s[i] == t[j])
            i++ , j++;
        else{
            if(j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
    return j; //longest suffix which is also a prefix
}


int main(){
    string s , t;
    int testcase;
    cin >> testcase;
    int x;
    int ans ;
    while(testcase--){
        cin >> n >> x;
        cin >> s ;
        ans = n;
        for(int i = 0 ; i < x - 1 ; i++){
            cin >> t;
            set_lps(t);
            ans += (n - kmp(s , t));
            s = t;
        }
        cout << ans << endl;
    }
    return 0;
}
