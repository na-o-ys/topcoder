#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

int main(int argc, char const* argv[])
{
  int w, h; cin >> w >> h;
  int n; cin >> n;

  int x[n], y[n];
  vector<pair<int, int>> perm(n);
  loop(n, i) {
    cin >> x[i] >> y[i];
  }
  bool field[w+1][h+1];

  loop(w, i) loop(h, j) {
    field[i+1][j+1] = true;
  }

  bool use[n];
  fill(use, use+n, false);
  int count = n;
  loop(n, i) {
    int next = 0;
    int __count = 0;
    loop(n, i) {
      if (use[i]) continue;
      bool _f[w+1][h+1];
      loop(w+1, i) loop(h+1, j) _f[i][j] = field[i][j];

      int _count = 0;
      loop(n, j) {
        if (i == j || use[j]) continue;

        int _x = x[j];
        int _y = y[j];

        // right
        loop_from_to(_x+1, w, ix) {
          if (!field[ix][_y]) break;
          _count++;
        }

        // left
        for (int ix = _x-1; ix > 0; ix--) {
          if (!field[ix][_y]) break;
          _count++;
        }

        // top
        for (int iy = _y+1; iy <= h; iy++) {
          if (!field[_x][iy]) break;
          _count++;
        }

        // bottom
        for (int iy = _y-1; iy > 0; iy--) {
          if (!field[_x][iy]) break;
          _count++;
        }
      }

      if (__count < _count) {
        next = i;
        use[i] = true;
      }
    }

    int _x = x[next];
    int _y = y[next];

    field[_x][_y] = false;

    // right
    loop_from_to(_x+1, w, ix) {
      if (!field[ix][_y]) break;
      count++;
      field[ix][_y] = false;
    }

    // left
    for (int ix = _x-1; ix > 0; ix--) {
      if (!field[ix][_y]) break;
      count++;
      field[ix][_y] = false;
    }

    // top
    for (int iy = _y+1; iy <= h; iy++) {
      if (!field[_x][iy]) break;
      count++;
      field[_x][iy] = false;
    }

    // bottom
    for (int iy = _y-1; iy > 0; iy--) {
      if (!field[_x][iy]) break;
      count++;
      field[_x][iy] = false;
    }
  }

  cout << count << endl;
  return 0;
}
