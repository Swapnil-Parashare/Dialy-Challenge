// 171. Excel Sheet Column Number.

#include <iostream>
#include<cmath>

using namespace std;

int titleToNumber(string columnTitle)
{
        int size = columnTitle.size();
        int weight = 0;
        int value = 0;
        int answer = 0;
        for(int i = size-1 ; i >= 0 ; i--)
        {
            weight = pow(26,size-i-1);
            value = (columnTitle[i] - 'A') + 1;
            answer += weight * value;
        }
        return answer;
}

int main()
{
    string input = "AZCDS";
    cout << titleToNumber(input) << endl;
}