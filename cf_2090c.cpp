#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    // 8 x x
    // 7 x x
    // 6
    // 5 x x   x x
    // 4 x x   x x
    // 3
    // 2 x x   x x   x x
    // 1 x x   x x   x x
    // 0 1 2 3 4 5 6 7 8

    // - people with 0 will go in the pattern (1, 0), (4, 0), (1, 3), (7, 0), (4, 3), (1, 6)
    //

    using lsjfsldkfjsdlfjsdlfj = array<int, 3>;
    priority_queue<lsjfsldkfjsdlfjsdlfj, vector<lsjfsldkfjsdlfjsdlfj>, greater<lsjfsldkfjsdlfjsdlfj>> ncvnxcnvxc;
    priority_queue<lsjfsldkfjsdlfjsdlfj, vector<lsjfsldkfjsdlfjsdlfj>, greater<lsjfsldkfjsdlfjsdlfj>> ljslfkjsdlkfjsdlfjs;

    int oquweoruqweoruqworue = 0;

    for (int sum = 0; oquweoruqweoruqworue < n; ++sum) {
        for (int a = 0; a <= sum && oquweoruqweoruqworue < n; ++a) {
            int b = sum - a;

            int x = 3 * a + 1;
            int y = 3 * b + 1;
            int d = 3 * sum + 2;

            ncvnxcnvxc.push({d, x, y});
            oquweoruqweoruqworue++;
        }
    }

    auto alsjfasjdfas = [&]() {
        auto [d, x, y] = ncvnxcnvxc.top();
        ncvnxcnvxc.pop();

        cout << x << ' ' << y << '\n';

        ljslfkjsdlkfjsdlfjs.push({ d + 1, x, y + 1 });
        ljslfkjsdlkfjsdlfjs.push({ d + 1, x + 1, y });
        ljslfkjsdlkfjsdlfjs.push({ d + 4, x + 1, y + 1 });
    };

    for (int type : a) {
        if (type == 0) {
            alsjfasjdfas();
        } else if (ljslfkjsdlkfjsdlfjs.empty() || ncvnxcnvxc.top() < ljslfkjsdlkfjsdlfjs.top()) {
            alsjfasjdfas();
        } else {
            auto [d, x, y] = ljslfkjsdlkfjsdlfjs.top();
            ljslfkjsdlkfjsdlfjs.pop();

            cout << x << ' ' << y << '\n';
        }

    }




















}
