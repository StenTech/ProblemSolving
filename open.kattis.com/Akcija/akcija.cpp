#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, cost = 0, m;
    vector<int> prices;

    cin >> n;

    m = n/3;

    for (int i = 0; i < n; i++)
    {
        int price;
        
        cin >> price;

        cost+=price;

        prices.push_back(price);
    }

    sort(prices.begin(), prices.end(), greater<int>{});
    
    //cout << cost << endl;

    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cost -= prices[i*3+2];
    }

    cout << cost << endl;
    

    

    return 0;
}