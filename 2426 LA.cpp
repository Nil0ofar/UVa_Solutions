#include <bits/stdc++.h>

using namespace std ;

#define N 26
#define pb push_back
#define ll long long
#define mod 1000000007
#define pll pair<ll, ll>
#define double long double
#define fi first
#define se second
#define INF 1e18

int dp[1005];

struct TrieNode{
    TrieNode* child[N];
    bool isEnd;
};

TrieNode* getNode(){
    TrieNode* node = new TrieNode;
    node -> isEnd = false;
    for(int i = 0 ; i < N ; i++)
        node -> child[i] = NULL;
    return node;
}

void insertt(TrieNode* node , string key){
    int idx ;
    int n = key.size();
    for(int i = 0 ; i < n ; i++){
        idx = key[i] - 'A';
        if(node -> child[idx] == NULL)
            node -> child[idx] = getNode();
        node = node -> child[idx];
    }
    node -> isEnd = true;
}

string morse[] = {".-" , "-..." , "-.-." , "-.." ,
                  "."  , "..-." , "--."  , "....",
                  ".." , ".---" , "-.-" ,  ".-.." ,
                  "--" , "-."   , "---" ,  ".--." ,
                  "--.-" , ".-." , "..." , "-",
                  "..-" , "...-" , ".--" , "-..-" ,
                  "-.--" , "--.."};
string code;

bool can(int idx_c , int m){
    for(int i = 0 ; i < (int)morse[m].size() ; i++){
        if(idx_c == code.size())
            return false;

        if(code[idx_c] == morse[m][i]){
            idx_c++;
        }
        else
            return false;
    }
    return true;
}

TrieNode* root;

int countt(TrieNode* node , int idx){
    if(node == root){
        if(dp[idx] != -1)
            return dp[idx];
    }
    int ans = 0;
    if(idx == code.size()){
        if(node -> isEnd)
            return 1;
        return 0;
    }
    for(int i = 0 ; i < N ; i++){
        if(node -> child[i] != NULL){
            if(can(idx , i)){
                ans += countt(node -> child[i] , idx + morse[i].size());
            }
        }
    }

    if(node -> isEnd)
        ans += countt(root , idx);

    if(node == root)
        dp[idx] = ans;

    return ans;
}


int main(){
    int testcase;
    cin >> testcase;
    int n ;
    string s;
    while(testcase--){
        memset(dp , -1 , sizeof dp);
        root = getNode();
        cin >> code;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> s;
            insertt(root , s);
        }

        cout << countt(root , 0) << endl;
        if(testcase)
            cout <<endl;
    }
    return 0;
}


