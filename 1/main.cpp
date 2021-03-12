#include <iostream>
#include "complex.cpp"

using namespace std;

// sorting complex vector
vector<Complex> ComplexVectorSort(std::vector<Complex> arr){
    for(int i = 0; i < arr.size()-1; ++i){
        for(int j = 0; j < arr.size()-1; ++j){
            if(arr[j].absaluteValue() > arr[j+1].absaluteValue()){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    return arr;
}

// start pont for app
int main()
{
    // // declare result
    // Complex result;

    // // init complex numbers
    //  Complex c1 = Complex(9,5);
    //  Complex c2 = Complex(5,9);

    // // text - operator
    // result = c1 - c2;
    // result.output();

   cout << "Init complex vector \n";
    // create complex vector and init
    vector<Complex> complexVecor(5);
    for(int i = 0;i < complexVecor.size(); ++i){
        int a ,b;
        cin >> a;
        cin >> b;
        complexVecor[i] = Complex(a,b);
        complexVecor[i].output();
    }

    //sort vector
    vector<Complex> sortedVec = ComplexVectorSort(complexVecor);

    cout << "print complex sorted vector \n";
    // print sorted vector
     for(int j = 0;j < sortedVec.size(); ++j){
        sortedVec[j].output();
    }

    return 0;
}