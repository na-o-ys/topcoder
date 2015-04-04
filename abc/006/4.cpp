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
  int c[n];
  loop(n, i) {
    cin >> c[i];
  }

  int d[n];
  fill(d, d+n, 0);
  loop(n, i) {
    int j = c[i]-1;
    d[j]++;
    j++;
    while(1) {
      if (j > n) break;
      if (d[j] >= d[c[i]-1]) break;
      d[j]++;
      j++;
    }
    //loop(i, j) {
    //  if (c[i] > c[j] && d[j] >= d[i]) d[i] = d[j] + 1;
    //}
  }
  
  //loop(n, i) cout << i << ":" << d[i] << endl;

  cout << n - *max_element(d, d+n) << endl;
  return 0;
}
