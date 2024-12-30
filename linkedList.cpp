#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 2
 * 2 3
 * 1 3
 * 1 2
 */

typedef struct l_node {
  int data = 0;
  l_node *next = nullptr;
  l_node *prev = nullptr;
} l_node;

void add_node(l_node **head, int data) {
  l_node *new_node = new l_node;
  new_node->data = data;

  if (*head == nullptr) {
    head = &new_node;
  }

  l_node *last_node = *head;
  while (last_node->next != nullptr) {
    last_node = last_node->next;
  }
  // now current = the end of the linked list

  last_node->next = new_node;
  new_node->prev = last_node;
}

void delete_node(l_node **head, int needle) {
  if (head == nullptr) {
    cout << "list is empty" << endl;
    return;
  }
  l_node *current_node = *head;
  if (current_node->data == needle) {
    cout << "deleting head" << endl;
    l_node *tmp = *head;
    if (current_node->next != nullptr) {
      current_node->next->prev = nullptr;
      *head = current_node->next;
    } else {
			*head = nullptr;
		}
    free(tmp);
    return;
  }
  while (current_node->next != nullptr) {
    if (current_node->data == needle) {
      // delete
      l_node *tmp = current_node;
      current_node->prev->next = current_node->next;
      current_node->next->prev = current_node->prev;
      free(tmp);
      return;
    }
    current_node = current_node->next;
  }
  if (current_node->data == needle) {
    l_node *tmp = current_node;
    current_node->prev->next = nullptr;
    free(tmp);
    return;
  }
}

void display(l_node *head) {
  if (head == nullptr) {
    cout << "emtpy list" << endl;
    return;
  }
  l_node *current_node = head;
  while (current_node->next != nullptr) {
    cout << current_node->data << '\t';
    current_node = current_node->next;
  }
  cout << current_node->data << endl;
}

int main() {
  l_node *head = new l_node;
  head->data = 1;
	add_node(&head, 2);
  display(head);
  delete_node(&head, 2);
  display(head);
}
