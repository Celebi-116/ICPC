#include <bits/stdc++.h>
using namespace std;
int n, W, H, w[101], c[101], S;
long long dp[100001][2];
bool pre, cur;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> W >> H;
    memset(dp, 0x7f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i], S += c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = S; j >= c[i]; j--)
        for (int f = 0; f <= 1; f++) {
            if (f == 1) {
                dp[j][f] = min(dp[j][f], dp[j - c[i]][f] + w[i]);
            }
            else {
                dp[j][f] = min(dp[j][f], dp[j - c[i]][f] + w[i]);
                if (w[i] <= H) dp[j][1] = min(dp[j][1], dp[j - c[i]][f]);
            }
        }
    }
    for (int x = S; x >= 0; x--)
        if (dp[x][0] <= W || dp[x][1] <= W) {
            return cout << x, 0;
        }
    return 0;
}
