class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //The idea behind is that if we add some numbers and if total is making up to x then we will
        // have to add x+1 to our answer else we will add the current element to our sum

        int i=0;
        long long int ans=0;
        long long int sum=1;
        while(sum<=n)
        {
            if(i<nums.size() && nums[i]<=sum)
            {
                sum+=nums[i];
                i++;
            }
            else
            {
                sum+=sum;
                ans++;
            }
        }
        return ans;
    }
};
// Step	    Current nums	Miss	Action	            Reason	                            New Coverage
// 1	    [1, 5, 10]	    1	    Use 1	    1 is available and matches miss	            Sums up to 1
// 2	    [1, 5, 10]	    2	    Add 2	    5 is too large to form sum 2	            Sums up to 3
// 3	    [1, 5, 10]	    4	    Add 4	    5 is too large to form sum 4	            Sums up to 7
// 4	    [1, 5, 10]	    8	    Use 5	    Can use 5 with existing numbers to form 8	Sums up to 12
// 5	    [1, 5, 10]	    13	    Use 10	    Can use 10 with existing numbers to form 13	Sums up to 22