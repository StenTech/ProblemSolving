#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, w, h, maxi;
    double hp;
    
    cin >> n >> w >> h;
    
    hp = (double)sqrt(w*w + h*h);

    for (int i = 0; i < n; i++)
    {
        
        int lght;
        cin >> lght;

        if (lght <= w || lght <= h || lght <= hp)
        {
            //cout << lght << ":" << hp << endl;
            cout << "DA" << endl;
        }
        else
        {
            cout << "NE" << endl;
        }
        
    }
    
    return 0;
}