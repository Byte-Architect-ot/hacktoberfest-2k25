#include <iostream>
#include <vector>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool match = true;
            for (int k = 0; k < n; k++) {
                if (grid[i][k] != grid[k][j]) {
                    match = false;
                    break;
                }
            }
            if (match) count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int result = equalPairs(grid);
    cout << "Number of equal row and column pairs: " << result;

    return 0;
}
