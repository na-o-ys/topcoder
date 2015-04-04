#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
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
  int n; cin>>n;
  int d[51][51]={};
  int ans[2501]={};
  loop(n,x) loop(n,y) {
    cin>>d[x+1][y+1];
  }

  loop(n,x) loop(n,y) {
    d[x+1][y+1]+=d[x][y+1];
  }
  loop(n,x) loop(n,y) {
    d[x+1][y+1]+=d[x+1][y];
  }

  loop(n,x0) loop(n,y0) loop(n,x1) loop(n,y1) {
    if (x0>x1 || y0>y1) continue;
    int area = (x1-x0+1)*(y1-y0+1);
    int val = d[x1+1][y1+1] - d[x0][y1+1] - d[x1+1][y0] + d[x0][y0];
    assign_if_larger(ans[area], val);
  }

  loop(n*n,i) assign_if_larger(ans[i+1], ans[i]);
  
  int q; cin>>q;
  while(q--) {
    int p; cin>>p;
    cout<<ans[p]<<endl;
  }

  return 0;
}
