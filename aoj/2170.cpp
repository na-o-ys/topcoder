#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

class UnionFind {
public:
    vector<int> par;
    UnionFind(vector<int> par) : par(par) {}
    int get_root(int i) {
        if (par[i] == i) return i;
        return par[i] = get_root(par[i]);
    }
    void set_root(int i, int root) {
        par[i] = get_root(root);
    }
};

int main()
{
    while (1) {
        int n, q; cin >> n >> q;
        if (!n) break;

        vector<int> par(n);
        loop (n-1, i) {
            cin >> par[i+1];
            par[i+1]--;
        }

        vector<char> type(q);
        vector<int> val(q);
        loop (q, i) {
            cin >> type[i] >> val[i];
            val[i]--;
        }

        vector<int> marked(n);
        loop (q, i) {
            if (type[i] == 'M') {
                if (marked[val[i]]) type[i] = 'x';
                else marked[val[i]] = 1;
            }
        }

        vector<int> ufpar(n);
        loop (n, i) {
            if (marked[i]) ufpar[i] = i;
            else ufpar[i] = par[i];
        }

        UnionFind UF(ufpar);

        ll ans = 0;
        loop (q, i) {
            int j = q - 1 - i;
            if (type[j] == 'Q') {
                ans += UF.get_root(val[j]) + 1;
            }
            if (type[j] == 'M') {
                UF.set_root(val[j], par[val[j]]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
