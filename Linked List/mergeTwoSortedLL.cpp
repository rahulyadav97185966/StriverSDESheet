#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* temp = new Node<int>(-1);
    Node<int>* head = temp;
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    else{
        Node<int>* temp1 = first;
        Node<int>* temp2 = second;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data <= temp2->data){
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
        }
        while(temp1 != NULL){
             temp->next = temp1;
             temp1 = temp1->next;
             temp = temp->next;
        }
        while(temp2 != NULL){
             temp->next = temp2;
             temp2 = temp2->next;
             temp = temp->next;
        }
    }
    Node<int>* head1 = head;
    head=head->next;
    head1->next = NULL;
    delete head1;
    return head;
}
