#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define N 1000005

int lps[N];
char txt[N] , pat[N];
int n;

void set_lps(){
    int i = 0 , j = 1;
    lps[0] = 0;
    while(j < n){
        if(pat[i] == pat[j]){
            lps[j] = i + 1;
            i++ , j++;
        }

        else{
            if(i == 0){
                lps[j] = 0;
                j++;
            }
            else
                i = lps[i - 1];
        }
    }
}

int kmp(){
    int t = 0 , p = 0;
    int ans = 0;
    while(t < n){
        if(txt[t] == pat[p]){
            p++ , t++;
        }

        else{
            if(p == 0)
                t++;
            else{
                ans = max(ans , p);
                p = lps[p - 1];
            }
        }
    }
    ans = max(ans , p);
    return ans;
}

int main(){
    int testcase;
    scanf("%d" , &testcase);
    int len;
    while(testcase--){
        scanf("%s" , &pat);
        n = strlen(pat);
        for(int i = 0 ; i < n ; i++)
            txt[i] = pat[n - i - 1];
        txt[n] = '\0';

        set_lps();
        len = kmp();
        if(len > 0){
            for(int i = len - 1 ; i >= 0 ; i--)
                printf("%c" , pat[i]);
            printf("\n");
        }
        else
            printf("%c" , txt[0]);
    }
    return 0;
}
