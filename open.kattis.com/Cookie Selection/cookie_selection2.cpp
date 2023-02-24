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
    priority_queue<long> pq_max;
    priority_queue<long, vector<long>, greater<long>> pq_min;


    while (cin >> s) {
            
            if (s == "#") {                    
                cout << pq_min.top() << endl;
                pq_min.pop();
                if (pq_min.size() < pq_max.size()) {
                    pq_min.push(pq_max.top());
                    pq_max.pop();
                }
            }
            else {
                long num;
                stringstream ss(s);
                ss >> num;
                if (pq_min.size() == 0) {
                    pq_min.push(num);
                } else {
                    if (num > pq_min.top()) {
                        pq_min.push(num);
                        if (pq_min.size() > pq_max.size() + 1) {
                            pq_max.push(pq_min.top());
                            pq_min.pop();
                        }
                    } else {
                        pq_max.push(num);
                        if (pq_max.size() > pq_min.size()) {
                            pq_min.push(pq_max.top());
                            pq_max.pop();
                        }
                    }
                }
            }
    }

    return 0;

}