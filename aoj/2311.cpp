#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

char s[] = { 'o', 'x' };
string B[10];
int dx[] = {  0, -1, -1, -1, 0, 1, 1, 1  };
int dy[] = { -1, -1,  0,  1, 1, 1, 0, -1 };

int count(int t, int ii, int jj)
{
    if (B[ii][jj] != '.') return 0;
    int ans = 0;
    loop (8, p) {
        int i = ii + dx[p], j = jj + dy[p];
        int cnt = 0;
        while (B[i][j] == s[!t]) i += dx[p], j += dy[p], cnt++;
        if (B[i][j] == s[t]) ans += cnt;
    }
    return ans;
}

int move(int t, int ii, int jj)
{
    B[ii][jj] = s[t];
    loop (8, p) {
        int i = ii, j = jj;
        i += dx[p], j += dy[p];
        while (B[i][j] == s[!t]) i += dx[p], j += dy[p];
        if (B[i][j] != s[t]) continue;
        i = ii + dx[p], j = jj + dy[p];
        while (B[i][j] == s[!t]) B[i][j] = s[t], i += dx[p], j += dy[p];
    }
}

int main()
{
    B[0] = "----------";
    B[9] = "----------";
    loop (8, i) {
        string s; cin >> s;
        B[i+1] = "-" + s + "-";
    }

    int t = 0;
    int end = 0;
    while (1) {
        int m_cnt = 0, x = -1, y = -1;
        loop (8, ii) loop (8, jj) {
            int i = ii + 1, j = jj + 1;
            if (t) i = 8 - ii, j = 8 - jj;

            int cnt = count(t, i, j);
            if (cnt > m_cnt) m_cnt = cnt, x = i, y = j;
        }
        if (m_cnt) end = 0, move(t, x, y);
        else end++;
        t ^= 1;
        if (end > 1) break;
    }
    loop (8, i) {
        cout << B[i+1].substr(1, 8) << endl;
    }
    return 0;
}
