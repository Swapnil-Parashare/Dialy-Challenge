#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

/***************************************  Helper Functions *************************************/

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


Node* swapPairs(Node* head)
    {
        if(head == NULL || (head)->next == NULL)          // Here we are ensuring that atleast initial two nodes exist.
        {
           return head;
        }
        
        Node* prev = head;
        Node* curr = prev->next;
        
        head = curr;                                    // "current" will be our new head, as we will swap 1st two nodes.

        Node* next = NULL;
        
        while(true)
        {
            next = curr->next;                           // 1] Set 'next' pointer.
            curr->next = prev;                           // 2] Swap current pair.
            
            if(next == NULL || next->next == NULL)       // 3] Check wheather consecutive pair exist or not with the help of our pre planted 'next' pointer. (Step 1)
            {
                prev->next = next;                       // 4] If next pair does not exist, then link current pairs last element to 'next'.
                break;                                   // 5] 'next' may be NULL or a single node.
            }
            
            prev->next = next->next;                      // 6] If consecutive pair do exist then form a bridge. i.e Link current pair's last element with next pair's upcoming first element.
            
            prev = next;                                  // Reallocating 'prev' and 'curr' pointers. 'next' will be reallocated agian at start of the loop. 
            curr = prev->next;
        }
        
        return head;
        
    }



int main()
{
    Node* head = new Node();

    createLL(head);      

    display(head);

    head = swapPairs(head);
    
    display(head);

}

/*
Why changes done on 'head' in swapPairs() is not visible outside the function?

1] In createLL() function, we are not doing changes on 'head' pointer (i.e we are not changing the value of 'head' pointer which is a address)
2] We are modifying the Node pointed by that 'head' pointer. 
3] So the modifications of Node which is pointed by pointer are visible outside the function.
4] If you try to change the value of 'head', i.e if you attempt to change the address which is stored in 'head', it won't be visible outside the function.

Similarty...
1] In swapPairs() function, you can modify the Node pointed by 'head'.
2] Modification of the node pointed by pointer will be visible outside the function.
3] But modification of pointer itself, i.e changing were pointer is pointing to, i.e changing the address stored in pointer
   will not be visible outside the function.

Its Deep....
1] If you want to change value of pointer inside a function, i.e you to change were a pointer is pointing too, i.e the address stored in pointer.
2] Then you will be required to use "Double Pointer" as function parametre.
3] And then pass pointer's address to the function.


Its simple : 1] Pointer points to Node. So you can modify the data stored in Node. But cannot make pointer point to another node.
             2] Double pointer points to pointer. So you modify data stored in this pointer(i.e address). But cannot make double pointer point to another pointer.



Ex :

Node* swapPairs(Node** head)
    {
        if(*head == NULL || (*head)->next == NULL)          // Here we are ensuring that atleast initial two nodes exist.
        {
           return *head;
        }
        
        Node* prev = *head;
        Node* curr = prev->next;
        
        *head = curr;                                    // "current" will be our new head, as we will swap 1st two nodes.

        Node* next = NULL;
        
        while(true)
        {
            next = curr->next;                           // 1] Set 'next' pointer.
            curr->next = prev;                           // 2] Swap current pair.
            
            if(next == NULL || next->next == NULL)       // 3] Check wheather consecutive pair exist or not with the help of our pre planted 'next' pointer. (Step 1)
            {
                prev->next = next;                       // 4] If next pair does not exist, then link current pairs last element to 'next'.
                break;                                   // 5] 'next' may be NULL or a single node.
            }
            
            prev->next = next->next;                      // 6] If consecutive pair do exist then form a bridge. i.e Link current pair's last element with next pair's upcoming first element.
            
            prev = next;                                  // Reallocating 'prev' and 'curr' pointers. 'next' will be reallocated agian at start of the loop. 
            curr = prev->next;
        }
        
        return *head;
        
    }


Now here changes done on "head" are visible outside the function.

*/