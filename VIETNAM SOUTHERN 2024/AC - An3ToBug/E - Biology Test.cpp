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
int n , q;
vector < int > g[N];
bool visit[N];

void DFS(int x)
{
    visit[x] = true;
    for(auto v: g[x])
        DFS(v);
}

main()
{
    //freopen("A.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n - 1)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    cin >> q;
    while(q--)
    {
        int x , y;
        cin >> x >> y;
        memset(visit , false , sizeof(visit));
        DFS(x);
        if(visit[y] == true)
           cout << "Yes\n";
        else
            cout << "No\n";

    }
}
