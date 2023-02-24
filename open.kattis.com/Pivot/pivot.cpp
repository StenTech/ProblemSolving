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
    problem: Pivot
    link: https://open.kattis.com/problems/pivot
    
    this problem consists in finding the number of pivots in a vector
    a pivot is an element that is greater than all the elements to the left
    and smaller than all the elements to the right
    // commented solution code

*/
int main(int argc, char const *argv[]) {
    

    long n, num(0);
    cin >> n;

    // priority queue for the maX
    priority_queue<long> pq_max;
    
    // priority queue for the min
    priority_queue<long, vector<long>, greater<long>> pq_min;

    // vector for the input
    vector<long> v(n);
    
    // vector for the max
    vector<bool> v2;
    
    // vector for the min
    vector<bool> v3;
    
    for (long i = 0; i < n; i++) {
        cin >> v[i];
    }

    // pacourir le vecteur dans les deux sens
    for( long i = 0, j = n-1; i < n ; i++, j--) {
        
        if( i== 0 && j == n-1) {
            v2.push_back(true);
            v3.push_back(true);
        }else {
            if (v[i] > pq_max.top()){
                v2.push_back(true);
            } else {
                v2.push_back(false);
            }

            if (v[j] < pq_min.top()){
                v3.push_back(true);
            } else {
                v3.push_back(false);
            }
        }

        pq_max.push(v[i]);
        pq_min.push(v[j]);
    }

    for (long i = 0, j = n-1; i < n ; i++, j--) {
        if (v2[i] && v3[j]) {
            num++;
        }
    }

    cout << num << endl;
    
    return 0;
    /*/ fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vi v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    vi left(n);
    vi right(n);
    left[0] = v[0];
    right[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], v[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = min(right[i + 1], v[i]);
    }
    for (int i = 0; i < n; i++) {
        if (v[i] >= left[i] && v[i] <= right[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;*/
}