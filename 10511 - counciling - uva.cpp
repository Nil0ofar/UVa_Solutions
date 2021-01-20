#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int , int>
#define pib pair<int , bool>
#define pll pair<long long , long long>
#define fi first
#define se second
#define N 3005
#define mod 998244353
#define MAX 1000000

int source = 0 , destination;
vector<int> adj[N];
int cap[N][N];
int flow[N][N];
bool mark[N];
int par[N];

void update_flow(){
    int node = destination;
    int p;
    while(node != source){
        p = par[node];
        flow[p][node] += 1;
        flow[node][p] -= 1;
        node = p;
    }
}

bool augmentation_path(){
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
            if(mark[other] == false && cap[node][other] > flow[node][other]){
                mark[other] = true;
                par[other] = node;
                if(other == destination){
                    update_flow();
                    return true;
                }
                q.push(other);
            }
        }
    }
    return false;
}


int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    string s;
    getline(cin , s);
    stringstream st(s);
    st >> testcase;
    getline(cin , s);

    string names[N];
    map<string , int> mp_res , mp_club , mp_party;
    int res_id , party_id , club_id;
    int club_num , temp;
    vector<int> p;
    vector<int> c;
    int node , other;
    bool flag = true;

    while(testcase--){
        node = 1 ;
        club_num = 0;
        mp_res.clear();
        mp_party.clear();
        mp_club.clear();
        flag = true;
        memset(cap , 0 , sizeof cap);
        memset(flow , 0 , sizeof flow);
        for(int i = 0 ; i < N ; i++)
            adj[i].clear();
        p.clear();
        c.clear();

        while(getline(cin , s) && s != ""){
            if(flag == false)
                continue;

            stringstream ss(s);
            ss >> s;
            mp_res[s] = node;
            names[node] = s;
            res_id = node++;

            ss >> s;
            if(mp_party[s] == 0){
                mp_party[s] = node;
                names[node] = s;
                p.pb(node);
                party_id = node++;
            }
            else
                party_id = mp_party[s];

            adj[res_id].pb(party_id);
            adj[party_id].pb(res_id);
            cap[res_id][party_id] = 1;

            while(ss >> s){
                if(mp_club[s] == 0){
                    mp_club[s] = node;
                    club_id = node;
                    names[node] = s;
                    c.pb(node);
                    node++;
                    club_num++;
                    if(club_num > 1000)
                        flag = false;
                }
                else
                    club_id = mp_club[s];

                if(!flag)
                    continue;

                adj[source].pb(club_id);
                cap[source][club_id] = 1;
                adj[club_id].pb(res_id);
                adj[res_id].pb(club_id);
                cap[club_id][res_id] = 1;

            }
        }

        if(!flag){
            cout << "Impossible.\n" ;
            if(testcase != 0)
                cout << endl;
            continue;
        }

        destination = node++;
        temp = (club_num - 1) / 2;
        for(int i = 0 ; i < (int)p.size() ; i++){
            adj[destination].pb(p[i]);
            adj[p[i]].pb(destination);
            cap[p[i]][destination] = temp;
        }

        int maxFlow = 0;

        while(augmentation_path())
            maxFlow++;

        if(maxFlow == club_num){
            for(int i = 0 ; i < (int)c.size() ; i++){
                node = c[i];
                for(int j = 0 ; j < adj[node].size() ; j++){
                    other = adj[node][j];
                    if(flow[node][other] == 1){
                        cout << names[other] <<' ' << names[node] << endl;
                        break;
                    }
                }
            }
        }
        else{
            cout << "Impossible.\n" ;
        }

        if(testcase != 0){
            cout << endl;
        }

    }
    return 0;
}
