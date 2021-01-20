#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 50005
#define mod 998244353
#define MAX 1000000000

int source = 0 , destination = 309;
int cap[310][310];
int flow[310][310];
vector<int> adj[310];
int par[310];
bool mark[310];

int find_min(){
    int node = destination;
    int p ;
    int mn = MAX;
    while(node != source){
        p = par[node];
        mn = min(mn , cap[p][node] - flow[p][node]);
        node = p;
    }
    return mn;
}

void update_flow(int mn){
    int node = destination;
    int p ;
    while(node != source){
        p = par[node];
        flow[p][node] += mn;
        flow[node][p] -= mn;
        node = p;
    }
}

int augmentation_path(){
    queue<int> q;
    memset(mark , false , sizeof mark);
    mark[source] = true;
    q.push(source);
    int node , other;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i = 0 ; i < adj[node].size() ; i++){
            other = adj[node][i];
            if(!mark[other] && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    int mn = find_min();
                    update_flow(mn);
                    return mn;
                }
                q.push(other);
            }
        }
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int n , m;
    vector<pii> vec , vec_2;
    vector<int> interval;
    int v , a , b;
    int sum[N];
    int needed;
    int testcase = 1;
    int last[310];

    while(cin >> n && n!= 0){
        cin >> m;
        vec.clear();
        interval.clear();
        memset(sum , 0 , sizeof sum);
        memset(last , 0 , sizeof last);
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i < 310 ; i++){
            adj[i].clear();
        }
        needed= 0;

        for(int i = 1 ; i <= n ; i++){
            cin >> v >> a >> b;
            cap[source][i] = v;
            adj[source].pb(i);
            vec.pb(pii(a , b));
            interval.pb(a);
            interval.pb(b);
            needed += v;
        }

        sort(interval.begin() , interval.end());

        for(int i = 0 ; i < vec.size() ; i++){
            for(int j = 1 ; j < interval.size() ; j++){
                if(interval[j - 1] >= vec[i].fi && interval[j] <= vec[i].se){
                    cap[i + 1][n + j] = interval[j] - interval[j - 1];
                    adj[i + 1].pb(n + j );
                    adj[n + j].pb(i + 1);
                }
            }
        }

        for(int i = 1 ; i < interval.size() ; i++){
            cap[i + n][destination] = m * (interval[i] - interval[i - 1]);
            adj[i + n].pb(destination);
        }

        int mxFlow = 0;
        int temp , other;
        while(true){
            temp = augmentation_path();
            if(temp == 0)
                break;
            mxFlow += temp;
        }
        if(mxFlow == needed){
            cout << "Case " << testcase << ": Yes\n" ;
            testcase++;
            for(int i = 1 ; i <= n ; i++){
                vec.clear();
                for(int j = 0 ; j < adj[i].size() ; j++){
                    other = adj[i][j];
                    if(flow[i][other] == 0)
                        continue;
                    if(flow[i][other] == cap[i][other]){
                        vec.pb(pii(interval[other - n - 1] , interval[other - n]));
                    }

                    else if(flow[i][other] <= cap[i][other] - last[other - n - 1]){
                        vec.pb(pii(interval[other - n - 1] + last[other - n - 1] , interval[other - n - 1] + last[other - n - 1] + flow[i][other]));
                        last[other - n - 1] += flow[i][other];
                        last[other - n - 1] %= (cap[i][other] + 1);
                    }

                    else{
                        vec.pb(pii(interval[other - n - 1] + last[other - n - 1] , interval[other - n]));
                        temp = flow[i][other] - (cap[i][other] - last[other - n - 1]);
                        vec.pb(pii(interval[other - n - 1] , interval[other - n - 1] + temp));
                        last[other - n - 1] = temp;
                        last[other - n - 1] %= (cap[i][other] + 1);
                    }

                }
                sort(vec.begin() , vec.end());
                vec_2.clear();
                vec_2.pb(vec[0]);
                int p = 0;
                for(int i = 1 ; i < vec.size() ; i++){
                    if(vec[i].fi == vec[i].se)
                        continue;
                    if(vec[i].fi == vec_2[p].se)
                        vec_2[p].se = vec[i].se;
                    else{
                        vec_2.pb(vec[i]);
                        p++;
                    }
                }

                cout << vec_2.size();
                for(int i = 0 ; i < vec_2.size() ; i++)
                    cout <<' ' << '(' << vec_2[i].fi <<',' << vec_2[i].se << ')' ;
                cout << endl;

            }


        }
        else{
            cout << "Case " << testcase << ": No\n" ;
            testcase++;
        }

    }

    return 0;
}
