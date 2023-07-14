#include <iostream>
#define MAX 100


using namespace std;

int arr[MAX];
int current_index = 0;

void insertEnd(int elem) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl;
        return;
    } else {
        arr[current_index] = elem;
        current_index++;
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
            return;
        }
    }
}

void displayElements() {
    if (current_index == 0) {
        cout<<"Array empty!"<<endl;
        return;
    } else {
        for (int i=0; i<current_index; i++) {
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

void emptyArray() {
    if (current_index == 0) {
        cout<<"Array already empty!"<<endl;
        return;
    } else {
        current_index = 0;
    }
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
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
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 0: return;
            default: cout<<"Invalid choice!"<<endl;
        }
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout<<"Array Operations"<<endl;
        cout<<"1. Enter elements"<<endl;
        cout<<"2. Display elements"<<endl;
        cout<<"3. Search Menu"<<endl;
        cout<<"4. Delete Menu"<<endl;
        cout<<"5. Insert Menu"<<endl;
        cout<<"6. Update Menu"<<endl;
        cout<<"7. Empty array"<<endl;
        cout<<"0. Quit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: insertElements(); break;
        case 2: displayElements(); break;
        case 3: searchMenu(); break;
        case 4: deleteMenu(); break;
        case 5: insertMenu(); break;
        case 6: updateMenu(); break;
        case 7: emptyArray(); break;
        case 0: exit(0); break;
        default: cout<<"Invalid choice!"<<endl;
        }
    }
}



int main() {
    mainMenu();
    return 0;
}