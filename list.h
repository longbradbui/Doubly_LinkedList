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
            outstream << temp << " -> ";
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
    // NULL reference
    if (data == nullptr)
    {
        cerr << "#ERROR: Invalid User Input." << endl;
        return false;
    }
    // Empty List
    if (head == nullptr)
    {
        head = new Node<T>();
        head->data = new T(*data);
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
        return true;
    }
    // First in line
    if (*head->data > *data)
    {
        Node <T> *insert_node = new Node < T>();
        insert_node->data = new T(*data);
        insert_node->next = head;
        insert_node->prev = nullptr;
        head->prev = insert_node;
        head = insert_node;
        return true;
    }
    // All others 
    Node<T>* current = head;
    while (current->next != nullptr)
    {
        if (*current->data >= *data)
        {
            Node<T>* insert_node = new Node <T>();
            insert_node->data = new T(*data);
            insert_node->next = current->next;
            insert_node->prev = current;
            current->next->prev = insert_node;
            current->next = insert_node;
            return true;
        }
        else
        {
            current = current->next;
        }
    }
    // At the end
    Node <T>* insert_node = new Node <T>();
    insert_node->data = new T(*data);
    insert_node->next = nullptr;
    insert_node->prev = tail;
    tail->next = insert_node; // Link the previous last node to the new last node
    tail = insert_node; // Update the tail pointer to point to the new last node 
    return true;
}

template <class T>
int List<T>::RemoveAll(T& data)
{

}