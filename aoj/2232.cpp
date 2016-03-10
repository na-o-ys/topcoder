#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

vector<string> del(vector<string> b, int n)
{
    int h = b.size(), w = b[0].size();
    loop (h-1, i) loop (w, j) {
        int ii = h-2-i;
        int t = ii + 1;
        for (; t < h && b[t][j] == '.'; t++);
        swap(b[t-1][j], b[ii][j]);
    }
    vector<vector<int>> dl(h, vector<int>(w));
    loop (h, i) loop (w, j) {
        for (int ii = i+1; ii < h; ii++) {
            if (b[ii][j] != b[i][j]) break;
            if (ii - i == n - 1) {
                loop (n, k) dl[i+k][j] = 1;
            }
            if (ii - i > n - 1) dl[ii][j] = 1;
        }
        for (int jj = j+1; jj < w; jj++) {
            if (b[i][jj] != b[i][j]) break;
            if (jj - j == n - 1) {
                loop (n, k) dl[i][j+k] = 1;
            }
            if (jj - j > n - 1) dl[i][jj] = 1;
        }
    }

    loop (h, i) loop (w, j) if (dl[i][j]) b[i][j] = '.';
    return b;
}

void show(vector<string> s) {
    for (auto p : s) {
        cout << p << endl;
    }
    cout << endl;
}

int main()
{
    int h, w, n; cin >> h >> w >> n;

    vector<string> B;
    loop (h, i) {
        string s; cin >> s;
        B.push_back(s);
    }

    loop (h, i) loop (w-1, j) {
        vector<string> curr = B;
        swap(curr[i][j], curr[i][j+1]);
        vector<string> next = del(curr, n);
        while (next != curr) {
            curr = next;
            next = del(curr, n);
        }
        int y = 1;
        loop (h, i) loop (w, j) if (curr[i][j] != '.') y = 0;
        if (y) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
