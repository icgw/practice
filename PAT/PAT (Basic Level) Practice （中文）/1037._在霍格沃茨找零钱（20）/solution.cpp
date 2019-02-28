#include <iostream>
using namespace std;

void payreturn(int g_need, int s_need, int k_need, int g, int s, int k) {
    if (g_need > g || (g_need == g && s_need > s) || (g_need == g && s_need == s && k_need > k)) {
        cout << "-";
        payreturn(g, s, k, g_need, s_need, k_need);
        return ;
    }
    
    int x, y, z;
    if (k >= k_need) {
        z = k - k_need;
    } else {
        z = 29 + k - k_need;
        s--;
    }
    
    if (s >= s_need) {
        y = s - s_need;
    } else {
        y = 17 + s - s_need;
        g--;
    }
    
    x = g - g_need;
    cout << x << "." << y << "." << z << endl;
    return ;
}

int main() {
    int g_need, s_need, k_need, g, s, k;
    scanf("%d.%d.%d", &g_need, &s_need, &k_need);
    scanf("%d.%d.%d", &g, &s, &k);
    payreturn(g_need, s_need, k_need, g, s, k);
    return 0;
}