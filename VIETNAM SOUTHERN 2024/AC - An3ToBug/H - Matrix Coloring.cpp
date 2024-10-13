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

const int N = 1e3 + 5;
const int M = (1 << 10) + 5;
int n , m;
char a[N][15];
int f[M] , num[M];
int dp[N][M] , g[N][M];

main()
{
    srand(time(0));
    //freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> a[i][j];

    for(int j = 0 ; j < (1 << m) ; j++)
    {
        int cur = 0;
        int pre = 1;
        for(int k = 0 ; k < m ; k++)
        {
            if((j >> k) & 1)
            {
                cur += pre;
                pre = 0;
            }
            else
                pre = 1;
        }
        f[j] = cur;
        num[j] = __builtin_popcount(j);
    }

    int ans = 1e9;

    for(int i = 1 ; i < (1 << m) ; i++)
        dp[0][i] = 1e9 , g[0][i] = 1e9;

     for(int mask = 0 ; mask < (1 << m) ; mask++)
            for(int submask = mask ; ; submask = (submask - 1) & mask)
            {
                g[0][submask] = min(g[0][submask] , dp[0][mask]);
                if(submask == 0)
                    break;
            }



    for(int i = 1 ; i <= n ; i++)
    {
        int mask = 0;
        for(int j = 1 ; j <= m ; j++)
            if(a[i][j] == '#')
                mask += (1 << (j - 1));

        for(int j = 0 ; j < (1 << m) ; j++)
            dp[i][j] = 1e9 , g[i][j] = 1e9;

        for(int submask = mask ; ; submask = (submask - 1) & mask)
        {
            int miss = mask ^ submask;
            for(int submask2 = submask ; ; submask2 = (submask2 - 1) & submask)
            {
                //cout << mask << " " << submask << " " << submask2 << " " << miss << " " << num[submask2 ^ submask] << " " << f[miss] << endl;
                dp[i][submask] = min(dp[i][submask] , g[i - 1][submask2] + num[submask2 ^ submask] + f[miss]);
                if(submask2 == 0)
                    break;
            }



            //cout << i << " " << submask << " " << dp[i][submask] << endl;
            if(i == n)
                ans = min(dp[i][submask] , ans);
            g[i][mask] = dp[i][mask];
            if(submask == 0)
                break;
        }


        for(int mask = 0 ; mask < (1 << m) ; mask++)
            for(int submask = mask ; ; submask = (submask - 1) & mask)
            {
                g[i][submask] = min(g[i][submask] , dp[i][mask]);
                if(submask == 0)
                    break;
            }

    }
    cout << ans;

}



