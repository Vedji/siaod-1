#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Node {
    int date; // общая сумма денег на вкладе
    int code; // номер счета в банке
    Node* prev = nullptr; // указатель на предыдущий элемент
    Node* next = nullptr; // указатель на следующий элемент
};

struct List {
    Node* Head = NULL;
    Node* Tail = NULL;
    int tired = 0;
    int size = 0;
    int sums = 0;
    vector<int> nodes;
    void Add(int n);
    void Show();
    Node* Given();
    void Insert();
    vector<int> Remove(vector<int> nodes);
    void Delete(vector<int> Remove);

};


void List::Add(int n) {
    for (int i = 0; i < n; i++) {
        cout << " - введите сумму за день : \n";
        cout << " - введите номер счета в банке : \n";
        int date, code;
        cin >> date >> code;
        Node* temp = new Node{ date, code };
        if (Head == NULL or Tail == NULL) {
            Head = Tail = temp;
        }
        else {
            temp->prev = Tail;
            Tail->next = temp;
            Tail = temp;
        }
        size++;
    }
}

void List::Insert() {
    int date, code;
    cout << "\nВведите данные по счету\n";
    cin >> date >> code;
    Node* insert = new Node{ date, code }; // новый узел
    if (size == 0) {
        Head = insert;
        Tail = insert;
    }
    else if (size == 1) {
        Head->next = insert;
        insert->prev = Head;
        Tail = insert;
    }
    else {
        Node* save = Head->next;
        Head->next = insert;
        insert->prev = Head;
        insert->next = save;
        save->prev = insert;
    }
}

vector<int> List::Remove(vector<int> nodes) {
    Node* ex = Head;
    int count = 0;
    vector<int> codes;
    vector<int> means;
    vector<int> finals;
    int finalsCount = 0;
    while (ex != nullptr) {
        codes.push_back(ex->code);
        means.push_back(ex->date);
        count++;
        ex = ex->next;
    }
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << endl << codes[i] << "~" << means[i] << endl;
    }
    for (int i = 0; i < count; i++) {
        int check = 0;
        for (int j = i; j < count; j++) {
            if (codes[i] == codes[j]) {
                check += means[j];
            }
        }
        if (check == 0) {
            cout << codes[i] << " " << endl;
            sums += 1;
            finalsCount += 1;
            finals.push_back(codes[i]);
        }
    }
    for (int i = 0; i < finalsCount; i++) {
        nodes.push_back(finals[i]);
    }
    return nodes;
}

void List::Delete(vector<int> Remove) {
    for (int i = 0; i < Remove.size(); i++) {
        Node* p = Head;
        Node* save;
        Node* last;
        while (p != nullptr) {
            if (p->code == Remove[i]) {
                if (p->prev == nullptr) {
                    tired++;
                    Head = p->next;
                    p = Head;
                    p->prev = nullptr;
                }
                else if (p->prev != nullptr && p->next != nullptr) {
                    tired++;
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    p = p->prev;
                }
                else if (p->next = nullptr) {
                    tired++;
                    Tail = p->prev;
                    p->prev->next = nullptr;
                    p = nullptr;
                }
                continue;
            }
            p = p->next;
        }
    }
    
}

void List::Show() {
    cout << "\n Элементы списка: \n";
    Node* current1 = this->Head;
    Node* current2 = this->Tail;
    while (current1 != nullptr) {
        cout << current1->date << " -> ";
        current1 = current1->next;
    }
    cout << endl;
    while (current2 != nullptr) {
        cout << " <- " << current2->date;
        current2 = current2->prev;
    }
}

Node* List::Given() {
    int meaning;
    cout << endl << "* enter your given meaning : ";
    cin >> meaning;
    Node* current = this->Head;
    while (current != nullptr) {
        if (meaning == current->date) {
            return current;
        }
        current = current->next;
    }
    return current;
}



int main()
{
    setlocale(0, "");
    int n;
    cout << " * enter number of elements -----: ";
    cin >> n;
    List m;
    Node* copy = nullptr;
    m.Add(n);
    m.Show();
    cout << "Your node has number : " << m.Given()->date;
    m.Insert();
    m.Show();
    vector<int> pArr;
    m.Delete(m.Remove(pArr));
    m.Show();


}

/*456
rrr
6
1
222

666
uuu
9
1
222

999
yyy
16
1
222

343
sss
20
1
222

*/