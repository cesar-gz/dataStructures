#include <iostream>
#include <vector>
#include <cstdlib> //for random number generation
#include <ctime>
using namespace std;

class HighArray{
    private:
        vector<double> v;       //create a vector v of double type
        int nElems;             //number of data items
    
    public:
        HighArray() : nElems(0){}   //our default constructor

        HighArray(int max) : nElems(0){     // one argument constructor
            v.resize(max);          // resize the basic vector to size max for now
        }

        bool find(double searchKey){    // find the specified value
            int j;
            for(j=0; j<nElems; j++){
                if(v[j] == searchKey)
                    break; // if the item is found
            }
            if(j == nElems)
                return false; // we looped through the array and didnt find it
            else
                return true; // we did find it
        }

        void insert(double value){  //add element from array
            v[nElems] = value; // add the value at the end
            nElems++;   //increase size
        }

        bool remove(double value){  //remove element from array
            int j;
            for(j=0; j<nElems; j++){
                if(value == v[j])   //find the first element that is the value we are looking for
                    break;
            }
            if(j == nElems)
                return false;   // we couldn't find it in the array
            else{
                //we did find it
                for(int k=j; k<nElems; k++){
                    v[k] = v[k+1]; //the current value of k is now = to its next value
                }
                nElems--; //decrement size
                return true;
            }
        }

        void display(){
            //displays array contents
            for(int j=0; j<nElems; j++){
                cout << v[j] << " ";
            }
            cout << endl;
        }
};

int main(){
    int maxSize = 100;
    HighArray arr(maxSize); //create an array with a size of 100
    
    srand(time(0)); //initialize random number generator

    double value;
    for(int i=0; i<10; i++){
        value = (rand()%10) + 1; // create a random between 1 and 10
        arr.insert(value);
    }
    arr.display();

    value = (rand()%10) + 1;
    int searchKey = value; // look for a random number that was generated
    if(arr.find(searchKey))
        cout << "Found " << searchKey << endl;
    else
        cout << "Can't Find " << searchKey << endl;

    for(int i=0; i<3; i++){
        value = (rand()%10) + 1;
        cout << "Attempting to delete a random value of " << value << " if its in the array" << endl;
        arr.remove(value);
    }
    arr.display();
    return 0;

}