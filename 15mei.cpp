
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

class DoubleLinkedList
{
private:
    Node* START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;
        cout << "\nEnter the name of the student: ";
        cin >> nm;

        Node* newNode = new Node(); // new node
        newNode->noMhs = nim;
        newNode->name = nm;

        // insert the node into the list
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed\n";
                return;
            }
            newNode->next = START;
            if (START != NULL)
                START->prev = newNode;
            newNode->prev = NULL;
            START = newNode;
            return;
        }

        Node* previous = START;
        Node* current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = previous;
        if (current != NULL)
        {
            current->prev = newNode;
        }
        previous->next = newNode;
    }

    void deleteNode()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node* current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nRecord not found\n";
            return;
        }

        if (current->next != NULL)
            current->next->prev = current->prev;

        if (current->prev != NULL)
            current->prev->next = current->next;
        else
            START = current->next;

        delete current;
        cout << "\nRecord with roll number " << rollNo << " deleted\n";
    }

    void displayAscending()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        Node* current = START;
        cout << "\nRecords in ascending order of roll number are:\n";
        while (current != NULL)
        {
            cout << current->noMhs << " " << current->name << "\n";
            current = current->next;
        }
    }

    void displayDescending()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        Node* current = START;
        while (current->next != NULL)
        {
            current = current->next;
        }

        cout << "\nRecords in descending order of roll number are:\n";
        while (current != NULL)
        {
            cout << current->noMhs << " " << current->name << "\n";
            current = current->prev;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty\n";
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node* current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nRecord not found\n";
        }
        else
        {
            cout << "\nRecord found:\n";
            cout << "Roll number: " << current->noMhs << "\n";
            cout << "Name: " << current->name << "\n";
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu\n";
        cout << "1. Add a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Display in ascending order\n";
        cout << "4. Display in descending order\n";
        cout << "5. Search for a record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.deleteNode();
            break;
        case '3':
            list.displayAscending();
            break;
        case '4':
            list.displayDescending();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            break;
        default:
            cout << "\nInvalid option\n";
        }
    } while (choice != '6');

    return 0;
}
