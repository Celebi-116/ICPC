#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i , x , n) for(int i = x ; i <= n ; i++)
#define REP(i , x) for(int i = 0 ; i < x ; i++)
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define visit asdasd

const int N = 1e6 + 5;
int n , p , m;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
iii x[N];
char type[N];
int k[N];
ii ans[N];

void update(int p)
{
    int u = 0 , v = 0 , cur = p;
    int mv_x = -1 , mv_y = -1;
    for(int i = 1 ; i <= m ; i++)
    {
        if(type[i] == 'A')
        {
            u += dx[cur] * k[i];
            v += dy[cur] * k[i];
        }
        else if(type[i] == 'R')
        {
            cur = (cur + k[i]) % 4;
        }
        else
        {
            mv_x = k[i] / n;
            mv_y = k[i] % n;

            u = 0;
            v = 0;
        }
        //cout << u << " " << v << endl;
    }
    for(int i = 1 ; i <= m ; i++)
        if(x[i].fi == p)
        {
            if(mv_x != -1 && mv_y != -1)
                x[i].second.first = mv_x , x[i].second.second = mv_y;

            ans[i] = {((x[i].second.first + u) % n + n) % n ,
                      ((x[i].second.second + v) % n + n) % n};
        }
    //exit(0);

}

main()
{
    srand(time(0));
    //freopen("A.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> m;

    for(int i = 1 ; i <= p ; i++)
    {
        cin >> x[i].se.fi >> x[i].se.se >> x[i].fi;
        x[i].fi--;
    }


    for(int i = 1 ; i <= m ; i++)
        cin >> type[i] >> k[i];

    for(int i = 0 ; i <= 3 ; i++)
        update(i);

    for(int i = 1 ; i <= p ; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}




