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

struct GCDSegmentTree {
  vector<int> v;
  int size, m;
  int *node;
  public:
    void add(int n) {v.push_back(n);}

    void init() {
      size=v.size();
      m=1; while(m<size) m*=2;
      node = new int[size+m-1];

      loop(size, i) node[m-1+i] = v[i];
      recursive_init(0);
    }

    int recursive_init(int n) {
      if (n >= size+m-1) return -1;
      if (n >= m-1) return node[n];
      node[n] = gcd(recursive_init(2*n+1), recursive_init(2*n+2));
      return node[n];
    }

    void update_range(int l, int r, int t) {
      int a=m-1+l, b=m-1+r-1;
      loop_from_to(a, b, i) node[i]+=t;
      while(a>0) {
        a=(a-1)/2, b=(b-1)/2;
        loop_from_to(a, b, i) node[i]=gcd(node[i*2+1], node[i*2+2]);
      }
    }

    void show() {
      int i=1;
      while(m >= i) {
        loop(i,j) {
          if(j >= size) break;
          cout << node[i-1+j] << " ";
        }
        cout << endl;
        i<<=1;
      }
    }

    int query(int a, int b) {
      return query(a, b, 0, 0, m);
    }

    int query(int a, int b, int k, int l, int r) {
      if (r<=a || b<=l) return -1;
      if (a<=l && r<=b) return node[k];
      int vl = query(a, b, k*2+1, l, (l+r)/2);
      int vr = query(a, b, k*2+2, (l+r)/2, r);
      return gcd(vl, vr);
    }

    int gcd(int a, int b) {
      if (a<0 || b<0) return max(a,b);
      if (a<b) swap(a,b);

      while(b>0) {
        int tmp=b;
        b=a%b;
        a=tmp;
      }
      return a;
    }
};

int main(int argc, char const* argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n; cin>>n;
  GCDSegmentTree tree;
  repeat(n) {int a; cin>>a; tree.add(a);}

  tree.init();
  // tree.show();

  int m; cin>>m;
  repeat(m) {
    int t, l, r; cin>>t>>l>>r;
    l--;
    if(t==0) cout<<tree.query(l, r)<<endl;
    else tree.update_range(l, r, t);
    // tree.show();
  }
  return 0;
}
