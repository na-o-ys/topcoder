#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define loop_from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

int main(int argc, char const* argv[])
{
    char colors[5] = { 'R', 'G', 'B', 'Y', 'W' };
    int n; cin >> n;
    int cards[5][5] = {};
    loop(n, i) {
        string s; cin >> s;
        int col = 0;
        while (colors[col] != s[0]) col++;
        int num = s[1]-'1';
        cards[col][num] = 1;
    }
    int ans = 20;
    loop(5, col) {
        loop(5, num) cout << cards[col][num] << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; (i>>10) == 0; i++) {
        while (1) {
            bool cf = false;
            loop(5, col) loop(5, num) {
                if (!cards[col][num]) continue;
                if (!((i>>col)&1) && !((i>>(num+5))&1)) continue;
                if (((i>>col)&1) && ((i>>(num+5))&1)) {
                    cards[col][num] = 0;
                    cf = true;
                    continue;
                }
                bool ng = false;
                if ((i>>col)&1) {
                    loop(5, k) if (k != num && cards[col][k]) ng = true;
                }
                if ((i>>(num+5))&1) {
                    loop(5, k) if (k != col && cards[k][num]) ng = true;
                }
                if (!ng) {
                    cards[col][num] = 0;
                    cf = true;
                    // continue;
                    if (i == 128) {
                        loop(5, col) {
                            loop(5, num) cout << cards[col][num] << " ";
                            cout << endl;
                        }
                        cout << endl;
                    }
                }
            }
            
            if (!cf) break;
        }

        int cnt = 0;
        loop(5, col) loop(5, num) cnt += cards[col][num];
        if (cnt > 1) continue;

        int asks = 0;
        loop(10, j) if ((i>>j)&1) asks++;
        ans = min(ans, asks);
    }

    cout << ans << endl;
    return 0;
}
