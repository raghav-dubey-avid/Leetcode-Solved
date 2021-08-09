//T(n) - O(n)

// CPP program to rearrange a linked list in given manner 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
/* Function to reverse the linked list */
void arrange(struct Node* head) 
{ 
    struct Node* temp = head; 
    deque<int> d; // defining a deque 
  
    // push all the elements of linked list in to deque 
    while (temp != NULL) { 
        d.push_back(temp->data); 
        temp = temp->next; 
    } 
  
    // Alternatively push the first and last elements 
    // from deque to back to the linked list and pop 
    int i = 0; 
    temp = head; 
    while (!d.empty()) { 
        if (i % 2 == 0) { 
            temp->data = d.front(); 
            d.pop_front(); 
        } 
        else { 
            temp->data = d.back();  
            d.pop_back();  
        } 
        i++; 
        temp = temp->next; // increase temp 
    } 
} 
  
/*UTILITY FUNCTIONS*/
/* Push a node to linked list. Note that this function 
changes the head */
void push(struct Node** head_ref, char new_data) 
{ 
    /* allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to pochar to the new node */
    (*head_ref) = new_node; 
} 
  
// printing the linked list 
void printList(struct Node* head) 
{ 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 
  
/* Drier program to test above function*/
int main() 
{ 
    // Let us create linked list 1->2->3->4 
    struct Node* head = NULL; 
  
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
    cout << "Given linked list\t"; 
    printList(head); 
    arrange(head); 
    cout << "\nAfter rearrangement\t"; 
    printList(head); 
    return 0; 
} 