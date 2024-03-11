#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	Node* next;
	Node* prev;
	T* data;
};

template <class T>
class List
{
    friend ostream& operator<<(ostream& outstream, const List<T>& rhs)
    {
        if (rhs.head == nullptr)
        {
            cerr << "This is an empty list" << endl;

        }
        Node<T>* current = rhs.head;
        while (current != nullptr)
        {
            T temp = *(current->data);
            outstream << temp << " <-> ";
            current = current->next;
        }
        return outstream;
    }
public:
	List();
	~List();
	bool InsertNewItem(T* data);
    int RemoveAll(T& data);
    Node<T>* head;
    Node<T>* tail;
    template <class U>
    friend ostream& operator<<(ostream& outstream, const List<T>& rhs);
private:
};
#endif

template <class T>
List<T>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
List<T>::~List()
{
}

template <class T>
bool List<T>::InsertNewItem(T* data)
{
    if (data == nullptr)
    {
        cerr << "#ERROR: Invalid User Input." << endl;
        return false;
    }
    Node<T>* insert_node = new Node<T>();
    insert_node->data = new T(*data);
    // Empty List
    if (head == nullptr)
    {
        head = insert_node;
        tail = insert_node;
        insert_node->prev = nullptr;
        insert_node->next = nullptr;
        return true;
    }
    Node<T>* current = head;
    while (current != nullptr)
    {
        if (*current->data > *insert_node->data)
        {
            // First in line 
            if (current == head)
            {
                insert_node->next = head;
                insert_node->prev = nullptr;
                head->prev = insert_node;
                head = insert_node;
            }
            // All others
            else
            {
                insert_node->next = current;
                insert_node->prev = current->prev;
                current->prev->next = insert_node;
                current->prev = insert_node;
            }
            return true;
        }
        else if (*current->data == *insert_node->data)
        {
            // Insert duplicate node after the current node
            insert_node->next = current->next;
            if (current->next != nullptr)
            {
                current->next->prev = insert_node;
            }
            else // (current->next == nullptr)
            {
                tail = insert_node;
            }
            current->next = insert_node;
            insert_node->prev = current;
            return true;
        }
        else // (*current->data < *insert_node->data)
        {
            current = current->next;
        }
    }
    // Insert at the end
    insert_node->next = nullptr;
    insert_node->prev = tail;
    tail->next = insert_node;
    tail = insert_node;
    return true;
}


template <class T>
int List<T>::RemoveAll(T& data)
{
    if (head == nullptr)
    {
        return 0;
    }
    else
    {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr)
        {
            if (*current->data != data)
            {
                current = current->next;
            }
            else
            {
                Node<T>* temp = current;  // Keep a reference to the node to be deleted
                if (current == head)
                {
                    head = head->next;  // Update head if deleting the first node
                    if (head->next != nullptr)
                    {
                        head->prev = nullptr;  // Update the previous pointer of the new head (list does not become empty after deletion)
                    }
                    else
                    {
                        tail = nullptr;  // If the list becomes empty, update tail as well (list become empty after deletion)
                    }
                }
                else if (current == tail)
                {
                    tail = current->prev;  // Update tail if deleting the last node
                    if (tail != nullptr)
                    {
                        tail->next = nullptr;  // Update the next pointer of the new tail (list does not become empty after deletion)
                    }
                    else
                    {
                        head = nullptr;  // If the list becomes empty, update head as well (list become empty after deletion)
                    }
                }
                else // (current == somewhere in the list)
                {
                    current->prev->next = current->next;  // Link previous node to the next node
                    current->next->prev = current->prev;  // Link next node to the previous node
                }
                current = current->next;  // Move the current pointer to the next node. Temp pointer still holds to the "old" current pointer 
                delete temp->data;  // Delete the data of the current node
                delete temp;  // Delete the current node
                count++;  // Increment the counter
            }
        }
        return count;  // Return the total number of nodes deleted
    }
}
