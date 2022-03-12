#include <iostream>
#include <vector>
#include <numeric>                 // For accumulate() function.
#include <unordered_map>

using namespace std;

/**************************************** Using Kadane's Algorithm *********************************************/
// It doesn't work in the required way.

int subarraySum_1(vector<int>& nums, int k)
{
    int sum = 0;
    int count = 0;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        sum = sum + nums[i];
        if(sum == k)
        {
            count++;
            sum = 0;
        }
        else if( sum > k)
        {
            sum = 0;
        }
    }
    return count;
}
/******************************************     Normal Brute Force Approach (TLE)   *****************************************************************/

int subarraySum_2(vector<int>& nums, int k )
{
    int count = 0;
    int size = nums.size();
    int sum = 0;

    vector<int> :: iterator start_itr;
    vector<int> :: iterator end_itr;

    for(int start = 0 ; start < size ; start++)
    {
        for(int end = start; end < size ; end++)
        {
            start_itr = nums.begin() + start;
            end_itr = nums.begin() + end;
            sum = accumulate(start_itr,end_itr+1,0);
            if(sum == k ) count++;
        }
    }
    return count;
}

/**********************************************************  Prefix Sum Array (Gives TLE) ***********************************************************/

vector<int> prefixSumArray(vector<int> nums)
{
    int sum = 0;
    vector<int> answer;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        sum = sum + nums[i];
        answer.push_back(sum);
    }
    return answer;
}

int subarraySum_3(vector<int> nums, int k)
{
    int count = 0;
    int size = nums.size();
    int sum = 0;
    vector<int> prefixSum = prefixSumArray(nums);

    for(int start = 0 ; start < size ; start++)
    {
        for(int end = start; end < size ; end++)
        {
            if(start == 0) sum = prefixSum[end];
            else sum = prefixSum[end] - prefixSum[start-1];

            if(sum == k) count++;

        }
    }
    return count;
    
}

/*
Calculating Sum of Subarray from "Prefix Sum Array" in the given range (i,j)
1]sum(i,j) = prefixSum[j] - prefixSum[i-1];
2]If i = 0, then sum(i,j) = prefixSum[j];            (Corner Case Handling)
*/


/********************************************   Prefix Sum Array (Single Traversal Approach)[Accepted]  *******************************************************/

/* Logic 
1] Here we will construct "Prefix Sum Array" during the traversal itself.
2] Check 1 : Current Sum is equal to our 'k' or not.
   Check 2 : i]Current Sum - 'k' is present in our "Prefix Sum Array" or not.            
             ii]Current_Sum - K = Value, If this 'Value' exist in our "Prefix Sum Array", it means from the point of the "Value", "K" is being added in the form of 
                single element or group of continuous elements in order to reach to our Current_Sum.
             iii] So subarray with sum "K" exists!!!


*/

int subarraySum(vector<int> nums, int k)
{
    int size = nums.size();
    int count = 0;
    unordered_map <int,int> prefixSum;
    int sum = 0;

    for(int i = 0 ; i < nums.size() ; i++)
    {
        sum = sum + nums[i];

        if(sum == k ) count++;                                           

        if( prefixSum.find(sum - k) != prefixSum.end() ) count+=prefixSum[sum-k];
        
        prefixSum[sum]++;                                                              // We are adding element in map at last, to tackel "k=0" case. (This syntax will insert the key if it is absent with value 1 and increment its value if it exists.)
    }
    return count;
}









/********************************************************************************************************************/

int main()
{
    vector<int> nums = {0,0,0,0,0,0,0,0,0};
    subarraySum(nums,3);

}