#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/
Node* HasCycle(Node* &head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return fast;
            }
        }
        return NULL;
    }
 Node* solve(Node* &head){
        
        Node* hasCycle = HasCycle(head);
        if(hasCycle == NULL){
            return NULL;
        }
        else{
            Node* fast = hasCycle;
            Node* slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        //we need to return a node here
    }
Node *firstNode(Node *head)
{
	//    Write your code here.
    Node* ans = solve(head);
        return ans;
}
