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
  int n; cin >> n;
  int a[n]; loop(n, i) cin >> a[i];

  int map[1000000] = {};

  int s = 0, t = 0, ans = 0;

  map[a[0]] = 1;
  while (s < n) {
    // おしりを進める
    while (t + 1 < n && map[a[t + 1]] == 0) {
      t++;
      map[a[t]] = 1;
    }

    ans = max(ans, t - s + 1);

    // 頭を進める
    map[a[s]] = 0;
    s++;
  }

  cout << ans << endl;
  return 0;
}
