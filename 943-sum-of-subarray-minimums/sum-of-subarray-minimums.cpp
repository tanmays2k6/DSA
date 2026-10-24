class Solution {
public:
    vector<int> FindNSE(vector<int>& arr){
        int n=arr.size();
        vector<int> nse(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> FindPSEE(vector<int>& arr){
        int n=arr.size();
        vector<int>psee(n);
        stack<int> st;

        for(int i=0;i<=n-1;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=FindNSE(arr);
        vector<int> pse=FindPSEE(arr);
        long long total=0;
        long long mod=1000000007;

        for(int i=0;i<=n-1;i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }
        return total;
    }
};