class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        ring = n;
        disc = discount;

        int m = (int) products.size();
        for (int i = 0; i < m; ++i) {
            ps[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        double base = 0.0;

        int n = (int) product.size();
        for (int i = 0; i < n; ++i) {
            base += ps[product[i]] * amount[i];
        }

        if (current % ring == 0) {
            base = base * ((100.0 - disc) / 100.0);
        }

        current = (current + 1) % ring;
        return base;
    }
private:
    int current = 1;
    int ring;
    double disc;
    unordered_map<int, int> ps;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
