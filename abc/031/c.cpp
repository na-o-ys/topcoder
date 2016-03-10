//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> A(n);
    loop (n, i) cin >> A[i];
    int ans = -(1<<29);
    loop (n, i) {
        int m_aok = -(1<<29);
        int m_j = 0;
        loop (n, j) {
            if (i == j) continue;
            int a = i, b = j, s = 0;
            if (a > b) swap(a, b);
            for (int k = a+1; k <= b; k += 2) {
                s += A[k];
            }
            if (s > m_aok) {
                m_aok = s;
                m_j = j;
            }
        }
        int a = i, b = m_j, s = 0;
        if (a > b) swap(a, b);
        for (int k = a; k <= b; k += 2) {
            s += A[k];
        }
        if (s > ans) ans = s;
    }
    cout << ans << endl;
    return 0;
}
