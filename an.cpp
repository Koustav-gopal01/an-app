#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

pair<string, string> split(string &s) {
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') {
      string eid = s.substr(0, i);
      string fid = s.substr(i + 1, s.size() - i - 1);
      return {eid, fid};
      cout << eid << ":" << fid << endl;
    }
  }
  return {string("x"), string("x")};
}

int main() {
  string line;
  ifstream file("test.log");
  unordered_map<string, unordered_set<string>> m;

  while (getline(file, line)) {
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == ' ') {
        string eid = line.substr(0, i);
        string fid = line.substr(i + 1, line.size() - i - 1);

        auto it1 = m.find(fid);
        if (it1 == m.end())
          m.insert({fid, unordered_set<string>()});

        auto s = m.find(fid);
        if (s->second.count(eid) == 1) {
          cout << "Duplicate entries" << endl;
          return 1;
        } else {
          s->second.insert(eid);
        }
      }
    }
  }

  vector<pair<string, int>> v;
  for (auto it = m.begin(); it != m.end(); ++it) {
    v.push_back({it->first, it->second.size()});
  }


  sort(v.begin(), v.end(), [](pair<string, int> &a, pair<string, int> &b) {
    return a.second >= b.second;
  });

  for (int i = 0; i < 3 && i < v.size(); ++i) {
    cout << (i + 1) << ") " << v[i].first << endl;
  }

  return 0;
}
