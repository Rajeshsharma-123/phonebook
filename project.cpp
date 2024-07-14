#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class PhoneBook {
private:
    string Name, PhNo, Address;
public:
    PhoneBook() : Name(""), PhNo(""), Address("") {}

    void setName(const string& name) {
        Name = name;
    }

    void setPhNo(const string& phNo) {
        PhNo = phNo;
    }

    void setAddress(const string& address) {
        Address = address;
    }

    string getName() const {
        return Name;
    }

    string getPhNo() const {
        return PhNo;
    }

    string getAddress() const {
        return Address;
    }
};

void addNo(PhoneBook& ph) {
    string name, phNo, address;

    cout << "\tEnter Name Of User: ";
    cin.ignore();
    getline(cin, name);
    ph.setName(name);

    cout << "\tEnter Phone Number: ";
    getline(cin, phNo);
    ph.setPhNo(phNo);

    cout << "\tEnter Address Of User: ";
    getline(cin, address);
    ph.setAddress(address);

    ofstream outfile("D:/PhoneBook.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        outfile << ph.getName() << " : " << ph.getPhNo() << " : " << ph.getAddress() << endl;
    }
    outfile.close();
    cout << "\tPhone Number Added Succesfully!" << endl;
    cout.flush(); // Ensure output is flushed
}

void searchNo() {
    string name;
    cout << "\tEnter Name Of User: ";
    cin.ignore();
    getline(cin, name);

    ifstream infile("D:/PhoneBook.txt");
    if (!infile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        string line;
        bool found = false;
        while (getline(infile, line)) {
            istringstream ss(line);
            string userName, userPhNo, userAddress;

            getline(ss, userName, ':');
            getline(ss, userPhNo, ':');
            getline(ss, userAddress, ':');

           // Trim whitespaces from parsed strings
            userName.erase(0, userName.find_first_not_of(" \t"));
            userName.erase(userName.find_last_not_of(" \t") + 1);
            userPhNo.erase(0, userPhNo.find_first_not_of(" \t"));
            userPhNo.erase(userPhNo.find_last_not_of(" \t") + 1);
            userAddress.erase(0, userAddress.find_first_not_of(" \t"));
            userAddress.erase(userAddress.find_last_not_of(" \t") + 1);

            if (name == userName) {
                found = true;
                cout << "\t" << userName << " : " << userPhNo << " : " << userAddress << endl;
            }
        }
        if (!found) {
            cout << "\tUser Not Found In Phone Book!" << endl;
        }
    }
    infile.close();
    cout.flush(); // Ensure output is flushed
}

int main() {
    PhoneBook ph;

    bool exit = false;
    while (!exit) {
        int val;
        cout << "\tWelcome To Phone Book Management System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t1. Add Number." << endl;
        cout << "\t2. Search Number." << endl;
        cout << "\t3. Exit." << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        if (val == 1) {
            addNo(ph);
        } else if (val == 2) {
            searchNo();
        } else if (val == 3) {
            exit = true;
            cout << "\tGood Luck!" << endl;
            cout.flush(); // Ensure output is flushed
        } else {
            cout << "\tInvalid Choice! Please try again." << endl;
            cout.flush(); // Ensure output is flushed
        }
    }
    return 0;
}
