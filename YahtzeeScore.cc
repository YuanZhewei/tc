#include <vector>

using namespace std;

class YahtzeeScore {
public:
     int maxPoints(vector<int> toss) {
        int s[6] = {0, 0, 0, 0, 0, 0};
        int ret = -1;
        for (int i = 0; i < toss.size(); i++) {
            s[toss[i]-1] += toss[i];
            ret = max(ret, s[toss[i]-1]);
        }
        return ret;
     }
};
