#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using TPL = tuple<int, int, int>;
using P = pair<int, int>;
char mp[2010][2010];
int cnt[2010][2010];
int D[] = { -1, 0, 1, 0, -1 };

int dfs(int i, int j)
{
    if (cnt[i][j] != 1) return 0;

    int dd;
    loop (4, d) if (mp[i + D[d]][j + D[d+1]] == '.') dd = d;

    cnt[i][j] = 0;
    cnt[i + D[dd]][j + D[dd+1]] = 0;
    char a, b;
    if (D[dd] == -1) {
        a = 'v';
        b = '^';
    } else if (D[dd] == 1) {
        a = '^';
        b = 'v';
    } else if (D[dd+1] == -1) {
        a = '>';
        b = '<';
    } else if (D[dd+1] == 1) {
        a = '<';
        b = '>';
    }
    mp[i][j] = a;
    mp[i + D[dd]][j + D[dd+1]] = b;

    loop (4, d) {
        cnt[i + D[d]][j + D[d+1]] = max(0, cnt[i + D[d]][j + D[d+1]]-1);
        cnt[i + D[dd] + D[d]][j + D[dd+1] + D[d+1]] = max(0, cnt[i + D[dd] + D[d]][j + D[dd+1] + D[d+1]]-1);
    }

    loop (4, d) {
        dfs(i + D[d], j + D[d+1]);
        dfs(i + D[dd] + D[d], j + D[dd+1] + D[d+1]);
    }

    return 1;
}

int main()
{
    int n, m; cin >> n >> m;
    loop (n, i) loop (m, j) cin >> mp[i+1][j+1];
    loop (n, i) mp[i][0] = mp[i][m+1] = '*';
    loop (m, i) mp[0][i] = mp[n+1][i] = '*';
    if (n == 1 && m == 1 && mp[1][1] == '.') {
        cout << "Not unique" << endl;
        return 0;
    }

    fill (cnt[0], cnt[2009]+2010, 0);

    vector<P> rank;
    loop (n, i) loop (m, j) {
        if (mp[i+1][j+1] != '.') continue;
        int c = 0;
        loop (4, d) {
            char m = mp[i+1 + D[d]][j+1 + D[d+1]];
            if (m == '.') c++;
        }
        cnt[i+1][j+1] = c;
    }

    while (1) {
        bool changed = false;
        loop (n, i) loop (m, j) {
            changed = dfs(i+1, j+1);
        }
        if (!changed) break;
    }

    loop (n, i) loop (m, j) if (cnt[i+1][j+1]) {
        cout << "Not unique" << endl;
        return 0;
    }

    loop (n, i) {
        loop (m, j) cout << mp[i+1][j+1];
        cout << endl;
    }

    return 0;
}
