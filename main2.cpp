#include "Bst.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Bst<char> tree(3);
    tree.insert(7);
    tree.insert(8);
    string name;
    string firstname;
    string lastname;
    ifstream myfiles("phonebook.txt");

    if (myfiles.is_open())
    {
        while (myfiles >> name)
        {   
            std::string s = name;
            tree.insert(1);
            if(name == "#")
                break;
        }
        myfiles.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }

    cout << "Welcome to the telephone directory system\n"
         << endl;

    while (true)
    {
        cout << "Enter lastname of the person to search for: ";
        cin >> lastname;
        if (lastname == "quit" || lastname == "exit")
        {
            break;
        }

        cout << "\nEnter firstname fo the person to search for: ";
        cin >> firstname;
        cout << "\nThe phone number of " << firstname << " " << lastname << " is" << endl;
        cout << name;
        break;
    }
}
