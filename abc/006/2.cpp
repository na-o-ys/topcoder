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

const int MAX = 10000001;
const int MOD = 10007;
int m[MAX];
int calc(int n) {
  if(m[n-1] == -1) m[n-1] = (calc(n-1) + calc(n-2) + calc(n-3)) % MOD;

  return m[n-1];
}

int main(int argc, char const* argv[])
{
  fill(m, m+MAX, -1);
  m[0] = 0;
  m[1] = 0;
  m[2] = 1;

  int n; cin >> n;
  cout << calc(n) << endl;
  return 0;
}

