#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;

   while (cin >> n)
   {
        int c, x;
        bool s = true, q = true, p = true;
        stack<int> stk;
        queue<int> qe;
        priority_queue<int> pq;

            for (int i = 0; i < n; i++)
            {
                cin >> c >> x;

                if (c == 1)
                {
                    if(s) {
                        stk.push(x);
                    }
                    if(q) {
                        qe.push(x);
                    }
                    if(p) {
                        pq.push(x);
                    }
                }
                else {
                    if (s) {
                        if (stk.empty() || x != stk.top())
                            s = false;
                        else
                            stk.pop();                        
                    }
                    if (q) {
                        if (qe.empty() || x != qe.front())
                            q = false;
                        else
                            qe.pop();
                    }
                    if (p) {
                        if (pq.empty() || x != pq.top())
                            p = false;
                        else
                            pq.pop();
                    }

                }
                
            }            
            if(s) {
                if(!q && !p) {
                    cout << "stack" << endl;
                }
                else {
                    cout << "not sure" << endl;
                }
            }
            else if(q) {
                if(!p) {
                    cout << "queue" << endl;
                }
                else {
                    cout << "not sure" << endl;
                }
            }
            else if(p) {
                cout << "priority queue" << endl;            
            }else {
                cout << "impossible" << endl;
            }
        }
    

    return 0;
}