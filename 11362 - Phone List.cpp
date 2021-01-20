#include <bits/stdc++.h>

using namespace std ;

#define N 10

bool flag ;

struct TrieNode{
    TrieNode* children[N];
    bool isEnd;
};

TrieNode* getNode(){
    TrieNode* node = new TrieNode;
    node->isEnd = false;
    for(int i = 0 ; i < N ; i++)
        node -> children[i] = NULL;
    return node;
}

void insertt(TrieNode *node , string key){
    int idx;
    for(int i = 0 ; i < (int)key.size() ; i++){
        idx = key[i] - '0';
        if(node -> isEnd)
            flag = false;
        if(node -> children[idx] == NULL){
            node -> children[idx] = getNode();
        }
        else if(i == key.size() - 1)
            flag = false;

        node = node -> children[idx];
    }
    node -> isEnd = true;
}


main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int n;
    string s;
    while(testcase--){
        cin >> n;
        flag = true;
        TrieNode *root = getNode();

        for(int i = 0 ; i < n ; i++){
            cin >> s;
            insertt(root , s);
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

