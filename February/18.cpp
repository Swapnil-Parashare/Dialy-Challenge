#include <iostream>
#include<stack>

using namespace std;

string removeKdigits(string num, int k)
{
    int size = num.size();

    stack<int> myStack;

    for(int i = 0 ; i < size ; i++)
    {
        
        // While Loop is for deleting Left-most maxima's.

        while(!myStack.empty() && myStack.top() > num[i] && k > 0)                     // Stack should not be empty.
        {                                                                              // It should be a "Dip". i.e Current Element should be less than Stack Top.
            myStack.pop();                                                             // 'k' should not be 0. 
            k--;                                                                       //  It means now we can delete our left most maxima.
        }


        
        if(myStack.empty())                                                             // If loop is break because of stack is empty, then we need to check for 0.                        
        {                 
            if(num[i] == '0')                                                           // If Stack is empty and current element is 0, then simply skip current iteration. We will not include 0.
            {                                                                          
                continue;
            }
            else
            {
                myStack.push(num[i]);                                                   // If Stack is empty and current element is non-zero then we will include it.
            }
        }
        else if ( (myStack.top() <= num[i])  ||  k == 0 )                               // If loop is break because there is no "Dip"   OR   our 'k' is finished, then simply include the element. 
        {
            myStack.push(num[i]);                                                       // We can include directly without checking for 0, because at this point stack is non-empty.
        }
        
    }


    // Corner Case 1 : If input number was already given in ascending order.
    while(!myStack.empty() && k)                                                       // Here we end up not deleting even a single element.
    {                                                                                  // So the left most maxima are deleted using this while loop.
        myStack.pop();
        k--;
    }

    // Corner Case 2 : If 'k' was equal to size of string.
    if(myStack.empty())                                         // Here we will end up emptying entire stack till this point.                
    {
        return "0";                                             // So return "0"
    }


    // Now the elements present in our "Stack" is our answer.
    while(!myStack.empty())
    {
        num[size - 1] = myStack.top();                          // Remove elements from stack and fill them in answer from backside.
        myStack.pop();
        size--;
    }

    return num.substr(size);                                   // Return substring from current index till end.


}

int main()
{
    removeKdigits("10200", 1);
}