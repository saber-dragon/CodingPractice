#include "utils.hpp"


using namespace std;

namespace saber {
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        if (n <= 1) return 0;

        // forward direction: F[i]
        std::vector<int> F(n, 0);
        int best_buy_price = prices[0];
        int t;
        for (size_t k = 1;k < n;++ k) {
            if ((t = prices[k] - best_buy_price) > F[k - 1])
                F[k] = t;// update forward maximum profit (one transaction is allowed)
            else
            {
                F[k] = F[k - 1];
                if (best_buy_price > prices[k])
                    best_buy_price = prices[k];// update lowest price
            }
        }
        // backward
        std::vector<int> B(n, 0);
        int best_sell_price = prices[n - 1];
        for (int k = n - 2;k >= 0;-- k){
            if ((t = best_sell_price - prices[k]) > B[k + 1])
                B[k] = t;
            else {
                B[k] = B[k + 1];
                if (best_sell_price < prices[k])
                    best_sell_price = prices[k];
            }
        }

        int max_profit = 0;

        for (size_t i = 1;i < n;++ i){
            if ((t = F[i - 1] + B[i]) > max_profit)
                max_profit = t;
        }

        // cout << "Prcies: "
        //       << prices
        //       << endl;
        // cout << "Forward: "
        //     << F
        //     << endl;
        // cout << "Backward: "
        //     << B
        //     << endl;
        return max_profit;
    }
}
int main(){
    vector<int> v{12,  4, 22,  2, 23,  7,  3,  5, 12,  2};
    cout << saber::maxProfit(v);
    return 0;
}
