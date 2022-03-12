/*
Given a vector, write a function that will return a 2D vector, containing all the subarrays of the given vector.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>    // For copy() function.


using namespace std;


void display(vector< vector<int> > vec)
{
    int len;
    for(int i = 0 ; i < vec.size() ; i++)
    {
        len = vec[i].size();
        for( int j = 0 ; j < len ; j++)
        {   
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector< vector<int> >  solve(vector<int> nums)
{

    int size = nums.size();
    vector< vector<int> > subarrays;
    vector<int> :: iterator start_itr ;
    vector<int> :: iterator end_itr ;

    for(int start = 0 ; start < size ; start++)
    {
        for( int end = start ;  end < size ; end++)
        {
            start_itr = nums.begin() + start;
            end_itr = nums.begin() + end + 1;                     // Its point to the very next location were our subarray ends. ( For sake of copy() funciton ).

            vector<int> temp;                                     // For each subarray create a new 'temp' vector;
            vector<int> :: iterator temp_itr;

            copy(start_itr, end_itr, inserter(temp,temp_itr));    // Syntax of copy() when size of destination vector is unknown. 
            // copy(start_itr,end_itr,temp.begin());              // Syntax of copy() when size of destination vector is known.

            subarrays.push_back(temp);
        }
        
    }
    return subarrays;
}



int main()
{
    vector<int> temp = {1,2,3,4,5};
    vector< vector<int> > ans = solve(temp);
    display(ans);


}