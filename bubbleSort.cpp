#include <iostream>
#include <vector>
#include <cstdlib> //for random number generation
#include <ctime>
using namespace std;

class ArrayBub{
    private:
        vector<double> v;           //our vector
        int nElems;                 // number of data items

        void swap(int one, int two){
            double temp = v[one];
            v[one] = v[two];
            v[two] = temp;
        }
    public:
        ArrayBub(int max) : nElems(0){
            //constructor
            v.resize(max);          //size the vector
        }
        void insert(double value){
            v[nElems] = value;      //add the value at the end of the vector
            nElems++;               //increment size
        }
        void display(){
            for(int j=0; j<nElems; j++){
                cout << v[j] << " ";
            }
            cout << endl;
        }
        void bubbleSort(){
            int out, in;
            for(out = nElems-1; out>1; out--){       //outer loop goes backwards
                for(in=0; in<out; in++){             //inner loop goes forwards
                    if(v[in] > v[in+1])              //if preceding is greater than its adajacent, swap them
                        swap(in, in+1);
                }
            }
        }
};

int main(){
    int maxSize = 100;      //array size
    ArrayBub arr(maxSize);  //create the array

    srand(time(0)); //initialize random number generator
    int value;
    for(int i=0; i<10; i++){
        value = (rand()%99) + 1; // create a random between 1 and 99
        arr.insert(value);
    }

    cout << "Before the sort: ";
    arr.display();
    arr.bubbleSort();
    cout << "\nAfter the sort: ";
    arr.display();

    return 0;
}