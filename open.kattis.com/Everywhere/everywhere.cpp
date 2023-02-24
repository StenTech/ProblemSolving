#include <bits/stdc++.h>

using namespace std;

/**
 * @brief https://open.kattis.com/problems/everywhere
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m, res = 0;
        string cities[100], other[100];

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            string city;
            cin >> city;
            bool breaked (false);

            for (int j = 0; j < i; j++)
            {
                if (city.compare(cities[j]) == 0)
                {
                    breaked = true;
                    break;
                }
            }
            if (!breaked)
            {
                cities[i] = city;
                res++;
            }
            
        }

        cout << res << endl;
        
    }
    
    return 0;
}