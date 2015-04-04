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
int INF = 1000000;

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  int d[1000][1000];
  loop(1000, i) loop(1000, j) {
    if (i == j) d[i][j] = 0;
    else d[i][j] = INF;
  }

  loop(n-1, i) {
    int a, b;
    cin >> a >> b;
    d[a-1][b-1] = 1;
    d[b-1][a-1] = 1;
  }

  loop(n, k) loop(n, i) loop(n, j) {
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }

  int md = 0;
  int ma, mb;
  loop(n, i) loop(n, j) {
    if (d[i][j] > md) {
      md = d[i][j];
      ma = i;
      mb = j;
    }
  }

  cout << ma + 1 << " " << mb + 1 << endl;

  return 0;
}
