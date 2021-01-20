#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define N 1000005

string pat , txt;
int n;
int lps[N];
int idx;

void set_lps(){
    lps[0] = 0;
    int i = 0 , j = 1;
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
            else{
                i = lps[i - 1];
            }
        }
    }
}

int kmp(){
    int t = 0 , p = 0;
    while(t < n){
        if(pat[p] == txt[t]){
            t++ , p++;
        }
        else{
            if(p == 0){
                t++;
            }
            else
                p = lps[p - 1];
        }
    }
    return p;
}

bool isPalid(int i , int j){
    //cout << i <<' ' << j << endl;
    while(i < j ){
        if(txt[i] != txt[j])
            return false;
        i++ , j--;
    }
    return true;
}

int check(){
    if(idx == n){
        if(n == 1)
            return 1;
        int half = n / 2;
        if(n % 2 == 0)
            half--;
        if(isPalid(0 , half) && isPalid(half + 1 , n - 1))
            return 2;
        else
            return 1;
    }
    if(isPalid(0 , n - idx - 1))
        return 2;
    else
        return 0;
}

int main(){
    int testcase;
    cin >> testcase;
    string s;
    while(testcase--){
        cin >> s;
        n = s.size();
        pat = txt = s;
        reverse(pat.begin(), pat.end());
        set_lps();
        idx = kmp() ;
        int ans = check();
        swap(txt , pat);
        set_lps();
        idx = kmp();

        ans = max(ans , check());

        if(ans == 0)
            cout << "simple\n";
        else if(ans == 1)
            cout << "palindrome\n";
        else
            cout << "alindrome\n";
    }
    return 0;
}
