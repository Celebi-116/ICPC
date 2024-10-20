#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 15;
int n, q, P[N][27], D[N];
vector <int> E[N];
const string ans[2] = {"NO\n", "YES\n"};
void DFS (int u, int p = -1) {
    for (int i = 0, v = E[u][i]; i < E[u].size(); i++, v = E[u][i]) {
        if (v != p) {
            P[v][0] = u;
            D[v] = D[u] + 1;
            for (int i = 1; i <= __lg(n); i++) P[v][i] = P[P[v][i - 1]][i - 1];
            DFS(v, u);
        }
    }
}
int LCA (int x, int y) {
    if (D[x] < D[y]) swap(x, y);
    int H = D[x] - D[y];
    for (int i = __lg(n); i >= 0; i--)
        if ((H >> i) & 1) x = P[x][i];
    if (x == y) return x;
    for (int i = __lg(n); i >= 0; i--)
        if (P[x][i] != P[y][i]) x = P[x][i], y = P[y][i];
    return P[x][0];
}
int Len (int x, int y) {
    return D[x] + D[y] - 2 * D[LCA(x, y)];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    DFS(1);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << ans[Len(x, y) + Len(y, z) == Len(x, z)];
    }
    return 0;
}
