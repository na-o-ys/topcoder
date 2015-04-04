#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, N;
char s1[11], s2[11];
map<string, int> mp;
vector<string> names;
vector<pair<int, double> > e[400];

int gao(string s) {
  if (mp.find(s) == mp.end()) {
    mp[s] = (int)names.size();
    names.push_back(s);
  }
  return mp[s];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d%s", s1, &m, s2);
    int id1 = gao(s1);
    int id2 = gao(s2);
    e[id1].push_back({id2, 1.0 / m});
    e[id2].push_back({id1, 1.0 * m});
  }
  N = (int)names.size();

  vector<double> c(N, -1.0);
  c[0] = 1.0;
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i : e[u]) {
      int v = i.first;
      double t = i.second;
      if (c[i.first] >= 0.0) {
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

  printf("1%s=%.0f%s\n", names[large].c_str(), c[large] / c[small], names[small].c_str());

  return 0;
}
