#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


int n;
int a[1000111];

int main(){
    cin >> n;
    for(int i=2; i<=n; i++) cin >> a[i];
    
    int need = 2; 
    double s = 0, lng = pow(2, -3.0/4), lrg = pow(2, -5.0/4);

    for(int i=2; i<=n; i++){
        
        s += need/2 * lng;
        need-=a[i];
        
        if (need <= 0) break;
        need *= 2;
        
        double temp= lrg;
        lrg= lng/2;
        lng= temp;
        
    }
    
    if (need > 0) cout<<"impossible";
    else cout << fixed << setprecision(11) << s;
}