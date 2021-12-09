#include <iostream>

#include "fl_node.h"

int main(int, char**) {
    auto ll = {0, 1, 2, 3, 4, 5, 6, 7};
    auto sl = std::make_shared<FLNode<int>>(ll);

    {
        auto head = sl;
        while (nullptr != head.get()) {
            std::cout << head->value << " ";
            auto next = head->next;
            head.reset();
            head = next;
        }
        std::cout << std::endl;
    }

    std::shared_ptr<FLNode<int>> empty(nullptr);
    auto first = empty;
    auto second = empty;
    auto third = empty;
    auto head = sl;
    while (nullptr != head.get()) {
        if (nullptr != second.get()) {
            second->next.reset();
            second->next = first;
        }
        first.reset();
        first = second;
        second.reset();
        second = third;
        third.reset();
        third = head;
        auto next = head->next;
        head.reset();
        head = next;
    }

    if (nullptr != second.get()) {
        second->next.reset();
        second->next = first;
    }
    if (nullptr != third.get()) {
        third->next.reset();
        third->next = second;
    }
    head = third;

    first.reset();
    second.reset();
    third.reset();

    sl.reset();
    sl = head;

    while (nullptr != head.get()) {
        std::cout << head->value << " ";
        auto next = head->next;
        head.reset();
        head = next;
    }
    std::cout << std::endl;

    sl.reset();

    return 0;
}
