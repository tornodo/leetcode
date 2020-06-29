#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

class graph {
public:
    graph(vector<string>& dict) {
        sort(dict.begin(), dict.end(), std::greater<string>());
        for(int i = 0; i < dict.size(); i++) {
            charsSet.insert(dict[i]);
            if (pvMap.count(dict[i][0]) == 0) {
                list<string> tmpList;
                tmpList.emplace_back(dict[i]);
                pvMap[dict[i][0]] = tmpList;
            } else {
                list<string>& tmpList = pvMap[dict[i][0]];
                tmpList.emplace_back(dict[i]);
            }
        }
    }

    bool findPath(const string& source) {
        set<char> tmpSet;
        string tmp = source;
        if(pvMap.count(tmp[0]) == 0) {
            return false;
        }

        auto tmpList = pvMap[tmp[0]];
        if (tmpList.size() == 0) {
            return false;
        }
        return findSubPath(tmp, tmpList);
    }

    bool findSubPath(const string& source, const list<string>& node) {
        if (notFind) {
            return false;
        }
        for(auto iter = node.begin(); iter != node.end(); ++iter) {
            stringstream ssbuf(source);
            int pos = source.find(*iter);
            if (pos != -1 && pos == 0) {
                ssbuf.seekg((*iter).size());
                string tmp;
                ssbuf >> tmp;
                if (tmp.empty()) {
                    return true;
                }
                auto tmpList = pvMap[tmp[0]];
                if (tmpList.size() == 0) {
                    if (!isStringInDict(tmp)) {
                        notFind = true;
                        return false;
                    }
                    continue;
                }
                if (findSubPath(tmp, tmpList)) {
                    return true;
                } else {
                    if (notFind) {
                        return false;
                    }
                }
            }
        }
        return false;
    }

private:
    bool isStringInDict(const string& source) {
        bool found = false;
        for(auto iter = charsSet.begin(); iter != charsSet.end(); ++iter) {
            string::size_type pos = source.find(*iter);
            if (pos == 0) {
                found = true;
                break;
            }
        }
        return found;
    }

private:
    map<char, list<string>> pvMap;
    set<string> charsSet;
    bool notFind = false;
};

bool wordBreak(string s, vector<string>& wordDict) {
    // graph g(wordDict);
    // return g.findPath(s);
    int n = s.size();
    vector<bool> dp(n + 1);
    vector<int> index;
    set<int> indexSet;
    dp[0] = true;
    int idx = 0;
    for(int i = 0 ; i < s.size(); ){
        if(dp[i])
            for(string& str : wordDict){
                if(n - i >= str.size() && str == s.substr(i, str.size())){
                    int tindex = i + str.size();
                    dp[tindex] = true;
                    if(indexSet.count(tindex) == 0) {
                        indexSet.insert(tindex);
                        index.push_back(tindex);
                    }
                }
            }

        if (++idx > index.size()) {
            break;
        }
        i = index[idx];
    }
    return  dp[n];
}