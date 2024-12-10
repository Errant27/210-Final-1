// 210 | Final | Neil Orton
// IDE used: Xcode
#include <iostream>
#include <deque>
using namespace std;

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
void push_back(string nam, string ord) {
    CoffeeBooth *newCustomer = new CoffeeBooth(nam, ord);
    if(!head)
        head = newCustomer;
    else

}

};

int main() {
    
    string names[5] = {"Daniel", "Erica", "Lily", "Moique", "Nathan"};
    string drinks[3] = {"Coffee", "Latte", "Espresso"};
    
    
    
    return 0;
}
