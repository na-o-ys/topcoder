#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

#define loop(n, i) for(int i=0;i<n;i++)
using namespace std;
const int MAX_V=400;

int n, m, N;
char s1[11],s2[11];

struct edge{int to; double v;};
vector<edge> units[MAX_V];

int V=0;
string label[MAX_V];
int get_index(string l) {
  loop(V,i) {
    if(label[i]==l) return i;
  }
  label[V]=l;
  return V++;
}

int main(int argc, char const* argv[])
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d%s", s1, &m, s2);
    int id1 = get_index(s1);
    int id2 = get_index(s2);
    edge e1={id2, 1.0 / m};
    edge e2={id1, 1.0 * m};
    units[id1].push_back(e1);
    units[id2].push_back(e2);
  }
  N = V;

  vector<double> c(N, -1.0);
  c[0] = 1.0;
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i : units[u]) {
      int v = i.to;
      double t = i.v;
      if (c[i.to] >= 0.0) {
        continue;
      }
      c[v] = c[u] * t;
      q.push(v);
    }
  }
  int large = 0, small = 0;
  for (int i = 0; i < N; ++i) {
    if (c[i] > c[large]) {
      large = i;
    }
    if (c[i] < c[small]) {
      small = i;
    }
  }

  printf("1%s=%.0f%s\n", label[large].c_str(), c[large] / c[small], label[small].c_str());

  return 0;
}
