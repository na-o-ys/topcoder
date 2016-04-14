#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

const double EPS = 1e-8;
const int INF = 1<<29;

struct Point { int x, y; };

vector<string> B;
vector<vector<int>> vis;
int h, w, inc;
vector<vector<int>> G;
vector<vector<Point>> pieces;

void dfs(int y, int x, int id) {
    if (vis[y][x]) return;
    vis[y][x] = 1;

    pieces[id].push_back({ x, y });

    char crr = B[y][x];
    if (x-1 >= 0 && B[y][x-1] == crr) dfs(y, x-1, id);
    if (x+1 < w  && B[y][x+1] == crr) dfs(y, x+1, id);
    if (y-1 >= 0 && B[y-1][x] == crr) dfs(y-1, x, id);
    if (y+1 < h  && B[y+1][x] == crr) dfs(y+1, x, id);

    if (y+1 < h && B[y+1][x] != crr && B[y+1][x] != '.' && !vis[y+1][x]) {
        int nxt = inc++;
        G[id].push_back(nxt);
        dfs(y+1, x, nxt);
    }
}

double dfs_w(int i, int& cnt) {
    double ret = 0;
    for (auto b : pieces[i]) {
        ret += 0.5 + b.x;
        cnt++;
    }
    for (int j : G[i]) ret += dfs_w(j, cnt);
    return ret;
}

int main()
{
    while (1) {
NG:
        cin >> w >> h;
        if (!w) break;
        B = vector<string>(h);
        vis = vector<vector<int>>(h, vector<int>(w));
        G = vector<vector<int>>(w*h);
        pieces = vector<vector<Point>>(w*h);
        inc = 1;

        loop (h, i) cin >> B[i];
        reverse(all(B));
        loop (w, i) if (B[0][i] != '.') dfs(0, i, 0);

        vector<int> left(inc, INF), right(inc);
        loop (inc, i) {
            for (auto b : pieces[i]) {
                if (b.y == 0 || (B[b.y][b.x] != B[b.y-1][b.x] && B[b.y-1][b.x] != '.')) {
                    left[i] = min(left[i], b.x);
                    right[i] = max(right[i], b.x);
                }
            }
        }

        loop (inc, i) {
            int cnt = 0;
            double cx = dfs_w(i, cnt);
            cx /= cnt;
            if (left[i] + EPS > cx || right[i] + 1 < cx + EPS) {
                cout << "UNSTABLE" << endl;
                goto NG;
            }
        }
        cout << "STABLE" << endl;
    }
    return 0;
}
