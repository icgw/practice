#include <iostream>
using namespace std;

int main() {
    string A, B;
    
    int DA, DB;
    cin >> A >> DA >> B >> DB;
    
    int D1 = 0, D2 = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] - '0' == DA) {
            D1 = 10 * D1 + DA;
        }
    }
    
    for (int i = 0; i < B.size(); ++i) {
        if (B[i] - '0' == DB) {
            D2 = 10 * D2 + DB;
        }
    }
    
    cout << D1 + D2 << endl;
    return 0;
}