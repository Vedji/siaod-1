#include <iostream>
#include <typeinfo>

using namespace std;

//определение структуры узла
struct Node
{
    char value;
    Node *next = nullptr;
};

Node* fillNode(char simbol, Node* ukaz) {
    return new Node{ simbol, ukaz };
}

bool Equality(Node* ukazOne, Node* ukazTwo) {
    bool flag = true;
    while (ukazOne != nullptr and ukazTwo != nullptr) {
        if (ukazOne->value != ukazTwo->value) {
            flag = false;
        }
        ukazOne = ukazOne->next;
        ukazTwo = ukazTwo->next;
    }
    return flag and ukazOne == ukazTwo; 
}

Node* Insert(Node* ukazOne, Node* ukazTwo) {
    cout << "enter " << endl;
    ukazOne = fillNode(ukazTwo->value, ukazTwo);
    return ukazOne;
}

Node* Deleting(Node* ukazTwo) {
    int type = 0;
    Node* node = ukazTwo->next;
    if (typeid(ukazTwo->value).name() == typeid(type).name()) {
        delete node;
    }
    return ukazTwo;
}

void Show(Node* ukazOne, Node* ukazTwo) {
    while (ukazOne->next != nullptr and ukazTwo->next != nullptr) {
        cout << ukazOne->value << ukazTwo->value << endl;
        ukazOne = ukazOne->next;
        ukazTwo = ukazTwo->next;
    }
}

int main()
{
    setlocale(0, "");
    int amount;
    //создание указателей для узлов
    Node* ptr1 = nullptr;
    Node* ptr2 = nullptr;
    cout << "Enter sizes: " << endl;
    cin >> amount;
    for (int i = 0; i < amount; i++) {
        char b;
        cin >> b;
        ptr1 = fillNode(b , ptr1);
        cin >> b;
        ptr2 = fillNode(b, ptr2);
    }
    Node* copy_ptr1 = ptr1;
    Node* copy_ptr2 = ptr2;
    Equality(copy_ptr1, copy_ptr2);
    Deleting(copy_ptr2);
    Insert(copy_ptr1, copy_ptr2);
    Show(copy_ptr1, copy_ptr2);
}
