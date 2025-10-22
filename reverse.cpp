#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result = "";
        vector<string> words;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};

int main() {
    Solution obj;
    string s = "  the sky  is  blue ";
    cout << obj.reverseWords(s);
    return 0;
}
