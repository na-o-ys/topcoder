#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
int main()
{
    int M = 20010;
    unordered_set<int> sqsum;
    for (int i = 0; i*i < M; i++) {
        for (int j = 0; j*j < M; j++) {
            sqsum.insert(i*i + j*j);
        }
    }
    vector<int> sqsump(M);
    for (int i : sqsum) for (int j : sqsum) {
        if (i*j < M) sqsump[i*j]++;
    }
    int N; cin >> N;
    while (N--) {
        int m, n; cin >> m >> n;
        cout << (sqsump[m*m+n*n] < 3 ? "P" : "C") << endl;
    }
    return 0;
}
