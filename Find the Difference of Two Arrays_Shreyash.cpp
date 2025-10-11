#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> diff1, diff2;

    for (int num : set1)
        if (set2.find(num) == set2.end())
            diff1.push_back(num);

    for (int num : set2)
        if (set1.find(num) == set1.end())
            diff2.push_back(num);

    return {diff1, diff2};
}

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    vector<vector<int>> result = findDifference(nums1, nums2);

    cout << "Unique to first array: ";
    for (int x : result[0]) cout << x << " ";
    cout << "\nUnique to second array: ";
    for (int x : result[1]) cout << x << " ";

    return 0;
}
