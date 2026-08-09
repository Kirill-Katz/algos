
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> src(n);
    iota(src.begin(), src.end(), 1);

    vector<int> seg(4 * n + 5);

    auto fill = [&](auto&& self, int u, int l, int r) {
        if (l == r) {
            seg[u] = src[l];
            return;
        }

        int m = l + (r - l) / 2;
        int left = 2 * u + 1;
        int right = 2 * u + 2;

        self(self, left, l, m);
        self(self, right, m + 1, r);

        seg[u] = max(seg[left], seg[right]);
    };

    auto change = [&](auto&& self, int u, int l, int r, int p, int v) {
        if (l > p || p > r) {
            return;
        }

        if (l == r && l == p) {
            seg[u] = v;
            return;
        }

        int left = 2 * u + 1;
        int right = 2 * u + 2;

        int m = l + (r - l) / 2;

        self(self, left, l, m, p, v);
        self(self, right, m + 1, r, p, v);

        seg[u] = max(seg[left], seg[right]);
    };
}

int compact() {
    int n
    cin >> n;

    vector<int> src(n);
    iota(src.begin(), src.end(), 1);

    vector<int> seg(n * 2);

    auto fill = [&](const auto& src, auto& seg) {
        for (int i = 0; i < n; ++i) {
            seg[n + i] = src[i];
        }
        for (int i = n - 1; i > 0; --i) {
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        }
    };

    auto change = [&](auto& seg, int p, auto v) {
        p += seg.size() / 2;
        seg[p] = v;

        while (p > 1) {
            p /= 2;
            seg[p] = max(seg[2 * p], seg[2 * p + 1]);
        }
    };
}


