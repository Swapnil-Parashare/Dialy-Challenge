#include <iostream>
#include <vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& nums)
{
    int size = nums.size();
    if(size < 3) return 0;

    vector<int> dp(0,size);
    int ans = 0;

    for(int i = 0 ; i < size ; i++)
    {
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
        {
            dp[i] = dp[i-1] + 1;
            ans += dp[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    int ans = numberOfArithmeticSlices(nums);
    cout << ans << endl;
    return 0;
}