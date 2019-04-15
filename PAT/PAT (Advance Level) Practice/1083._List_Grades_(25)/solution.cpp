#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    char name[12];
    char id[12];
    int score;
};

bool cmp(const Student &a,
         const Student &b)
{
    return a.score > b.score;
}

int main()
{
    int N; cin >> N;
    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i].name >> students[i].id >> students[i].score;
    }
    int lo, hi;
    cin >> lo >> hi;
    int m = 0;
    for (int i = 0; i < N; ++i) {
        if (students[i].score < lo || students[i].score > hi) {
            students[i].score = -1;
        } else {
            ++m;
        }
    }
    sort(students.begin(), students.end(), cmp);
    for (int i = 0; i < m; ++i) {
        cout << students[i].name << " " << students[i].id << endl;
    }
    if (m == 0) {
        cout << "NONE\n";
    }
    return 0;
}