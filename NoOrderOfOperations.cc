#include <string>

using namespace std;

class NoOrderOfOperations {
public:
    int evaluate(string expr) {
        int r = expr[0] - '0';
        for (int i = 1; i < expr.size(); i += 2) {
            int a = expr[i+1] - '0';
            switch(expr[i]) {
                case '+':
                    r += a;
                    break;
                case '-':
                    r -= a;
                    break;
                case '*':
                    r *= a;
                    break;
            }
        }
        return r;
    }
};
