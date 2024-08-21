#ifndef GLL_H
#define GLL_H

#include <iostream>
#include <cassert> // For assert usage within the class if necessary

template<typename T>
class GLL {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
    };

    Node* head;
    Node* tail;
    Node* iter; // Iterasyon icin degisken
    


public:
    GLL() : head(nullptr), tail(nullptr), iter(nullptr) {} // iter için başlatma

    ~GLL() {
        flush();
    }

    void flush() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }



    bool isEmpty() const {
        return head == nullptr;
    }

    bool append(const T& value) {
        Node* newNode = new Node(value, tail, nullptr);
        if (tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
        return true;
    }

    bool prepend(const T& value) {
        Node* newNode = new Node(value, nullptr, head);
        if (head) head->prev = newNode;
        else tail = newNode;
        head = newNode;
        return true;
    }
    // void append(const T& value) {
    //     Node* newNode = new Node(value, tail, nullptr);
    //     if (isEmpty()) {
    //         head = tail = newNode;
    //     } else {
    //         tail->next = newNode;
    //         tail = newNode;
    //     }
    // }
    bool contains(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }



    bool merge(GLL& other) {
        if (this == &other) return true;
        if (other.head) {
            if (head) {
                tail->next = other.head;
                other.head->prev = tail;
            } else {
                head = other.head;
            }
            tail = other.tail;
        }
        other.head = nullptr;
        other.tail = nullptr;
        return true;
    }
// keep appending so I need to check if two lists are appending I need to leave it. 
    GLL& operator+=(const GLL& other) {
        if (this != &other) {
            // If not appending to itself, directly append the nodes
            for (Node* current = other.head; current != nullptr; current = current->next) {
                this->append(current->data);
            }
        } else {
            // Self-assignment: Need to create a manual temporary copy of the data
            Node* tempHead = nullptr;
            Node* tempTail = nullptr;
            Node* current = head;
            while (current != nullptr) {
                // Create a new node with the current data
                Node* newNode = new Node(current->data);
                if (!tempHead) {
                    tempHead = newNode;
                    tempTail = newNode;
                } else {
                    tempTail->next = newNode;
                    newNode->prev = tempTail;
                    tempTail = newNode;
                }
                current = current->next;
            }

            // Now append the temporary list back to the original list
            current = tempHead;
            while (current != nullptr) {
                this->append(current->data);
                Node* next = current->next;
                delete current; // Clean up temporary nodes
                current = next;
            }
        }
        return *this;
    };



    GLL& operator-=(const GLL& other) {
        Node* current = head;
        while (current != nullptr) {
            Node* toRemove = current;
            current = current->next;
            if (other.contains(toRemove->data)) {
                removeNode(toRemove);
            }
        }
        return *this;
    }



    int purgeGoofy() {
        int count = 0;
        Node* current = head;
        while (current) {
            Node* next = current->next;
            if (isGoofy(current->data)) {
                removeNode(current);
                count++;
            }
            current = next;
        }
        return count;
    }


    int keepGoofy() {
        int count = 0;
        Node* current = head;
        while (current) {
            Node* next = current->next;
            if (!isGoofy(current->data)) {
                removeNode(current);
                count++;
            }
            current = next;
        }
        return count;
    }

    void demoteGoofy() {
        if (!head || !head->next) return;  // No need to demote if list is empty or has only one element

        Node* originalLast = tail;  // Remember the last node when starting
        Node* current = head;

        while (current && current != originalLast->next) {
            Node* next = current->next;  // Save the next node to move to

            if (isGoofy(current->data)) {
                if (current == tail) {
                    // If the current node is already the tail, skip to the next node
                    current = next;
                    continue;
                }
                
                // Detach from the current position
                if (current == head) {
                    head = next;
                    head->prev = nullptr;
                } else {
                    current->prev->next = next;
                    if (next) next->prev = current->prev;
                }

                // Attach to the end
                tail->next = current;
                current->prev = tail;
                current->next = nullptr;
                tail = current;  

                if (current == originalLast) {
                    // If the current was the original last, then stop processing further
                    break;
                }
            }

            current = next;
        }
    }


    bool reset() {
        if (isEmpty()) {
            iter = nullptr; // List boşsa, iter'i null yap
            return false; // ve false döndür
        } else {
            iter = head; // List boş değilse, iter'i listenin başına ayarla
            return true; // ve true döndür
        }
    }



    bool finished() const {
        // Eğer iterator nullptr ise, listenin sonuna gelinmiş demektir
        return iter == nullptr;
    }


    T proceed() {
        if (iter != nullptr) {
            T data = iter->data;
            iter = iter->next;
            return data;
        }
        return T(); // Veya uygun bir değer döndür
    }

private:
    
    void removeNode(Node* node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        delete node;
    }

    
};

#endif // GLL_H
