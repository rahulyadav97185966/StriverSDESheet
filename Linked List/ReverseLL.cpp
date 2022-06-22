#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *current = head;
    while(current != NULL){
        LinkedListNode<int> *nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    return prev;
    
    
}
