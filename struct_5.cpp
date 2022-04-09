#include <iostream>
#include <string>
using namespace std;


struct Node{
    char value = 0;
    Node* next = nullptr;
};


bool is_number(char symbol){
    char numbers[] = "1234567890";
    for (int i = 0; i < 10; i++){
        if (symbol == numbers[i])
            return true;
    }
    return false;
}


Node* deleting(Node* first){
    if (first == nullptr)
        return nullptr;
    Node* new_first = nullptr;
    while (first->next != nullptr){
        if (! is_number(first->value)){
            new_first = first;
            break;
        }
        first = first->next;
    }
    if (new_first == nullptr)
        return nullptr;
    Node* last_node_not_int = new_first;

    while (first->next != nullptr){
        if (! is_number(first->value)){
            Node*buff = first->next;
            last_node_not_int->next = first;
            last_node_not_int = first;
            first = buff;
            continue;
        }
        first = first->next;
    }
    return new_first;
}

int main() {
    Node* first = nullptr;
    string a = "abc10zxc";
    for (int i = 0; i < a.size(); i++)
        first = new Node{a[i], first};

    first = deleting(first);
    Node* buff = first;
    while (buff != nullptr){  // cba01cba
        cout << buff->value;
        buff = buff->next;
    }
    return 0;
}
