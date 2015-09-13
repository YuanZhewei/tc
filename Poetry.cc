#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Poetry {
public:
    string rhymeScheme(vector<string> poem) {
        map<string, char> m;
        string r = "";
        char last = 'a';
        for (int i = 0; i < poem.size(); i++) {
            string word = lastword(poem[i]);
            if (word == "") {
                r += " ";
            } else {
                string p = pattern(word);
                map<string, char>::iterator it ;
                char t = last;
                if ((it = m.find(p)) == m.end()) {
                    m.insert(pair<string, char>(p, last));
                    if (last != 'z')
                        last++;
                    else
                        last = 'A';
                } else {
                    t = it->second;
                }
                r += t;
            }
        }
        return r;
    }

private:
    int skipblank(const string &s, int end) {
        for (int i = end; i >= 0; i--)
            if (s[i] != ' ')
                return i;
        return -1;
    }

    string lastword(const string &s) {
        string r = "";
        int e = skipblank(s, s.size()-1);
        if (e == -1)
            return r;
        int b;
        for (b = e; b >= 0; b--)
            if (s[b] == ' ')
                break;
        return s.substr(b+1, e-b);
    }
    string pattern(string &s) {
        int b = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
        for (int i = s.size()-1; i >= 0; i--)
            if (isVowel(s, i))
                b = i;
        return s.substr(b);
    }
    bool isVowel(const string &s, int i) {
        switch(s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            case 'y':
                if (i != 0 && i != s.size()-1)
                    return true;
                else
                    return false;
            default:
                return false;
        }
    }
};

