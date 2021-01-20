#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pii pair<ll , ll>
#define pli pair<ll, int >
#define pb push_back
#define N 1005

string s;
int lps[N];
int mx;
string ans;
int cnt;

void LPS(int st){
    int i = st;
    lps[i] = st;
    int j = 1 + i;

    while(j < (int)s.size()){
        if(s[i] == s[j]){
            lps[j] = i + 1;
            i++ , j++;
        }
        else{
            if(i == st){
                lps[j] = i;
                j++;
            }
            else{
                i = lps[i - 1];
            }
        }
    }

    int m = *max_element(lps , lps + (int)s.size());
    if(m - st > mx){
        mx = m - st;
        cnt = count(lps , lps + (int)s.size() , m);
        ans = s.substr(st , mx);
    }
    else if(m - st == mx){
        string temp = s.substr(st , mx);
        if(temp < ans){
            ans = temp;
            cnt = count(lps , lps + (int)s.size() , m);
        }
    }
    for(int k = 0 ; k < (int)s.size() ; k++){
        lps[k] = 0;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;

    while(t--){
        cin >> s;
        ans = "";
        mx = - 1;
        for(int i = 0 ; i < (int)s.size() - 1; i++){
            LPS(i);
        }

        if(ans == "")
            cout << "No repetitions found!\n";
        else
            cout << ans << ' ' << cnt + 1 << endl;
    }
    return 0;
}
