#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    int n; cin >> n;
    vector<vector<string>> N(n, vector<string>(2));
    loop (n, i) {
        cin >> N[i][0] >> N[i][1];
        if (N[i][0] > N[i][1]) swap(N[i][0], N[i][1]);
    }
    vector<int> P(n);
    loop (n, i) cin >> P[i];
    string prev = "";
    for (int i : P) {
        i--;
        if (prev > N[i][1]) {
            cout << "NO" << endl;
            return 0;
        }
        prev = prev > N[i][0] ? N[i][1] : N[i][0];
    }
    cout << "YES" << endl;
    return 0;
}
