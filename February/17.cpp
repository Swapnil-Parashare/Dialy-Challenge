// 39. Combination Sum

#include<iostream>
#include<vector>

using namespace std;

/*************************************************** Non Optimized *******************************************************/

void solve(int index, int target, vector<int>& combination, vector< vector<int> >& finalAnswer, vector<int>& candidates)
{
    // Base Conditions
    if(index == candidates.size())                                    // This is our "Leaf Node".                              
    {    
        if(target == 0)                                           
        { 
            finalAnswer.push_back(combination);                       // We will get all our valid combinations at "Leaf Node " only.
        }                                                      
        return;
    }

    

    if(candidates[index] <= target)                                                
    {
         // Pick up element
        combination.push_back(candidates[index]);
        solve(index,target-candidates[index],combination,finalAnswer,candidates);

        combination.pop_back();                                                         // Backtracking.
    }

                                                                            
        // Don't Pick up element
        solve(index+1, target, combination, finalAnswer, candidates);
  
}


/*********************************************************** Optimized *************************************************************************************/

void solve_1(int index, int target, vector<int>& combination, vector< vector<int> >& finalAnswer, vector<int>& candidates)
{
    // Base Conditions
    if(index == candidates.size())                               // Target will never become 0 at index == size.                                   
    {                                                            // Hence we can directly terminate the call without any hesitation.
        return;
    }

    if(target == 0)                                              // Lots of recursive calls will be saved due to this termination.
    { 
        finalAnswer.push_back(combination);                      // We will get valid combinations at "Non-Leafs" nodes only. At Leaf Node (Index == Size) only termination will occur.
        return;                                                  
    }

    if(candidates[index] <= target)                                                
    {
         // Pick up element
        combination.push_back(candidates[index]);
        solve(index,target-candidates[index],combination,finalAnswer,candidates);

        combination.pop_back();                                                         // Backtracking.
    }
                                                                    
        // Don't Pick up element
        solve(index+1, target, combination, finalAnswer, candidates);
  
}

/*********************************************************************************************************************************************/


vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector< vector<int> > finalAnswer;
    vector<int> combination;
    solve(0,target,combination,finalAnswer,candidates);
    return finalAnswer;
}

void display(vector<vector<int>> vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        for(int j = 0 ; j < vec[i].size() ; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

/*
1] If "Current Element" is less than or equal to "Target" then you have choice.
   i] You may pick it.
   ii] You may not pick it.
   We will try both the possiblities.

2] But if "Current Element" is greater than our "Target" then you have only one choice.
   i] You cannot pick such element.  (There is no point in doing so)

*/


int main()
{
    vector<int> input = {1,3,2,2};
    int target = 3;

    vector<vector<int> > answer = combinationSum(input, target);

    display(answer);
}


