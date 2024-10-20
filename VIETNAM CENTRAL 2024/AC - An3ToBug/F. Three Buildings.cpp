//https://vn.spoj.com/problems/NKFLOW/
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
#define t top()

#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 999999999
#define Nga cute

const int N = 2e4 + 5;
int n , m , source , sink , q;
int work[N] , dist[N] , cnt[N] , f[N];

struct edge
{
    int to , rev;
    int flow , cap;
};

vector < edge > g[N];

void addedge(int u , int v , int cap)
{
    edge a = {v , g[v].size() , 0 , cap};
    edge b = {u , g[u].size() , 0 , 0};
    g[u].pb(a);
    g[v].pb(b);
}

bool BFS()
{
    queue < int > q;
    memset(dist , -1 , sizeof(dist));
    q.push(source);
    dist[source] = 0;
    while(!q.empty())
    {
        int u = q.fr;
        q.pop();
        REP(s , g[u].size())
        {
            edge e = g[u][s];
            int v = e.to;
            if(dist[v] < 0 && e.flow < e.cap)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[sink] > 0;
}

int DFS(int u , int f)
{
    if(u == sink)
        return f;
    for(int s = 0 ; s < g[u].size() ; s++)
    {
        edge &e = g[u][s];
        int v = e.to;
        if(dist[v] == dist[u] + 1 && e.flow < e.cap)
        {
            int df = DFS(v , min(f , e.cap - e.flow));
            if(df > 0)
            {
                e.flow += df;
                g[v][e.rev].flow -= df;
                return df;
            }
        }
    }
    return 0;
}

void solve()
{
    int res = 0;
    while(BFS())
    {
        memset(work , 0 , sizeof(work));
        while(int del = DFS(source , oo))
            res += del;
    }
    cout << res << "\n";
}

int main()
{
    //freopen("dibotrencay.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        int m = n;

        n = 8;
        source = 0;
        sink = 4 + n;

        FOR(i , 0 , 7)
        {
            for(int j = 0 ; j < 3 ; j++)
                if((i >> j) & 1)
                    addedge(i + 1 , n + j + 1 , 100000);
        }


        FOR(i , 1 , 3)
        {
            int x;
            cin >> x;
            addedge(n + i , sink , x);
        }
        FOR(i , 1 , 3)
        {
            int x;
            cin >> x;
            FOR(j , 1 , x)
            {
                int k;
                cin >> k;
                f[k] |= (1 << (i - 1));
//                addedge(k , n + i , 1);
            }
        }

        FOR(i , 1 , m)
            cnt[f[i]]++;

        FOR(i , 1 , 8)
            addedge(source , i , cnt[i - 1]);


        solve();
        FOR(i , source , sink)
            g[i].clear() , cnt[i] = 0;

        FOR(i , 1 , m)
            f[i] = 0;
    }
}
