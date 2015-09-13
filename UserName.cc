#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
#include <string>

using namespace std;

class UserName {
public:
    string newMember(vector<string> &existingNames, string &newName) {
        set<string> s;
        char candidate[64];
        for(size_t i = 0; i < existingNames.size(); i++)
            s.insert(existingNames[i]);
        int num = 0;
        for (;;) {
            if (num > 0)
                sprintf(candidate, "%s%d", newName.c_str(), num);
            else
                sprintf(candidate, "%s", newName.c_str());
            if (s.find(candidate) != s.end())
                break;
            num++;
        }
        return string(candidate);
    }
};
