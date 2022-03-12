// 1288. Remove Covered Intervals

#include <iostream>
#include <vector>

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals)
{
    int currentFirst, currentSecond, nextFirst, nextSecond;
    int i = 0;
    int j = 1;
    while(i < intervals.size() - 1)                                    // Current Pair
    {
        j = i+1;                                                       // Whenever "current" pair is updated, 'j' should start from its immediate next pair.
        
        while(j < intervals.size())                                    // Next Pair
        {
            currentFirst = intervals[i][0];
            currentSecond = intervals[i][1];
            nextFirst = intervals[j][0];
            nextSecond = intervals[j][1];

            // Current is eating Next.
            if ( currentFirst <= nextFirst && nextSecond <= currentSecond)
            {
                intervals.erase(intervals.begin() + j);                                            // Delete Next.
            }  

            // Next is eating Current.
            else if(nextFirst <= currentFirst && currentSecond <= nextSecond) 
            {
                intervals.erase(intervals.begin() + i);                                            // Delete Current.
                j = i+1;                                                                           // Here new 'current' is set, so 'j' should start from its immediate next element.
            }

            else
            {
                j++;
            }

        }
        i++;
    }

    return intervals.size();
}

int main()
{
    vector < vector<int> >  input = { {1,2} , {1,4} , {3,4}};
    cout << removeCoveredIntervals(input) << endl;
}