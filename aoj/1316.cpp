#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int dx[] = { -1, -1, 1, 1  };
int dy[] = { -1,  1, 1, -1 };

int gcd(int a, int b)
{
    if (!a) return b;
    return gcd(b % a, a);
}

int main()
{
    string B[11];
    while (1) {
        vector<string> spells;
        int h, w; cin >> h >> w;
        if (!h) break;

        loop (h, i) cin >> B[i];

        int m = h * w / gcd(h, w);
        loop (h, i) loop (w, j) {
            int x = i, y = j;
            string left(w, ' ');
            left[0] = B[i][j];
            loop (w, k) {
                left[k] = B[x][y];
                y = (y + w - 1) % w;
            }
            spells.push_back(left);
            string right(w, ' ');
            x = i, y = j;
            loop (w, k) {
                right[k] = B[x][y];
                y = (y + 1) % w;
            }
            spells.push_back(right);
            string up(h, ' ');
            x = i, y = j;
            loop (h, k) {
                up[k] = B[x][y];
                x = (x + h - 1) % h;
            }
            spells.push_back(up);
            string down(h, ' ');
            x = i, y = j;
            loop (h, k) {
                down[k] = B[x][y];
                x = (x + 1) % h;
            }
            spells.push_back(down);

            vector<string> diags(4);
            loop (4, k) diags[k] = string(m, ' ');
            loop (4, p) {
                x = i, y = j;
                loop (m, k) {
                    diags[p][k] = B[x][y];
                    x = (x + dx[p] + h) % h;
                    y = (y + dy[p] + w) % w;
                }
            }
            spells.insert(spells.end(), diags.begin(), diags.end());
        }

        sort(all(spells));
        int l = spells.size();

        int m_cnt = 1;
        string ans;
        loop (l-1, i) {
            int j = 0;
            int len = min(spells[i].size(), spells[i+1].size());
            while (j < len && spells[i][j] == spells[i+1][j]) j++;
            if (j > m_cnt) {
                m_cnt = j;
                ans = spells[i].substr(0, j);
            }
        }
        if (m_cnt == 1) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
