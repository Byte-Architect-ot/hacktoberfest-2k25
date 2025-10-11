#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) freq[num]++;

    unordered_set<int> seen;
    for (auto& p : freq) {
        if (seen.count(p.second)) return false;
        seen.insert(p.second);
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (uniqueOccurrences(arr))
        cout << "Yes, all occurrences are unique.";
    else
        cout << "No, occurrences are not unique.";

    return 0;
}
