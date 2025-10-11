#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int a : asteroids) {
        bool alive = true;
        while (alive && a < 0 && !st.empty() && st.top() > 0) {
            if (st.top() < -a) st.pop();
            else if (st.top() == -a) { st.pop(); alive = false; }
            else alive = false;
        }
        if (alive) st.push(a);
    }

    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;
    vector<int> asteroids(n);
    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) cin >> asteroids[i];

    vector<int> result = asteroidCollision(asteroids);

    cout << "Asteroids after collisions: ";
    for (int x : result) cout << x << " ";

    return 0;
}
