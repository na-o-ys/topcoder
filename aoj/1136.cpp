#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

template <typename T>
class Mat
{
    vector<vector<T>> mat;
    int rows, columns;
public:
    Mat<T>(int r, int c) : rows(r), columns(c) {
        mat = vector<vector<T>>(rows, vector<T>(columns));
    }

    Mat<T>(initializer_list<initializer_list<T>> _mat) : rows(_mat.size()), columns(_mat.begin()->size()){
        mat = vector<vector<T>>(rows, vector<T>(columns));
        int i = 0;
        for (auto&& row : _mat) {
            copy(row.begin(), row.end(), mat[i++].begin());
        }
    }

    vector<T> &operator[](int m) {
        return mat[m];
    }

    vector<T> operator*(const vector<T> v) const {
        auto ret = vector<T>(rows);
        for (int m = 0; m < rows; m++) {
            T sum = 0;
            for (int n = 0; n < columns; n++) {
                sum += mat[m][n] * v[n];
            }
            ret[m] = sum;
        }
        return ret;
    }

    Mat<T> &t() {
        auto _mat = vector<vector<T>>(columns, vector<T>(rows));
        for (int m = 0; m < rows; m++) for (int n = 0; n < columns; n++) {
            _mat[n][m] = mat[m][n];
        }
        mat = _mat;
        swap(rows, columns);
        return *this;
    }
};

const vector<Mat<int>> Rot = {
    {{ 1, 0 }, { 0, 1 }},
    {{ 0, 1 }, { -1, 0 }},
    {{ -1, 0 }, { 0, -1 }},
    {{ 0, -1 }, { 1, 0 }}
};

void normalize(vector<int> &x, vector<int> &y)
{
    for (int i = x.size()-1; i >= 0; i--) {
        x[i] -= x[0], y[i] -= y[0];
    }

    int d = 0;
    if (y[1] > 0) d = 1;
    if (x[1] < 0) d = 2;
    if (y[1] < 0) d = 3;

    loop (x.size(), i) {
        auto a = Rot[d] * vector<int>({ x[i], y[i] });
        x[i] = a[0];
        y[i] = a[1];
    }
}

int main()
{
    while (1) {
        int n; cin >> n;
        if (!n) break;
        int m; cin >> m;
        vector<int> orig_x(m), orig_y(m);
        loop (m, i) cin >> orig_x[i] >> orig_y[i];
        normalize(orig_x, orig_y);

        loop (n, i) {
            cin >> m;
            vector<int> x(m), y(m);
            loop (m, j) cin >> x[j] >> y[j];
            normalize(x, y);

            loop (2, k) {
                if (orig_x == x && orig_y == y) {
                    cout << i + 1 << endl;
                    break;
                }

                reverse(all(x));
                reverse(all(y));
                normalize(x, y);
            }
        }
        cout << "+++++" << endl;
    }
    return 0;
}
