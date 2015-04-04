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
  int n, m; cin >> n >> m;

  if (m < 2*n ||  m > 4*n) {
    cout << "-1 -1 -1" << endl;
    return 0;
  }

  m -= 2*n;
  if (m > n) {
    cout << 0 << " " << 2 * n - m << " " << m - n << endl;
    return 0;
  }

  cout << n - m << " " << m << " " << 0 << endl;

  return 0;
}
