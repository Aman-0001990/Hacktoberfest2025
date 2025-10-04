class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        stack<int> gt;
        vector<int> nsi(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                nsi[i] = n;
            else
                nsi[i] = st.top();
            st.push(i);
        }

        vector<int> psi(n);
        for (int i = 0; i < n; i++) {
            while (!gt.empty() && arr[gt.top()] >= arr[i])
                gt.pop();

            if (gt.empty())
                psi[i] = -1;
            else
                psi[i] = gt.top();
            gt.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int he = arr[i];
            int be = nsi[i] - psi[i] - 1;
            int area = he * be;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
