#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> counts;
    stack<string> resultStack;
    string result = "";
    int index = 0;

    while (index < s.size()) {
        if (isdigit(s[index])) {
            int count = 0;
            while (isdigit(s[index])) {
                count = count * 10 + (s[index] - '0');
                index++;
            }
            counts.push(count);
        } 
        else if (s[index] == '[') {
            resultStack.push(result);
            result = "";
            index++;
        } 
        else if (s[index] == ']') {
            string temp = resultStack.top();
            resultStack.pop();
            int repeatTimes = counts.top();
            counts.pop();
            for (int i = 0; i < repeatTimes; i++)
                temp += result;
            result = temp;
            index++;
        } 
        else {
            result += s[index];
            index++;
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    string decoded = decodeString(s);
    cout << "Decoded string: " << decoded;

    return 0;
}
