// ## Problem Statement
// Implement a function to reverse a singly linked list iteratively.

// ## Task
// - Create reverseList() function
// - Use iterative approach with 3 pointers
// - Add proper test cases

// ## Example
// Input: 1->2->3->4->5
// Output: 5->4->3->2->1

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr; // Previous node
    ListNode* curr = head;    // Current node
    while (curr) {
        ListNode* nextTemp = curr->next; // Store next node
        curr->next = prev;               // Reverse the link
        prev = curr;                     // Move prev forward
        curr = nextTemp;                 // Move curr forward
    }
    return prev; // New head of reversed list
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
