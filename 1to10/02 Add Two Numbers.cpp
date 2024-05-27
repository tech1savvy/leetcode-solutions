class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *listSum= NULL;
        ListNode *current= NULL;
        
        int i=0;
        int x,y;
        int sum = 0;
        int carry = 0;

        if(l1==NULL && l2==NULL){
            listSum = new ListNode(0);
        }else{
            while(l1!=NULL || l2!=NULL){
                x= l1!=NULL ? l1->val : 0;
                y= l2!=NULL ? l2->val : 0;
                sum= x+y+carry;
                carry = sum>=10 ? 1:0;

                if(listSum==NULL){
                    listSum= new ListNode(sum%10);
                    current = listSum;
                }else{
                    current->next = new ListNode(sum%10);
                    current = current->next;
                }
                
                if(l1!=NULL) l1= l1->next;
                if(l2!=NULL) l2= l2->next;
                
                i++;
            }
        }

        if(carry) current->next = new ListNode(1);
        return listSum;
    }
};