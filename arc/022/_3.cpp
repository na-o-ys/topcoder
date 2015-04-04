#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
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
  int n;
  cin >> n;
  if (n > 1001) return 0;

  vector<int> G[1000];
  loop(n-1, i) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int max_distance = 0;
  int ma, mb;

  loop(n, i) {
    queue<pair<int, int>> q;
    bool b[n];
    fill(b, b+n, false);

    q.push(make_pair(i, 0));
    b[i] = true;
    while (!q.empty()) {
      auto v = q.front();
      q.pop();

      int count = 0;
      each(t, G[v.first]) {
        if (!b[*t]) {
          q.push(make_pair(*t, v.second + 1));
          b[*t] = true;
          count++;
        }
      }

      if (count == 0) {
        if (v.second > max_distance) {
          max_distance = v.second;
          ma = i;
          mb = v.first;
        }
      }
    }
  }

  cout << ma+1 << " " << mb+1 << endl;
  return 0;
}
