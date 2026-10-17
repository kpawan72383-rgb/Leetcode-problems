class Solution {
public:
    string removeDuplicates(string s) {
        stack<pair<char, int>> st;
        int k = 2;
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});
            }
        }
        string result = "";
        while (!st.empty()) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }   
        reverse(result.begin(), result.end());
        return result;
    }
};
