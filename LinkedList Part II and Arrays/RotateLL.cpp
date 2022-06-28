#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/
 int getlength(Node* &head){
        int count = 0;
        Node* temp  = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

Node *rotate(Node *head, int k) {
     // Write your code here.
    int n = getlength(head);
        if(k == 0 || n == 0 || k%n == 0 || n == 1){
            return head;
        }
        k = k % n;
        
        Node* prev = NULL;
        Node* current = head;
        int t = n - k;
        while(t--){
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        Node* temp = current;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        return current;
}
