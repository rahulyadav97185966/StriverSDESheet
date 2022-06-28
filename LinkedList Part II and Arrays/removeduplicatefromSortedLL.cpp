/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
             return head;
        }
        Node* prev = head;
        if(prev->data == prev->next->data){
            Node* temp = prev->next;
            prev->next = prev->next->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            prev = prev->next;
        }
        uniqueSortedList(prev);
        return head;
}
