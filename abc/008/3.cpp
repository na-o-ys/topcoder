#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
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
  vector<int> coins(n);
  loop(n, i) cin >> coins[i];

  int count = 0;
  int trial = 0;

  int perm[n];
  loop(n, i) {
    perm[i] = i;
  }

  do {
    bool fliped[n];
    fill(fliped, fliped+n, false);

    loop(n, i) {
      loop_from_to(i+1, n-1, j) {
        if ((coins[perm[j]] % coins[perm[i]]) == 0) {
          fliped[j] = !fliped[j];
        }
      }
    }

    loop(n, i) {
      if (!fliped[i]) count++;
    }

    trial++;
  } while (next_permutation(perm, perm+n));

  cout << setprecision(16) << (double)count / trial << endl;
  return 0;
}
