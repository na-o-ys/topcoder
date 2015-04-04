#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using P = pair<int, int>;
using TPL = tuple<int, int, int, int>;

int solve()
{
    int M, N; cin >> M >> N;
    int map[4][110][110] = {};
    fill(map[0][0], map[3][109]+110, 1);
    P start, goal;

    loop (M, m) {
        string line; cin >> line;
        loop (N, n) {
            loop (4, i) {
                int v;
                if (line[n] == '.') v = 0;
                if (line[n] == '#') v = 1;
                if (line[n] == 'S') { v = 0; start = P(m+1, n+1); }
                if (line[n] == 'G') { v = 0; goal = P(m+1, n+1); }
                if (line[n] == '^') v = i%4 + 4;
                if (line[n] == '>') v = (i+1)%4 + 4;
                if (line[n] == 'v') v = (i+2)%4 + 4;
                if (line[n] == '<') v = (i+3)%4 + 4;
                map[i][m+1][n+1] = v;
            }
        }
    }

    int D[] = { -1, 0, 1, 0, -1 };
    loop (4, i) for (int m = 1; m <= M; m++) for (int n = 1; n <= N; n++) {
        if (map[i][m][n] < 4) continue;
        int dm = D[ map[i][m][n] - 4 ];
        int dn = D[ map[i][m][n] - 3 ];
        int pm = m+dm, pn = n+dn;
        while (map[i][pm][pn] != 1 && map[i][pm][pn] < 4) {
            map[i][pm][pn] = 2;
            pm += dm;
            pn += dn;
        }
    }

    // loop (4, i) {
    //     loop (M, m) {
    //         loop (N, n) cout << (map[i][m+1][n+1] ? '#' : '.');
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int count[4][110][110];
    fill(count[0][0], count[3][109]+110, 1<<20);
    queue<TPL> q;
    q.emplace(0, start.first, start.second, 0);
    while (q.size()) {
        int f = get<0>(q.front()), m = get<1>(q.front()),
            n = get<2>(q.front()), cnt = get<3>(q.front());
        q.pop();
        if (cnt != 0 && (count[f][m][n] <= cnt || map[f][m][n])) continue;
        count[f][m][n] = cnt;
        loop (4, i) {
            q.emplace((f+1)%4, m+D[i], n+D[i+1], cnt+1);
        }
    }

    int ans = 1<<20;
    loop (4, i) ans = min(ans, count[i][goal.first][goal.second]);
    return ans == 1<<20 ? -1 : ans;
}

int main()
{
    int T; cin >> T;
    loop (T, i) {
        int c = solve();
        printf("Case #%d: ", i+1);
        if (c >= 0) cout << c << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}
