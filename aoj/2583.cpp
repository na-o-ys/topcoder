#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;

        vector<string> S(n);
        loop (n, i) cin >> S[i];

        vector<int> P(n), Ns(n), crr(n);
        loop (n, i) {
            int nst = 0;
            while (S[i][nst] == '.') nst++;
            Ns[i] = nst;
            if (nst) P[i] = crr[nst-1];
            else P[i] = -1;
            crr[nst] = i;

            loop (nst, j) S[i][j] = ' ';
            if (nst) S[i][nst-1] = '+';
        }

        loop (n, i) loop (n, j) {
            if (i >= j || P[i] != P[j]) continue;
            for (int k = i+1; k < j; k++) {
                if (P[i] != P[k]) S[k][Ns[P[i]]] = '|';
            }
        }

        for (auto s : S) cout << s << endl;
    }
    return 0;
}
