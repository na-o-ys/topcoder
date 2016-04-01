#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef struct {
    int x, y;
    VVI b;
    int count;
} Move;

int gx, gy;
const int INF = 1<<29;
int dirs[] = { 1, 0, -1, 0, 1 };
VVI B;

int dfs(int crr_x, int crr_y, int count)
{
    if (count >= 10) return INF;
    int ans = INF;
    loop (4, i) {
        int x = crr_x+dirs[i], y = crr_y+dirs[i+1];
        if (B[x][y] != 0) continue;
        while (B[x][y] == 0) {
            if (x == gx && y == gy) return count + 1;
            x += dirs[i];
            y += dirs[i+1];
        }
        if (B[x][y] == 2) continue;
        B[x][y] = 0;
        ans = min(ans, dfs(x-dirs[i], y-dirs[i+1], count+1));
        B[x][y] = 1;
    }
    return ans;
}

int main()
{
    while (1) {
        int w, h; cin >> w >> h;
        if (!w) break;
        int sx, sy;
        B = VVI(w+2, VI(h+2));
        loop (h+2, y) {
            B[0][y] = 2;
            B[w+1][y] = 2;
        }
        loop (w+2, x) {
            B[x][0] = 2;
            B[x][h+1] = 2;
        }
        loop (h, y) loop (w, x) {
            int v; cin >> v;
            if (v == 2) sx = x+1, sy = y+1;
            if (v == 3) gx = x+1, gy = y+1;
            B[x+1][y+1] = (v == 1);
        }

        int ans = dfs(sx, sy, 0);
        if (ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
