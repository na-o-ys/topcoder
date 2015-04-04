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
  int n,m; cin>>n>>m;
  int xz,a,p; cin>>xz>>a>>p;

  // if not unique
  if(a%p==0) {
    if(xz<=p) {
      cout<<0<<endl;
      return 0;
    } else {
      cout<<2*(n-1)<<endl;
      return 0;
    }
  }

  vector<tuple<int,int,int>> x(n*m);
  x[0] = make_tuple(xz,0,0);
  loop_from_to(1,n*m-1,i) x[i] = make_tuple((get<0>(x[i-1])+a)%p,i/m,i%m);

  int count=0;
  vector<vector<int>> moved(n);

  sort(x.begin(),x.end());

  // vertical move
  loop(n,i) loop(m,j) {
    count += abs(get<1>(x[i*m+j])-i);
    moved[i].push_back(get<2>(x[i*m+j]));
  }

  // horizontal move
  loop(n,i) {
    sort(moved[i].begin(),moved[i].end());
    loop(m,j) count += abs(moved[i][j]-j);
  }

  cout<<count<<endl;
  return 0;
}
