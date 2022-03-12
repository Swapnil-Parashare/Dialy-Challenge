#include <iostream>
#include <vector>
#include <algorithm>                             // For copy() function.

using namespace std;

void generate(vector<int>& subset,int i, vector<int>& nums, vector< vector<int> >& answer)
{
    if(i == 3)
    {
        answer.push_back(subset);
        return;
    }

    // Include current element.
    subset.push_back(nums[i]);
    generate(subset,i+1,nums,answer);

    // Don't include element.
    subset.pop_back();                                  // We need to undo the changes. (Back Tracking Step).
    generate(subset,i+1,nums,answer);
}

void generate_2(vector<int> subset,int i, vector<int>& nums, vector< vector<int> >& answer)              // Pass subset by value.
{
    if(i == 3)
    {
        answer.push_back(subset);
        return;
    }
   
    // Don't include element.
    generate_2(subset,i+1,nums,answer);

    // Include current element.
    subset.push_back(nums[i]);
    generate_2(subset,i+1,nums,answer);

    // No Backtracknig required. As we are passing subset by value and modification is done at last of the funciton.

}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector< vector<int> > answer;
    vector<int> empty;
    generate_2(empty,0,nums,answer);
    return answer;
}

int main()
{
    vector<int> nums = {1,2,3};
    subsets(nums);
}