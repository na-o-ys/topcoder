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

ll incl(ll n, int d, ll fill, ll all, ll zero) {
  if (n == 0) {
    if (d == 0) return zero;
    return fill;
  }

  int p = n % 10;
  ll fi = 0, al = 0, ze = 0;
  loop_from_to(0, 9, i) {
    if (i == 0) ze += zero;

    if (i == d) continue;
    al += all;
    if (n < 10 && i < p) ze += all;
    if (n < 10 && i == p) ze += fill;
    if (n > 9) ze += all;
    if (i < p) fi += all;
    if (i == p) fi += fill;
  }
  return incl(n / 10, d, fi, al, ze);
}

ll incl(ll n, int d) {
  return n - (incl(n, d, 1, 1, 0) - incl(0, d, 1, 1, 0));
}

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main(int argc, char const* argv[])
{
  // int w; cin >> w;
  // int v; cin >> v;
  // cout << incl(w, v) << endl;
  // return 0;
  int t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    ll num = 0;
    loop_from_to(0, 9, i) {
      num += incl(n, i);
    }
    cout << num << endl;
    ll g = gcd(num, n*10);
    cout << (num / g) << "/" << (n*10 / g) << endl;
  }
  return 0;
}
