#include <bits/stdc++.h>
using namespace std;
int D[105][105], G[16][16], dp[1 << 16][16];
int R, C, N, F[105][105], Z, k;
const int Dx[4] = {-1, 0, 1, 0};
const int Dy[4] = {0, 1, 0, -1};
pair <int, int> S[16];
bool ins (int a, int b) {
    return (a >= 1 && a <= R && b >= 1 && b <= C);
}
int LenPath (int a, int b, int c, int d) {
    queue <pair <int, int> > Q;
    Q.push({a, b});
    memset(D, 0x7f, sizeof D);
    D[a][b] = 0;
    bool flag = 1;
    while (Q.size()) {
        int x, y;
        x = Q.front().first; y = Q.front().second; Q.pop();
        if (x == c && y == d) flag = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + Dx[dir], ny = y + Dy[dir];
            if (!ins(nx, ny) || F[nx][ny]) continue;
            if (D[nx][ny] > D[x][y] + 1) {
                D[nx][ny] = D[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    if (flag) return -1;
    else return D[c][d];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> R >> C >> N;
    S[0] = {1, 1};
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            char c;
            cin >> c;
            if (c == 'S') S[++k] = {i, j};
            F[i][j] = (c == '#');
        }
    for (int i = 1; i <= N; i++) {
        G[0][i] = G[i][0] = LenPath(1, 1, S[i].first, S[i].second);
        for (int j = i + 1; j <= N; j++)
            G[i][j] = G[j][i] = LenPath(S[i].first, S[i].second, S[j].first, S[j].second);
    }

    for (int i = 0; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            if (G[i][j] == -1) return cout << -1, 0;
        }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i <= N; i++) dp[(1 << i)][i] = G[0][i], dp[0][i] = 0;

    for (int mask = 0; mask < (1 << (N + 1)); mask++) {
        for (int i = 0; i <= N; i++)
        if ((mask >> i) & 1)  {
            for (int j = 0; j <= N; j++) {
                if (j == i) continue;
                if ((mask >> j) & 1) dp[mask][j] = min(dp[mask][j], dp[mask ^ (1 << j)][i] + G[i][j]);
            }
        }
    }

    int F = (1 << (N + 1)) - 1;
    cout << *min_element(dp[F], dp[F] + N + 1);
    return 0;
}