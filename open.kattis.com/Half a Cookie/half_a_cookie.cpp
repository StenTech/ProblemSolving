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

float y(float x, float r) {
    return sqrt(r*r - x*x);
} 

int main(int argc, char const *argv[]) {

    float r, x, y;
    cin.precision(10);
    cout.precision(9);
    while(cin >> r >> x >> y) {
        x = abs(x);
        y = abs(y);
        float d = sqrt(x*x + y*y);
        if(d >= r) {
            cout << "miss" << endl;
        } else {
            float theta = 2*acos(d/r);
            float area = r*r*(theta - sin(theta))/2;
            cout << M_PI*r*r - area  << " " << area << endl;
        }
    }

    return 0;
}