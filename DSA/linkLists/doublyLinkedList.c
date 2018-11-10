#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;

    struct node *next;
    struct node *prev;
};

// this link always point to first link
struct node *head = NULL;

// this link always point to last link
struct node *last = NULL;

struct node *current = NULL;

// is list empty
bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next) {
        length ++;
    }

    return length;
}

// display the list in from first to last
void displayForward() {
    // start from the beginning
    struct node *ptr = head;

    // navigate till the end of the list
    printf("[ ");

    while (ptr != NULL) {
        printf("(%d, %d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    
    printf("]\n");
}

// display the list from last to first
void displayBackward() {
    // start from the last
    struct node *ptr = last;

    // navigate till the start of the list
    printf("[ ");
    
    while (ptr != NULL) {
        printf("(%d, %d) ", ptr->key, ptr->data);
        ptr = ptr->prev;
    }

    printf("]\n");
}

// insert link at the first location
void insertFirst(int key, int data) {
    // create a link
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if (isEmpty()) {
        // make it the last link
        last = link;
    } else {
        // update first prev link
        head->prev = link;
    }

    // point it to old first link
    link->next = head;
    head = link;
}

// insert link at the last location
void insertLast(int key, int data) {
    // create a link
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;

    if (isEmpty()) {
        // make it the last link
        last = link;
    } else {
        // make link a new last link
        last->next = link;

        // mark old last node as prev of new link
        link->prev = last;
    }

    // point last to new last node
    last = link;
}

// delete first item
struct node *deleteFirst() {
    // save reference to first link
    struct node *tempLink = head;

    // if only one link
    if (head->next == NULL) {
        last = NULL;
    } else {
        head->next->prev = NULL;
    }

    head = head->next;
    // return the deleted link
    return tempLink;
}

struct node *deleteLast() {
    // save reference to last link
    struct node *tempLink = last;

    // if only one link
    if (head->next == NULL) {
        head = NULL;
    } else {
        last->prev->next = NULL;
    }

    last = last->prev;

    // return the deleted link
    return tempLink;
}

// delete a link with given key
struct node *delete(int key) {
    // start from the first link
    struct node *current = head;
    struct node *previous = NULL;

    // if list is empty
    if (head == NULL) {
        return NULL;
    }

    // navigate through list
    while (current->key != key) {
        // if it is last node
        if (current->next == NULL) {
            return NULL;
        } else {
            // store reference to current link
            previous = current;

            // move to next link
            current = current->next;
        }
    }

    // found a math, update the link
    if (current == head) {
        // change first to point to next link
        head = head->next;
    } else {
        // bypass the current link
        current->prev->next = current->next;
    }

    return current;
}

bool insertAfter(int key, int newKey, int data) {
    // start from the first link
    struct node *current = head;

    // if list is empty
    if (head == NULL) {
        return false;
    }

    // navigate through list
    while (current->key != key) {
        // if it is last node
        if (current->next == NULL) {
            return false;
        } else {
            // move to next link
            current = current->next;
        }
    }

    // create a link
    struct node *newLink = (struct node*)malloc(sizeof(struct node));
    newLink->key = newKey;
    newLink->data = data;

    if (current == last) {
        newLink->next = NULL;
        last = newLink;
    } else {
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;
    return true;
}

int main() {
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    printf("List (First to Last): \n");
    displayForward();

    printf("List (Last to first): \n");
    displayBackward();

    printf("List, after deleting first record: \n");
    deleteFirst();
    displayForward();

    printf("List, after deleting last record: \n");
    deleteLast();
    displayForward();

    printf("List, insert after key(4): \n");
    insertAfter(4, 7, 13);
    displayForward();

    printf("List, after delete key(4): \n");
    delete(4);
    displayForward();

    return 0;
}