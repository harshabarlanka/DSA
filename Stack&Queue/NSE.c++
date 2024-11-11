#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> NSE(n, -1);  
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            NSE[i] = st.top();
        }

        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << NSE[i] << " ";
    }
    cout << endl;

    return 0;
}
