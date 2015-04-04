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

vector<int> G[100001];

pair<int, int> dfs(int parent, int curr) {
  int max_distance = 0;
  int node = curr;

  for(auto n : G[curr]) {
    if (n == parent) continue;
    auto m = dfs(curr, n);

    if (m.first + 1 > max_distance) {
      max_distance = m.first + 1;
      node = m.second;
    }
  }

  return make_pair(max_distance, node);
}

int main(int argc, char const* argv[])
{
  int n; cin >> n;
  loop(n-1, i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  auto s = dfs(-1, 0);
  auto t = dfs(-1, s.second);

  cout << s.second+1 << " " << t.second+1 << endl;
  
  return 0;
}
