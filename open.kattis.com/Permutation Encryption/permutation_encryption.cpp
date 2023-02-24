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
    normalizes the message to be a multiple of n
*/
void normalize(string &msg, int n) {
    int len = msg.size();
    int m = len%n;
    if (m == 0) return;
    for (int i = 0; i < n - len%n; i++)
    {
        msg += " ";
    }
}

/*
    encrypts the message using the key
*/
void encrypt(string &msg, string &msg_crypt, vector<int> &key, int n) {
    
    int len = msg.size();

    for (int i = 0; i < len/n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            msg_crypt += msg[i*n + key[j] - 1];
        }
    }

}




int main(int argc, char const *argv[]) {

    int n;
    while (cin >> n)
    {

        if (n == 0) break;

        vector<int> keys(n);
        string msg, msg_crypt("");

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            keys[i] = k;
        }

        cin.ignore();
        getline(cin, msg);

        normalize(msg, n);

        encrypt(msg, msg_crypt, keys, n);
        //cout << "'" << msg << "'" << endl;
        cout << "'" << msg_crypt << "'" << endl;
        
    }
    

    return 0;
}