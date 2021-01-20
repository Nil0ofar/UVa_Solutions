#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back


int main(){
    int testcase;
    cin >> testcase;
    string s;
    int mat[100];
    int cnt ;
    while(testcase --){
        cin >> s;
        memset(mat, 0 , sizeof mat);
        int i = 0 , j = 1;
        cnt = 1;
        while(j != s.size()){
            if(s[i] == s[j]){
                mat[j] = cnt ++ ;
                i ++  , j ++ ;
            }
            else if(s[i] != s[j]){
                cnt = 1;
                if(i == 0){
                    j++;
                }
                else{
                    i = mat[i - 1];
                }
            }
        }

        int len = mat[s.size() -1 ];
        int pat_len = s.size() - len ;
        if(len % pat_len == 0)
            cout<<pat_len<<endl;
        else
            cout<<s.size()<<endl;
        //if(testcase != 0)
            cout<<endl;
    }

    return 0;
}
