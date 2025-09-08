#include <iostream>
#include <cstring>
using namespace std;

class MovieTicket {
public:
    char* name;
    int seatno;

    // Default constructor
    MovieTicket() {
        name = new char[15];
        strcpy(name, "unknown");
        seatno = 0;
    }

  
    MovieTicket(const char* t, int sno) {
        name = new char[strlen(t) + 1];
        strcpy(name, t);
        seatno = sno;
    }

 
    MovieTicket(const MovieTicket& m) {
        name = new char[strlen(m.name) + 1];
        strcpy(name, m.name);
        seatno = m.seatno;
    }

    MovieTicket& operator=(const MovieTicket& m) {
        if (this != &m) {
            delete[] name; 
            name = new char[strlen(m.name) + 1];
            strcpy(name, m.name);
            seatno = m.seatno;
        }
        return *this;
    }

    ~MovieTicket() {
        delete[] name;
    }

    void print() const {
        cout << "Movie: " << name << ", Seat: " << seatno << endl;
    }
};

int main() {
    MovieTicket t1;              
    MovieTicket t2(t1);          
    MovieTicket t3("Avengers", 25); 

    t1 = t3;                    

    t1.print(); 
    t2.print();
    t3.print(); 

    return 0;
}



