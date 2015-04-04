#include <bits/stdc++.h>
 
using namespace std;
 
#define long int64_t
 
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<(b);++i)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))
 
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define eb emplace_back
 
int n;
vector<vector<int> > G;
 
void input()
{
    cin >> n;
    G.assign(n, vector<int>());
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b, --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
}
 
int farthest(int s)
{
    int ret = -1;
    vector<int> d(n, 1000000);
 
    queue<int> q;
    q.push(s), d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        ret = v;
        q.pop();
 
        rep(i, int(G[v].size())) {
            const int nv = G[v][i];
            if (d[nv] > d[v] + 1) {
                q.push(nv), d[nv] = d[v] + 1;
            }
        }
    }
 
    return ret;
}
 
void solve()
{
    int s = farthest(0);
    int t = farthest(s);
 
    cout << s + 1 << ' ' << t + 1 << endl;
}
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    input();
    solve();
 
    return 0;
}
