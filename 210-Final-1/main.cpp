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
        cout << setw(W) << newCustomer->name << " ordered a " << newCustomer->order << endl;
    }
    else {
        Customer *ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = newCustomer;
        newCustomer->next = nullptr;
        cout << setw(W) << newCustomer->name << " ordered a " << newCustomer->order << endl;
    }
}

void print_booth() {
    Customer* current = head;
    if (!current) {
        cout << "Line is empty." << endl;
        return;
    }
    while (current) {
        cout << current->name << endl;
        current = current->next;
    }
}

void help_customer() {
    Customer* current = head;
    if(head) {
        head = head->next;
        cout << current->name << " helped\n";
        delete current;
        current = nullptr;
    }
}

};

int main() {
    CoffeeBooth booth;
    string name;
    string order;
    
    string names[7] = {"Daniel", "Erica", "Lily", "Monique", "Nathan", "Josh", "Tim"};
    string drinks[7] = {"Coffee", "Latte", "Espresso", "Tea", "Water", "Cappacino", "Americano"};
    
    for (int i = 0; i < 3; i++) {
        random_device randNum;
        uniform_int_distribution<int>range(0, 6);
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
        cout << "[Updates]" << endl;
        booth.help_customer();
        
        if (event < 50) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 6);
            int num = range(randNum);
            
            name = names[num];
            order = drinks[num];
            booth.insert(name, order);
        }
        else
            cout << "No other updates\n";
        
        cout << "[Resulting Line]" << endl;
        booth.print_booth();
        cout << "---------" << endl;
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
