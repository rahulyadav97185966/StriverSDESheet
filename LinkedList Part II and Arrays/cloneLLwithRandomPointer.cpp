/*************************************************************

	Following is the Node class structure

		class Node
		{
		public:
		    int data;
		    Node *next;
		    Node *random;
		    Node(int data)
		    {
		        this->data = data;
		        this->next = NULL;
		        this->random = NULL;
		    }
		    ~Node()
		    {
		        if (next)
		        {
		            delete next;
		        }
		    }
		};

*************************************************************/

void insertAtTail(Node* &cloneHead, Node*  &cloneTail, int data){
        Node* node = new Node(data);
        if(cloneHead == NULL){
            cloneHead = node;
            cloneTail = node;
        }
        else{
            cloneTail->next = node;
            cloneTail = node;
        }
    }
Node *cloneLL(Node *head)
{
	// Write your code here
    if(head == NULL){
            return head;
        }
        //Step1 : Create clone node and insert into it
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        //step 2 : map the clone node to originalLsit
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            //For original Node
            Node* nextNode = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = nextNode;
            
            //For Clone Node
            nextNode = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = nextNode;
        }
        
        //Step 3: Map the random pointer now
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }
        
        //Step 4: revert the changes
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        
        //Step 5 : return the answer
        return cloneHead;

}
