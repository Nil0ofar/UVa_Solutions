#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 10005
#define mod 1000000007
#define double long double
#define INF 1e9 + 7

struct Node{
    int idx , has , gone = 0;
    Node(int _idx , int _has){
        idx = _idx ;
        has = _has;
    }

    Node(){};

   const bool operator<(const Node &node)const{
        return has - gone * 2 < node.has - node.gone * 2;
    }
};


int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int n , m;
    int x , y;
    vector<int> vec[105];
    bool mark[105][105];
    vector<int> lis;
    bool used[105];
    int needed;
    for(int t = 1 ; t <= testcase ; t++){
        memset(mark , false ,sizeof mark);
        cin >> n >> m;
        for(int i = 0 ; i <= n ; i++)
            vec[i].clear();

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y;
            if(mark[x][y])
                continue;
            mark[x][y]  = mark[y][x] = true;
            vec[x].pb(y);
            vec[y].pb(x);
        }

        Node node[105];
        for(int i = 1 ; i < n ; i++){
            node[i] = Node(i , vec[i].size());
        }

        lis.clear();
        needed = ceil(1.0 * m / 2.0);
        int sum_other = 0;
        int idx , other;
        Node cur;
        bool imp = false;
        int temp;
        while(needed > 0){
            cur = *max_element(node + 1 , node + n + 1 );
            //cout << cur.idx <<' ' << cur.has <<' ' << cur.gone<<endl;
            idx = cur.idx;
            temp = cur.has - cur.gone * 2;
            if(temp <= 0){
                imp = true;
                break;
            }

            needed -= temp;
            node[idx].has = -100;
            lis.pb(idx);

            for(int i = 0 ; i < vec[idx].size() ; i++){
                other = vec[idx][i];
                node[other].gone++;
            }

        }

        cout << "Case #" << t <<": " ;
        if(imp){
            cout << "Impossible\n\n";
        }
        else{
            cout << (int)lis.size() << endl;
            for(int i = 0 ; i < (int)lis.size() ; i++){
                cout << lis[i] ;
                if(i != (int)lis.size() - 1)
                    cout << ' ' ;
            }
            cout << endl;
        }
    }
}
