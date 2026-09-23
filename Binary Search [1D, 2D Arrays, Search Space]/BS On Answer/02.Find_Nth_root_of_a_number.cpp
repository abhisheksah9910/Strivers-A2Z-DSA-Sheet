#include <bits/stdc++.h>
using namespace std;

double multiply(double number, int n) {
    double ans = 1.0;

    for (int i = 1; i <= n; i++) {
        ans = ans * number;
    }

    return ans;
}

double getNthRoot(int n, int m) {

    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps) {

        double mid = (low + high) / 2.0;

        if (multiply(mid, n) < m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << "Low: " << low << endl;
    cout << "High: " << high << endl;

    return low;
}

int main() {

    int n, m;
    cin >> n >> m;

    double ans = getNthRoot(n, m);

    cout << fixed << setprecision(6);
    cout << "Nth Root: " << ans << endl;

    // Verification
    cout << "Using pow: "
         << pow(m, 1.0 / n) << endl;

    return 0;
}