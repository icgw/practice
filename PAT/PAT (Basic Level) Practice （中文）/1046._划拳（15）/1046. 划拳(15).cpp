#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    int JDrink = 0, YDrink = 0;
    for (int i = 0; i < N; ++i) {
        int JSay, JShow, YSay, YShow;
        cin >> JSay >> JShow >> YSay >> YShow;
        int BothSay = JSay + YSay;
        if (BothSay == JShow && BothSay != YShow) {
            ++YDrink;
        }
        if (BothSay == YShow && BothSay != JShow) {
            ++JDrink;
        }
    }
    cout << JDrink << " " << YDrink;
    return 0;
}