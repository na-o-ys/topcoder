#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

int x[30];
int y[30];
int n;
unordered_map<string, int> memo;

int solve(int x1, int y1, int x2, int y2) {
  stringstream ss;
  ss << x1 << ":" << y1 << ":" << x2 << ":" << y2;
  string key = ss.str();
  if (memo.find(key) != memo.end()) return memo[key];

  int ans = 0;
  loop(n, i) {
    if (x1 > x[i] || y1 > y[i] || x2 < x[i] || y2 < y[i]) continue;

    int count = (x2 - x1) + (y2 - y1) + 1;
    count += solve(x1, y1, x[i]-1, y[i]-1);
    count += solve(x[i]+1, y[i]+1, x2, y2);
    count += solve(x[i]+1, y1, x2, y[i]-1);
    count += solve(x1, y[i]+1, x[i]-1, y2);
    assign_if_larger(ans, count);
  }

  return memo[key] = ans;
}

int main(int argc, char const* argv[])
{
  int w, h; cin >> w >> h;
  cin >> n;
  loop(n, i) cin >> x[i] >> y[i];

  cout << solve(1, 1, w, h) << endl;
  return 0;
}
