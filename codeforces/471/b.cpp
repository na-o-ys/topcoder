#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    vector<int> C[2001];
    int n; cin >> n;
    vector<int> H(n);
    loop (n, i) { cin >> H[i]; C[H[i]].push_back(i+1); }
    vector<int> two, three;
    loop (2001, i) {
        if (C[i].size() >= 2) two.push_back(i);
        if (C[i].size() >= 3) three.push_back(i);
    }
    if (two.size() <= 1 && three.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    loop (2001, i) {
        for (int c : C[i]) cout << c << " ";
    }
    cout << endl;
    if (three.size()) {
        loop (2001, i) {
            if (C[i].size() >= 3) {
                cout << C[i][1] << " " << C[i][0] << " ";
                from_to (2, C[i].size()-1, j) cout << C[i][j] << " ";
            }
            else for (int c : C[i]) cout << c << " ";
        }
        cout << endl;
        loop (2001, i) {
            if (C[i].size() >= 3) {
                cout << C[i][2] << " " << C[i][0] << " " << C[i][1] << " ";
                from_to (3, C[i].size()-1, j) cout << C[i][j] << " ";
            }
            else for (int c : C[i]) cout << c << " ";
        }
        cout << endl;
        return 0;
    }
    bool fst = 1;
    loop (2001, i) {
        if (C[i].size() >= 2) {
            if (fst) {
                cout << C[i][1] << " " << C[i][0] << " ";
                fst = 0;
            }
            else for (int c : C[i]) cout << c << " ";
        }
        else if (C[i].size())cout << C[i][0] << " ";
    }
    cout << endl;
    loop (2001, i) {
        if (C[i].size() >= 2) {
            if (fst) {
                for (int c : C[i]) cout << c << " ";
                fst = 0;
            }
            else cout << C[i][1] << " " << C[i][0] << " ";
        }
        else if (C[i].size())cout << C[i][0] << " ";
    }
    cout << endl;
    return 0;
}
