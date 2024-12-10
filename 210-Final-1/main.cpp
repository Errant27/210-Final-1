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
    struct Customer {
        string name;
        string order;
        Customer* next;
        Customer(string na, string ord, Customer* n = nullptr) {
            name = na;
            order = ord;
            next = n;
        }
    };
    
    Customer *head;
        
public:
CoffeeBooth() { head = nullptr; }
    
void insert(string nam, string ord) {
    Customer *newCustomer = new Customer(nam, ord);
    if(!head) {
         head = newCustomer;
        cout << setw(W) << newCustomer->name << " added to the line" << endl;
    }
    else {
        Customer *ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = newCustomer;
        newCustomer->next = nullptr;
        cout << setw(W) << newCustomer->name << " added to the line" << endl;
    }
}

void print_booth() {
    Customer* current = head;
    if (!current) {
        cout << "Line is empty." << endl;
        return;
    }
    while (current) {
        cout << current->name << " ordered a " << current->order << endl;
        current = current->next;
    }
}

void help_customer() {
    Customer* current = head;
    if(!head)
        cout << "No update\n";
    else {
        head = head->next;
        cout << current->name << " helped from the front of the line\n";
        delete current;
        current = nullptr;
    }
}

};

int main() {
    CoffeeBooth booth;
    string name;
    string order;
    
    string names[5] = {"Daniel", "Erica", "Lily", "Monique", "Nathan"};
    string drinks[5] = {"Coffee", "Latte", "Espresso", "Tea", "Drink"};
    
    for (int i = 0; i < 3; i++) {
        random_device randNum;
        uniform_int_distribution<int>range(0, 4);
        int num = range(randNum);
        
        name = names[num];
        order = drinks[num];
        booth.insert(name, order);
    }
    cout << "---------\n";
    
    cout << "Coffee Booth Initial cue:\n";
    booth.print_booth();
    cout << "---------\n";
    
    for (int i = 0; i < 10; ++i) {
        static int sim = 1;
        
        cout << "Time interval #" << sim << endl;
        int event = rand_num();
        booth.help_customer();
        
        cout << "---------" << endl;
        cout << "Updates:" << endl;
        
        if (event < 50) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 4);
            int num = range(randNum);
            
            name = names[num];
            order = drinks[num];
            booth.insert(name, order);
        }
        
        cout << "Resulting Line:" << endl;
        booth.print_booth();
        sim++;
    }
    
    
    return 0;
}

int rand_num() {
    random_device randNum;
    uniform_int_distribution<int>range(1, 100);
    int num = range(randNum);
    
    return num;
}
