// 210 | Final | Neil Orton
// IDE used: Xcode
#include <iostream>
#include <iomanip>
#include <deque>
#inlcude <vector>
#include <list>
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
    
    // Muffin Booth
    deque<string> muffinBooth;
    string muf_name;
//    string muf_order;
    
//    string muffins[7] = {"Blueberry", "Strawberry", "Coffee", "Poppyseed", "Water", "Chocolate", "Hazelnut"};
    
    for (int i = 0; i < 3; i++) {
        random_device randNum;
        uniform_int_distribution<int>range(0, 6);
        int num = range(randNum);
        
        muf_name = names[num];
//        muf_order = muffins[num];
        muffinBooth.push_back(muf_name);
    }
    cout << "---------\n";
    
    cout << "Muffin Booth Initial cue:\n";
    for (int i = 0; i < muffinBooth.size(); i++) {
        cout << muffinBooth[i] << endl;
    }
    cout << "---------\n";
    
    for (int i = 0; i < 10; ++i) {
        static int sim = 1;
        
        cout << "Time interval #" << sim << endl;
        int event = rand_num();
        cout << "[Updates]" << endl;
        if (muffinBooth.size() > 0) {
            cout << muffinBooth[0] << " helped\n";
            muffinBooth.pop_front();
        }
        
        
        if (event < 50) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 6);
            int num = range(randNum);
            
            muf_name = names[num];
    //        muf_order = muffins[num];
            muffinBooth.push_back(muf_name);
        }
        else
            cout << "No other updates\n";
        
        cout << "[Resulting Line]" << endl;
        if (muffinBooth.size() != 0) {
            for (int i = 0; i < muffinBooth.size(); i++) {
                cout << muffinBooth[i] << endl;
            }
        }
        else
            cout << "Booth empty\n";
        cout << "---------" << endl;
        sim++;
    }
    
    // Bracelet Booth
    vector<string> bracletBooth;
    string brac_name;
//    string brac_order;
    
//    string bracelets[7] = {"Blueberry", "Strawberry", "Coffee", "Poppyseed", "Water", "Chocolate", "Hazelnut"};
    
    for (int i = 0; i < 3; i++) {
        random_device randNum;
        uniform_int_distribution<int>range(0, 6);
        int num = range(randNum);
        
        brac_name = names[num];
//        muf_order = muffins[num];
        bracletBooth.push_back(brac_name);
    }
    cout << "---------\n";
    
    cout << "Bracelet Booth Initial cue:\n";
    for (int i = 0; i < bracletBooth.size(); i++) {
        cout << bracletBooth[i] << endl;
    }
    cout << "---------\n";
    
    for (int i = 0; i < 10; ++i) {
        static int sim = 1;
        
        cout << "Time interval #" << sim << endl;
        int event = rand_num();
        cout << "[Updates]" << endl;
        if (bracletBooth.size() > 0) {
            cout << muffinBooth[0] << " helped\n";
            bracletBooth.pop_back();
        }
        
        
        if (event < 50) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 6);
            int num = range(randNum);
            
            muf_name = names[num];
    //        muf_order = muffins[num];
            bracletBooth.push_back(muf_name);
        }
        else
            cout << "No other updates\n";
        
        cout << "[Resulting Line]" << endl;
        if (bracletBooth.size() != 0) {
            for (int i = 0; i < bracletBooth.size(); i++) {
                cout << bracletBooth[i] << endl;
            }
        }
        else
            cout << "Booth empty\n";
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
