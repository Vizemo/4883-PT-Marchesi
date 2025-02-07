## 2 - Add Two Numbers
### Victor Marchesi

## Description

- I chose problem [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P2.pdf) | PDF instructions for P2. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P2. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P2. |

### Solution in C++
```c++
/*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Head of the result list
        ListNode* head = nullptr;
        // Pointer to traverse the result list
        ListNode* current = nullptr;
        // Carry for digits exceeding 9
        int carry = 0;

        // Traverse both lists and handle carry
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = 0;
            int val2 = 0;

            // Get the value from l1 if available
            if(l1 != nullptr) {
                val1 = l1->val;
                l1 = l1->next;
            }

            // Get the value from l2 if available
            if(l2 != nullptr) {
                val2 = l2->val;
                l2 = l2->next;
            }

            // Calculate the sum of both digits plus any carry from the previous step
            int sum = val1 + val2 + carry;

            // Update the carry (sum divided by 10)
            carry = sum / 10;

            // Create the new node with the single digit value
            ListNode* newNode = new ListNode(sum % 10);

            // If head is null, it's the first node of the result list
            if(head == nullptr) {
                head = newNode;
                current = head;
            }
            else{
                current->next = newNode;
                current = current->next;
            }
        }

        // Return the head of the result list
        return head;
    }
};
```