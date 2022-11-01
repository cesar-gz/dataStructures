#include <iostream>
#include <vector>
#include <cstdlib> //for random number generation
#include <ctime>
using namespace std;

class ArrayIns{
    private:
        vector<double> v;
        int nElems;
    
    public:
        ArrayIns(int max): nElems(0){
            v.resize(max);
        }

        void insert(double value){
            v[nElems] = value;
            nElems++;
        }

        void display(){
            for(int j=0; j<nElems; j++){
                cout << v[j] << " ";
            }
            cout << endl;
        }

        void insertionSort(){
            int in, out;
            for(out = 1; out<nElems; out++){        //out is the dividing line
                double temp = v[out];               //remove marked item
                in = out;                           //start shifts at out
                while(in>0 && v[in-1] >= temp){     //until one is smaller,
                    v[in] = v[in-1];                //shift item to right
                    --in;                           //go left one position
                }
                v[in] = temp;                       //insert marked item
            }
        }
};

int main(){
    int maxSize = 100;
    ArrayIns arr(maxSize);

    srand(time(0)); //initialize random number generator
    int value;
    for(int i=0; i<10; i++){
        value = (rand()%99) + 1; // create a random between 1 and 99
        arr.insert(value);
    }

    cout << "Before the sort: ";
    arr.display();
    arr.insertionSort();
    cout << "\nAfter the sort: ";
    arr.display();

    return 0;

}