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
    ListNode* reversegrp(ListNode* head, int size , int len)
    {
        if (len > size) {
            if (size % 2 != 0) {
                return head;
            }

            ListNode* prev = NULL;
            ListNode* current = head;
            ListNode* n = NULL;
            while (current != NULL)
            {
                n = current->next;
                current->next = prev;
                prev = current;
                current = n;
            }
            head = prev;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* n = NULL;
        for (int i = 1; i <= len; i++)
        {
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        int remain = size - 2 * len - 1;
        if (remain <= 0) {
            int nr = size - len;
            if (nr % 2 == 0) {
                ListNode* p = NULL;
                ListNode* c = current;
                ListNode* n = NULL;
                while (c != NULL) {
                    n = c->next;
                    c->next = p;
                    p = c;
                    c = n;
                }
                c = p;
                head->next = c;
                return prev;
            }
            else {
                head->next = current;
                return prev;
            }
        }
        int j = 0;
        head->next = current;
        while (current != NULL and j < len) {
            current = current->next;
            j++;
        }
        current->next = reversegrp(current->next, size - 2 * len - 1, len + 2);
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int n = 0;
        if (head == NULL or head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;

        }
        head->next = reversegrp(head->next, n - 1, 2);
        return head;

    }
};