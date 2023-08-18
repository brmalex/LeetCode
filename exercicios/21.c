/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addNode(struct ListNode* list, int val){
    struct ListNode* temp = (struct ListNode*) malloc (sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    struct ListNode* currentNode = list;
    if (list == NULL){
        list = temp;
    }
    else {
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = temp;
    }

    return list;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* list = (struct ListNode*) malloc (sizeof(struct ListNode));
    list = NULL;
    struct ListNode* temp1 = list1;
    struct ListNode* temp2 = list2;
    if (list1 == NULL && list2 && NULL){
        return list;
    } else if (list1 == NULL){
        return list2;
    } else if (list2 == NULL){
        return list1;
    } else {
        while(temp1 != NULL || temp2 != NULL){
            if(temp1 == NULL){
                list = addNode(list, temp2->val);
                temp2 = temp2->next;
            } else if(temp2 == NULL){
                list = addNode(list, temp1->val);
                temp1 = temp1->next;
            } else if(temp1->val <= temp2->val){
                list = addNode(list, temp1->val);
                temp1 = temp1->next;
            } else {
                list = addNode(list, temp2->val);
                temp2 = temp2->next;
            }
        }
    }    
    return list;
}
