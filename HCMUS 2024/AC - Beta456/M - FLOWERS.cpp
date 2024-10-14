#include <bits/stdc++.h>
using namespace std;
const int MAX = 2E5 + 25;
int n, d, a[MAX], cur, res;
int med (vector <int> &v) {
    if (d % 2 == 1) return 2 * v[d / 2];
    else return v[(d - 1) / 2] + v[d / 2];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> v;
    for (int i = 1; i <= d; i++) v.push_back(a[i]);
    sort(v.begin(), v.end());
    if (d % 2 == 1) cur = 2 * v[d / 2];
    else cur = v[(d - 1) / 2] + v[d / 2];
    for (int i = d + 1; i <= n; i++) {
        if (a[i] >= cur) res++;
        auto it = lower_bound(v.begin(), v.end(), a[i - d]);
        v.erase(it);
        it = lower_bound(v.begin(), v.end(), a[i]);
        v.insert(it, a[i]);
        cur = med(v);
    }
    cout << res;
    return 0;
}
