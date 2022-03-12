#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

/********************************************************* Helper Functions *************************************************************/

void createLL(Node* first)
{
    int x;
    cout << "\n\nEnter the value of first node : ";
    cin >> x;

    Node* t1 = first;
    t1->data = x;
    t1->next = NULL;

    Node* temp;

    while(true)
    {
        cout << "Enter Value of next node : ";
        cin >> x;
        if(x == -1) break;

        temp = new Node();
        temp->data = x;
        temp->next = NULL;
        t1->next = temp;
        t1 = temp;
    }
}

void display(Node* first)
{   
    Node* temp = first;
    cout << "\nLinked List : ";
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }   
}


/******************************************** This was my first approach and it got accepted on Leetcode ************************************************/

Node* merge(Node* first, Node* second)
{
    Node* third;
    Node* last;

    if(first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        last = third = second;
        second = second->next;
        last->next = NULL;
    }

    while(first != NULL && second != NULL)
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if(first != NULL) last->next = first;
    else last->next = second;

    return third;
}



Node* mergeKLists(vector<Node*>& lists)
    {
        int size = lists.size();
        if(size == 0) return NULL;
        else if(size == 1) return lists[0];
        
        Node* l1;
        Node* l2;
    
        while(lists.size() > 1)
        {
            if(lists[0] != NULL && lists[1] != NULL)
            {
                l1 = lists[0];
                lists.erase(lists.begin());  
                l2 = lists[0];     
                lists.erase(lists.begin());
                lists.push_back(merge(l1,l2));
             }
            else if( lists[0] == NULL && lists[1] == NULL)
            {
                lists.erase(lists.begin());
                lists.erase(lists.begin());
            }
            else if( lists[0] == NULL) lists.erase(lists.begin());
            else if( lists[1] == NULL) lists.erase(lists.begin() + 1);

        }
        return lists[0];
        
    }

/***********************************************************************************************************************************************/
// This problem is also solved using Priority Queues( Heap ), give it a try whenever possible.

int main()
{
    vector<Node*> lists;
    Node* temp;
    for(int i = 0 ; i < 3 ; i++)
    {   
        temp = new Node();
        createLL(temp);
        lists.push_back(temp);
    }

    Node* answer = mergeKLists(lists);

    display(answer);
}