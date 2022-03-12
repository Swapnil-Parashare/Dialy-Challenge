// 662. Maximum Width of Binary Tree

/* 
Width : 1]Length between the endnodes (i.e Leftmost and the Rightmost 'Non-Null' nodes) on a same level.
        2]The Null nodes between the end nodes(Non Null) are counted.
    
*/

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int widthOfBinaryTree(TreeNode* root)
{
    if(root == NULL) return 0;

    int ans = 0;

    queue< pair<TreeNode*, int> > q;    // Queue will store a pair of TreeNode pointer and 'int' for storing our index.

    q.push({root,0});

    while(!q.empty())                  
    {
        int size = q.size();
        int min = q.front().second;
        int first, last, current_index;
        TreeNode* node;

        for(int i = 0 ; i < size ; i++)  // Here we iterating over nodes of particular level.
        {
            current_index = q.front().second - min;      // Update the index of current parent.
            
            TreeNode* node = q.front().first;
            q.pop();

            if(i == 0 ) first = current_index;
            if(i == size-1) last = current_index;

            if(node->left) q.push({node->left,2*current_index + 1});                // No matter we are pushing childrens , for-loop will still end after current parent level is done.
            if(node->right) q.push({node->right,2*current_index + 2});
        }
        ans = max(ans , last-first+1);
    }
    return ans;


}

/*
Note :

1] At a given point of time our queue will always contain nodes of a particular level only.
2] Its because we are deleting the parent nodes as soon as we push their childrens in the queue.

Why Minimum of a particular level is q.front() ?

1] We know that queue contains nodes of particular level at a given time.
2] We also know that at a given level the minimum index node is always the left most.
3] And we are doing Level Order traversal while pushing the nodes in the queues.
4] Hence nodes are pushed from left to right.
5] Therefore minimum index node is always q.front().

What the fuck does the for-loop actually doing?
1] Iterate over the parent level.
2] For each parent reinitialze there current index, which is equal to its present index - Minimum index present in parent level.
3] Hold the parent in our temporary pointer and delete it.
4] If the parent is left most, store its address as 'first'.
5] If the parent is right most, store its address as 'last'.
6] Push Parent's both the children in the queue.
   IMP :  Children's index are initialize on the basis of updated index of the parent(index-Minimum).

Conclusion : Loop will run only for size of Parent Level.

             A} 1] We are extracting 'first' and 'last'.
                2] After for-loop ends i.e parent level is finished, we are calculating its weidth.

             B} 1] While iterating over the parents level we are pushing there children in the queue.
                2] This childrens are being pushed with the updated index of parent(index-minimum).
             
             C} 1] At the end of the for loop, we will calculate the width of parent level, which we just iterated.
                2] It will get calculated from the 'first' and 'last' which we calculated in loop itself.

             At the start of while loop i.e after we are done with this for-loop.
             1] Current level stored in the queue becomes new parent level.
             2] Size of this parent level is stored in 'size' variable.
             3] So the next for loop runs only for this parent level only.
             4] We also make sure to store the "Minimum Index" of current parent level.

*/

int main()
{
    return 0;
}