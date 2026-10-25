
class Solution {
public:
    vector<int> FindNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> FindPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    long long sumMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = FindNSE(arr);
        vector<int> pse = FindPSEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total += left * right * arr[i];
        }
        return total;
    }

    long long sumMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n), pge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;

            total += left * right * arr[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& arr) {
        return sumMax(arr) - sumMin(arr);
    }
};
