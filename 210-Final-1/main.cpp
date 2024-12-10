// 210 | Final | Neil Orton
// IDE used: Xcode
#include <iostream>
#include <iomanip>
#include <deque>
#include <vector>
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


int main() {
    struct Customer {
        string name;
        string order;
    };
    
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
    
    cout << endl;
// Muffin Booth
    deque<Customer> muffinBooth;
    string muffins[7] = {"Blueberry", "Strawberry", "Coffee", "Poppyseed", "Water", "Chocolate", "Hazelnut"};
    
    for (int i = 0; i < 3; i++) {
        random_device randNum;
        uniform_int_distribution<int>range(0, 6);
        int num = range(randNum);
        Customer newMufCust;
        
        newMufCust.name = names[num];
        newMufCust.order = muffins[num];
        muffinBooth.push_back(newMufCust);
    }
    cout << "---------\n";
    
    cout << "Muffin Booth Initial cue:\n";
    for (int i = 0; i < muffinBooth.size(); i++) {
        cout << muffinBooth[i].name << "ordered a " << muffinBooth[i].order << endl;
    }
    cout << "---------\n";
    
    for (int i = 0; i < 10; ++i) {
        static int sim = 1;
        
        cout << "Time interval #" << sim << endl;
        int event = rand_num();
        cout << "[Updates]" << endl;
        if (muffinBooth.size() > 0) {
            cout << muffinBooth[0].name << " helped\n";
            muffinBooth.pop_front();
        }
        
        if (event <= 50) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 6);
            int num = range(randNum);
            Customer newMufCust;
            
            newMufCust.name = names[num];
            newMufCust.order = muffins[num];
            muffinBooth.push_back(newMufCust);
        }
        else
            cout << "No other updates\n";
        
        cout << "[Resulting Line]" << endl;
        if (muffinBooth.size() != 0) {
            for (int i = 0; i < muffinBooth.size(); i++) {
                cout << muffinBooth[i].name << "ordered a " << muffinBooth[i].order << endl;
            }
        }
        else
            cout << "Booth empty\n";
        cout << "---------" << endl;
        sim++;
    }
 
    cout << endl;
// Bracelet Booth
    vector<Customer> bracletBooth;
    string bracColors[7] = {"Blue", "Red", "Violet", "Teal", "Green", "White", "Pink"};
    
    for (int i = 0; i < 3; i++) {
        random_device randNum;
        uniform_int_distribution<int>range(0, 6);
        int num = range(randNum);
        Customer newBracCust;
        
        newBracCust.name = names[num];
        newBracCust.order = bracColors[num];
        bracletBooth.push_back(newBracCust);
    }
    cout << "---------\n";
    
    cout << "Bracelet Booth Initial cue:\n";
    for (int i = 0; i < bracletBooth.size(); i++) {
        cout << bracletBooth[i].name << " ordered a " << bracletBooth[i].order << endl;
    }
    cout << "---------\n";
    
    for (int i = 0; i < 10; ++i) {
        static int sim = 1;
        
        cout << "Time interval #" << sim << endl;
        int event = rand_num();
        cout << "[Updates]" << endl;
        if (bracletBooth.size() > 0) {
                auto it = bracletBooth.begin();
                cout << it->name << " helped\n";
                bracletBooth.erase(it);
            }
        
        
        if (event <= 50) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 6);
            int num = range(randNum);
            Customer newBracCust;
            
            newBracCust.name = names[num];
            newBracCust.order = bracColors[num];
            bracletBooth.push_back(newBracCust);
        }
        else
            cout << "No other updates\n";
        
        cout << "[Resulting Line]" << endl;
        if (bracletBooth.size() != 0) {
            for (int i = 0; i < bracletBooth.size(); i++) {
                cout << bracletBooth[i].name << ": " << bracletBooth[i].order << endl;
            }
        }
        else
            cout << "Booth empty\n";
        cout << "---------" << endl;
        sim++;
    }
    

    cout << endl;
// Soda Booth
        list<Customer> sodaBooth;
        string sodas[7] = {"Coke", "Pepsi", "Sprite", "Root Beer", "Water", "Club Soda", "Red Drink"};

        
        for (int i = 0; i < 3; i++) {
            random_device randNum;
            uniform_int_distribution<int>range(0, 6);
            int num = range(randNum);
            Customer newSodCust;
            
            newSodCust.name = names[num];
            newSodCust.order = sodas[num];
            sodaBooth.push_back(newSodCust);
        }
        cout << "---------\n";
        
        cout << "Soda Booth Initial cue:\n";
        auto it = sodaBooth.begin();
        for (int i = 0; i < sodaBooth.size(); i++) {
            cout << it->name << " ordered a " << it->order << endl;
            it++;
        }
        cout << "---------\n";
        
        for (int i = 0; i < 10; ++i) {
            static int sim = 1;
            
            cout << "Time interval #" << sim << endl;
            int event = rand_num();
            cout << "[Updates]" << endl;
            if (sodaBooth.size() > 0) {
                auto it = sodaBooth.begin();
                cout << it->name << " helped\n";
                sodaBooth.erase(it);
            }
            
            
            if (event <= 50) {
                random_device randNum;
                uniform_int_distribution<int>range(0, 6);
                int num = range(randNum);
                Customer newSodCust;
                
                newSodCust.name = names[num];
                newSodCust.order = sodas[num];
                sodaBooth.push_back(newSodCust);
            }
            else
                cout << "No other updates\n";
            
            cout << "[Resulting Line]" << endl;
            if (sodaBooth.size() != 0) {
                auto it = sodaBooth.begin();
                for (int i = 0; i < sodaBooth.size(); i++) {
                    cout << it->name << ": " << it->order << endl;
                    it++;
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
