#include <iostream>
#include <vector>
using namespace std;

int min_swaps(string s) {
    vector<int> reds;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            reds.push_back(i);
        }
    }
    int n = reds.size();
    if (n == 0) {
        return 0;
    }
    int start_ptr = 0;
    int end_ptr = n - 1;
    int count = 0;
    while (start_ptr < end_ptr) {
        count += reds[end_ptr] - reds[start_ptr] - end_ptr + start_ptr;
        start_ptr += 1;
        end_ptr -= 1;
    }
    return (count > 1e9 || count < -1) ? -1 : count;
}

int main() {
    string s;
    cin >> s;
    int res = min_swaps(s);
    cout << res << endl;
    return 0;
}
