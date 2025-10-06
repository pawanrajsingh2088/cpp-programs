/*
  Program: Linked List Cycle Detection (Floyd's Tortoise and Hare Algorithm)
  Problem:
    Given the head pointer of a singly linked list, determine if the list contains a cycle.

  Approach:
    Use two pointers (slow and fast) moving at different speeds.
    If they meet, a cycle exists.

  Example Input:
    // 1 -> 2 -> 3 -> 4
    //      ^         |
    //      |_________|

  Example Output:
    Cycle detected: Yes

    // For 1 -> 2 -> 3 -> 4 -> nullptr
    Cycle detected: No

  Time Complexity: O(n)
  Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// --- Example Usage ---
int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create a cycle: node 4 -> node 2
    head->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle detected: Yes" << endl;
    else
        cout << "Cycle detected: No" << endl;

    // Now, break the cycle for a no-cycle test
    head->next->next->next->next = nullptr;
    if (hasCycle(head))
        cout << "Cycle detected: Yes" << endl;
    else
        cout << "Cycle detected: No" << endl;

    // Free the memory (proper deletion omitted for simplicity, as cycle handling would complicate demo)
    return 0;
}
