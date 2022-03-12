#include <iostream>
#include <vector>

using namespace std;

/******************************************* This logic got accepted on leetcode on my very first attempt ***************************************/

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() == 1) return 1;

    int count = 1;
    int i = 1;                                                                  // Start from 2nd number.

    while(i < nums.size())
    {
        if(nums[i] == nums[i-1])                                                // If a number is same as its previous number.
        {
            count++;                                                            // Then simply increment the counter.
            if(count > 2)                                                       // And check wheater the count is greater than 2.
            {
                nums.erase(nums.begin() + i);                                   // If it is, then delete the current element.
                continue;                                                       // We don't want our 'i' to be incremented in this case
            }
            else                                                                // If count is not greater than 2
            {
                i++;                                                            // Then simply move on to next element.
            }
        }
        else                                                                    // If a number is not equal to its previous number.
        {
            count = 1;                                                          // Then simply re-initilize the 'count' to 1.       
            i++;                                       
        }
    }
    return nums.size();

}

/*****************************************************************************************************************************************************/

int main()
{
    vector<int> nums = {0,0,0,1,1,1,2,3,3};
    cout << removeDuplicates(nums) << endl;
}