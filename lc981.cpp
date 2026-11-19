class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        store[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp) {
        if (!store.contains(key)) {
            return "";
        }

        int l = 0, r = (int)store[key].size() - 1;

        while (l < r) { // TTTFFF
            int m = l + (r - l + 1) / 2;
            int val = store[key][m].first;

            if (val <= timestamp) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        if (store[key][l].first <= timestamp) {
            return store[key][l].second;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

