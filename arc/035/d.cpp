#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;
const int MAX = 1000010;
double fact[MAX];

template <typename T>
class BIT
{
public:
    vector<T> bit;
    int M;

    BIT(int M): bit(vector<T>(M+1, 0)), M(M) {}

    T sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, T x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }

    T get(int i) {
        if (!i) return 0;
        return sum(i) - sum(i-1);
    }

    void set(int i, T x) {
        add(i, x - get(i));
    }

    T range(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

double comb(int n, int m)
{
    return fact[n] - fact[m] - fact[n-m];
}

int main()
{
    fact[0] = 0;
    loop (MAX-1, i) {
        fact[i+1] = fact[i] + log2(i+1);
    }

    int N; cin >> N;
    vector<int> p(N+1), q(N+1);
    loop (N, i) {
        cin >> p[i+1] >> q[i+1];
    }

    BIT<double> prod(N);
    for (int i = 1; i < N; i++) {
        prod.set(i, comb(p[i+1] - p[i] + q[i+1] - q[i], p[i+1] - p[i]));
    }

    int Q; cin >> Q;
    loop (Q, i) {
        int t; cin >> t;
        if (t == 1) {
            int k; cin >> k;
            cin >> p[k] >> q[k];
            for (int j = max(1, k-1); j <= min(k, N-1); j++) {
                prod.set(j, comb(p[j+1] - p[j] + q[j+1] - q[j], p[j+1] - p[j]));
            }
        } else {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            vector<double> V = {
                prod.range(l1, r1),
                prod.range(l2, r2)
            };
            cout << (V[0] > V[1] ? "FIRST" : "SECOND") << endl;
        }
    }
    return 0;
}
