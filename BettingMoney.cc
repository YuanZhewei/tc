#include <vector>

using namespace std;

class BettingMoney {
public:
     int moneyMade(vector <int> amounts, vector <int> centsPerDollar, int finalResult) {
        int r = 0;
        for (int i = 0; i < amounts.size(); i++) {
            if (i != finalResult)
                r += amounts[i] * 100;
            else
                r -= amounts[i] * centsPerDollar[i];
        }
        return r;
     }
};
