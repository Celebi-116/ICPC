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

const int N = 2e5 + 5;
int n , q;
int a[N];
int st_1[4 * N] , st_2[4 * N] , lazy[4 * N] , maxi[4 * N];
set < int > p;


void down(int id , int l , int r , int mid)
{
    if(lazy[id] != 0)
    {
        int x = lazy[id];
        lazy[id * 2] = x;
        st_2[id * 2] = x * (mid - l + 1);


        lazy[id * 2 + 1] = x;
        st_2[id * 2 + 1] = x * (r - mid);

        lazy[id] = 0;
    }
}


void update_1(int id , int l , int r , int pos , int k)
{
    if(l > pos || r < pos)
        return;
    if(l == r)
    {
        st_1[id] = k;
        maxi[id] = k;
        return;
    }
    int mid = (l + r) / 2;
    update_1(id * 2 , l , mid , pos , k);
    update_1(id * 2 + 1 , mid + 1 , r , pos , k);
    st_1[id] = st_1[id * 2] + st_1[id * 2 + 1];
    maxi[id] = max(maxi[id * 2] , maxi[id * 2 + 1]);
}


void update_2(int id , int l , int r , int u , int v , int k)
{
    if(l > v || r < u)
        return;
    if(l >= u && r <= v)
    {
        st_2[id] = k * (r - l + 1);
        lazy[id] = k;
        return;
    }
    int mid = (l + r) / 2;
    down(id , l , r , mid);
    update_2(id * 2 , l , mid , u , v , k);
    update_2(id * 2 + 1 , mid + 1 , r , u , v , k);
    st_2[id] = st_2[id * 2] + st_2[id * 2 + 1];
}


int get_2(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return 0;
    if(l >= u && r <= v)
        return st_2[id];
    int mid = (l + r) / 2;
    down(id , l , r , mid);
    return get_2(id * 2 , l , mid , u , v)
        +  get_2(id * 2 + 1 , mid + 1 , r , u , v);

}

int get_1(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return 0;
    if(l >= u && r <= v)
        return st_1[id];
    int mid = (l + r) / 2;
    return get_1(id * 2 , l , mid , u , v)
        +  get_1(id * 2 + 1 , mid + 1 , r , u , v);

}



int walk_left(int id , int l , int r , int u , int v , int k)
{
    /// pos phải nhất [1,n] f[pos] <= k
    if(l > v || r < u || maxi[id] <= k)
        return -1;

    if(l == r)
        return l;

    int mid = (l + r) / 2;

    int ret = walk_left(id * 2  , l , mid , u , v , k);

    if(ret == -1)
        ret = walk_left(id * 2  + 1 , mid + 1 , r , u , v , k);
    return ret;

}


void paint(int u)
{
    auto it = p.lower_bound(u);
    p.insert(u);

    int r = *(it) - 1;

    while(u <= r)
    {
        int x = walk_left(1 , 1 , n , u + 1 , r , a[u]);

        if(x != -1)
        {
            update_2(1 , 1 , n , u , x - 1 , a[u]);
            u = x;
        }
        else
        {
            update_2(1 , 1 , n , u , r , a[u]);
            u = r + 1;
        }
    }
}

void change(int u , int x)
{
    int l = *(--p.upper_bound(u));
    int r = *(p.upper_bound(u)) - 1;
    a[u] = x;
    update_1(1 , 1 , n , u , a[u]);

    //cout << l << " " << r << " " << get_1(1 , 1 , n , u , u) << endl;
    u = l;
    while(u <= r)
    {
        int x = walk_left(1 , 1 , n , u + 1 , r , a[u]);

        if(x != -1)
        {
            update_2(1 , 1 , n , u , x - 1 , a[u]);
            u = x;
        }
        else
        {
            update_2(1 , 1 , n , u , r , a[u]);
            u = r + 1;
        }
    }

}

int solve(int x , int y)
{
    int u = x;
    int r = min(*(p.upper_bound(u)) - 1 , y);

    int ans = 0;
    while(u <= r)
    {
        int x = walk_left(1 , 1 , n , u + 1 , r , a[u]);

        if(x != -1)
        {
            ans += a[u] * ((x - 1) - u + 1) - get_1(1 , 1 , n , u , x - 1);
            u = x;
        }
        else
        {
            ans += a[u] * (r - u + 1) - get_1(1 , 1 , n , u , r);
            u = r + 1;
        }
    }

    if(u > y)
        return ans;


    r = *(--p.upper_bound(y));


    if(r != u)
    {
        ans -= get_1(1 , 1 , n , u , r - 1);
        ans += get_2(1 , 1 , n , u , r - 1);

        u = r;
    }


    r = y;

    while(u <= r)
    {
        int x = walk_left(1 , 1 , n , u + 1 , r , a[u]);
        //cout << x << " " << u << endl;
        if(x != -1)
        {
            ans += a[u] * ((x - 1) - u + 1) - get_1(1 , 1 , n , u , x - 1);
            u = x;
        }
        else
        {
            ans += a[u] * (r - u + 1) - get_1(1 , 1 , n , u , r);
            u = r + 1;
        }
    }
    return ans;

}

int main()
{
    ///freopen("dibotrencay.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    p.insert(n + 1);
    FOR(i , 1 , n)
    {
        cin >> a[i];
        update_1(1 , 1 , n , i , a[i]);
    }

    paint(1);
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 3)
        {
            int l , r;
            cin >> l >> r;
            cout << solve(l , r) << "\n";
        }
        else if(type == 2)
        {
            int u;
            cin >> u;
            paint(u + 1);
        }
        else
        {
            int u , x;
            cin >> u >> x;
            change(u , x);
        }
    }
}
