#include <iostream>

using namespace std;

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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 0: return;
            default: cout<<"Invalid choice!"; break;
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 0: return;
            default: cout<<"Invalid choice!";
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 0: return;
            default: cout<<"Invalid choice!";
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 0: return;
            default: cout<<"Invalid choice!";
        }
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout<<"Array Operations"<<endl;
        cout<<"1. Enter elements"<<endl;
        cout<<"2. Search Menu"<<endl;
        cout<<"3. Delete Menu"<<endl;
        cout<<"4. Insert Menu"<<endl;
        cout<<"5. Update Menu"<<endl;
        cout<<"6. Empty array"<<endl;
        cout<<"0. Quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: break;
        case 2: searchMenu(); break;
        case 3: deleteMenu(); break;
        case 4: insertMenu(); break;
        case 5: updateMenu(); break;
        case 6: break;
        case 0: break;
        default: cout<<"Invalid choice!";
        }
    }
}



int main() {
    return 0;
}