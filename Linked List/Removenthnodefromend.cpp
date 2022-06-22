/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* &head){
        ListNode* temp = head;
        int cnt = 0;
        if(temp == NULL){
            return 0;
        }
        else{
            while(temp != NULL){
                temp = temp->next;
                cnt++;
            }
        }
        return cnt;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLength(head);
        if(length == 0){
            return NULL;
        }
        cout<<"the length of the list is "<<length<<endl;
        int k = length-n;
        cout<<"value of k is"<<k<<"\n";
        ListNode* temp = head;
        //if we want to delete first elemt
        if(k == 0 && length == 1){
            return NULL;
        }
        else if(k == 0){
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        //last element
        else if(k == length-1){
            ListNode* prev = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            prev = temp->next;
            delete prev;
            temp->next = NULL;
        }
        //middle element
        else{
            k = k-1;
            while(k--){
                temp = temp->next;
            }
            ListNode* prev = temp->next;
            temp->next = prev->next;
            prev->next = NULL;
            delete prev;
        }
        return head;
    }
    
    
};
