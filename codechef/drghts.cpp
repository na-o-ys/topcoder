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

const int MAX_V = 50000;

struct vertex {
  vector<vertex*> edge;
  int id;
  bool window;
};

vertex G[MAX_V];
bool visited[MAX_V];
int V, E;

// returns whether there is a descendent whose window is open
bool dfs(int &draughts, int &open_windows, int v, int p) {
  visited[v] = true;

  // window is open
  if (G[v].window) open_windows++;

  bool descendent_window = false;
  each(child, G[v].edge) {
    if ((*child)->id == p) continue;
    descendent_window = dfs(draughts, open_windows, (*child)->id, v) || descendent_window;
  }

  // (self or descendents)'s window is open
  if (descendent_window || (v != p && G[v].window)) draughts++;

  return descendent_window || G[v].window;
}

int main(int argc, char const* argv[])
{
  // init
  fill(visited, visited+MAX_V, false);

  cin>>V>>E;

  // read window conditions and init graph
  loop(V,i) {
    int w; scanf("%d", &w);
    if (w) G[i].window = true;
    else G[i].window = false;
    G[i].id = i;
  }

  // read edges
  loop(E,i) {
    int a, b; scanf("%d %d", &a, &b);
    G[a-1].edge.push_back(&G[b-1]);
    G[b-1].edge.push_back(&G[a-1]);
  }

  int draughts = 0;
  long long pairs = 0;
  for (int i=0;i<V;i++) {
    if (visited[i] || !G[i].window) continue;
    int open_windows = 0;
    dfs(draughts, open_windows, i, i);
    if (open_windows > 1) pairs += (long long)open_windows * (open_windows - 1) / 2;
  }

  cout << pairs << " " << draughts << endl;

  return 0;
}
