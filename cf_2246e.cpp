#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<uint32_t> dist(0, (1u << 29) - 1); // there are 2^29 odd numbers

void solve() {
    // ok so knowing the value of any bit of v will solve the problem.
    // Now the hard part is that I don't know if a single interaction is enough to determine that.
    //
    // Because the system can pick the value v after we picked our x we can force it to pick a value we would like to.
    //
    // Now ty is random for both us and the system so the system cannot choose it against us.
    //
    // If we choose x = 1 then then:
    //
    // 1. Assume ty is |. Then v cannot be a value > 1 otherwise it will show us a bit in the response and we will be able to solve the
    // problem very easily.
    //
    // 2. Assume ty is &. Then v cannot choose any even values besides 0, because 1 & 0 = 0, so we will be able to tell that it picked an even
    // number real easy.
    //
    // So essentially if we pick x = 1 then the possible set of values is:
    // 1. | => {0, 1}
    // 2. & => {some odd numbo}
    //
    // It cannot pick an even number (besides 0) in either case because then in the | case we will get a numbo > 1 in the & case we will get an even number.
    //
    // Ok, so now we would like our m_0 to return a non zero value unless v = 0 and we would like our m_1 to return a non zero value unless v = m_1.
    //
    // Now we can pick m_1 at random and set m_0 to 2. This way if the system picks an odd number and sticks with it the probability that we
    // will hit that exact number is 1 / 2^29. If the system picks the number at random too (which it probably won't do because it is against its interest)
    // then we get an even better probability that is 1 / 2^29 * 1 / 2^29.
    //
    // So the probability that we will get a collision is 1 / 2^29.
    //
    // We have t <= 1e5, which makes the probability of collision around 0.019% which is fine I guess.


    int x = 1;

    cout << x << '\n';
    cout.flush();

    int o = 0;
    cin >> o;

    if (o == 1) {
        int m_0 = 2;
        uint32_t m_1 = (dist(rng) << 1) | 1u;

        cout << m_0 << ' ' << m_1 << '\n';
        cout.flush();

        int ans = 0;
        cin >> ans;

       if (ans == m_1 || (ans % 2 == 0 && ans != 2)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        cout.flush();
    } else if (o == 0) { // (v == 0 or v % 2 == 0) and ty == &
        cout << 0 << ' ' << 1 << '\n';
        cout.flush();

        int ans = 0;
        cin >> ans;

        if (ans & 1) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        cout.flush();
    } else { // v > 1 and ty == |
        int m_0 = 0;
        int m_1 = o;

        cout << m_0 << ' ' << m_1 << '\n';
        cout.flush();

        int ans = 0;
        cin >> ans;
        ans >>= 1;

        if (ans != 0) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
        cout.flush();
    }
}
