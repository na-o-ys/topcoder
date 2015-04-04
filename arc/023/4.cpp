#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main(int argc, char const* argv[])
{
  int n, m;
  cin >> n >> m;
  unordered_map<int, ll> prev;
  unordered_map<int, ll> count;

  loop(n, i) {
    unordered_map<int, ll> crr;
    int a; cin >> a;

    crr[a]++;

    for (auto&& p : prev) {
      int g = gcd(p.first, a);
      crr[g] += p.second;
    }

    for (auto&& p : crr) {
      count[p.first] += p.second;
    }

    prev = crr;
  }

  loop(m, i) {
    int b; cin >> b;
    cout << count[b] << endl;
  }
  return 0;
}
