#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct moonCake {
  float mount, price, unit;
};

bool cmp(moonCake &a, moonCake &b) {
  return a.unit > b.unit;
}

int main() {
  int N, need;
  cin >> N >> need;
  vector<moonCake> mc(N);
  for (int i = 0; i < N; ++i) cin >> mc[i].mount;
  for (int i = 0; i < N; ++i) cin >> mc[i].price;
  for (int i = 0; i < N; ++i) mc[i].unit = mc[i].price / mc[i].mount;
  
  sort(mc.begin(), mc.end(), cmp);
  
  float maxReward = 0.0;
  for (int i = 0; i < N; ++i) {
    if (need >= mc[i].mount) {
      maxReward += mc[i].price;
    } else {
      maxReward += mc[i].unit * need;
      break;
    }
    need -= mc[i].mount;
  }
  
  printf("%.2f", maxReward);
  return 0;
}