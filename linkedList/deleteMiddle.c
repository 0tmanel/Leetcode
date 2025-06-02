  #include <stdio.h>
#include <stdlib.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
  struct ListNode*ft_create_elem(int data)
{
	struct ListNode* new_node;
	
	new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(new_node)
	{
		new_node->val = data;
		new_node->next = NULL;
	}
	return (new_node);
}
int calcu(struct ListNode* head)
{
    struct ListNode* temp = head;
    int index = 0;
    while(temp)
    {
        index++;
        temp = temp->next;
    }
    return index;
}
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!head || !head->next) {
         // Edge case: 0 or 1 node
        free(head);
        return NULL;
    }
    int mid = calcu(head) / 2;
    struct ListNode* old;
    struct ListNode* cur = head;
    int i = 0;
    while( cur->next)
    {
        if(i == mid)
        {
            struct ListNode* temp = cur;
            if(old)
            {
                old->next = cur->next;
            }else{
                head = cur->next;
            }
            free(temp);
            break;
        } 
        i++;
        old = cur;
        cur = cur->next;
    }
    return head;
}
int main ()
{
    int a  = 1;
    int b = 3;
    int c = 4;
    int d = 7;
     int e = 1;
    int f = 2;
    int j = 6;


    struct ListNode*head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    head->next->next->next = ft_create_elem(d);
    head->next->next->next->next = ft_create_elem(e);
    head->next->next->next->next->next = ft_create_elem(f);
    head->next->next->next->next->next->next = ft_create_elem(j);
   struct ListNode* head2 = deleteMiddle(head);
   while (head2)
   {
    printf("%d\n", head2->val);
    head2 = head2->next;
   }
   
}
/*struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head== NULL || head->next==NULL){
        free(head);
        return NULL;
    }
    struct ListNode*temp=head,*nextnode;
    
    int size=countnodes(head);
    int mid=size/2;
     int i=1;
    while(i<mid && temp->next!=NULL){
        i++;
temp=temp->next;
 }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    return head;
    
}*/