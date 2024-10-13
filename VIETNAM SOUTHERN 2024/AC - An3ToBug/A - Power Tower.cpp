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

const int N = 1e2 + 5;
int n , q , m;
int f[N][N][N];
int a[N][N][N];


void up(int x , int y , int z , int val)
{
    for(int i = x ; i <= n ; i += i & -i)
        for(int j = y ; j <= n ; j += j & -j)
            for(int k = z ; k <= n ; k += k & -k)
                f[i][j][k] += val;
}

int get(int x1 , int y1 , int z1)
{
    int ret = 0;
    for(int i = x1 ; i ; i -= i & -i)
        for(int j = y1 ; j ; j -= j & -j)
            for(int k = z1 ; k ; k -= k & -k)
                ret += f[i][j][k];
    return ret;
}

int query(int x1 , int y1 , int z1 , int x2 , int y2 , int z2)
{
    return get(x2 , y2 , z2)
        -  get(x1 - 1 , y2 , z2)
        -  get(x2 , y1 - 1 , z2)
        -  get(x2 , y2 , z1 - 1)
        +  get(x1 - 1 , y1 - 1 , z2)
        +  get(x1 - 1 , y2 , z1 - 1)
        +  get(x2 , y1 - 1 , z1 - 1)
        -  get(x1 - 1 , y1 - 1 , z1 - 1);
}

main()
{
    srand(time(0));
    //freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n >> m;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                for(int k = 1 ; k <= n ; k++)
                    f[i][j][k] = 0 , a[i][j][k] = 0;


        while(m--)
        {
            string s;
            cin >> s;
            if(s[0] == 'U')
            {
                int x , y , z , k;
                cin >> x >> y >> z >> k;
                up(x , y , z , -a[x][y][z]);
                a[x][y][z] = k;
                up(x , y , z , a[x][y][z]);
            }
            else
            {
                int x1 , y1 , z1 , x2 , y2 , z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << query(x1 , y1 , z1 , x2 , y2 , z2) << "\n";
            }
        }
    }
}



