// 210 | Final | Neil Orton
// IDE used: Xcode
#include <iostream>
#include <iomanip>
#include <deque>
#include <random>
using namespace std;
const int W = 3;
int rand_num();

struct CoffeeBooth {
private:
    string name;
    string order;
    CoffeeBooth(string na, string ord, CoffeeBooth* n = nullptr) {
        name = na;
        order = ord;
    }
    
    CoffeeBooth *head;
    CoffeeBooth *next;

public:
CoffeeBooth() { head = nullptr; }
    
void push_back(string nam, string ord) {
    CoffeeBooth *newCustomer = new CoffeeBooth(nam, ord);
    
    if(!head)
        head = newCustomer;
    else {
        head->next = newCustomer;
//        cout << setw(W) << newCustomer->name << " added to the line" << endl;
    }
}

void print_booth() {
    CoffeeBooth* current = head;
    if (!current) {
        cout << "Line is empty." << endl;
        return;
    }
    while (current) {
        cout << current->name << "ordered a " << current->order << endl;
        current = current->next;
    }
    cout << endl;
}

};

int main() {
    CoffeeBooth booth;
    string name;
    string order;
    
    string names[5] = {"Daniel", "Erica", "Lily", "Monique", "Nathan"};
    string drinks[3] = {"Coffee", "Latte", "Espresso"};
    
    for (int i = 0; i < 4; ++i) {
        int num = rand_num();
        
        name = names[num];
        order = drinks[num];
        cout << name << " " << order << endl;
        
        booth.push_back(name, order);
    }
    
//    cout << "Coffee Booth Initial cue:\n";
//    cout << "---------\n";
//    booth.print_booth();
    
    
    return 0;
}

int rand_num() {    // Function to generate random number
    random_device randNum;
    uniform_int_distribution<int>range(0, 4);
    int num = range(randNum);
    
    return num;
}
