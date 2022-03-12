// 133. Clone Graph

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node* orignal, Node* current, vector< Node* >& visited)                              // Orignal Node(For guidance), Current Node(For further creation), visited(To trace previously created node)
{
    visited[current->val] = current;                                                          // Marking our newly created node as visited.


    for(auto orignalNeighbour : orignal->neighbors)                                           // Iterating over "Orignal's" neighbour array.                    
    {
        if(visited[orignalNeighbour->val] == NULL)                                            // If that neighbour is not present in our "visited" array.
        {
            Node* newNode = new Node(orignalNeighbour->val);                                  // Create a new node.
            (current->neighbors).push_back(newNode);                                          // Push it in our "Current" node's 'neighbour' array.
            dfs(orignalNeighbour,newNode,visited);                                            // Recursive call with ---> Orignal Neighbour, Newly created Node, visited array.
        }
        else
        {
            (current->neighbors).push_back(visited[orignalNeighbour->val]);                   // If the orignal neighbour is previously created, then simply push its address in our current node's neighbour's array. 
        }
    }
}

Node* cloneGraph(Node* node)
{
    if(node == NULL) return NULL;

    vector<Node* > visited(1000, NULL);

    Node* current = new Node(node->val);
    
    dfs(node, current, visited);

    return current;
}

int main()
{
    return 0;
}