#include <iostream>
#include <vector>
#include <numeric>                                    // For accumulate() function.
using namespace std;

/*********************************************   My first approach, got accepted on leetcode   *************************************************/

vector<int> putInVector(int num)
{
    vector<int> temp;

    while(num)
    {
        temp.insert(temp.begin(),num%10);
        num = num/10;
    }
    return temp;
}

int addDigits(int num)
{
    vector<int> temp;
    while(num > 9)
    {
        temp = putInVector(num);                                             // We put the 'num' into the vector (digit by digit).
        num = accumulate(temp.begin(), temp.end(), 0);                       // We get the sum of entire vector.
    }
    return num;       
}

/*********************************************************************************************************************************/

int main()
{
    int number = 123456;
    cout << addDigits(number) << endl;
    return 0;
}