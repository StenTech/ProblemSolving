#include <bits/stdc++.h>

using namespace std;


string order_f(string s1, string s2) {
    if(s1 < s2){
        return "INCREASING";
    }else {
        return "DECREASING";
    }   
}

/**
 * @brief https://open.kattis.com/problems/lineup
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    int n;
    string order("NEITHER");
    string names[20];
    cin >> n;

/*
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        if (i > 0) {
            if ( i >1 && name < names[i-1])
            {
                if ( order != order_f(names[i-1], name)){
                    order = "NEITHER";
                    break;
                }
            }else {
                order = order_f(names[i-1], name);
            }
            
        }



        names[i] = name;
        
    }

*/

    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    order = order_f(names[0], names[1]);

    for (int j = 1; j < n-1; j++)
    {
        if ( order != order_f(names[j], names[j+1])){
                    order = "NEITHER";
                    break;
        }
    }
    
    
    cout << order;
    
    return 0;
}