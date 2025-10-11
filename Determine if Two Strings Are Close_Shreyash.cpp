#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;

    vector<int> freq1(26, 0), freq2(26, 0);
    vector<bool> exist1(26, false), exist2(26, false);

    for (char c : word1) {
        freq1[c - 'a']++;
        exist1[c - 'a'] = true;
    }
    for (char c : word2) {
        freq2[c - 'a']++;
        exist2[c - 'a'] = true;
    }

    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2 && exist1 == exist2;
}

int main() {
    string word1, word2;
    cout << "Enter first string: ";
    cin >> word1;
    cout << "Enter second string: ";
    cin >> word2;

    if (closeStrings(word1, word2))
        cout << "Yes, the strings are close.";
    else
        cout << "No, the strings are not close.";

    return 0;
}
