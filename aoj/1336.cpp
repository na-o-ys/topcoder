#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> T;

int main()
{
    while (1) {
        int n, l; cin >> n >> l;
        if (!n) break;

        vector<T> crr;
        loop (n, i) {
            char d; int p; cin >> d >> p;
            int id = d == 'L' ? -1 : 1;
            crr.emplace_back(p, i, id);
        }
        sort(all(crr));

        int time = 0;
        while (1) {
            if (crr.size() <= 2) {
                int ok = 1;
                for (T a : crr) {
                    int p = get<0>(a);
                    ok = ok && (p == 0 || p == l);
                }
                if (ok) {
                    cout << time << " " << get<1>(crr[0])+1 << endl;
                    break;
                }
            }
            vector<T> next;
            for (T a : crr) {
                int p = get<0>(a), id = get<1>(a), d = get<2>(a);
                if (p+d >= 0 && p+d <= l) {
                    next.emplace_back(p+d, id, d);
                }
            }
            sort(all(next));
            loop (next.size()-1, i) {
                if (get<0>(next[i]) == get<0>(next[i+1])) {
                    next[i] = T{
                        get<0>(next[i]),
                        get<1>(next[i]),
                        -get<2>(next[i])
                    };
                    next[i+1] = T{
                        get<0>(next[i+1]),
                        get<1>(next[i+1]),
                        -get<2>(next[i+1])
                    };
                }
            }
            crr = next;
            time++;
        }
    }
    return 0;
}
