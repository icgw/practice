#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    string cnt = to_string(A * B);
    reverse(cnt.begin(), cnt.end());
    cout << stoi(cnt);
    return 0;
}