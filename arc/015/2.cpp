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
  int n; cin>>n;
  int out[6];
  fill(out,out+6,0);
  while(n--) {
    float M,m; cin>>M>>m;
    if(M>=35) out[0]++;
    if(M>=30 && M<35) out[1]++;
    if(M>=25 && M<30) out[2]++;
    if(m>=25) out[3]++;
    if(m<0 && M>=0) out[4]++;
    if(M<0) out[5]++;
  }
  loop(5,i) cout<<out[i]<<" ";
  cout<<out[5]<<endl;
  return 0;
}
