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
typedef long long ll;

int main(int argc, char const* argv[])
{
  int l; cin >> l;

  ll b[l];
  ll ans[l];
  for(ll i = 0; i < l; i++) {
    cin >> b[i];
    ans[i] = 0;
  }

  loop(30, j) {
    loop_from_to(1, l-1, i) { 
      ans[i] += (((b[i-1] >> j) & 1) ^ ((ans[i-1] >> j) & 1)) << j;
    }
    if ((((ans[l-1] >> j) & 1) ^ ((ans[0] >> j) & 1)) != ((b[l-1]) >> j & 1)) {
      cout << -1 << endl;
      return 0;
    }
  }

  for(ll i = 0; i < l; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
