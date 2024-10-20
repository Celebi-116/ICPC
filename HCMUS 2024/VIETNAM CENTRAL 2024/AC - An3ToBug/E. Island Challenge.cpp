//http://ntucoder.net/Problem/Details/5626
#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define pp pop_back()

#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 999999999
#define Nga cute

const int N = 1e2 + 5;
int n , m , x , y , res;
int a[N];
int dist[N][N] , dp[(1 << 17) + 5][17] , b[N][N];
char f[N][N];
vector < ii > g;
int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};

void BFS(int i , int j)
{
    queue < ii > q;
    q.push(ii(i , j));
    memset(b , 0x3f , sizeof(b));
    b[i][j] = 0;
    while(!q.empty())
    {
        int x = q.fr.fi;
        int y = q.fr.se;
        q.pop();
        REP(s , 4)
        {
            int u = x + dx[s];
            int v = y + dy[s];
            if(u >= 1 && u <= n && v >= 1 && v <= m && f[u][v] != '#' && b[u][v] > 1e7)
            {
                b[u][v] = b[x][y] + 1;
                q.push(ii(u , v));
            }
        }
    }
}

int main()
{
    //freopen("dibotrencay.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    memset(dp , 0x3f , sizeof(dp));
    memset(dist , 0x3f , sizeof(dist));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            b[i][j]=1e7+10;
        }
    }
    res = oo;
    g.clear();
    FOR(i , 1 , n)
        FOR(j , 1 , m)
        {
            cin >> f[i][j];
            if(i == 1 && j == 1)
                x = i , y = j;
            else if(f[i][j] == 'S')
                 g.pb(ii(i , j));
        }
    REP(s , g.size())
    {
        BFS(g[s].fi , g[s].se);
        REP(k , g.size())
            dist[s][k] = b[g[k].fi][g[k].se];
    }
    BFS(x  , y);
    int lim = (1 << g.size());
    REP(i , g.size())
        dp[(1 << i)][i] = b[g[i].fi][g[i].se];// cout << dp[(1 << i)][i] << endl;


    REP(i , lim)
    {
        int k = i;
        int r = 0;
        int cnt = 0;
        while(k != 0)
        {
            if(k & 1)
                a[r++] = cnt;
            cnt++;
            k = (k >> 1);
        }
        REP(s1 , r)
        {
            int j = a[s1];
            int x = i ^ (1 << j);
            REP(s2 , r)
                if(s1 != s2)
                {
                    int k = a[s2];
                    dp[i][j] = min(dp[i][j] , dp[x][k] + dist[k][j]);
                }
        }
    }
    REP(i , g.size())
        res = min(res , dp[(1 << g.size()) - 1][i]);
    if(res > 1e7)
        cout << "-1" << "\n";
    else
        cout << res << "\n";
}
