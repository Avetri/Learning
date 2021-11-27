#include <iostream>

template <typename T> struct Node{
    Node(T value, Node<T>* next) {
        this->value = value;
        this->next  = next;
    }
    Node(T value) {
        this->value = value;
        this->next  = NULL;
    }
    Node(std::initializer_list<T> list) {
        struct Node<T>* head = NULL;
        for (T node: list) {
            if (NULL == head) {
                this->value = node;
                this->next  = NULL;
                head = this; 
            } else {
                head->next = new Node<T>(node);
                head = head->next;
            }
        }
    }
    T value;
    Node<T>* next;
};

int main(int argc, char** argv) {
    struct Node<int> sl = {0, 1, 2, 3, 4, 5, 6, 7};

    struct Node<int>* head = &sl;
    while (NULL != head) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;

    struct Node<int>* first = NULL;
    struct Node<int>* second = NULL;
    struct Node<int>* third = NULL;
    head = &sl;
    while (NULL != head) {
        if (NULL != second) {
            second->next = first;
        }
        first = second;
        second = third;
        third = head;
        head = head->next;
    }
    if (NULL != second) {
        second->next = first;
    }
    if (NULL != third) {
        third->next = second;
    }
    head = third;
    while (NULL != head) {
        std::cout << head->value << " ";
        head = head->next;
    }

    return 0;
}
