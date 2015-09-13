#include <string>

using namespace std;

class Quipu {
public:
    int readKnots(string knots) {
        int r = 0, c = 0;
        for (int i = 1; i < knots.size(); i++) {
            if (knots[i] == 'X') {
                c++;
            } else {
                r *= 10;
                r += c;
                c = 0;
            }
        }
        return r;
    }
};
