class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = nums.size()-1;

        // this loop gives starting of unsorted subarray
        while(start + 1 < nums.size() && nums[start] <= nums[start+1]){
            start++;
        }

        // this loop gives ending of unsorted subarray
        while(end - 1 >= 0 && nums[end - 1] <= nums[end]){
            end--;
        }

        // it means no unsorted array is present
        if(start == nums.size() - 1){
            return 0;
        }
        int wMin = INT_MAX; // it shows that wMin cannot store any value beyond this limit
        int wMax = INT_MIN; // it shows that wMax cannot store any value below this limit

        // this loop check largest & smallest element of subarray b/w start & end
        for(int i = start; i <= end; i++){
            wMin = min(wMin, nums[i]);
            wMax = max(wMax, nums[i]);
        }

        // this loop checks whether the elements outside the subarray are smaller or not
        while(start - 1 >= 0 && nums[start-1] > wMin){
            start--;
        }

        // this loop checks whether the elements outside the subarray are greater or not
        while(end + 1 <= nums.size() - 1 && nums[end + 1] < wMax){
            end++;
        }
        return end - start +1;
    }
};
