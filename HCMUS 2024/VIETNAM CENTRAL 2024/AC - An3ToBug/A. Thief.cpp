#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define REPD(i, b, a) for(int i = b; i >= a; i--)
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int n,W,H;
const int N = 105;
const int M = 100000;
const int INFF = 1e18;
#define fi first
#define se second
int w[N],c[N];
int dp[N+5][M+5][2];
main(){
    cin >> n >> W >> H;
    REP(i, 1, n)
    cin >> w[i] >> c[i];
    REP(i, 0, n)
    REP(j, 0, M)
    REP(k, 0, 1)
    dp[i][j][k] = INFF;
    dp[0][0][0] = 0;
    REP(i, 1, n)
    REP(j, 0, M){
        dp[i][j][0] = dp[i-1][j][0];
        dp[i][j][1] = dp[i-1][j][1];
        REP(k, 0, 1)
        if(j >= c[i])
        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-c[i]][k] + w[i]);
        if(w[i] <= H && j >= c[i])
        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-c[i]][0]);
    }
    int ans = 0;
    REP(i, 1, n)
    REP(j, 0, M)
    REP(k, 0, 1){
        if(dp[i][j][k] <= W)
            ans = max(ans, j);
    }
    cout << ans;
}
