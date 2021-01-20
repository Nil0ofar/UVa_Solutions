#include <bits/stdc++.h>

using namespace std;

#define pii pair<int , int>
#define ll long long
#define pb push_back
#define pli pair<long long , int >


vector<int> nb[60];
ll dis[60];
bool mark[60];
ll edge[60][60];
int start , des;
int p;

ll find_d(ll x){
    return ceil(1.0*x / 19.0);
}

void f(int node){
    priority_queue<pli> pq;
    dis[node] = p;
    pq.push( pli(-dis[node] , node));
    int other;
    ll d;

    while(!pq.empty()){
        node = pq.top().second;
        pq.pop();
        if(mark[node])
            continue;
        mark[node] = true;
        for(int i = 0 ; i < nb[node].size() ; i++){
            other = nb[node][i];
            if(node >= 'a' - 'A' && node <= 'z' - 'A')
                d = 1;
            else{
                d = find_d(dis[node]);
            }
            edge[node][other] = d;

            if(mark[other])
                continue;

            if(dis[other] > dis[node] + d){
                dis[other] = dis[node] + d;
                pq.push( pli(-dis[other], other));
            }
        }
    }
}

void print(int node){
    mark[node] = true;
    cout<<char('A' + node);
    if(node == des)
        return;
    cout<<'-';
    int other;
    for(int i = 0 ; i < nb[node].size() ; i++){
        other = nb[node][i];
        if(dis[node] == dis[other] + edge[other][node] && !mark[other]){
            print(other);
            return;
        }
    }
}

int main()
{
    //cout<<find_d(999999999)<<endl;
    //cout<<int('a')<<' '<<int('z')<<' '<<int('A')<<' '<<int('Z')<<endl;
    int e;
    int x, y;
    int testcase = 1;
    char temp;
    while(cin >> e , e != -1){
        for(int i = 0 ; i < 60 ; i++)
            nb[i].clear();

        for(int i = 0 ; i < e ; i++){
            cin >> temp;
            x = temp - 'A';
            cin >> temp;
            y = temp - 'A';
            nb[y].pb(x);
            nb[x].pb(y);
        }

        for(int i = 0 ; i < 60 ; i++)
            sort(nb[i].begin(), nb[i].end());

        cin >> p;
        cin >> temp;
        start = temp - 'A';
        cin >> temp;
        des = temp - 'A';

        memset(edge , -1 , sizeof edge);
        for(int i = 0 ; i < 60 ; i++){
            dis[i] = (ll)1e18;
            mark[i] = false;
        }
        f(des);
        cout<<"Case "<< testcase++ <<":\n";
        cout<<dis[start]<<endl;
        memset(mark, false, sizeof mark);
        print(start);
        cout<<endl;

    }
    return 0;
}
