#include <iostream>
using namespace std;

bool isValid(string id){
    static int nums[17];
    for(int i = 0; i < 17; ++i){
        if (id[i] == 'X') {
            nums[i] = 10;
            continue;
        }
        nums[i] = id[i] - '0';
    }
    int sum = 0;
    int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
    for (int i = 0; i < 17; ++i){
        sum += nums[i] * weight[i];
    }
    sum %= 11;
    
    int m[11] = { 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2 };
    int end = (id[17] == 'X') ? 10 : (id[17] - '0');
    if (m[sum] == end) {
        return true;
    }
    cout << id << endl;
    return false;
}

int main(){
    int N; cin >> N;
    int pass = true;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        if (!isValid(s)) pass = false;
    }
    if (pass) {
        cout << "All passed\n";
    }
    return 0;
}