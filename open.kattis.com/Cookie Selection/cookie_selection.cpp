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

bool cmp(int a, int b) {
    return a < b;
}


int main(int argc, char const *argv[]) {

    string s;
    long nlines = 0;
    vector<long> v;

    while (cin >> s) {
        
        if (s == "#") {
            
            long l = v.size();
            long a = 0;
            
            //sort(v.begin(), v.end());               
            
            if (l%2 == 0) {
                a = l/2;
            } else {
                a = (l-1)/2;
            }

            cout <<  v[a] << endl;
            v.erase(v.begin()+a);

        }
        else {
            long num;
            stringstream ss(s);
            ss >> num;
           
            auto it = upper_bound(v.begin(), v.end(), num);
            v.insert(it, num);
            
        }        

    }

    return 0;
}