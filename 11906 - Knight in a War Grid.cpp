#include<bits/stdc++.h>

using namespace std;

#define N 105
#define INF 100000000000000
#define fi first
#define se second
#define pii pair<int , int>
#define ll long long
#define pli pair<ll, int >
#define pb push_back

bool mat[N][N];
bool mark[N][N];
int R , C , n , m;
int even , odd;
int idx_x[] = {1 , 1 , -1 , -1};
int idx_y[] = {1 , -1 , -1 , 1};

void f(){
    mark[0][0] = true;
    queue<pii> q;
    q.push(pii(0 , 0));
    int x, y ,xo , yo;
    int temp;
    even = odd = 0;
    set<pii> st;
    if(mat[0][0] == false)
        return;

    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        q.pop();
        int xo , yo;
        st.clear();
        for(int i = 0 ; i < 4 ; i++){
            xo = x + idx_x[i] * m;
            yo = y + idx_y[i] * n;

            if(xo >= R || xo < 0 || yo >= C || yo < 0)
                continue;

            if(!mat[xo][yo])
                continue;
            st.insert(pii(xo , yo));

            if(mark[xo][yo] == false){
                mark[xo][yo] = true;
                q.push(pii(xo , yo));
            }
        }


        for(int i = 0 ; i < 4 ; i++){
            xo = x + idx_x[i] * n;
            yo = y + idx_y[i] * m;

            if(xo >= R || xo < 0 || yo >= C || yo < 0)
                continue;

            if(!mat[xo][yo])
                continue;

            st.insert(pii(xo, yo));

            if(mark[xo][yo] == false){
                mark[xo][yo] = true;
                q.push(pii(xo , yo));
            }
        }

        temp = st.size();
        if(temp % 2 == 0)
            even++;
        else
            odd++;
    }
}

int main(){
    int testcase;
    cin >> testcase;
    int w , x , y ;

    for(int t = 1 ; t <= testcase ; t++){
        cin >> R >> C >> m >> n ;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                mat[i][j] = true;
                mark[i][j] = false;
            }
        }

        cin >> w;
        while(w--){
            cin >> x >> y ;
            mat[x][y] = false;
        }

        f();

        cout << "Case " << t << ": " << even << ' ' << odd << endl;
    }
}
