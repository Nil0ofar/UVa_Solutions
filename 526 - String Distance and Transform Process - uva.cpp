#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back

string s ,t;
int dp[85][85];

int f(int i , int j){
    if(i == s.size() && j == t.size() )
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == s.size()){
        dp[i][j] = 1 + f(i , j + 1); //insert
        return dp[i][j];
    }
    if(j == t.size()){
        dp[i][j] = 1 + f(i + 1 , j); // delete
        return dp[i][j];
    }

    int ans ;

    if(s[i] == t[j]){
        ans = f(i + 1 , j + 1);
    }
    else{
        ans = 1 + f(i + 1 , j + 1); // change
        ans = min ( ans , 1 + f(i + 1 , j)); //delete
        ans = min ( ans , 1 + f(i , j + 1)); // insert
    }
    dp[i][j] = ans ;
    return ans;
}

int counter = 1;
int idx ;

void print(int i , int j){
    if(i == s.size() && j == t.size())
        return;

    if(i == s.size()){
        cout << counter++ <<" Insert " << idx++ << ',' << t[j] <<endl;
        return print(i , j + 1);
    }

    if(j == t.size()){
        cout << counter++ <<" Delete " << idx << endl;
        return print( i + 1 , j);
    }

    if(s[i] == t[j]){
        idx ++ ;
        return print(i + 1 , j + 1);

    }

    if(f(i , j) == 1 + f(i + 1 , j + 1)){
        cout<< counter++ <<" Replace " << idx ++ << ',' << t[j] <<endl;
        return print( i + 1 , j + 1);

    }

    if(f(i , j) == 1 + f(i + 1 , j)){
        cout << counter++ <<" Delete " << idx << endl;
        return print( i + 1 , j);

    }

    cout << counter++ <<" Insert " << idx++ << ',' << t[j] <<endl;
    print(i , j + 1);
}

int main(){
    bool first = true;
    while(getline(cin , s)){
        getline(cin , t);
        memset(dp, -1 , sizeof dp);
        counter = 1;
        idx = 1;
        if(!first)
            cout<<endl;
        first = false;
        cout<<f(0 , 0)<<endl;
        print(0 , 0);
    }
    return 0;
}
