/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* new_head = new Node(
            head->val
        );

        Node* prev = new_head;
        Node* current = head->next;

        while (current != nullptr) {
            Node* new_node = new Node(
                current->val
            );

            prev->next = new_node;

            prev = new_node;
            current = current->next;
        }

        Node* current_old = head;
        Node* current_new = new_head;

        while (current_old != nullptr) {
            Node* next_old = current_old->next;
            Node* next_new = current_new->next;

            current_old->next = current_new;
            current_new->next = next_old;

            current_old = next_old;
            current_new = next_new;
        }

        Node* c = head;
        Node* ans = c->next;

        while (c != nullptr) {
            if (c->random != nullptr) {
                c->next->random = c->random->next;
            }

            c = c->next->next;
        }

        c = head;

        while (c != nullptr) {
            Node* old = c;
            Node* new_ = c->next;

            old->next = new_->next;

            if (old->next != nullptr) {
                new_->next = old->next->next;
            } else {
                new_->next = nullptr;
            }

            c = old->next;
        }

        return ans;
    }
};
