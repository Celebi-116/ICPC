#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
#define fi first
#define se second
string res[2] = {"No\n", "Yes\n"};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int u = 0;
        vector <int> P(n + 1, 0), V(n + 1, 0), A;
        for (int i = 1; i <= n; i++) {
            int l;
            cin >> V[i] >> l;
            if (l != -1) P[l] = i;
            else u = i;
        }
        do {
            A.push_back(V[u]);
            u = P[u];
        } while (u != 0);
        bool flag = is_sorted(A.begin(), A.end());
        reverse(A.begin(), A.end());
        flag = flag || is_sorted(A.begin(), A.end());
        cout << res[flag];
    }
}
/*
3
5
3 5
2 4
1 2
2 1
4 -1
3
4 2
4 3
3 -1
3
1 -1
4 1
3 2
*/
