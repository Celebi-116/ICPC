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
string s;
int n , ans = 0 , mod = 1e9 + 7;
set < int > st;
int f[N] , pre[N];
int sum;
map < int , int > mp;
int cnt[N];

mt19937_64 rd(time(0));
int rand(int l , int r)
{
    return uniform_int_distribution < int > (l , r)(rd);
}

main()
{
    srand(time(0));
//    freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    cin >> s;
    for(auto v: s)
        st.insert(v);

    s = " " + s;

    for(auto v: st)
    {
        int x = rand(1 , 5e13);
        //cout << x << endl;
        f[v] = x;
        //cout << v << " " << f[v] << endl;
        sum += x;
    }

    sum -= f[*st.begin()];
    f[*st.begin()] = -sum;

    int ans = 0;
    mp[pre[0]] = 1;


    for(int i = 1 ; i <= n ; i++)
    {
        pre[i] = pre[i - 1] + f[s[i]];
        ans += mp[pre[i]];
        mp[pre[i]]++;
    }
    cout << ans % mod;

}



