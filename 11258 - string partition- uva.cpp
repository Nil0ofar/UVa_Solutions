#include<bits/stdc++.h>

using namespace std;

#define pb push_back

struct pii{
    int i , j;
    pii(int _i , int _j){
        i = _i;
        j = _j;
    }

    const bool operator<(const pii &p)const{
        if(j < p.j)
            return true;
        if(j == p.j && i > p.i)
            return true;
        return false;
    }
};

string s ;
vector< int > p[30];
set<string> st;
vector<string > output;
vector< pii > pali;

int dp[256][256];

int is_pali(int i , int j){
   // cout<<i<<' '<<j<<endl;
    if(i >= j)
        return true;
    if(s[i] != s[j])
        return false;
    if(dp[i][j] != -1)
        return dp[i][i];
    return is_pali(i + 1 , j - 1);
}

int  main()
{
    int last_i  , last_j;
    int idx;
    while(cin >> s){
        /*if(s == "1")
            break;*/
        memset(dp , -1 , sizeof dp);
        last_i = last_j = -1 ;
        st.clear();
        pali.clear();
        for(int i = 0 ; i < 26 ; i++)
            p[i].clear();

        for(int i = 0 ; i < s.size() ; i++){
            p[s[i] - 'A'].pb(i);
        }

        for(int i = 0 ; i < s.size() ; i++){
            for(int j = 0 ; j < p[s[i] - 'A'].size() ; j++){
                idx = p[s[i] - 'A'][j];
                if(idx < i)
                    continue;
                if(idx - i >= 2){
                    if(is_pali(i , idx)){
                        pali.pb(pii(i , idx));
                    }
                }
            }
        }

        sort(pali.begin(), pali.end());

        int i , j;
        for(int k = 0 ; k < pali.size() ; k++){
            i = pali[k].i;
            j = pali[k].j;
            if( j == last_j || i < last_i)
                continue;
            last_i = i;
            last_j = j;
            st.insert(s.substr(i , j - i + 1));
        }

        if(st.size() >= 2)
            output.pb(s);

    }

    for(int i = 0 ; i < output.size() ; i++)
        cout<<output[i]<<endl;
}
