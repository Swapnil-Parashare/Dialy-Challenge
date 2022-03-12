/* 121 : Best Time to Buy and Sell Stock : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/*/
#include <iostream>
#include <vector>
using namespace std;


// Brute Force Approach.
int max_Profit(vector<int>& prices)                         
{
        int size = prices.size();
        int maxProfit = INT_MIN;
        int currentProfit = 0;
        for(int i = 0 ; i < size-1 ; i++)
        {
            for(int j = i+1 ; j < size ; j++)
            {
                if(prices[j] < prices[i]) continue;                                       // If we are not encountering profit, then skip the current iteration.
                currentProfit = prices[j] - prices[i];
                maxProfit = max(currentProfit, maxProfit);
            }
        }
        if(maxProfit > 0) return maxProfit;
        else return 0;
}

// Pre-Requisite : "Kadanes Algorithm" 
int kadane(vector<int>& arr)   
{

    int maxSum = INT_MIN;
    int sumTillNow = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        sumTillNow = sumTillNow + arr[i];                           // Logic of calculating sum of entire array.           
        if(sumTillNow > maxSum)
        {
            maxSum = sumTillNow;                                    // Recording the maximum positive value 'sumTillNow' ever had.
        }
        if(sumTillNow < 0 )
        {
            sumTillNow = 0;                                         // As soon as sumTillNow becomes negative, reinitialize sumTillNow to 0.
        }
    }
    return maxSum;
}

// Final Optimal Solution.
int maxProfit(vector<int>& prices) {
        
    int size = prices.size();
    
    int todayPrice = 0;
    int minPriceTillNow = INT_MAX;
    int todayProfit = 0;
    int maxProfit = INT_MIN;
    
    for(int i = 0 ; i < size ; i++)
    {
        todayPrice = prices[i];
        if(todayPrice < minPriceTillNow)
        {
            minPriceTillNow = todayPrice;
        }
        todayProfit = todayPrice - minPriceTillNow;
        if(todayProfit > maxProfit)
        {
            maxProfit = todayProfit;
        }
    }
    return maxProfit;
}

int main()
{
    cout << "Hello World!!!"   << endl;
}

/*
Pre-requisite : "Kadanes Algorithm".

My Intuition about Kadane:
1] Simply follow the logic of ---> Calculating Sum of entire array.
2] At any time if 'sumTillNow' becomes negative, then re-initialize 'sumTillNow' to zero.
3] Use 'max_Sum' counter to record the maximum positive value held by 'sumTillNow'.

Optimal Solution :-

Logic :- (Note : It gives answer in single Traversal).

1] During the traversal, consider I am standing at a point(At a particular day) .        (IMP : I am treating this point as a "Selling Point")
2] Now inorder to make maximum profit, what will be my "Buying Price"?
3] My Buying Price will be the Minimum price exists, till this point. (i.e To the left of standing point)
4] "Today's Profit" = "Todays's Price" - "Mininum Price exist in past".
5] I have also kept "Maximum Profit" counter which will get updated at each iteration and Maximum Profit from all the "Today's Profit", will be returned.

Flow :

Treat :-      Today's Price     as       Selling Price
              Minimum_Price     as       Buying Price
              (Till Now)

              Profit = Selling Price - Buying Price
  i.e Today's Profit = Today's Price - Minimum Price (Till Now)

1] When you are standing at a point you need to know the minimum price present to the left of that index. So calculate minimum price at each iteration.
2] Calculate today's profit by simply substracting 'minmum price' from 'today's price'.
3] If today's profit is greater than maximum profit then, update maximum profit counter with today's profit.
4] Return maximum profit at the end of the loop.
*/