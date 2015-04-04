#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;
typedef pair<int, int> P;
const int INF = 100000000;

int main(int argc, char const* argv[])
{
  int r, c; cin >> r >> c;
  int sy, sx; cin >> sy >> sx;
  sy--; sx--;
  int gy, gx; cin >> gy >> gx;
  gy--; gx--;

  int board[c][r];

  loop(r, i) loop(c, j) {
    char m; cin >> m;
    if (m == '#') board[j][i] = -1;
    else board[j][i] = INF;
  }

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  queue<P> que;
  que.push(P(sx, sy));
  board[sx][sy] = 0;
  while(que.size()) {
    P p = que.front(); que.pop();
    if (p.first == gx && p.second == gy) break;

    loop(4, i) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;

      if (board[nx][ny] == INF) {
        que.push(P(nx, ny));
        board[nx][ny] = board[p.first][p.second] + 1;
      }
    }
  }

  cout << board[gx][gy] << endl;
  return 0;
}
