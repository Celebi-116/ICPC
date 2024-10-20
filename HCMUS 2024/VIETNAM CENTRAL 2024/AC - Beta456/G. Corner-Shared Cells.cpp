#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int M, N, p, q;
    cin >> M >> N >> p >> q;
    int res = 0;
    for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) continue;
        int x = p + i, y = q + j;
        if (x < 1 || x > M || y < 1 || y > N) continue;
        res++;
    }
    cout << res;
    return 0;
}
