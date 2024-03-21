#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void appendNode(Node*& tail, Node* newNode) {
    if (tail) {
        tail->next = newNode;
    }
    tail = newNode;
    newNode->next = nullptr;
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    Node *smallerTail = nullptr, *largerTail = nullptr;

    // Initialize smaller and larger lists as empty.
    smaller = larger = nullptr;

    while (head != nullptr) {
        Node* next = head->next; // Save next node.
        if (head->val <= pivot) {
            if (!smaller) {
                smaller = head; // Initialize smaller list with head.
            } else {
                appendNode(smallerTail, head); // Append to smaller list.
            }
            smallerTail = head; // Update tail of smaller list.
        } else {
            if (!larger) {
                larger = head; // Initialize larger list with head.
            } else {
                appendNode(largerTail, head); // Append to larger list.
            }
            largerTail = head; // Update tail of larger list.
        }
        head = next; // Move to the next node in the original list.
    }

    // Ensure the last nodes of the smaller and larger lists do not link back to the original list.
    if (smallerTail) {
        smallerTail->next = nullptr;
    }
    if (largerTail) {
        largerTail->next = nullptr;
    }

    // The original list is now empty.
    head = nullptr;
}
