#include <iostream>

using namespace std;

struct node {
    int data;
    node *next = NULL;
};

node *first = NULL;
node *last = NULL;

void insertEnd(int data) {
    node *p = new node;
    p->data = data;

    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

void insertElements() {
    int elem;
    char choice;
    while (true) {
        cout<<"Enter elements"<<endl;
        cin>>elem;
        insertEnd(elem);
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>choice;
        if (choice == 'n') {
            cout<<endl;
            return;
        }
    }
}

void displayLinkedList() {
    if (first == NULL) {
        cout<<"Linked List is empty!"<<endl;
    } else {
        node *temp = first;
        while (temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}

void searchMenu() {
    int choice;
    while (true) {
        cout<<"Search Menu"<<endl;
        cout<<"1. Search specific element"<<endl;
        cout<<"2. Search before specific element"<<endl;
        cout<<"3. Search after specific element"<<endl;
        cout<<"4. Search multiple occurrences of element"<<endl;
        cout<<"5. Search element at specific index"<<endl;
        cout<<"0. Back to main menu"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:{
                int elem;
                cout<<"Enter element to be searched"<<endl;
                cin>>elem;
                //searchSpecific(elem);
                break;
            } 
            case 2: {
                int elem;
                cout<<"Enter element to search before"<<endl;
                cin>>elem;
                //searchBefore(elem);
                break;
            } 
            case 3: {
                int elem;
                cout<<"Enter element to search after"<<endl;
                cin>>elem;
                //searchAfter(elem);
                break;
            }
            case 4:{
                int elem;
                cout<<"Enter element to be searched"<<endl;
                cin>>elem;
                //searchMultiple(elem);
                break;
            } 
            case 5:{
                int index;
                cout<<"Enter index at which to search"<<endl;
                cin>>index;
                //searchSpecificIndex(index);
                break;
            } 
            case 0: return;
            default: cout<<"Invalid choice!"<<endl;
        }
    }
}

void deleteMenu() {
    int choice;
    while (true) {
        cout<<"Delete Menu"<<endl;
        cout<<"1. Delete specific element"<<endl;
        cout<<"2. Delete at start"<<endl;
        cout<<"3. Delete at end"<<endl;
        cout<<"4. Delete before specific element"<<endl;
        cout<<"5. Delete after specific element"<<endl;
        cout<<"6. Delete multiple occurrences of element"<<endl;
        cout<<"7. Delete element at specific index"<<endl;
        cout<<"0. Back to main menu"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:{
                int elem;
                cout<<"Enter element to be deleted"<<endl;
                cin>>elem;
                //deleteSpecific(elem);
                break;
            } 
            case 2: break;//deleteStart(); break;
            case 3: break;//deleteEnd(); break;
            case 4:{
                int elem;
                cout<<"Enter element to be deleted before"<<endl;
                cin>>elem;
                //deleteBefore(elem);
                break;
            } 
            case 5:{
                int elem;
                cout<<"Enter element to be deleted after"<<endl;
                cin>>elem;
                //deleteAfter(elem);
                break;
            } 
            case 6:{
                int elem;
                cout<<"Enter element to be deleted"<<endl;
                cin>>elem;
                //deleteMultiple(elem);
                break;
            }
            case 7:{
                int index;
                cout<<"Enter index at which to delete"<<endl;
                cin>>index;
                //deleteSpecificIndex(index);
                break;
            } 
            case 0: return;
            default: cout<<"Invalid choice!"<<endl;
        }
    }
}

void insertMenu() {
    int choice;
    while (true) {
        cout<<"Insert Menu"<<endl;
        cout<<"1. Insert at start"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert before specific element"<<endl;
        cout<<"4. Insert after specific element"<<endl;
        cout<<"5. Insert multiple occurrences of element"<<endl;
        cout<<"6. Insert element at specific index"<<endl;
        cout<<"0. Back to main menu"<<endl;
        cin>>choice;
        switch (choice) {
            case 1: {
                int elem;
                cout<<"Enter element to be inserted"<<endl;
                cin>>elem;
                //insertStart(elem);
                break;
            } 
            case 2: {
                int elem;
                cout<<"Enter element to be inserted"<<endl;
                cin>>elem;
                insertEnd(elem);
                break;
            } 
            case 3: {
                int elem, _new;
                cout<<"Enter element to insert before"<<endl;
                cin>>elem;
                cout<<"Enter element to be inserted"<<endl;
                cin>>_new;
                //insertBefore(elem, _new);
                break;
            } 
            case 4: {
                int elem, _new;
                cout<<"Enter element to insert after"<<endl;
                cin>>elem;
                cout<<"Enter element to be inserted"<<endl;
                cin>>_new;
                //insertAfter(elem, _new);
                break;
            } 
            case 5: {
                int elem, count, index;
                cout<<"Enter element to be inserted"<<endl;
                cin>>elem;
                cout<<"Enter count of insertions"<<endl;
                cin>>count;
                cout<<"Enter index at which to insert"<<endl;
                cin>>index;
                //insertMultiple(elem, count, index);
                break;
            } 
            case 6: {
                int elem, index;
                cout<<"Enter element to be inserted"<<endl;
                cin>>elem;
                cout<<"Enter index at which to insert"<<endl;
                cin>>index;
                //insertSpecificIndex(elem, index);
                break;
            } 
            case 0: return;
            default: cout<<"Invalid choice!"<<endl;
        }
    }
}

void updateMenu() {
    int choice;
    while (true) {
        cout<<"Update Menu"<<endl;
        cout<<"1. Update at start"<<endl;
        cout<<"2. Update at end"<<endl;
        cout<<"3. Update before specific element"<<endl;
        cout<<"4. Update after specific element"<<endl;
        cout<<"5. Update multiple occurrences of element"<<endl;
        cout<<"6. Update element at specific index"<<endl;
        cout<<"0. Back to main menu"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:{
                int elem;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                //updateStart(elem);
                break;
            } 
            case 2:{
                int elem;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                //updateEnd(elem);
                break;
            } 
            case 3:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                //updateBefore(elem,_new);
                break;
            } 
            case 4:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                //updateAfter(elem,_new);
                break;
            }
            case 5:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                //updateMultiple(elem,_new);
                break;
            }
            case 6:{
                int index, elem;
                cout<<"Enter index at which to update"<<endl;
                cin>>index;
                cout<<"Enter new element"<<endl;
                cin>>elem;
                //updateSpecific(index,elem);
                break;
            } 
            case 0: return;
            default: cout<<"Invalid choice!"<<endl;
        }
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout<<"Linked List Operations"<<endl;
        cout<<"1. Enter elements"<<endl;
        cout<<"2. Display elements"<<endl;
        cout<<"3. Search Menu"<<endl;
        cout<<"4. Delete Menu"<<endl;
        cout<<"5. Insert Menu"<<endl;
        cout<<"6. Update Menu"<<endl;
        cout<<"7. Empty Linked List"<<endl;
        cout<<"0. Quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: insertElements(); break;
        case 2: displayLinkedList(); break;
        case 3: searchMenu(); break;
        case 4: deleteMenu(); break;
        case 5: insertMenu(); break;
        case 6: updateMenu(); break;
        case 7: break;//emptyArray(); break;
        case 0: exit(0); break;
        default: cout<<"Invalid choice!"<<endl;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}