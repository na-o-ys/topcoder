#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

template <typename T>
class Mat
{
public:
    vector<vector<T>> mat;
    int rows, columns;

    Mat<T>(int r, int c) : rows(r), columns(c) {
        mat = vector<vector<T>>(rows, vector<T>(columns));
    }

    Mat<T>(initializer_list<initializer_list<T>> _mat)
        : rows(_mat.size()), columns(_mat.begin()->size()) {
        mat = vector<vector<T>>(rows, vector<T>(columns));
        int i = 0;
        for (auto&& row : _mat) {
            copy(row.begin(), row.end(), mat[i++].begin());
        }
    }

    vector<T> &operator [](int m) {
        return mat[m];
    }

    vector<T> operator *(const vector<T> v) const {
        vector<T> ret(rows);
        for (int m = 0; m < rows; m++) {
            for (int n = 0; n < columns; n++) {
                ret[m] += mat[m][n] * v[n];
            }
        }
        return ret;
    }

    Mat<T> operator *(Mat<T>& o) const {
        Mat<T> ret(rows, o.columns);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < o.columns; c++) {
                for (int i = 0; i < columns; i++) {
                    ret[r][c] += mat[r][i] * o[i][c];
                }
            }
        }
        return ret;
    }

    void operator *=(Mat<T>& o) {
        *this = *this * o;
    }

    Mat<T> pow(int n) const {
        Mat ans(rows, columns);
        for (int i = 0; i < rows; i++) {
            ans[i][i] = 1;
        }

        Mat base = *this;

        for (int i = 0; n>>i; i++) {
            if (n>>i&1) {
                ans *= base;
            }
            base *= base;
        }
        return ans;
    }

    Mat<T> &t() {
        vector<vector<T>> _mat(columns, vector<T>(rows));
        for (int m = 0; m < rows; m++) for (int n = 0; n < columns; n++) {
            _mat[n][m] = mat[m][n];
        }
        mat = _mat;
        swap(rows, columns);
        return *this;
    }

    void show() {
        for (auto&& row : mat) {
            for (T t : row) {
                cout << t << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const* argv[])
{
    Mat<int> m = {{1, 0, 0}, {0, 2, 1}, {0, 0, 1}};
    m.show();
    printf("\n");
    loop (10, i) {
        m.pow(i).show();
        printf("\n");
    }
    return 0;
}
