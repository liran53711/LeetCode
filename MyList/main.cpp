#include <iostream>


typedef struct node {
    int data;
    node* next;
}Node;

class MyList {
private:
    Node * head ;
    Node * current ;
    Node * last ;
    int size = 0 ;
public :
    Node * getHead() {
    return head ;
}
    MyList() {
    head  = new Node;
    head->next = nullptr;

    current = head ;
    last = head ;
}
    void AddNode(int data) {
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if ( size == 0 ) {
        head = last = current = newNode ;

    }else {
        last->next = newNode ;
        last = newNode;
        current = newNode;

    }
    size ++;
}

    void printList (Node * begin) {
    while (begin != nullptr  ) {
        std::cout << begin->data << " ";
        begin = begin->next;
    }
}

    void reverse () {
    Node * prev = head;
    current = head->next;
    prev->next = nullptr ;

    Node * next ;


    while (current != nullptr) {

            next = current->next ;
            current->next = prev ;
            prev = current ;
            current = next ;

    }
    head = prev ;

}



};
int main() {
    MyList list ;
    int num;
    std::cin >> num;
    int tem;
    for (int i = 0; i < num; i++) {
        std :: cin >> tem ;
        list.AddNode(tem);
    }
    list.reverse();
    list.printList(list.getHead());

}