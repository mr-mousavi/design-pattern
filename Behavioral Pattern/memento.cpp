#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Memento
{
    int balance;

public:
    explicit Memento(int balance)
    : balance(balance) {}

    friend class BankAccount;
};

class BankAccount
{
    int balance{0};
    vector<shared_ptr<Memento>> changes;
    int current;
public:
    explicit BankAccount(const int& balance) : balance(balance)
    {
        changes.emplace_back(make_shared<Memento>(balance));
        current=0;
    }

    shared_ptr<Memento> deposit(const int& amount)
    {
        balance += amount;
        auto m = make_shared<Memento>(balance);
        changes.push_back(m);
        ++current;
        return m;
    }

    void restor(const shared_ptr<Memento>& m) {
        if (m) {
            balance = m->balance;
            changes.push_back(m);
            current = changes.size() - 1;
        }
    }

    shared_ptr<Memento> undo() {
        if(current>0) {
            --current;
            auto m = changes.at(current);
            balance = m->balance;
            return m;
        }
        return {};
    }

    shared_ptr<Memento> redo() {
        if(current + 1 < changes.size())
        {
            ++current;
            auto m = changes.at(current);
            balance = m->balance;
            return m;
        }
        return {};
    }

    friend ostream &operator<<(ostream &os, const BankAccount &obj) {
        os << "balance: " << obj.balance;
        return os;
    }

};

int main() {

    BankAccount ba{100};
    ba.deposit(50);
    ba.deposit(25);

    cout<<ba <<endl;
    ba.undo();
    cout<<"undo1:" <<ba <<endl;
    ba.undo();
    cout<<"undo2:" <<ba <<endl;
    ba.redo();
    cout<<"redo:" <<ba <<endl;

    ba.deposit(200);
    ba.redo();
    cout<<"redo:" <<ba <<endl;
    return 0;
}
