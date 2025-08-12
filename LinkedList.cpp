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
}

void LinkedList::Append(string data)
{
    // append node to the front of the lsit
    // is list empty?
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
}

void LinkedList::PopFront()
{
    if (head != nullptr)
    {
        Node* ptr = head->GetNext();
        delete head;
        head = ptr;
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
    }
    else
    {
        head = nullptr;
    }
}

void LinkedList::Remove(string data)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->GetData() == data)
        {
            // cout << current->GetData() << endl;
            // we found the data to delete
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
            else // somewhere in the middle
            {
                Node* temp = current->GetPrev();
                temp->SetNext(current->GetNext());
                temp = current->GetNext();
                temp->SetPrev(current->GetPrev());

                delete current;
            }
        }
    
        current = current->GetNext();
    }
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

void LinkedList::PrintReversed()
{
    Node* current = tail;
    while (current != nullptr)
    {
        cout << current->GetData() << " ";
        current = current->GetPrev();
    }
}