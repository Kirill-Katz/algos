class RandomizedSet {
private:
    vector<int> vals;
    unordered_map<int, int> vmap;
    std::mt19937 rng{std::random_device{}()};

public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (vmap.contains(val)) {
            return false;
        }

        vals.push_back(val);
        vmap[val] = (int)vals.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!vmap.contains(val)) {
            return false;
        }

        int idx = vmap[val];

        vals[idx] = vals[vals.size() - 1];
        vals.pop_back();
        vmap[vals[idx]] = idx;

        vmap.erase(val);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dist(0, vals.size() - 1);
        return vals[dist(rng)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
