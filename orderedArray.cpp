#include <iostream>
#include <vector>
#include <cstdlib> //for random number generation
#include <ctime>
using namespace std;

class OrdArray{
    private:
        vector<double> v;  
        int nElems;                          //number of data items
    public:
        OrdArray(int max) : nElems(0){       //constructor
            v.resize(max);                   //size of vector
        }

        int getSize(){
            return nElems;                  //return the number of elements
        }

        int find(double searchKey){
            int lowerBound = 0;
            int upperBound = nElems-1;
            int curIn;                          //current index

            while(true){
                curIn = (lowerBound + upperBound)/2;
                if(v[curIn] == searchKey)
                    return curIn;               //we found it
                else if(lowerBound > upperBound)
                    return nElems;              //can't find it
                else{
                    //divide range
                    if(v[curIn] < searchKey)
                        lowerBound = curIn + 1; //it's in upper half
                    else
                        upperBound = curIn - 1; //its in the lower half
                }
            }
        }

        void insert(double value){
            int j;
            for(j=0; j<nElems; j++){            //find where it goes
                if(v[j] > value)                //linear search
                    break;
            }
            for(int k = nElems; k>j; k--){
                v[k] = v[k-1];                  //move bigger values up
            }
            v[j] = value;                       //insert the value in the vector
            nElems++;                           //increment the size
        }

        bool remove(double value){
            int j = find(value);
            if(j == nElems)
                return false;                   //can't find the value
            else{
                for(int k=j; k<nElems; k++){    // move bigger values down
                    v[k] = v[k+1];
                }
                nElems--;                       // decrement the size
                return true;
            }    
        }

        void display(){
            cout << "The ordered array is: ";
            for(int j=0; j<nElems; j++){        // for each element
                cout << v[j] << " ";            // display it
            }
        }
};

int main(){
    int maxSize = 100;      //array size
    OrdArray arr(maxSize);  //create the array

    srand(time(0)); //initialize random number generator
    int value;
    for(int i=0; i<10; i++){
        value = (rand()%10) + 1; // create a random between 1 and 99
        arr.insert(value);
    }

    value = (rand()%10) + 1;
    int searchKey = value; // look for a random number that was generated
    value = (rand()%10) + 1;
    int searchKey2 = value; 
    value = (rand()%10) + 1;
    int searchKey3 = value; 

    if(arr.find(searchKey) != arr.getSize())
        cout << "Found " << searchKey << endl;
    else{
        cout << "Can't find " << searchKey << endl;
    }

    if(arr.find(searchKey2) != arr.getSize())
        cout << "Found " << searchKey2 << endl;
    else{
        cout << "Can't find " << searchKey2 << endl;
    }

    if(arr.find(searchKey3) != arr.getSize())
        cout << "Found " << searchKey3 << endl;
    else{
        cout << "Can't find " << searchKey3 << endl;
    }

    arr.display();

    cout << "\nDeleting " << searchKey << ", " << searchKey2 << ", and " << searchKey3 << " one time each if they are in ordered array." << endl;
    arr.remove(searchKey);
    arr.remove(searchKey2);
    arr.remove(searchKey3);

    arr.display();
    return 0;
}