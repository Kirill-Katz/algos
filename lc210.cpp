class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> g(n, vector<int>());
        vector<int> dep(n, 0);

        for (int i = 0; i < (int)prerequisites.size(); ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            g[b].push_back(a);
            dep[a]++;
        }

        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (dep[v] == 0) {
                q.push(v);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            ans.push_back(v);

            for (auto u : g[v]) {
                dep[u]--;

                if (dep[u] == 0) {
                    q.push(u);
                }
            }
        }

        if (ans.size() != n) {
            return {};
        }

        return ans;
    }
};
