#include <iostream>
#include <vector>
#include <algorithm>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define from_to(from, to, i) for(int i=from;i<=to;i++)

using namespace std;
using ll = long long;

class SegTree
{
    static const int MAX_N = 1<<17;
    int nodes, dat[2*MAX_N-1];

    int query(int a, int b, int k , int l, int r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return dat[k];
        else {
            int v1 = query(a, b, k*2+1, l, (l+r)/2);
            int v2 = query(a, b, k*2+2, (l+r)/2, r);
            return max(v1, v2);
        }
    }

public:
    SegTree(int n) {
        nodes = 1;
        while (nodes < n) nodes *= 2;
        fill(dat, dat+2*MAX_N-1, 0);
    }

    void set(int k, int a) {
        k += nodes-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }

    int query(int a, int b) { return query(a, b, 0, 0, nodes); }
};

int main(int argc, char const* argv[])
{
    int N; cin >> N;

    auto t = SegTree(N);
    loop (N, i) {
        int h; cin >> h;
        t.set(i, h);
    }

    loop (N, i) {
        ;
    }
    return 0;
}
