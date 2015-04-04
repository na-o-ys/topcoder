#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
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
  int n; cin >> n;
  int c[n];
  loop(n, i) cin >> c[i];

  double ans = 0;
  loop(n, i) {
    int d = 0;
    loop(n, j) {
      if (i == j) continue;
      if (c[i] % c[j] == 0) d++;
    }

    ans += ((d / 2) + 1) / (double)(d + 1);
  }

  cout << setprecision(12) << ans << endl;

  return 0;
}
