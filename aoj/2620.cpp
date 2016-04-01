#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
typedef struct { int x, y; } P;
typedef tuple<int, int, int> TPL;

int main()
{
    int w, h, n; cin >> w >> h >> n;
    int st_x, st_y, ed_x, ed_y;
    cin >> st_x >> st_y >> ed_x >> ed_y;
    int cost[510][510][4];
    fill(cost[0][0], cost[509][509]+4, 1<<29);
    loop (w+1, i) loop (h+1, j) loop (4, k) cost[i][j][k] = 0;

    while (n--) {
        int x, y, t; cin >> x >> y >> t;
        string pat; cin >> pat;
        while (t--) {
            for (char c : pat) {
                if (c == 'L' && x-1 >= 0) {
                    cost[x][y][3]++;
                    cost[x][y+1][1]++;
                    x--;
                }
                if (c == 'U' && y-1 >= 0) {
                    cost[x][y][2]++;
                    cost[x+1][y][0]++;
                    y--;
                }
                if (c == 'R' && x+1 < w) {
                    cost[x+1][y][3]++;
                    cost[x+1][y+1][1]++;
                    x++;
                }
                if (c == 'D' && y+1 < h) {
                    cost[x][y+1][2]++;
                    cost[x+1][y+1][0]++;
                    y++;
                }
            }
        }
    }

    priority_queue<TPL, vector<TPL>, greater<TPL>> Q;
    int vis[510][510] = {};
    Q.push(TPL{ 0, st_x, st_y });
    P dirs[] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    while (Q.size()) {
        auto top = Q.top(); Q.pop();
        int crr_cost = get<0>(top), crr_x = get<1>(top), crr_y = get<2>(top);
        if (vis[crr_x][crr_y]) continue;
        if (crr_x == ed_x && crr_y == ed_y) {
            cout << crr_cost << endl;
            return 0;
        }
        vis[crr_x][crr_y] = 1;
        loop (4, i) {
            int nxt_x = crr_x + dirs[i].x;
            int nxt_y = crr_y + dirs[i].y;
            if (nxt_x >= 0 && nxt_x <= w && nxt_y >= 0 && nxt_y <= h) {
                Q.push(TPL{
                        crr_cost + cost[crr_x][crr_y][i],
                        nxt_x,
                        nxt_y
                        });
            }
        }
    }
    return 0;
}
