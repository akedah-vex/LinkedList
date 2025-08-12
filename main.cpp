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
    }

    cout << "EXITING" << endl;
    return 0;
}