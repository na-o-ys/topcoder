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
typedef long long ll;
const ll MAX = 1ll<<61;

int main(int argc, char const* argv[])
{
  int k, n; cin >> k >> n;
  ll a[n], d[n];
  loop(n, i) cin >> a[i] >> d[i];

  ll left = 0, right = 1000000000000000ll;
  while(left < right) {
    ll center = (left + right) / 2;
    ll c = 0;

    // calc c
    loop(n, i) {
      if (center < a[i]) continue;
      c += (center - a[i]) / d[i] + 1;
    }

    if (c < k) {
      left = center + 1;
      continue;
    }
    right = center;
  }

  ll cost = 0;
  ll count = 0;
  loop(n, i) {
    if (left - 1 < a[i]) continue;
    ll c = (left - 1 - a[i]) / d[i] + 1;
    count += c;
    cost += a[i] * c + (c * (c - 1) / 2) * d[i];
  }

  cost += (k - count) * left;
  cout << cost << endl;

  return 0;
}
