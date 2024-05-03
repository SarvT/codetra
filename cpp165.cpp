class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();

        vector<int> dotIndex1,  dotIndex2;
        dotIndex1.push_back(-1);
        dotIndex2.push_back(-1);
        for (int i = 0; i < n; i++){
            if (version1[i] == '.') {
                dotIndex1.push_back(i);
                cout << i << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < m; i++){
            if (version2[i] == '.') {
                dotIndex2.push_back(i);
                cout << i << " ";
            }
        }
        dotIndex1.push_back(n);
        dotIndex2.push_back(m);

        int i = 1;
        while (i < dotIndex1.size() && i < dotIndex2.size()){
            string tmp1 = version1.substr(dotIndex1[i - 1] + 1, dotIndex1[i] - dotIndex1[i - 1] - 1);
            string tmp2 = version2.substr(dotIndex2[i - 1] + 1, dotIndex2[i] - dotIndex2[i - 1] - 1);

            if (stoi(tmp1) < stoi(tmp2)) return -1;
            if (stoi(tmp1) > stoi(tmp2)) {
                cout << stoi(tmp1) << " " << stoi(tmp2) << endl;
                return 1;
            }
            i++;
        }

        while (i < dotIndex1.size()){
            string tmp = version1.substr(dotIndex1[i - 1] + 1, dotIndex1[i] - dotIndex1[i - 1] - 1);
            if (stoi(tmp) > 0){
                cout << endl << stoi(tmp) << endl;
                return 1;
            }
            i++;
        }

        while (i < dotIndex2.size()){
            string tmp = version2.substr(dotIndex2[i - 1] + 1, dotIndex2[i] - dotIndex2[i - 1] - 1);
            if (stoi(tmp) > 0) return -1;
            i++;
        }

        return 0;
    }
};
