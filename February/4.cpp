#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/****************************  Just to clear my thought process for returning subarrays (Not just printing it) ************************************/
 
vector< vector<int> > getSubarrays(vector<int> nums)
{
    int size = nums.size();
    vector< vector<int> > answer;

    vector<int> :: iterator start_iterator;
    vector<int> :: iterator end_iterator;

    for(int start = 0 ; start < size ; start++)
    {
        for(int end = start ; end < size ; end++)
        {
            start_iterator = nums.begin() + start;
            end_iterator = nums.begin() + end + 1;                                              // It should point to next location were our subarray ends.        

            vector<int> temp(end-start+1);
            vector<int> :: iterator temp_itr;

            copy(start_iterator,end_iterator,temp.begin());

            answer.push_back(temp);
        }
    }
    return answer;

}

/************************************ This was the first logic which came to my mind. (This is overkill for sure, but it do works!!....LOL) *****************************************************************************/

int findMaxLength_1(vector<int>& nums)
{
        vector< vector<int> > subarrays = getSubarrays(nums);
        int sub_size;
        int answer = INT_MIN;
        int sum;
        for(int i = 0 ; i < subarrays.size() ; i++)
        {
            sub_size = subarrays[i].size();
            sum = 0;
            if( sub_size % 2 == 0)                                               // If subarray's size is even then only it can have equal numbers of 0's and 1's.
            {
                for(int j = 0 ; j < sub_size ; j++)
                {
                    sum += subarrays[i][j];
                }
                if(sum == sub_size/2)                                            // If sum of subarray is half of its size then its sure that it is having equal 0's and 1's. (Array is Binary, it only contains 0's and 1's)
                {
                    answer = max(answer,sub_size);                               // Recording the maximum size of such subarrays.
                }
            }
        }

        return answer;      
}

/********************************************** Same logic as above, but in very simple way and readable code too. ***********************/

int findMaxLength_2(vector<int>& nums)
{
    int size = nums.size();
    int answer = INT_MIN;
    int count_0;
    int count_1;
    int i,j;
    for(i = 0 ; i < size ; i++)
    {
        count_0 = 0;
        count_1 = 0;
        for(j = i ; j < size ; j++)
        {
            if(nums[j] == 0) count_0++;
            else count_1++;

            if(count_0 == count_1)
            {
                answer = max(answer,j-i+1);
            }
        }
    }
    return answer;
        
}

/****************************** Final Logic which got accepted on leetcode **************************/
// Using Unordered Map.


int findMaxLength(vector<int>& nums)
{
    unordered_map<int,int> map;                                         // "Sum" is our 'Key' and the index at which the "Sum" has occured is our 'Value'
    map[0] = -1;                                                        // Initial set Sum as 0 at index -1.
    int length = INT_MIN;
    int sum, temp, index;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(nums[i] == 0) sum--;
        else sum++;

        if(sum == 0)                                                    // It means 0's and 1's are equal at this point.
        {
            length = max(length,i+1);
        }

        else if(map.find(sum) != map.end())                            // If this 'sum' has occured before, then there are equal number of 0's and 1's between previous index and current index.(Let it sink in.)  
        {
            index = map[sum];
            temp = i - index;                                          // Length = Current Index - Previous Index
            length = max(length, temp);
        }

        else                                                          // If sum has not occured before insert it in our map.
        {
            map[sum] = i;
        }
    }
    return length;
    
}

/****************************************************************************************************/


int main()
{
    vector<int> input = {0,1,1};
    cout << findMaxLength_2(input) << endl;
}