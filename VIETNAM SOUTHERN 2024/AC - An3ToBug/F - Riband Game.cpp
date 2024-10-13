#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n , m , C , len , nen;
int mini[4 * N] , maxi[4 * N] , lazy[4 * N];
int l[N] , r[N] , c[N];
map < int , int > mp;
int mx[N];

void down(int id)
{
    if(lazy[id] != -1)
    {
        int x = lazy[id];
        mini[id * 2] = x;
        maxi[id * 2] = x;
        lazy[id * 2] = x;

        mini[id * 2 + 1] = x;
        maxi[id * 2 + 1] = x;
        lazy[id * 2 + 1] = x;
        lazy[id] = -1;
    }
}

void update(int id , int l , int r , int u , int v , int val)
{
    if(l > v || r < u)
        return;
    if(l >= u && r <= v)
    {
        mini[id] = val;
        maxi[id] = val;
        lazy[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(id * 2 , l , mid , u , v , val);
    update(id * 2 + 1 , mid + 1 , r , u , v , val);
    mini[id] = min(mini[id * 2] , mini[id * 2 + 1]);
    maxi[id] = max(maxi[id * 2] , maxi[id * 2 + 1]);
}

int get_maxi(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return -1e9;
    else if(l >= u && r <= v)
        return maxi[id];
    int mid = (l + r) / 2;
    down(id);
    return max(get_maxi(id * 2 , l , mid , u , v),
               get_maxi(id * 2 + 1 , mid + 1 , r , u , v));
}

int get_mini(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return 1e9;
    else if(l >= u && r <= v)
        return mini[id];
    int mid = (l + r) / 2;
    down(id);
    return min(get_mini(id * 2 , l , mid , u , v),
               get_mini(id * 2 + 1 , mid + 1 , r , u , v));
}

main()
{
    srand(time(0));
    //freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C;

    cin >> n >> m >> len;


    for(int i = 1 ; i <= 2 * m ; i++)
    {
        cin >> l[i];
        r[i] = l[i] + len - 1;
        mp[l[i]] = 1;
        mp[l[i] - 1] = 1;
        mp[r[i]] = 1;
        mp[r[i] + 1] = 1;

    }

    for(auto v: mp)
    {
        mp[v.first] = ++nen;
        mx[nen] = v.first;
    }

    memset(lazy , -1 , sizeof(lazy));
    update(1 , 1 , nen , 1 , nen , 1);

    int L1 = 0 , L2 = 0;
    for(int i = 1 ; i <= 2 * m ; i++)
    {
        if(r[i] < n)
        {
            if(i % 2 == 1)
            {
                int L = mp[l[i]];
                if(mp[l[i] - 1] != 0)
                    L--;

                int R = mp[r[i]];
                if(mp[r[i] + 1] != 0)
                    R++;

                if(get_maxi(1 , 1 , nen , L , R) == 2)
                    L1++;
                else
                {
                    update(1 , 1 , nen , mp[l[i]] , mp[r[i]] , 0);

//                    c[mp[l[i]]] += 1;
//                    c[mp[r[i] + 1]] -= 1;
                }
            }
            else
            {
                int L = mp[l[i]];
                if(mp[l[i] - 1] != 0)
                    L--;

                int R = mp[r[i]];
                if(mp[r[i] + 1] != 0)
                    R++;

                if(get_mini(1 , 1 , nen , L , R) == 0)
                    L2++;
                else
                {
                    update(1 , 1 , nen , mp[l[i]] , mp[r[i]] , 2);
//                    c[mp[l[i]]] += 1;
//                    c[mp[r[i] + 1]] -= 1;
                }
            }
        }
        else
        {
            if(i % 2 == 1)
                L1++;
            else
                L2++;
        }
    }

    int P1 = 0 , P2 = 0;
    int cur_1 , cur_2 = 0;
    for(int i = 1 ; i <= nen ; i++)
    {
        if(get_mini(1 , 1 , nen , i , i) == 0)
        {
            cur_1 = i;
            int sum = c[cur_1];
            while(i <= nen && get_mini(1 , 1 , nen , i + 1 , i + 1) == 0)
                i++;
            P1 = max(P1 , mx[i] - mx[cur_1] + 1);
        }

        if(get_maxi(1 , 1 , nen , i , i) == 2)
        {
            cur_2 = i;
            int sum = c[cur_2];
            while(i <= nen && get_maxi(1 , 1 , nen , i + 1 , i + 1) == 2)
                i++;
            P2 = max(P2 , mx[i] - mx[cur_2] + 1);
        }
    }


    if(C == 1)
        cout << L1 << " " << L2 << endl;
    else
        cout << P1 << " " << P2 << endl;



}



