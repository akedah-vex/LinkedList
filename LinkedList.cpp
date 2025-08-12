#include "LinkedList.h"

Node::Node()
{
    data = "";
    next = nullptr;
    prev = nullptr;
}

Node::Node(string data_)
{
    data = data_;
    next = nullptr;
    prev = nullptr;
}

Node::~Node() 
{
    next = nullptr;
    prev = nullptr;
    data = "";
}

string Node::GetData()
{
    return data;
}

void Node::SetNext(Node* ptr)
{
    next = ptr;
}

void Node::SetPrev(Node* ptr)
{
    prev = ptr;
}

Node* Node::GetNext()
{
    return next;
}

Node* Node::GetPrev()
{
    return prev;
}

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::InitEmptyList(string data)
{
    Node* node = new Node(data);
    head = node;
    tail = node;
    node->SetNext(nullptr);
    node->SetPrev(nullptr);
}

void LinkedList::InitEmptyList(Node* node)
{
    head = node;
    tail = node;
    node->SetNext(nullptr);
    node->SetPrev(nullptr);
}

void LinkedList::Add(string data)
{
    // is list empty?
    if (head == nullptr && tail == nullptr)
    {
        InitEmptyList(data);
    }
    else // list is not empty
    {
        Node* node = new Node(data);
  
        node->SetPrev(tail);
        tail->SetNext(node);
        tail = node;
    }

    size++;
}

void LinkedList::Add(Node* node)
{
    if (head == nullptr && tail == nullptr)
    {
        InitEmptyList(node);
    }
    else
    {
        node->SetPrev(tail);
        tail->SetNext(node);
        tail = node;
    }

    size++;
}

void LinkedList::Append(string data)
{
    if (head == nullptr && tail == nullptr)
    {
        InitEmptyList(data);
    }
    else
    {
        Node* node = new Node(data);
        node->SetNext(head);
        head->SetPrev(node);
        head = node;
    }

    size++;
}

void LinkedList::Append(Node* node)
{
    if (head == nullptr && tail == nullptr)
    {
        InitEmptyList(node);
    }
    else
    {
        node->SetNext(head);
        head->SetPrev(node);
        head = node;
    }

    size++;
}

void LinkedList::InsertAfter(string target, string data)
{
    Node* location = Find(data);
    Node* node = new Node(data);

    if (location == nullptr)
    {
        Add(node);
    }
    else if (location == tail)
    {
        Add(node);
    }
    else
    {
        location->SetNext(node);
        node->SetPrev(location);
        node->SetNext(location->GetNext());
        location->GetNext()->SetPrev(node);

        size++;
    }
}

void LinkedList::InsertBefore(string target, string data)
{
    Node* location = Find(target);
    Node* node = new Node(data);

    if (location == nullptr)
    {
        Add(node);
    }
    else if (location == head)
    {
        Append(node);
    }
    else
    {
        location->SetPrev(node);
        node->SetNext(location);
        node->SetPrev(location->GetPrev());
        location->GetPrev()->SetNext(node);

        size++;
    }
}

void LinkedList::PopFront()
{
    if (head != nullptr)
    {
        Node* ptr = head->GetNext();
        delete head;
        head = ptr;
        size--;
    }
    else
    {
        tail = nullptr;
    }
}

void LinkedList::PopBack()
{
    if (tail != nullptr)
    {
        Node* ptr = tail->GetPrev();
        delete tail;
        tail = ptr;
        size--;
    }
    else
    {
        head = nullptr;
    }
}

bool LinkedList::Remove(string data)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->GetData() == data)
        {
            if (current == head)
            {
                head = head->GetNext();
                delete current;
                head->SetPrev(nullptr);
            }
            else if (current == tail)
            {
                tail = tail->GetPrev();
                delete current;
                tail->SetNext(nullptr);
            }
            else
            {
                Node* temp = current->GetPrev();
                temp->SetNext(current->GetNext());
                temp = current->GetNext();
                temp->SetPrev(current->GetPrev());
                delete current;
            }

            size--;
            return true;    
        }

        current = current->GetNext();
    }
    
    return false;
}

void LinkedList::RemoveAll(string data)
{
    while (Remove(data));
}

void LinkedList::Clear()
{
    Node* current = head;
    Node* temp = head;
    while (current != nullptr)
    {
        temp = current->GetNext();
        delete current;
        current = temp;
        size--;
    }

    head = nullptr;
    tail = nullptr;
}

void LinkedList::Print()
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->GetData() << " ";
        current = current->GetNext();
    }
}

void LinkedList::Print(Node* node)
{
    if (node == nullptr) return;
    cout << node->GetData() << endl;
}

void LinkedList::PrintReversed()
{
    Node* current = tail;
    while (current != nullptr)
    {
        cout << current->GetData() << " ";
        current = current->GetPrev();
    }
}

Node* LinkedList::Find(string data)
{
    Node* iterator = head;
    while (iterator != nullptr)
    {
        if (iterator->GetData() == data)
        {
            return iterator;
        }

        iterator = iterator->GetNext();
    }

    return nullptr;
}

int LinkedList::Size()
{
    if (!size && head != nullptr && head != tail)
    {
        // this means size is 0, but there is data in the list.
        // this shouldn't happen but in the case that it does,
        // Size() will calculate the size of the list at O(n);
        Node* iterator = head;
        while (iterator != nullptr)
        {
            size++;
            iterator = iterator->GetNext();
        }
    }
    
    return size;
}
