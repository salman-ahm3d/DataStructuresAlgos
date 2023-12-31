#include <iostream>
#define MAX 100


using namespace std;


int arr[MAX];
int current_index = -1;




void updateStart(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        arr[0] = elem;
        cout<<"Updated!"<<endl;
    }
}

void updateEnd(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        arr[current_index] = elem;
        cout<<"Updated!"<<endl;
    }
}

void updateSpecific(int index, int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        if (index<=current_index && index>=0) {
            arr[index] = elem;
            cout<<"Updated!"<<endl;
        } else {
            cout<<"Invalid index"<<endl;
        }
    }
}


int searchElem(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
        return -1;
    }
    int returned_index = -1;
    for (int i = 0; i<=current_index; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return returned_index;
}

void updateBefore(int elem, int _new) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            if ((res-1) == 0) {
                updateStart(_new);
            } else if (res-1<0) {
                cout<<"Cannot update before start"<<endl;
                return;
            } else {
                arr[res-1] = _new;
                cout<<"Updated!"<<endl;
            }
        }
    }
}

void updateAfter(int elem, int _new) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            if ((res+1) == current_index) {
                updateEnd(_new);
            } else if (res+1>current_index) {
                cout<<"Cannot update after end"<<endl;
                return;
            } else {
                arr[res+1] = _new;
                cout<<"Updated!"<<endl;
            }
        }
    }
}

void updateMultiple(int elem, int _new) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            while (res!=current_index+1) {
                if (arr[res] == elem) {
                    arr[res] = _new;
                }
                res++;
            }
            cout<<"Updated!"<<endl;
        }
    }
} 

void searchBefore(int elem) {
    int result = searchElem(elem);
    if (result == -1) {
        cout<<"Not found!"<<endl;
    } else {
        if (result == 0) {
            cout<<"Cannot search before start"<<endl;
        } else {
            cout<<"Found "<<arr[result-1]<<" at index "<<result-1<<endl;
        }
    }
}

void searchAfter(int elem) {
    int result = searchElem(elem);
    if (result == -1) {
        cout<<"Not found"<<endl;
    } else {
        if (result == current_index) {
            cout<<"Cannot search after end"<<endl;
        } else {
            cout<<"Found "<<arr[result+1]<<" at index "<<result+1<<endl;
            cout<<"CURRENT_INDEX="<<current_index<<endl;
        }
    }
}

void searchMultiple(int elem) {
 if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            while (res!=current_index+1) {
                if (arr[res] == elem) {
                    cout<<"Found "<<elem<<" at index "<<res<<endl;
                }
                res++;
            }
        }
    }   
}

void searchSpecific(int elem) {
    int result = searchElem(elem);
    if (result == -1) {
        cout<<"Not found!";
    } else {
        cout<<"Found at index "<<result;
    }
    cout<<endl;
}

void searchSpecificIndex(int index) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        if (index<=current_index && index>=0) {
            cout<<"Found "<<arr[index]<<" at index "<<index<<endl;
        } else {
            cout<<"Invalid index"<<endl;
        }
    }
}


void insertStart(int elem) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl;
        return;
    } else {
        current_index++;
        for (int i = current_index; i>0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = elem;
        cout<<"Inserted!"<<endl;
    }
}

void insertEnd(int elem) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl;
        return;
    } else {
        current_index++;
        arr[current_index] = elem;
        cout<<"Inserted!"<<endl;
    }
}

void insertSpecificIndex(int elem, int index) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl; /*1 2 2 3 4 5*/
        return;
    } else {
        if (index >= current_index || index < 0) {
            cout<<"Invalid index!"<<endl;
        } else if (index == 0) {
            insertStart(elem);
        } else if (index == current_index) {
            insertEnd(elem);
        } else {
            current_index++;
            for (int i=current_index; i>index; i--) {
                arr[i] = arr[i-1];
            }
            arr[index] = elem;
            cout<<"Inserted!"<<endl;
        }
    }
}

void insertBefore(int elem, int _new) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl;
        return;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
        } else {
            insertSpecificIndex(_new, res);
        }
    }
}

void insertAfter(int elem, int _new) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl;
        return;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
        } else {
            insertSpecificIndex(_new, (res+1));
        }
    }
}

void insertMultiple(int elem, int count, int index) {
    if (current_index == MAX-1) {
        cout<<"Array full!"<<endl;
        return;
    } else {
        for (int i = 0; i<count; i++) {
            insertSpecificIndex(elem, index);
        }
    }
}

void deleteEnd() {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        current_index--;
        cout<<"Deleted!"<<endl;
    }
}

void deleteStart() {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl; /*1 2 3 4; 2 3 4 0*/
    } else {
        for (int i = 0; i<=current_index; i++) {
            arr[i] = arr[i+1];
        }
        current_index--;
        cout<<"Deleted!"<<endl;
    }
}

void deleteSpecificIndex(int index) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        if (index < 0 || index > current_index) {
            cout<<"Invalid index!"<<endl;
        } else if (index == 0) {
            deleteStart();
        } else if (index == current_index) {
            deleteEnd();
        } else {
            for (int i=index; i<=current_index; i++) {
                arr[i] = arr[i+1];
            }
            current_index--;
            cout<<"Deleted!"<<endl;
        }
    }
}

void deleteSpecific(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            if (res == 0) {
            deleteStart();
        } else if (res == current_index) {
            deleteEnd();
        } else {
            for (int i=res; i<=current_index; i++) {
                arr[i] = arr[i+1];
            }
            current_index--;
            cout<<"Deleted!"<<endl;
        }
        }
    }
}

void deleteBefore(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            if (res-1 < 0) {
                cout<<"Cannot delete before start!"<<endl;
            } else if (res-1 == 0) {
                deleteStart();
            } else {
                for (int i=res-1; i<=current_index; i++) {
                    arr[i] = arr[i+1];
                }
            current_index--;
            cout<<"Deleted!"<<endl;
            }
        }
    }
}

void deleteAfter(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            if (res+1 > current_index) {
                cout<<"Cannot delete after end!"<<endl;
            } else if (res+1 == current_index) {
                deleteEnd();
            } else {
                for (int i=res+1; i<=current_index; i++) {
                    arr[i] = arr[i+1];
                }
            current_index--;
            cout<<"Deleted!"<<endl;
            }
        }
    }
}

void deleteMultiple(int elem) {
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
    } else {
        int res = searchElem(elem);
        if (res == -1) {
            cout<<"Element not found!"<<endl;
            return;
        } else {
            while (res!=-1) {
                deleteSpecificIndex(res);
                res = searchElem(elem);
            }
        }
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
    if (current_index == -1) {
        cout<<"Array empty!"<<endl;
        return;
    } else {
        for (int i=0; i<=current_index; i++) {
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

void emptyArray() {
    if (current_index == -1) {
        cout<<"Array already empty!"<<endl;
        return;
    } else {
        current_index = -1;
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
            case 1:{
                int elem;
                cout<<"Enter element to be searched"<<endl;
                cin>>elem;
                searchSpecific(elem);
                break;
            } 
            case 2: {
                int elem;
                cout<<"Enter element to search before"<<endl;
                cin>>elem;
                searchBefore(elem);
                break;
            } 
            case 3: {
                int elem;
                cout<<"Enter element to search after"<<endl;
                cin>>elem;
                searchAfter(elem);
                break;
            }
            case 4:{
                int elem;
                cout<<"Enter element to be searched"<<endl;
                cin>>elem;
                searchMultiple(elem);
                break;
            } 
            case 5:{
                int index;
                cout<<"Enter index at which to search"<<endl;
                cin>>index;
                searchSpecificIndex(index);
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
                deleteSpecific(elem);
                break;
            } 
            case 2: deleteStart(); break;
            case 3: deleteEnd(); break;
            case 4:{
                int elem;
                cout<<"Enter element to be deleted before"<<endl;
                cin>>elem;
                deleteBefore(elem);
                break;
            } 
            case 5:{
                int elem;
                cout<<"Enter element to be deleted after"<<endl;
                cin>>elem;
                deleteAfter(elem);
                break;
            } 
            case 6:{
                int elem;
                cout<<"Enter element to be deleted"<<endl;
                cin>>elem;
                deleteMultiple(elem);
                break;
            }
            case 7:{
                int index;
                cout<<"Enter index at which to delete"<<endl;
                cin>>index;
                deleteSpecificIndex(index);
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
                insertStart(elem);
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
                insertBefore(elem, _new);
                break;
            } 
            case 4: {
                int elem, _new;
                cout<<"Enter element to insert after"<<endl;
                cin>>elem;
                cout<<"Enter element to be inserted"<<endl;
                cin>>_new;
                insertAfter(elem, _new);
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
                insertMultiple(elem, count, index);
                break;
            } 
            case 6: {
                int elem, index;
                cout<<"Enter element to be inserted"<<endl;
                cin>>elem;
                cout<<"Enter index at which to insert"<<endl;
                cin>>index;
                insertSpecificIndex(elem, index);
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
                updateStart(elem);
                break;
            } 
            case 2:{
                int elem;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                updateEnd(elem);
                break;
            } 
            case 3:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateBefore(elem,_new);
                break;
            } 
            case 4:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateAfter(elem,_new);
                break;
            }
            case 5:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateMultiple(elem,_new);
                break;
            }
            case 6:{
                int index, elem;
                cout<<"Enter index at which to update"<<endl;
                cin>>index;
                cout<<"Enter new element"<<endl;
                cin>>elem;
                updateSpecific(index,elem);
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