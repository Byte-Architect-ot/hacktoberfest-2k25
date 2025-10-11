#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
}

int main() {
    string s, t;
    cout << "Enter first string (subsequence to check): ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isSubsequence(s, t))
        cout << "Yes, it is a subsequence.";
    else
        cout << "No, it is not a subsequence.";

    return 0;
}
