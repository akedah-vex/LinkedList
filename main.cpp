#include "LinkedList.h"
using std::cin;
int main ()
{
    LinkedList* List = new LinkedList();

    string input = "";
    while (true)
    {
        cout << ">> ";
        cin >> input;

        if (input == "exit" || input == "x") return 0;

        if (input == "add" || input == "a")
        {
            cin >> input;
            List->Add(input);
        }
        else if (input == "append" || input == "aa")
        {
            cin >> input;
            List->Append(input);
        }
        else if (input == "print" || input == "p")
        {
            List->Print();
            cout << endl;
        }
        else if (input == "printrev" || input == "pr")
        {
            List->PrintReversed();
            cout << endl;
        }
        else if (input == "clear" || input == "c")
        {
            List->Clear();
            cout << endl;
        }
        else if (input == "remove" || input == "r")
        {
            cin >> input;
            List->Remove(input);
        }
        else if (input == "removeall" || input == "ra")
        {
            cin >> input;
            List->RemoveAll(input);
        }
        else if (input == "popf" || input == "pf")
        {
            List->PopFront();
        }
        else if (input == "popb" || input == "pb")
        {
            List->PopBack();
        }
        else if (input == "find")
        {
            cin >> input;
            List->Print(List->Find(input));
        }
        else if (input == "size" || input == "s")
        {
            cout << List->Size() << endl;
        }
        else if (input == "insertbefore" || input == "ib")
        {
            string data = "";
            cin >> input;
            cin >> data;
            List->InsertBefore(input, data);
        }
        else if (input == "insertafter" || input == "ia")
        {
            string data = "";
            cin >> input;
            cin >> data;
            List->InsertAfter(input, data);
        }
    }

    cout << "EXITING" << endl;
    return 0;
}