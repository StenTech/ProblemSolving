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

    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        int m;
        cin >> m;
        float x0=0, y0=0;
        float tt = 90;
        for(int j=0; j < m; j++) {
            
            float teta, d, O;
            
            cin >> teta >> d;
            tt += teta;
            O = (tt)*M_PI/180;

            x0 += d*cos(O);
            y0 += d*sin(O);
        }

        printf("%.6f %.6f\n", x0, y0);
    }

    return 0;
}