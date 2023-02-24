#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


int main(int argc, char const *argv[]) {

    double x1, y1, x2, y2, p;

    while (cin >> x1 >> y1 >> x2 >> y2 >> p)
    {
        double distance = pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1.0 / p);
        cout << setprecision(10) << distance << endl;
    }

    return 0;
}