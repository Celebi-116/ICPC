#include <bits/stdc++.h>
using namespace std;
const int N = 1004;
long long n, R, a[N];
int q, m;
vector <long long> L[N];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) cin >> a[i];
        sort(a + 1, a + m + 1);
        int u = 0;
        for (int i = 1; i <= m; i++)
            if (n % a[i] == 0) {
                for (int j = i; j <= m; j++)
                if (n % a[j] == 0) {
                    if (L[i].empty() || a[j] % L[i].back() == 0)
                    L[i].push_back(a[j]);
                }
            }
        R = 0;
        for (int i = 1; i <= m; i++) {
            long long res = 0, par = 1, cur = n;
            for (int k = L[i].size() - 1; k >= 0; k--) {
                if (cur == L[i][k]) continue;
                res += par;
                par *= cur / L[i][k];
                cur = L[i][k];
                //cout << cur << " " << par << "\n";
            }
            R = max(R, res);
        }
        for (int i = 1; i <= m; i++) L[i].clear();
        cout << R << "\n";
    }
    return 0;
}

