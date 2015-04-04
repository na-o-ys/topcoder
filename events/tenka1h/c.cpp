#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int L[1010][1010] = {};
int M[1010][1010] = {};
int main(int argc, char const* argv[])
{
    string S; cin >> S;
    int N = S.length();
    if (N > 1010) return 0;
    int Q; cin >> Q;

    loop (N, i) loop (N, j) {
        if (i >= j) continue;
        if (!(j-i)%2) continue;

        string s = S.substr(i, j-i+1);
        if (s.substr(0, s.length()/2) == s.substr(s.length()/2)) L[i+1][j+1] = s.length();
    }

    loop (N, i) for (int j = N-1; j; j--) {
        L[j][i+1] += L[j+1][i+1] + L[j][i] - L[j+1][i];
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        cout << L[a][b] << endl;
    }

    return 0;
}
