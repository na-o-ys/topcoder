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

typedef long long ll;
using namespace std;

const int MOD = 1000000007;

ll perm(ll n) {
  ll res = 1;
  loop(n,i) res = res*(i+1) % MOD;
  return res;
}

ll inv(ll n) {
  ll pow[32];
  pow[0] = n;
  loop_from_to(1,31,i) pow[i] = pow[i-1] * pow[i-1] % MOD;
  ll ret = 1;
  loop(32,i) {
    if (((MOD-2)>>i)&1) ret = (ret * pow[i]) % MOD;
  }
  return ret;
}

ll calc_pattern(int x, int y, int d, int l) {
  int e = x * y - d - l;
  ll res = perm(x*y);
  ll inv_fact_d = inv(perm(d));
  ll inv_fact_l = inv(perm(l));
  res = res * inv(perm(d)) % MOD;
  res = res * inv(perm(l)) % MOD;
  res = res * inv(perm(e)) % MOD;

  auto exclude_pattern = [inv_fact_d, inv_fact_l](int x, int y, int e) {
    ll p = perm(x*y);
    p = p * inv_fact_d % MOD;
    p = p * inv_fact_l % MOD;
    return p * inv(perm(e)) % MOD;
  };

  if (e < x && e < y) return res;

  if (e >= x && e < 2*x && e < y);
  if (e >= y && e < 2*y && e < x);
  if (e >= 2*x && e < y);
  if (e >= 2*y && e < x);
  if (e >= x && e < 2*x && e >= y && e < 2*y);
  if (e >= 2*x && e >= y && e < 2*y);
  if (e >= 2*y && e >= x && e < 2*x);
  if (e >= 2*x && e >= 2*y);

  ll top = 0;
  if (e >= x) top = exclude_pattern(x-1, y, e-x);

  ll left = 0;
  if (e >= y) left = exclude_pattern(x, y-1, e-y);

  ll top_left = 0;
  if (e >= x + y) top_left = exclude_pattern(x-1, y-1, e-x-y);

  return res;
}

int main(int argc, char const* argv[])
{
  int r,c,x,y,d,l; cin>>r>>c>>x>>y>>d>>l;

  ll pat = calc_pattern(x,y,d,l);
  ll ans = (pat * (r-x+1) * (c-y+1)) % MOD;

  cout << ans << endl;
  return 0;
}
