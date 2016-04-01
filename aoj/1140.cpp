#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
struct Pos { int x, y; };
struct State { int d, x, y; };

vector<Pos> Node;
vector<string> B;
int dist[11][11];
const int INF = 1<<29;

int dirs[] = { -1, 0, 1, 0, -1 };
void bfs(int i)
{
    Pos p = Node[i];
    int vis[21][21] = {};

    queue<State> Q;
    Q.push({ 0, p.x, p.y });
    while (Q.size()) {
        State v = Q.front(); Q.pop();
        if (vis[v.x][v.y]) continue;
        vis[v.x][v.y] = 1;
        char b = B[v.y][v.x];
        if (b >= '0' && b <= '9') {
            dist[i][b-'0'] = v.d;
            dist[b-'0'][i] = v.d;
        }

        loop (4, i) {
            int x = v.x + dirs[i], y = v.y + dirs[i+1];
            if (x >= 0 && x < B[0].size() && y >= 0 && y < B.size()) {
                if (B[y][x] != 'x' && !vis[x][y]) {
                    Q.push({ v.d + 1, x, y });
                }
            }
        }
    }
}

int memo[11][2000];
int dfs(int curr, int vis)
{
    if (memo[curr][vis] != -1) return memo[curr][vis];
    int n = Node.size();
    if (vis == ((1 << n) - 1)) return 0;
    int ans = INF;
    loop (n, i) {
        if (vis >> i & 1) continue;
        ans = min(ans, dist[curr][i] + dfs(i, vis | 1 << i));
    }
    memo[curr][vis] = ans;
    return ans;
}

int main()
{
    while (1) {
NG:
        fill(dist[0], dist[10]+11, INF);
        int w, h; cin >> w >> h;
        if (!w) break;

        B = vector<string>(h);
        loop (h, i) cin >> B[i];

        Node = vector<Pos>(1);
        loop (h, y) loop (w, x) {
            if (B[y][x] == 'o') {
                B[y][x] = '0';
                Node[0] = { x, y };
            }
            if (B[y][x] == '*') {
                B[y][x] = '0' + Node.size();
                Node.push_back({ x, y });
            }
        }

        loop (Node.size(), i) bfs(i);

        loop (Node.size(), i) {
            if (dist[0][i] == INF) {
                cout << -1 << endl;
                goto NG;
            }
        }

        fill(memo[0], memo[10] + 2000, -1);
        cout << dfs(0, 1) << endl;
    }
    return 0;
}
