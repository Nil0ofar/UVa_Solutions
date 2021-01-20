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

map<char , int> mp;
char C[] = {'A' , 'C' , 'G' , 'T'};

struct TrieNode{
    int cnt = 0;
    char ch;
    int level = 0;
    TrieNode* child[4];
};

TrieNode* getNode(){
    TrieNode* node = new TrieNode;
    for(int i = 0 ; i < 4 ; i++)
        node -> child[i] = NULL;
    node -> ch = '#';
    return node;
}

void insertt(TrieNode* root , string key){
    int idx;
    TrieNode* node ;
    for(int i = 0 ; i < (int)key.size() ; i++){
        node = root;
        node -> cnt++;
        for(int j = i ; j < (int) key.size() ; j++){
            idx = mp[key[j]];
            if(node -> child[idx] == NULL){
                node -> child[idx] = getNode();
                node -> child[idx] -> level = node -> level + 1;
                node -> child[idx] -> ch = key[j];
            }
            node = node -> child[idx];
            node -> cnt++;
        }
    }
}

string ans;
int mx;

bool findd(TrieNode* node){
    if(node -> cnt == 1){
        if(node -> level > mx){
            ans = "";
            mx = node -> level;
            return true;
        }
        return false;
    }

    bool flag = false;
    for(int i = 0 ; i < 4 ; i++){
        if(node -> child[i] == NULL)
            continue;
        if(findd(node -> child[i])){
            flag = true;
            if(node -> ch == '#')
                continue;
            ans += node -> ch;
        }
    }
    return flag;
}

int getNum(TrieNode* node , string key){
    for(int i = 0 ; i < (int)key.size() ; i++){
        node = node -> child[mp[key[i]]];
    }
    return node -> cnt;
}

int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    string s;
    mp['A'] = 0 , mp['C'] = 1 , mp['G'] = 2 , mp['T'] = 3;
    while(t--){
        cin >> s;
        TrieNode* root = getNode();
        insertt(root , s);
        ans = "";
        mx = -1;
        findd(root);
        if(ans == ""){
            cout << "No repetitions found!\n";
        }
        else{
            reverse(ans.begin() , ans.end());
            cout << ans << ' ' ;
            cout << getNum(root , ans) << endl;
        }

    }
    return 0;
}
