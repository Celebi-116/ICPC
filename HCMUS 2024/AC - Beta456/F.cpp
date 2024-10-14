#include <bits/stdc++.h>
using namespace std;
const int MAX = 1E6 + 16;
int u, v, F[2005];
void query () {
    int n, m;
    bool flag = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) F[i] = -1;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (F[u] == -1 && F[v] == -1) {
            F[u] = 0;
            F[v] = !F[u];
        }
        else if (F[u] == -1) F[u] = !F[v];
        else if (F[v] == -1) F[v] = !F[u];
        else if (F[u] == F[v]) flag = 1;
    }
    if (flag == 1) cout << "Suspicious bugs found!\n";
    else cout << "No suspicious bugs found!\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Scenario #" << i << ":\n";
        query();
    }
    return 0;
}
/*
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
*/
