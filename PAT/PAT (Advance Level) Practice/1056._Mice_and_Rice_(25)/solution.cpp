#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Mice {
    int index;
    int weight;
    int order;
    int rank;
};

int main()
{
    int Np, Ng; cin >> Np >> Ng;
    
    vector<int> weights (Np);
    for (int i = 0; i < Np; ++i) {
        cin >> weights[i];
    }

    vector<Mice> m (Np);
    int num;
    for (int i = 0; i < Np; ++i) {
        cin >> num;
        m[i].index  = num;
        m[i].weight = weights[num];
        m[i].order  = i;
    }

    queue<Mice> q;
    for (auto &x : m) {
        q.push(x);
    }

    while (!q.empty()) {
        int sz = q.size();
        if (1 == sz) {
            Mice tmp = q.front();
            q.pop();
            m[tmp.order].rank = 1;
            break;
        }

        Mice maxm;
        maxm.weight = -1;

        int rk = (sz + Ng - 1) / Ng;
        for (int k = 1; k <= sz; ++k) {
            Mice tmp = q.front();
            q.pop();
            m[tmp.order].rank = rk + 1;
            if (tmp.weight > maxm.weight) {
                maxm = tmp;
            }

            if (k % Ng == 0 || k == sz) {
                q.push(maxm);
                maxm.weight = -1;
            }
        }
    }

    sort(m.begin(), m.end(), [](Mice &a, Mice &b) {
        return a.index < b.index;
    });
    for (int i = 0; i < Np; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << m[i].rank;
    }
    cout << "\n";

    return 0;
}