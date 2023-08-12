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

void insertStart(int data) {
    node *p = new node;
    p->data = data;
    if (first == NULL) {
        first = last = p;
    } else {
        p->next = first;
        first = p;
    }
}

void updateStart(int data) {
    if (first==NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        first->data = data;
    }
}

void updateEnd(int data) {
    if (first==NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        last->data = data;
    }
}

void deleteFirst() {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *temp = first;
        first = first->next;
        delete temp;
        cout<<"Deleted!"<<endl;
    }
}

void deleteLast() {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
       if (first == last) {
        delete first;
        first = NULL;
       } else {
        node *q = first;
        node *q1 = NULL;
        while (q!=last) {
            q1 = q;
            q = q->next;
        }
        delete q;
        last = q1;
        last->next = NULL;
        cout<<"Deleted!"<<endl;
       }
    }
}

void deleteAll() {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        while (first!=NULL) {
            deleteFirst();
        }
    }
}

node* searchNode(int data) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
        return NULL;
    } else {
        node *temp = first;
        while (temp!=NULL) {
            if (temp->data == data) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
}

void searchSpecific(int data) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *res = searchNode(data);
        if (res==NULL) {
            cout<<"Element not found!"<<endl;
        } else {
            cout<<"Found "<<res->data<<endl;
        }
    }
}

void searchAfter(int data) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *res = searchNode(data);
        if (res->next==NULL) {
            cout<<"Element not found!"<<endl;
        } else {
            cout<<"Found "<<res->next->data<<endl;
        }
    }
}

void searchBefore(int data) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *q1 = NULL;
        node *q = first;
        while (q->data!=data) {
            q1 = q;
            q = q->next;
        }
        if (q == first) {
            cout<<"Cannot search before first!"<<endl;
        } else {
            cout<<"Found "<<q1->data<<endl;
        }
    }
}

void searchMultiple(int data) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        int count = 0;
        node *q = first;
        while (q!=NULL) {
            if (q->data == data) {
                cout<<"Found "<<q->data<<endl;
                count++;
            }
            q = q->next;
        }
        cout<<"Total occurences: "<<count<<endl;
    }
} 

void updateAfter(int old, int _new) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *res = searchNode(old);
        if (res->next==NULL) {
            cout<<"Element not found!"<<endl;
        } else {
            res->next->data = _new;
            cout<<"Updated!"<<endl;
        }
    }
}

void updateBefore(int old, int _new) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *q1 = NULL;
        node *q = first;
        while (q->data!=old) {
            q1 = q;
            q = q->next;
        }
        if (q == first) {
            cout<<"Cannot update before first!"<<endl;
        } else {
            q1->data = _new;
            cout<<"Updated!"<<endl;
        }
    }
}

void updateMultiple(int old, int _new) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        int count = 0;
        node *q = first;
        while (q!=NULL) {
            if (q->data == old) {
                q->data = _new;
                count++;
            }
            q = q->next;
        }
        cout<<"Total occurences updated: "<<count<<endl;
    }
}

void updateSpecific(int old, int _new) {
    if (first == NULL) {
        cout<<"Linked list empty!"<<endl;
    } else {
        node *target = searchNode(old);
        if (target!=NULL) {
            target->data = _new;
            cout<<"Updated!"<<endl;
        } else {
            cout<<"Element not found!"<<endl;
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
            cout<<endl;
            return;
        }
    }
}

void deleteSpecific(int data) {
    if (first == NULL) {
        cout<<"Linked List is empty!"<<endl;
    } else {
        if (first->data == data) {
            deleteFirst();
        } else if (last->data == data) {
            deleteLast();
        } else {
            node *q1 = NULL;
            node *q = first;
            while (q!=NULL) {
                if (q->data == data) {
                    break;
                }
                q1 = q;
                q = q->next;
            }

            if (q == NULL) {
                cout<<"Element not found!"<<endl;
                return;
            } else {
                q1->next = q->next;
                delete q;
            }
        }
    }
}

void deleteAfter(int data) {
    if (first == NULL) {
        cout<<"Linked List is empty!"<<endl;
    } else {
        node *res = searchNode(data);
        if (res == NULL) {
            cout<<"Element not found!"<<endl;
        } else {
            if (res == last) {
                cout<<"Cannot delete after last!"<<endl;
            } else if (res->next == last) {
                deleteLast();
            } else {
                node *temp = res->next;
                res->next = res->next->next;
                delete temp;
                cout<<"Deleted!"<<endl;
            }
        }
    }
}

void deleteBefore(int data) {
    if (first == NULL) {
        cout<<"Linked List is empty!"<<endl;
    } else {
        node *q = first;
        node *q1 = NULL;
        node *q2 = NULL;
        while (q!=NULL) {
            if (q->data == data) {
                break;
            }
            q2 = q1;
            q1 = q;
            q = q->next;
        }
        
        if (q == NULL) {
            cout<<"Element not found!"<<endl;
        } else {
            if (q == first) {
                cout<<"Cannot delete before first!"<<endl;
            } else if (q1 == first) {
                deleteFirst();
            } else {
                node *temp = q1;
                q2->next = q;
                delete temp;
                cout<<"Deleted!"<<endl;
            }
        }
    }
}

void deleteMultiple(int data) {
    if (first == NULL) {
        cout<<"Linked List is empty!"<<endl;
    } else {
        node *res;
        do {
            deleteSpecific(data);
            res = searchNode(data);
        } while (res!=NULL);
        cout<<"Deleted all instances!"<<endl;
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

void insertAfter(int old, int _new) {
    if (first == NULL) {
        cout<<"Linked list is empty!"<<endl;
    } else {
        node *res = searchNode(old);
        if (res == NULL) {
            cout<<"Element not found!"<<endl;
        } else if (res == last) {
            insertEnd(_new);
            cout<<"Inserted!"<<endl;
        } else {
            node *p = new node;
            p->data = _new;
            p->next = res->next;
            res->next = p;
            cout<<"Inserted!"<<endl;
        }
    }
}

void insertBefore(int old, int _new) {
    if (first == NULL) {
        cout<<"Linked list is empty!"<<endl;
    } else {
        node *q1 = NULL;
        node *q = first;
        while (q!=NULL) {
            if (q->data == old) {
                break;
            }
            q1 = q;
            q = q->next;
        }
        if (q == NULL) {
            cout<<"Element not found!"<<endl;
        } else if (q == first) {
            insertStart(_new);
            cout<<"Inserted!"<<endl;
        } else {
            node *p = new node;
            p->data = _new;
            p->next = q;
            q1->next = p;
            cout<<"Inserted!"<<endl;
        }
    }
}

void insertMultiple(int old, int _new, int count) {
    if (first == NULL) {
        cout<<"Linked list is empty!"<<endl;
    } else {
        node *res = searchNode(old);
        if (res == NULL) {
            cout<<"Element not found!"<<endl;
        } else if (res == last) {
            for (int i = 0; i<count; i++) {
                insertEnd(_new);
            }
            cout<<"Inserted "<<count<<" times!"<<endl;
        } else {
            node *p;
            for (int i = 0; i<count; i++) {
                p = new node;
                p->data = _new;
                p->next = res->next;
                res->next = p;
            }
            cout<<"Inserted "<<count<<" times!"<<endl;
        }
    }
}

void cleanExit() {
    deleteAll();
    exit(0);
}

void searchMenu() {
    int choice;
    while (true) {
        cout<<"Search Menu"<<endl;
        cout<<"1. Search specific element"<<endl;
        cout<<"2. Search before specific element"<<endl;
        cout<<"3. Search after specific element"<<endl;
        cout<<"4. Search multiple occurrences of element"<<endl;
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
            case 2: deleteFirst(); break;
            case 3: deleteLast(); break;
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
                int elem, count, target;
                cout<<"Enter element to be inserted"<<endl;
                cin>>elem;
                cout<<"Enter count of insertions"<<endl;
                cin>>count;
                cout<<"Enter element after which to insert"<<endl;
                cin>>target;
                insertMultiple(target, elem, count);
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
        cout<<"3. Update specific element"<<endl;
        cout<<"4. Update before specific element"<<endl;
        cout<<"5. Update after specific element"<<endl;
        cout<<"6. Update multiple occurrences of element"<<endl;
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
            case 3: {
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateSpecific(elem, _new);
                break;
            }
            case 4:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateBefore(elem,_new);
                break;
            } 
            case 5:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateAfter(elem,_new);
                break;
            }
            case 6:{
                int elem, _new;
                cout<<"Enter element to update"<<endl;
                cin>>elem;
                cout<<"Enter replacement"<<endl;
                cin>>_new;
                updateMultiple(elem,_new);
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
        case 7: deleteAll(); break;
        case 0: cleanExit(); break;
        default: cout<<"Invalid choice!"<<endl;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}