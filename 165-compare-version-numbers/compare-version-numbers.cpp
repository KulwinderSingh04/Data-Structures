class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i1 = 0, i2 = 0;
        int j1 = 0, j2 = 0;
        vector<int> v1, v2;
        // while(j1 < n1 && j2 < n2) {
        //     if(version1[j1] == '.' && version2[j2] == '.') {
        //         string s1 = version1.substr(i1, j1 - i1);
        //         string s2 = version2.substr(i2, j2 - i2);
        //         if(stoi(s1) > stoi(s2)) return 1;
        //         else if(stoi(s1) < stoi(s2)) return -1;
        //         j1++;
        //         j2++;
        //         i1 = j1;
        //         i2 = j2;
        //     } else if(version1[j1] == '.') j2++;
        //     else j1++;
        // }
        while(j2 < n2) {
            if(version2[j2] == '.') {
                string s2 = version2.substr(i2, j2 - i2);
                v2.push_back(stoi(s2));
                i2 = j2 + 1;
            }
            j2++;
        }
        string s2 = version2.substr(i2, j2 - i2);
        v2.push_back(stoi(s2));
        while(j1 < n1) {
            if(version1[j1] == '.') {
                string s1 = version1.substr(i1, j1 - i1);
                v1.push_back(stoi(s1));
                i1 = j1 + 1;
            }
            j1++;
        }
        string s1 = version1.substr(i1, j1 - i1);
        v1.push_back(stoi(s1));
        while(v1.size() < v2.size()) v1.push_back(0);
        while(v1.size() > v2.size()) v2.push_back(0);
        for(int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " " << v2[i] << endl;
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};