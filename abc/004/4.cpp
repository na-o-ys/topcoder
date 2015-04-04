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

int calc_cost(int base, int start, int n) {
  int left_start  = min(start, base);
  int left_end    = min(start+n-1, base);
  int right_start = max(base, start);
  int right_end   = max(start+n-1, base);

  return (base-left_start + base-left_end) * (left_end - left_start + 1) / 2
    + (right_start-base + right_end-base) * (right_end - right_start + 1) / 2;
}

int main(int argc, char const* argv[])
{
  int r,g,b; cin>>r>>g>>b;
  int n = r+g+b;
  long ans=1000000;

  // fix green position
  loop_from_to(-1000,1000,g_i) {
    // green cost
    long cost = calc_cost(0,g_i,g);

    // red cost
    if (-100 + (r - 1)/2 >= g_i)
      cost += calc_cost(-100,(g_i - r),r);
    else
      cost += calc_cost(-100,(-100 - (r - 1)/2),r);

    // blue cost
    if (100 - (b - 1)/2 <= g_i + g - 1)
      cost += calc_cost(100,(g_i + g),b);
    else
      cost += calc_cost(100,(100 - (b - 1)/2),b);

    assign_if_smaller(ans, cost);
  }

  cout<<ans<<endl;
  return 0;
}
