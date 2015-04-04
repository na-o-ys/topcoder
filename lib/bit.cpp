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

