class Spreadsheet {
public:
    vector<vector<int>> spread;
    Spreadsheet(int rows) {
        spread.resize(rows + 1, vector<int> (26));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 65;
        int row = stoi(cell.substr(1));
        spread[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 65;
        int row = stoi(cell.substr(1));
        spread[row][col] = 0;
    }
    
    int getValue(string formula) {
        int j = 1;
        int ans = 0;
        int n = formula.size();
        for(int i = 1; i < formula.size() + 1; i++) {
            if(formula[i] == '+' || i == n) {
                string cell = formula.substr(j, i - j);
                if(cell[0] >= 'A' && cell[0] <= 'Z') {
                    // cout << cell << endl;
                    int col = cell[0] - 65;
                    int row = stoi(cell.substr(1));
                    ans += spread[row][col];
                }
                else {
                    ans += stoi(cell);
                }
                j = i + 1;
            }
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */