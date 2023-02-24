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

bool cpm(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(int argc, char const *argv[]) {

    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<pii> time(n);

        for (int i = 0; i < n; i++) {
            int h, m;

            string ampm, H;
            //scanf("%d:%d %s", &h, &m, &ampm);

            cin >> H >> ampm;
            //position of :
            int pos = H.find(':');
            //get the hour
            h = stoi(H.substr(0, pos));
            //get the minute
            m = stoi(H.substr(pos+1, H.size()));
            
            if (h == 12) h = 0;
            
            if (ampm == "p.m."){
                h += 12;
                time[i] = {h, m};
            }
            else {
                time[i] = {h, m};
            }
        }

        sort(time.begin(), time.end(), cpm);

        for(int i = 0; i < n; i++) {
            int h = time[i].first;
            int m = time[i].second;
            if (h == 0) {
                printf("12:%02d a.m.\n", m);
            }
            else if (h < 12) {
                printf("%d:%02d a.m.\n", h, m);
            }
            else if (h == 12) {
                printf("12:%02d p.m.\n", m);
            }
            else {
                printf("%d:%02d p.m.\n", h-12, m);
            }
        }

        printf("\n");


    }

    return 0;
}