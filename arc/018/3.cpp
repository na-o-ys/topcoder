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

void show_cols(vector<vector<int>> cols) {
  loop(cols.size(),i) {
    loop(cols[i].size(),j) {
      cout << cols[i][j] << " ";
    }

    cout<<endl;
  }
}

int main(int argc, char const* argv[])
{
  int n,m;cin>>n>>m;
  int x[n*m];
  int g[n*m];
  int a,p;
  cin>>x[0]>>a>>p;
  g[0]=x[0];
  loop_from_to(1,n*m-1,i) {
    x[i]=(x[i-1]+a)%p;
    g[i]=x[i];
  }
  if (n*m>2 && m>=2 && x[1]==x[2]) {
    if (x[0]<=x[1]) {
      cout<<0<<endl;
    } else {
      cout<<2*(n-1)<<endl;
    }
    return 0;
  }

  long long count=0;
  vector<vector<int>> cols(n);

  int col[n];
  sort(g,g+n*m);
  loop(n,i) {
    col[i] = g[i*m];
    // cout<<i<<" "<<col[i]<<endl;
  }

  // vertical move
  loop(n,i) loop(m,j) {
    // cout<<x[i*m+j]<<": ";
    int c = lower_bound(col,col+n,x[i*m+j]+1)-col-1;
    // cout<<c<<endl;
    count+=c>i?c-i:i-c;
    cols[c].push_back(j);
  }

  // show_cols(cols);

  // horizontal move
  loop(n,i) {
    sort(cols[i].begin(),cols[i].end());
    loop(m,j) {
      count+=cols[i][j]>j?cols[i][j]-j:j-cols[i][j];
    }
  }
  cout<<count<<endl;

  return 0;
}
