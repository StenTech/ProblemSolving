#include <bits/stdc++.h>
#define MOD 1000000007

int A(int n);
int B(int n);
int C(int n);


using namespace std;

int a, b, c, n;

int A(int n) {
    if (n == 0) return 1;
    return (1LL * b * B(n - 1) + 1LL * c * C(n - 1)) % MOD;
}

int B(int n) {
    if (n == 0) return 1;
    return (1LL * a * A(n - 1) + 1LL * c * C(n - 1)) % MOD;
}

int C(int n) {
    if (n == 0) return 1;
    return (1LL * a * A(n - 1) + 1LL * b * B(n - 1)) % MOD;
}

int process(int n) {
    return (1LL * a * A(n - 1) + 1LL * b * B(n - 1) + 1LL * c * C(n - 1)) % MOD;
}

int main() {
    cin >> n >> a >> b >> c;
    cout << process(n) << endl;
    return 0;
}