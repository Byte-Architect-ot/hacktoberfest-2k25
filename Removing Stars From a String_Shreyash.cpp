#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeStars(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '*') {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string s;
    cout << "Enter string with stars: ";
    cin >> s;

    string result = removeStars(s);
    cout << "String after removing stars: " << result;

    return 0;
}
