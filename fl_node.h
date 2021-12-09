//
// Created by ux on 08.12.21.
//

#ifndef FL_REVERSING_FL_NODE_H
#define FL_REVERSING_FL_NODE_H

#include <memory>

/**
 * Templated node for a single linked (forward) list.
 *
 * @tparam T
 */

template <typename T>
struct FLNode{

    explicit FLNode(T value) {
        this->value = value;
        std::shared_ptr<FLNode<T>> empty(nullptr);
        this->next  = empty;
    }

    FLNode(std::initializer_list<T> list) {
        std::shared_ptr<FLNode<T>> empty(nullptr);
        //I can't use the head as a shared pointer because of the 'this'.
        FLNode<T> * head = nullptr;
        for (T node: list) {
            if (nullptr == head) {
                this->value = node;
                this->next  = empty;
                head = this;
            } else {
                head->next = std::make_shared<FLNode<T>>(node);
                head = head->next.get();
            }
        }
    }

    FLNode(FLNode & node) {
        this->value = node.value;
        this->next  = node.next;
    }

    FLNode(FLNode && node) {
        this->value = node.value;
        this->next  = std::move(node.next);
    }

    ~FLNode() {
        /*
        std::cout << "destruct: " << this->value << std::endl;
         */
    }

    T value;
    std::shared_ptr<FLNode<T>> next;
};

#endif //FL_REVERSING_FL_NODE_H
