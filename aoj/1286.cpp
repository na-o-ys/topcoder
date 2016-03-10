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
        int n, m, k; cin >> n >> m >> k;
        if (!n) break;

        int N = pow(m, n);
        double a = 0;
        loop (N, I) {
            int i = I, sum = 0;
            loop (n, j) {
                sum += (i % m) + 1;
                i /= m;
            }
            sum = max(sum - k, 1);
            a += sum;
        }
        cout << setprecision(9) << fixed;
        cout << a / N << endl;
    }
    return 0;
}
