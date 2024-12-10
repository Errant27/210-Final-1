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
        cout << setw(W) << newCustomer->name << " added to the line" << endl;
    }
}

void print_booth() {
        
}

};

int main() {
    
    CoffeeBooth booth;
    string name;
    string order;
    
    string names[5] = {"Daniel", "Erica", "Lily", "Moique", "Nathan"};
    string drinks[3] = {"Coffee", "Latte", "Espresso"};
    
    cout << "Coffee Booth Initial cue:\n";
    for (int i = 0; i < 3; ++i) {
        int num = rand_num();
        name = names[num];
        order = drinks[num];
        
        booth.push_back(name, order);
    }
    
    
    return 0;
}

int rand_num() {    // Function to generate random number
    random_device randNum;
    uniform_int_distribution<int>range(0, 4);
    int num = range(randNum);
    
    return num;
}
