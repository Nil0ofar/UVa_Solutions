#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define fi first
#define se second
#define ll long long
#define pii pair<ll , ll>
#define pli pair<ll, int >
#define pb push_back
#define N 200005

struct Hier{
    int x , y ;
    int cnt;
    int v;

    Hier(int _x , int _y , int _v){
        x = _x;
        y = _y;
        v = _v;
        cnt = 0;
    }
};

vector<Hier> vec;
int mat[205][205];
int idx_x[] = {0 , 0 , 1 , -1};
int idx_y[] = {1 , -1 , 0 , 0};
int h , w;

void set_hier(int idx , int x , int y){
    int xo , yo;
    mat[x][y] = vec[idx].v;

    for(int i = 0 ; i < 4 ; i++){
        xo = x + idx_x[i];
        yo = y + idx_y[i];

        if(xo >= h || xo < 0 || yo >= w || yo < 0)
            continue;

        if(mat[xo][yo] == 1)
            set_hier(idx , xo , yo);
    }
}

bool fill_space(int x , int y , int idx){
    mat[x][y] = -1;
    bool flag = true;

    int xo , yo;

    for(int i =  0 ; i < 4 ; i++){
        xo = x + idx_x[i];
        yo = y + idx_y[i];
        if(xo >= h || xo < 0 || yo >= w || yo < 0){
            flag = false;
            continue;
        }

        if(mat[xo][yo] == 0)
            flag &= fill_space(xo , yo , idx);

        else if(abs(mat[xo][yo]) == vec[idx].v){
            continue;
        }

        else if(mat[xo][yo] != -1)
            flag = false;

    }

    return flag;
}

void f(int x , int y , int idx){
    int xo , yo;
    mat[x][y] *= -1;

    for(int i = 0 ; i < 4 ; i++){
        xo = x + idx_x[i];
        yo = y + idx_y[i];

        if(xo >= h || xo < 0 || yo >= w || yo < 0)
            continue;

        if(mat[xo][yo] == 0){
            if(fill_space(xo , yo , idx)){
                vec[idx].cnt++;
            }
        }

        else if(mat[xo][yo] == vec[idx].v)
            f(xo , yo , idx);
    }
}



int main(){
    ios_base :: sync_with_stdio(false);
    string s;
    int n ;
    int testcase = 1;
    vector<char> ans;
    int x;

    while(cin >> h >> w){
        if(w == 0 && h == 0)
            break;

        memset(mat , 0 , sizeof mat);

        for(int i = 0 ; i < h ; i++){
            cin >> s;
            for(int j = 0 ; j < w ; j++){
                if(s[j] <= '9' && s[j] >= '0')
                    x = s[j] - '0';
                else
                    x = 10 + (s[j] - 'a');

                for(int k = 3 ; k >= 0 ; k--){
                    if((x & (1 << k)) != 0)
                        mat[i][j * 4 + 3 - k] = 1;
                }
            }
        }



        w *= 4;
        vec.clear();
        int cnt = 3;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(mat[i][j] == 1){
                    Hier hier(i , j , cnt);
                    cnt++;
                    vec.pb(hier);
                    set_hier((int)vec.size() - 1 , i , j );
                }
            }
        }


        n = vec.size();
        ans.clear();

        for(int i = 0 ; i < n ; i++){
            f(vec[i].x , vec[i].y , i);

            switch(vec[i].cnt){
                case 1 :
                    ans.pb('A');
                    break;
                case 2 :
                    ans.pb('K');
                    break;
                case 3 :
                    ans.pb('J');
                    break;
                case 4 :
                    ans.pb('S');
                    break;
                case 5 :
                    ans.pb('D');
                    break;
                case 0 :
                    ans.pb('W');
                    break;
            }

           // cout << ans[ans.size() - 1] << endl;
        }

        /*for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++)
                cout << mat[i][j] ;
            cout << endl;
        }
        cout << endl;*/
        sort(ans.begin() , ans.end());
        cout << "Case " << testcase++ << ": ";
        for(int i = 0 ; i < n ; i++)
            cout << ans[i];
        cout << endl;

    }
    return 0;
}
