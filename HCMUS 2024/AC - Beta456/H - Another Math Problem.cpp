#include <bits/stdc++.h>
using namespace std;

#define int long long
int a, b, m;

int add(int a, int b, int mod) {
    return (a + b) % mod;
}

int sub(int a, int b, int mod) {
    return (a - b + mod) % mod;

}

int mul(int a, int b, int mod) {
    int T = 0;
    while (b) {
        if (b & 1) T = (T + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return T;
}

int power(int a, int b, int mod) {
    int T = 1;
    while (b) {
        if (b & 1) T = mul(T, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return T;
}

void minimize (int& a, int& b, int& c) {
    if (a % 6 == 0) a /= 6;
    else if (b % 6 == 0) b /= 6;
    else if (c % 6 == 0) c /= 6;
    else if (a % 2 == 0 && b % 3 == 0) a /= 2, b /= 3;
    else if (a % 3 == 0 && b % 2 == 0) a /= 3, b /= 2;
    else if (a % 2 == 0 && c % 3 == 0) a /= 2, c /= 3;
    else if (a % 3 == 0 && c % 2 == 0) a /= 3, c /= 2;
    else if (b % 2 == 0 && c % 3 == 0) b /= 2, c /= 3;
    else if (b % 3 == 0 && c % 2 == 0) b /= 3, c /= 2;
}

int sumsq (int x, int m) {
    int a = x, b = x + 1, c = 2 * x + 1;
    minimize(a, b, c);
    return mul(a, mul(b, c, m), m);
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> m;
    cout << sub(sumsq(b, m), sumsq(a - 1, m), m);
    return 0;
}
// 1 1000000000000000000 1000000000000000000
// 444 155515 12544664467 -> 3993645876
