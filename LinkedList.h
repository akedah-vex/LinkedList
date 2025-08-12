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

        void Add(string data);
        void Append(string data);
        void PopFront();
        void PopBack();

        void InitEmptyList(string data);
        void Remove(string data);
        void Clear();

        void Print();
        void PrintReversed();

    private:
        Node* head;
        Node* tail;
};

