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
  int n;cin>>n;
  long long x[n],y[n];

  loop(n,i) cin>>x[i]>>y[i];

  int count = 0;
  loop(n,i) {
    loop_from_to(i+1,n-1,j) {
      loop_from_to(j+1,n-1,k) {
        long long area = x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j]);
        if (area && area%2 == 0) count++;
      }
    }
  }

  cout<<count<<endl;
  return 0;
}
