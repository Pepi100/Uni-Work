#include <iostream>

using namespace std;



class IoBase {
private:
public:
    // metoda citire
    virtual istream& read(istream& is) { // nu este nevoie de obiectul citit, pt ca avem this
        return is; // vom vedea ca in interfete deseori nu avem functionalitati
    }
    // metoda scriere
    virtual ostream& write(ostream& os) const { // nu este nevoie de obiectul citit, pt ca avem this
        return os; // vom vedea ca in interfete deseori nu avem functionalitati
    }

    friend ostream &operator<<(ostream &os, const IoBase &base) {
        return base.write(os);
    }

    friend istream &operator>>(istream &is, IoBase &base) {
        return base.read(is);
    }



};


class Gift {
protected:
    string name, giverName;
public:
    Gift(const string &name, const string &giverName) : name(name), giverName(giverName) {}

    virtual void offerGift(string receivedBy) {
        cout << "The gift named " << name
             << " was received by " << receivedBy
             << " thanks to the courtesy of " << giverName << '\n';
    }
};

// !! Toti constructorii pot fi generate automat in CLion

class GiftCard : public Gift {
private:
    int sum;
public:
    GiftCard(const string &name, const string &giverName, int sum) : Gift(name, giverName), sum(sum) {}

    void offerGift(string receivedBy) override {
        cout << "A giftcard for " << name
             << " was received by " << receivedBy
             << " thanks to the courtesy of " << giverName
             << " for the intredible sum of "<< sum << '\n';
    }
};

class GiftHoliday : public Gift {
private:
    string location;
public:
    GiftHoliday(const string &name, const string &giverName, const string &location) : Gift(name, giverName),
                                                                                       location(location) {}

    void offerGift(string receivedBy) override {
        cout << "An amazing holiday in " << location
             << " for was received by " << receivedBy
             << " thanks to the courtesy of " << giverName
             << " with the message: "<< name << '\n';
    }
};

class GiftFavouriteProduct : public Gift {
private:
    string category;
public:
    GiftFavouriteProduct(const string &name, const string &giverName, const string &category) : Gift(name, giverName),
                                                                                                category(category) {}

    void offerGift(string receivedBy) override {
        cout << "A/An " << category
             << " for was received by " << receivedBy
             << " thanks to the courtesy of " << giverName
             << " with the message: "<< name << '\n';
    }
};


int main() {
    Gift simpleGift("No Name", "Eleanor Roosevelt");
    GiftCard card("Andrei Popescu", "Popescu Miruna", 300);
    GiftHoliday holiday("Ibiza platita!", "Leonard Coste", "Ibiza, Spain");
    GiftFavouriteProduct phone("Pentru tine", "Costache Leurdean", "Apple Product");

    simpleGift.offerGift("Ioan");
    card.offerGift("Persida");
    holiday.offerGift("Romeo");
    phone.offerGift("Caligula");
}



