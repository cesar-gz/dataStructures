//practice using array class with a low-level interface

#include <iostream>
#include <vector>
using namespace std;

class LowArray{
    private:
        vector<double> v;  // vector holds double values
    public:
        LowArray(int max){
            // constructor, resize the vector
            v.resize((max));
        }

        void setElem(int index, double value){
            v[index] = value;   //put the element into array at the given index
        }

        double getElem(int index){
            return v[index];    //get element from array at index, at first instance
        }
};

int main(){
    LowArray arr(100);  // create a array of size 100
    int nElems = 0;     // number of items
    int j;              // loop variable

    arr.setElem(0,77);  // insert 10 items
    arr.setElem(1,99);
    arr.setElem(2,55);
    arr.setElem(3,44);
    arr.setElem(4,11);
    arr.setElem(5,00);
    arr.setElem(6,33);
    arr.setElem(7,66);
    arr.setElem(8,88);
    arr.setElem(9,22);
    nElems = 10;

    for(j=0; j<nElems; j++){    //display items
        cout << arr.getElem(j) << " ";
    }
    cout << endl;

    int searchKey = 26;     // search from this item
    for(j=0; j<nElems; j++){
        if(arr.getElem(j) == searchKey){
            cout << "Found it! \n" << endl;
            break;
        }
    }
    if(j == nElems){
        cout << "Can't find " << searchKey << endl;
    }

    double deleteKey = 99;    // lets delete 88
    cout << "Deleting element " << deleteKey << endl;
    for(j = 0; j<nElems; j++){
        if(arr.getElem(j) == deleteKey){
            // found it
            break;
        }
    }
    for(int k = j; k<nElems; k++){
        arr.setElem(k, arr.getElem(k+1));   //make current value = to the next value
    }
    nElems--; //decrement size

    for(j=0; j<nElems; j++){
        //display items
        cout << arr.getElem(j) << " ";
    }
    cout << endl;
    return 0;
}