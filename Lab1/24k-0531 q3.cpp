#include <iostream>
using namespace std;

class Inventory{
    public:
    int* prices;
    int size;

    Inventory(int s){
        size = s;
        prices = new int[size];
        for(int i=0 ; i<size; i++){
            prices[i] = 0;
        }

    }

    Inventory (const Inventory& other){
        size = other.size;
        prices = new int[size];
        for(int i=0;i<size; i++){
            prices[i] = other.prices[i];
        }
    }

    ~Inventory(){
        delete[] prices;
    }

    Inventory& operator=(const Inventory& other){
        if (this != &other) {
        delete[] prices;                  // free old memory
        size = other.size;
        prices = new int[size];           // allocate new memory
          for (int i = 0; i < size; i++) {
          prices[i] = other.prices[i];
          }
       }
       return *this;
    }


    void inputprices(){
        for(int i = 0; i<size; i++){
            cin>>prices[i];
        }
    }

    void updateprices(int index, int newp){
        if(index>=0 && index<size){
            prices[index]= newp;
        }else{
            cout<<"Invalid index"<<endl;
        }
    }

    void displayitemp(){
        for(int i = 0; i<size; i++){
            cout<<"item"<< i+1<<"="<<prices[i]<<endl;
        }
    }
};

int main(){
    Inventory obj1(4);
    obj1.inputprices();

    Inventory obj2 = obj1;

    obj2.updateprices(2,900);
    obj1.displayitemp();
    obj2.displayitemp();

    return 0;
}
