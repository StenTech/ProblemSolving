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

/*
    solution of problem: https://open.kattis.com/problems/areal
*/

int main(int argc, char const *argv[]) {

    long long int area;
    cin >> area;

    long double side = sqrt(area);

    cout << setprecision(10) << side * 4 << endl;

    return 0;
}