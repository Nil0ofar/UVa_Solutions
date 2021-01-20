#include<bits/stdc++.h>

using namespace std;

#define INF 100000000000000
#define fi first
#define se second
#define ll long long
#define pii pair<ll , ll>
#define pli pair<ll, int >
#define pb push_back
#define N 105

vector<int> art;
int low[N];
int num[N];
vector<int> edge[N];
int root;

void dfs(int node , int no , int p){
    bool flag = false;
    num[node] = low[node] = no;
    int cnt = 0;
    int other;

    for(int i = 0 ; i < (int)edge[node].size() ; i++){
        other = edge[node][i];
        if(other == p)
            continue;

        if(num[other] == -1){
            dfs(other , no + 1 , node);
            cnt++;
            if(low[other] >= num[node])
                flag = true;
            low[node] = min(low[node] , low[other]);
        }
        else{
            low[node] = min(low[node] , num[other]);
        }
    }

    if(node == root){
        if(cnt > 1)
            art.pb(node);
    }
    else if(flag)
        art.pb(node);
}

int main(){
    ios_base :: sync_with_stdio(false);
    string name[N];
    int n , m;
    int x , y;
    string s , t;
    map<string , int> mp;
    int testcase = 1;
    vector<string> order;

    while(cin >> n && n != 0){
        if(testcase > 1)
            cout << endl;

        mp.clear();
        for(int i = 0 ; i <= n ; i++)
            edge[i].clear();

        for(int i = 1 ; i <= n ; i++){
            cin >> name[i];
            mp[name[i]] = i;
        }

        cin >> m;

        for(int i = 0 ; i < m ; i++){
            cin >> s >> t;
            x = mp[s];
            y = mp[t];
            edge[x].pb(y);
            edge[y].pb(x);
        }

        memset(num , -1 , sizeof num);
        art.clear();

        for(int i = 1 ; i <= n ; i++){
            if(num[i] != -1)
                continue;
            root = i;
            dfs(root , 1 , -1);
        }

        order.clear();
        for(int i = 0 ; i < (int)art.size() ; i++)
            order.pb(name[art[i]]);

        sort(order.begin() , order.end());

        cout << "City map #" << testcase++ << ": " <<art.size() << " camera(s) found\n";
        for(int i = 0 ; i < (int)order.size() ; i++)
            cout << order[i] << endl;

    }

    return 0;
}
