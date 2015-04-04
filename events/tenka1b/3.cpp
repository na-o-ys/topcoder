#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int N; cin >> N;
    vector<vector<int>> C(N+2, vector<int>(N+2));
    loop (N, i) {
        string row; cin >> row;
        loop (N, j) C[i+1][j+1] = row[j] == '#' ? 1 : 0;
    }

    vector<vector<int>> A(N+2, vector<int>(N+2));
    loop (N-1, i) {
        loop (N, j) {
            A[i+2][j+1] = C[i+1][j+1] ^ A[i][j+1] ^ A[i+1][j] ^ A[i+1][j+2];
        }
    }

    loop (N, i) {
        loop (N, j) cout << (A[i+1][j+1] ? '#' : '.');
        cout << endl;
    }
    return 0;
}
