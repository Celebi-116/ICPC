#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define REPD(i, b, a) for(int i = b; i >= a; i--)
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int main(){
    int m,n;
    cin >> m >> n;
    int p,q;
    cin >> p >> q;
    int cnt = 0;
    REP(i, 0, 7){
        int xi = p + dx[i];
        int yi = q + dy[i];
        if(xi >= 1 && xi <= m && yi >= 1 && yi <= n)
            cnt++;
    }
    cout << cnt;
    return 0;
}
