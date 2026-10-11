class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_counts;
        remainder_counts[0] = 1;
        int prefix_sum = 0;
        int count = 0;  
        for (int num : nums) {
            prefix_sum += num;
            int rem = prefix_sum % k;     
            if (rem < 0) {
                rem += k;
            }    
            if (remainder_counts.find(rem) != remainder_counts.end()) {
                count += remainder_counts[rem];
            } 
            remainder_counts[rem]++;
        }    
        return count;
    }
};
