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
    P start, goal;

    loop (M, m) {
        string line; cin >> line;
        loop (N, n) {
            loop (4, i) {
                switch (line[n]) {
                    case '.':
                        map[i][m][n] = 0;
                        break;
                    case '#':
                        map[i][m][n] = 1;
                        break;
                    case 'S':
                        start = P(m, n);
                        map[i][m][n] = 0;
                        break;
                    case 'G':
                        goal = P(m, n);
                        map[i][m][n] = 0;
                        break;
                    case '^':
                        map[i][m][n] = i % 4 + 4;
                        break;
                    case '>':
                        map[i][m][n] = (i+1) % 4 + 4;
                        break;
                    case 'v':
                        map[i][m][n] = (i+2) % 4 + 4;
                        break;
                    case '<':
                        map[i][m][n] = (i+3) % 4 + 4;
                        break;
                }
            }
        }
    }

    int D[] = { -1, 0, 1, 0, -1 };
    loop (4, i) loop (M, m) loop (N, n) {
        if (map[i][m][n] < 4) continue;
        int dm = D[ map[i][m][n] - 4 ];
        int dn = D[ map[i][m][n] - 3 ];
        int pm = m+dm, pn = n+dn;
        while (pm >= 0 && pm < M && pn >= 0 && pn < N &&
                map[i][pm][pn] != 1 && map[i][pm][pn] < 4) {
            map[i][pm][pn] = 2;
            pm += dm;
            pn += dn;
        }
    }

    // loop (4, i) {
    //     loop (M, m) {
    //         loop (N, n) cout << (map[i][m][n] ? '#' : '.');
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int count[4][110][110];
    fill(count[0][0], count[3][109]+110, -1);
    queue<TPL> q;
    q.emplace(0, start.first, start.second, 0);
    while (q.size()) {
        int f = get<0>(q.front()), m = get<1>(q.front()),
            n = get<2>(q.front()), cnt = get<3>(q.front());
        // printf("%d, %d, %d\n", f, m, n);
        // printf("%d, %d\n", count[f][m][n], map[f][m][n]);
        q.pop();
        if (cnt != 0 && (
                    m < 0 || m >= M || n < 0 || n >= N ||
                    count[f][m][n] != -1 || map[f][m][n])) continue;
        // printf("%d, %d, %d\n", f, m, n);
        count[f][m][n] = cnt;
        loop (4, i) {
            q.emplace((f+1)%4, m+D[i], n+D[i+1], cnt+1);
        }
    }

    int ans = 1<<20;
    loop (4, i) if (count[i][goal.first][goal.second] != -1) {
        ans = min(ans, count[i][goal.first][goal.second]);
    }
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
