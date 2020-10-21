#include <cstdlib>
#include <iostream>
#include <vector>

struct Node
{
  int id;
  Node* next = nullptr;
};

void print_recursive(const Node* node)
{
  printf("Node(%d)", node->id);
  if (node->next != nullptr) {
    printf(" -> ");
    print_recursive(node->next);
  }
};

void print(const Node* node)
{
  printf("print nodes: ");
  print_recursive(node);
  printf("\n");
}

int main()
{
  // std::vector<int> input = {};
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};

  Node* head = nullptr;
  Node* last = nullptr;

  for (const auto& id : input) {
    if (last == nullptr) {
      last = new Node{id};
      head = last;
      continue;
    }

    auto node = new Node{id};
    last->next = node;
    last = node;
  }
  // last->next = head; // circulation

  auto runner1 = head;
  auto runner2 = head;

  if (runner2 == nullptr) {
    printf("node list is empty");
  }

  int middle;

  while (runner2 != nullptr) {
    if (runner2->next == nullptr) {
      middle = runner1->id;
      break;
    }

    if (runner2->next->next == nullptr) {
      middle = runner1->next->id;
      break;
    }

    runner1 = runner1->next;
    runner2 = runner2->next->next;

    if (runner1 == runner2) {
      printf("circulation detected...");
      return 1;
    }
  }

  print(head);
  printf("middle = %d", middle);

  return 0;
}
