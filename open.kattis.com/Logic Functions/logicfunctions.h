#include <iostream>

void exclusive(bool x, bool y, bool& ans);
void implies(bool x, bool y, bool& ans);
void equivalence(bool x, bool y, bool& ans);

using namespace std;

void checkAns(bool val, bool expected) {
    if (val != expected) {
        cout << "FAIL - expected " << expected << endl;
        exit(1);
    }
}

int main(){
    bool ans;
    exclusive(true, false, ans);
    cout << "T xor T: " << ans << endl;
    checkAns(ans, true);

    implies(true, false, ans);
    cout << "T => T: " << ans << endl;
    checkAns(ans, false);

    equivalence(true, false, ans);
    cout << "T <=> T: " << ans << endl;
    checkAns(ans, false);

    cout << "OK!" << endl;
}
