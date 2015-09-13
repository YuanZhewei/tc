#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MatchMaking {
public:
    string makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, vector <string> answersMen, string queryWoman) {
        vector<pair<string, string> > w, m;
        int l = namesWomen.size();
        for (int i = 0; i < l; i++) {
            w.push_back(pair<string, string>(namesWomen[i], answersWomen[i]));
            m.push_back(pair<string, string>(namesMen[i], answersMen[i]));
        }
        sort(w.begin(), w.end());
        sort(m.begin(), m.end());
        for (int i = 0; i < l; i++) {
            vector<pair<string, string> >::iterator it, match;
            int maxval = -1;
            for (it = m.begin(); it != m.end(); it++) {
                int t = score(w[i].second.c_str(), it->second.c_str());
                if (t > maxval) {
                    maxval = t;
                    match = it;
                }
            }
            if (w[i].first == queryWoman)
                return match->first;
            m.erase(match);
        }
        return "";
    }
private:
    int score(const char *a, const char *b) {
        int r = 0;
        while (*a) {
            if (*a == *b)
                r++;
            a++;
            b++;
        }
        return r;
    }
};
