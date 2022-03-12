// 136. Single Number

#include <iostream>
#include <vector>

using namespace std;



// Using XOR operation.

int singleNumber(vector<int>& nums) 
{
        
        int x = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            x = x ^ nums[i];
        }
        return x;    
}

int main()
{
    return 0;
}