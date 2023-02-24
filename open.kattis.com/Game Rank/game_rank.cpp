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

void increase_rank(int &r) {
    if (r >= 0) r -= 1; 
}
void decrease_rank(int &r) { 
    if (r < 25) {
        r += 1;
    }
}
/*
    solution of problem: https://open.kattis.com/problems/gamerank
*/


int main(int argc, char const *argv[]) {

    map<int, int> rank_stars = {
        {25, 2}, {24, 2}, {23, 2}, {22, 2}, {21, 2},
        {20, 3}, {19, 3}, {18, 3}, {17, 3}, {16, 3},
        {15, 4}, {14, 4}, {13, 4}, {12, 4}, {11, 4},
        {10, 5}, {9, 5},  {8, 5},  {7, 5},  {6, 5},
        {5, 5},  {4, 5},  {3, 5},  {2, 5},  {1, 5},
    };

    string history;
    cin >> history;

    int rank = 25, stars = 0, win_streak = 0;

    for (char c : history) {
        
        if (strncmp(&c, "W", 1) == 0) {
            
            win_streak++;
            stars++;

            if (win_streak >= 3 && rank >= 6 && rank <= 25 ) {
                stars++;
            }


            if (rank > 0 && stars > rank_stars[rank]) {
                stars -= rank_stars[rank];
                increase_rank(rank);
            }

        }
        else {
            if (rank >= 1 && rank <= 20) {
                if (stars > 0) stars--;
                else if (stars == 0 && rank < 20) {
                    decrease_rank(rank);
                    stars = rank_stars[rank] - 1;
                }
            }
            
            win_streak = 0;
        }

    }

    if (rank == 0) {
        cout << "Legend" << endl;
    }else {
        //cout << rank << " " << stars << endl;
        cout << rank << endl;
    }


    return 0;
}