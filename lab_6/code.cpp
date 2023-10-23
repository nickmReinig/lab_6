#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*the maximum size of any matrix is 100*100*/
const int max_size = 100;

/*this function is handed the empy matrix a and b, 
then collects user input for the file and modifies the two matrices
it also modifies a value n to represent the size*/
void readFile(int a[max_size][max_size], int b[max_size][max_size], int& n){
    /*file name is collected from user input*/
    string fileName;
    cout << "Enter a filename \n";
    cin >> fileName;

    /*value of n is created to know the size of the arrays
    the file is opened and two arrays of size n*n are created*/
    ifstream myfile;
    myfile.open (fileName);
    myfile >> n;

    /*for matrix a and b, the values are added using for loops*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            myfile >> a[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            myfile >> b[i][j];
        }
    }
}

/*This function takes one both matrices and prints their values*/
void printMatrix(const int matrixa[max_size][max_size], const int matrixb[max_size][max_size], int n){
    cout << "Matrix A \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrixa[i][j] << "\t";
        }
        cout << endl;
    }
        cout << "Matrix B \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrixb[i][j] << "\t";
        }
        cout << endl;
    }
    
}



/*All these functions will take the same parameters as the print function
this one will add both matrices and store it in a third matrix*/
void addMatrices(const int matrixa[max_size][max_size], const int matrixb[max_size][max_size], int n){
    cout << "A + B = \n";
    /*we will create a new matrix of max size,
    then iterate through the size of every array at once to
    create the new values*/
    int add[max_size][max_size];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int toAdd = matrixa[i][j] + matrixb[i][j];
            add[i][j] = toAdd;
        }
    }
    /*Now it is printed*/
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << add[i][j] << "\t";
        }
        cout << endl;
    }
}

/*This function will print a multiplication of the matrices*/
void multiplyMatrices(const int matrixa[max_size][max_size], const int matrixb[max_size][max_size], int n){
    cout << "A * B = \n";
    /*the new matrix will be created
    then it will be iterated through*/
    int multiply[max_size][max_size];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
           /*for every location in this matrix, we want the rowa*colb
           "essentially", to perform the correct matrix multuplication
           we can make a for loop that uses the i and j values
           and iterates through each column and row,
           adding values to a number in multiply's location*/
           int toAdd = 0;
           for (int x = 0; x < n; x++){
                toAdd = toAdd + (matrixa[i][x] * matrixb[x][j]);
           }
           multiply[i][j] = toAdd;
           
        }
    }

    /*now the new matrix is printed*/
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << multiply[i][j] << "\t";
                }
                cout << endl;
            }
    
}

/*subtractMatrices is an exact copy of add, with a few values flipped*/
void subtractMatrices(const int matrixa[max_size][max_size], const int matrixb[max_size][max_size], int n){
    cout << "A - B = \n";
    /*we will create a new matrix of max size,
    then iterate through the size of every array at once to
    create the new values*/
    int subtract[max_size][max_size];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int toAdd = matrixa[i][j] - matrixb[i][j];
            subtract[i][j] = toAdd;
        }
    }
    /*Now it is printed*/
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << subtract[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    /*main simply makes calls and prints in order to follow the output guide*/
    cout << "Nick Reinig \n" << "Lab #6: Matrix Manipulation \n";
    int n;
    int a[max_size][max_size];
    int b[max_size][max_size];
    readFile(a, b, n);
    printMatrix(a, b, n);
    addMatrices(a, b, n);
    multiplyMatrices(a, b, n);
    subtractMatrices(a, b, n);

    

    return 0;
}