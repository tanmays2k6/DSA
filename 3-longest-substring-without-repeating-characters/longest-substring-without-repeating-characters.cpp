class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> w;
        int n=s.length();
        int right=0, left=0, maxLen=0;

        while(right<n){
            if(!w.count(s[right])){
                w.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
                right++;
            }else{
                w.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};