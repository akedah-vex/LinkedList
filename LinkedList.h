#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Node {
    public:
        Node();
        Node(string data_);
        ~Node();

        string GetData();

        void SetNext(Node* ptr);
        void SetPrev(Node* ptr);
        Node* GetNext();
        Node* GetPrev();

    private:
        string data;
        Node* next;
        Node* prev;
};

class LinkedList {
    public: 
        LinkedList();
        ~LinkedList();

        void InitEmptyList(string data);
        void InitEmptyList(Node* node);

        void Add(string data);
        void Add(Node* node);
        void Append(string data);
        void Append(Node* node);

        // TODO: Fix these functions and test them out
        void InsertAfter(string target, string data);
        void InsertBefore(string target, string data);

        bool Remove(string data);
        void RemoveAll(string data);
        void PopFront();
        void PopBack();
        void Clear();

        void Print();
        void Print(Node* node);
        void PrintReversed();

        Node* Find(string data);

        int Size();

    private:
        Node* head;
        Node* tail;

        int size;
};

