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

typedef long long ll;

const int P = 1000000007;

int mult(int a, int b) {
  ll aa = a, bb = b;
  return (aa * bb) % P;
}

int modpow(int n, int m) {
  int k = n;
  int ans = 1;
  loop(32, i) {
    if ((m & (1 << i)) != 0) {
      ans = mult(ans, k);
    }
    k = mult(k, k);
  }
  return ans;
}

int divmod(int n, int d) {
  int r = modpow(d, P - 2);
  return mult(n, r);
}

int pascal(int w, int d) {
  int ans = 1;
  loop(w, i) {
    ans = divmod(mult(ans, d - i), i + 1);
  }
  return ans;
}

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  int A[2000];
  loop(n, i) cin >> A[i];

  int ans = 1;
  int count = 0;
  int l = 1;

  loop(n, i) {
    if (A[i] == -1) {
      count++;
    } else {
      if (count > 0) {
        int p = pascal(count, A[i] - l + count);
        ans = mult(ans, p);
        count = 0;
      }
      l = A[i];
    }
  }

  cout << ans << endl;
  return 0;
}
