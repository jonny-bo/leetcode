#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* createNode(int num)
{
    struct ListNode * node = NULL;
    node = (struct ListNode *)malloc(sizeof(struct ListNode));

    node->val = num;
    node->next = NULL;

    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(void)
{
    struct ListNode *l1, *l2, *l3 = NULL;
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (l1 == NULL || l2 == NULL) {
        printf("malloc size error!");
    }
    l1->val = 2;
    l1->next = createNode(4);
    // l1->next->next = createNode(3);

    l2->val = 5;
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    l3 = addTwoNumbers(l1, l2);
    printf("%d -> %d -> %d", l3->val, l3->next->val, l3->next->next->val);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1, *p2, *p3, *head = NULL;
    int up, num;
    
    p1 = l1;
    p2 = l2;
    up = num = 0;

    while(p1 != NULL || p2 != NULL || up != 0) {
        if (p1 == NULL && p2 != NULL) {
            num = p2->val + up;
            p2 = p2->next;
        } else if (p1 != NULL && p2 == NULL) {
            num = p1->val + up;
            p1 = p1->next;
        } else if (p1 != NULL && p2 != NULL) {
            num = p1->val + p2->val + up;
            p1 = p1->next;
            p2 = p2->next;
        } else {
            num = up;
        }

        if (num >= 10) {
            num = num - 10;
            up  = 1;
        } else {
            up = 0;
        }

        if (head == NULL) {
            head = (struct ListNode *)malloc(sizeof(struct ListNode));
            head->val = num;
            head->next = NULL;
            p3 = head;
        } else {
            p3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p3->next->val = num;
            p3->next->next = NULL;
            p3 = p3->next;
        }
    }

    return head;
}
