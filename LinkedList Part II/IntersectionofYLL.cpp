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

int findIntersection(Node *headA, Node *headB)
{
    //Write your code here
    if(headA == NULL){
            return -1;
        }
        if(headB == NULL){
            return -1;
        }
        unordered_map<Node*, bool> mp;
        Node* tempA = headA;
        Node* tempB = headB;
        while(tempA != NULL || tempB != NULL){
            if(tempA!= NULL && mp[tempA]){
                return tempA->data;
            }
            else{
                mp[tempA] = true;
            }
            if(tempB != NULL && mp[tempB]){
                return tempB->data;
            }
            else{
                mp[tempB] = true;
            }
            if(tempA != NULL){
                tempA = tempA->next;    
            }
            if(tempB != NULL){
                tempB = tempB->next;
            }
        }
        return -1;
}
