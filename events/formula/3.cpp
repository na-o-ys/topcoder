#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;
struct info { int id; int rank; int num; bool fix; };

int main(int argc, char const* argv[])
{
    int n, k; cin >> n >> k;
    unordered_map<int, info*> t;
    vector<info*> C;
    loop (n, i) {
        loop (k, j) {
            int a; cin >> a;
            if (t.find(a) != t.end() && t[a]->rank <= j) continue;
            if (t.find(a) == t.end()) {
                auto I = new info { a, j, i, false };
                t[a] = I;
                C.push_back(I);
            } else if (t[a]->rank > j) {
                t[a]->rank = j;
                t[a]->num = i;
            }
        }

        sort(C.begin(), C.end(), [](const info *a, const info *b) {
                return (a->rank < b->rank) || (a->rank == b->rank && a->num < b->num);
                });

        vector<int> fix;
        loop (C.size(), m) {
            if ((n-i-1) * C[m]->rank < k - m && !C[m]->fix) {
                fix.push_back(C[m]->id);
                C[m]->fix = true;
            }
        }
        sort(fix.begin(), fix.end());

        if (fix.size() > 1) loop (fix.size()-1, m) cout << fix[m] << " ";
        if (fix.size()) cout << fix[fix.size()-1];
        cout << endl;
    }
    return 0;
}
