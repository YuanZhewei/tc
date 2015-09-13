#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class FairWorkload {
public:
    int getMostWork(vector<int> folders, int workers) {
        int lo = *max_element(folders.begin(), folders.end()),
            hi = accumulate(folders.begin(), folders.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int req = 1;
            int acc = 0;
            bool p = true;
            for (int i = 0; i < folders.size(); i++) {
                if (acc + folders[i] <= mid) {
                    acc += folders[i];
                } else {
                    req++;
                    if (req > workers || folders[i] > mid) {
                        p = false;
                        break;
                    }
                    acc = folders[i];
                }
            }
            if (p)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
