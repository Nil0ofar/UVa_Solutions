#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define N 1000005

int lps[N];

int main(){
    string s;
    int ii , jj ;
    while(cin >> s && s!= "."){
        lps[0] = 0;
        ii = 0 , jj = 1;
        while(jj < (int)s.size()){
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

        int len = s.size() - lps[(int)s.size() - 1];
        if((int)s.size() % len == 0)
            cout << s.size() / len << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}
