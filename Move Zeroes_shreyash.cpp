#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[index]);
            index++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums)
        cout << num << " ";

    return 0;
}
