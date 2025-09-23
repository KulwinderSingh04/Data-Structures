class Solution {
public:
    int compareVersion(string version1, string version2) {
        version2.push_back('.');
        version1.push_back('.');
        int n1 = version1.size();
        int n2 = version2.size();
        int i1 = 0, i2 = 0;
        int j1 = 0, j2 = 0;
        while(j1 < n1 || j2 < n2) {
            int num1 = 0, num2 = 0;
            while(j1 < n1 && version1[j1] != '.') j1++;
            while(j2 < n2 && version2[j2] != '.') j2++;
            if(j1 < n1) num1 = stoi(version1.substr(i1, j1 - i1));
            if(j2 < n2) num2 = stoi(version2.substr(i2, j2 - i2));
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            j1++;
            j2++;
            i1 = j1;
            i2 = j2;
        }
        return 0;
    }
};