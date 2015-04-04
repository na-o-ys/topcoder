#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)
#define repeat(n) for(int i__=0;i__<n;i__++)
#define multi_cin(n, array) loop(n,i){cin>>array[i];}
#define assign_if_smaller(var, val) if(var>val)var=val;
#define assign_if_larger(var, val) if(var<val)var=val;
#define each(itr, c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)
#define r_each(itr, c) for(__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); itr++)

using namespace std;

const int MAX_V=400;
struct edge{int to; double v;};
vector<edge> units[MAX_V];
string label[MAX_V];
int V=0;

int get_index(string l) {
  loop(V,i) {
    if(label[i]==l) return i;
  }
  label[V]=l;
  return V++;
}

int main(int argc, char const* argv[])
{
  int n; cin>>n;
  loop(n,i) {
    string l,s;
    int m;
    cin>>l>>m>>s;

    int lu = get_index(l);
    int su = get_index(s);

    edge le={su,1.0/m};
    edge se={lu,1.0*m};
    units[lu].push_back(le);
    units[su].push_back(se);
  }

  vector<double> abs_units(V,-1.0);
  abs_units[0]=1;

  queue<int> q;
  q.push(0);

  while(q.size()) {
    int i=q.front(); q.pop();

    each(u, units[i]) {
      if(abs_units[u->to]<0) {
        abs_units[u->to] = abs_units[i]*u->v;
        q.push(u->to);
      }
    }
  }

  int M=0,m=0;
  loop(V,i) {
    if(abs_units[M]<abs_units[i]) M=i;
    if(abs_units[m]>abs_units[i]) m=i;
  }

  cout<<"1"<<label[M]<<"="<<(int)round(abs_units[M]/abs_units[m])<<label[m]<<endl;

  return 0;
}
