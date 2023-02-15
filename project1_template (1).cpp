/* 
    File name: (file name here)
    Created by: (your name here)
    Created on: (date here)
    Synopsis: (synopsis here)
*/ 



#include <math.h>
#include <iostream>
#include <iomanip> 
using namespace std;

// Default size of our dynamic coefficient array
const int DEFAULTPOLY = 10;    

//Default spacing for our Punnett square
const int SQUARESPACE = 10;

// Do NOT modify the class header.
class Poly
{
private:
  
    // Data members
    int arraySize;    // size of array
    int *coeff;       // dynamic array

public:

    // Default Class constructor
    // Allocate an array of DEFAULTPOLY elements and initialize it to the constant 0
    // post: Class object is initialized to degree-0 polynomial of 0  
    Poly();

  
    // Non-default (alternate) Class constructor
    // Allocate an array of 'size' elements and initializes it to the constant 0
    // post: Class object is initialized to degree-0 polynomial of 0  
    Poly(int size);

  
    // Copy constructor
    // Construct a new Poly that is a copy of an existing Poly
    // post: Class object is initialized to be a copy of the argument Poly
    Poly(const Poly& aPoly);

  
    // Destructor
    // Destroy a poly object by freeing the dynamically allocated array
    ~Poly();

  
    // Assignment operator
    // Assign 'aPoly' Poly object to 'this' Poly object
    // Note: This function is provided, please do not modify it
    const Poly& operator=(const Poly& aPoly);

    
    // grow
    // This method will allow us to increase the size of the dynamically allocated
    // array by allocating a new array of the desired size, copying the data from
    // the old array to the new array, and then releasing the old array.
    // If the newSize is less than or equal to the current size, then no actions 
    // are taken.
    // Note: the maximum degree of a polynomial is one less than the size of the 
    // array. The parameter newSize represents the size of the array.
    void grow(int newSize);

    
    // degree
    // Finds the degree of a polynomial (the highest power with a non-zero
    // coefficient)
    // pre: Class object exists
    // post: Returns the degree of the polynomial object.
    int degree() const;

    
    // setCoeff
    // Sets a term, value*x^i, in a polynomial, growing the array if necessary.
    // pre: Class object has been initialized. i is a non-negative integer.
    // post: In the polynomial, the term with power i has coefficient
    //       value. The polynomical was grown if required.
    void setCoeff(int value, int i);

    
    // getCoeff
    // Finds the coefficient of the x^i term in poly
    // pre: Class object has been initialized. i is a non-negative integer.
    // post: Returns the value of the coefficient of the term with power i
    // note: If the object does not contain a term with power i (e.g., 
    //       i>=arraySize), a coefficient value of zero is returned.
    int getCoeff(int i) const;


    // negate
    // Negate a polynomial
    // pre: The class object has been initialized.
    // post: The polynomial has been changed to represent its
    //       multiplication by -1.
    void negate();

    // punnettSquare
    // Calculates the punnett square of two polynomials
    // pre: Both polynomial objects have been initialized
    // post: Calculates the punnett square of the two polynomials and then
    //		 Invokes outputPunnet(..) function to display result into the screen
    void punnettSquare(const Poly& aPoly);

    // punnettSquare output
    // Displays the punnett square of two polynomials into the screen
    // pre: punnetSquare function generates a punnet Array then calls this function to display it.
    //		Must provide the second polinomial as well as the punnet Array
    // post: Displays the punnett square of the two polynomials into the screen
	void ouputPunnet(const Poly& aPoly, int** punnetArray);
	
    // addition operator
    // Add two polynomials together and return a new polynomial that is the result
    // pre: Both class objects have been initialized
    // post: The sum of two polynomials is stored in a new polynomial which is returned.
    //       The parameter polynomials are not changed.
    friend Poly operator+(const Poly& aPoly, const Poly& bPoly);

    
    // subtraction operator
    // Subtracts one polynomial from another and return a new polynomial that is the result
    // pre: Both class objects have been initialized
    // post: The difference of two polynomials is stored in a new polynomial which is returned.
    //       The parameter polynomials are not changed.
    friend Poly operator-(const Poly& aPoly, const Poly& bPoly);

    // multiplication operator
    // Multiplies one polynomial with another and returns a new polynomial that is the result
    // pre: Both class objects have been initialized
    // post: The product of the two polynomials is stored in a new polynomial which is returned
    //       The parameter polynomials are not changed.
    friend Poly operator*(const Poly& aPoly, const Poly& bPoly);

    
    // equality operator
    // Compare two polynomials and return true if they are the same, false otherwise
    // pre: Both class objects have been initialized
    // post: A boolean value indicating whether two polynomials are the same is returned.
    //       The parameter polynomials are not changed.
    friend bool operator==(const Poly& aPoly, const Poly& bPoly);
    

    // insertion operator for output
    // Print polynomials
    // pre: The class object has been initialized
    // post: several values representing the polynomial are inserted into the output stream
    friend ostream& operator<<(ostream& out, const Poly &aPoly);

};



int main(){
    
    Poly poly1, poly2;
    int numCoeff, coeffValue, coeffDegree, x;

    // prompt user for the number of coefficients
    cout << "How many coefficients for polynomial 1?" << endl;
    cin >> numCoeff;
    for (int i=0; i<numCoeff; ++i){
        cout << "Coefficient " << i+1 << " for polynomial 1:";
        cin >> coeffValue >> coeffDegree;
        poly1.setCoeff(coeffValue, coeffDegree);
    }

    cout << endl << "How many coefficients for polynomial 2?" << endl;
    cin >> numCoeff;
    for (int i=0; i<numCoeff; ++i){
        cout << "Coefficient " << i+1 << " for polynomial 2:";
        cin >> coeffValue >> coeffDegree;
        poly2.setCoeff(coeffValue, coeffDegree);
    }

    // Sample test cases for degree() and operator<<
    cout << endl << "Polynomial 1 = " << poly1 << endl;
    cout << "Polynomial 1 has degree " << poly1.degree() << endl;
    cout << "Polynomial 2 = " << poly2 << endl;
    cout << "Polynomial 2 has degree " << poly2.degree() << endl;

    // Sample test cases for operator+, operator- and operator*
    cout << endl << "Polynomial 1 + Polynomial 2 = " << poly1 + poly2 << endl;
    cout << "Polynomial 1 - Polynomial 2 = " << poly1 - poly2 << endl << endl;
    cout << "Punnett square of Polynomial 1 and Polynomial 2: " << endl;
    poly1.punnettSquare(poly2);		//the function uses outputPunnet(..) to display result
    cout << "Polynomial 1 * Polynomial 2 = " << poly1 * poly2 << endl << endl;

    // Sample test cases for operator==
    if (poly1==poly2)
        cout << "Two polynomials are the same." << endl;
    else
        cout << "Two polynomials are different." << endl;

    // Try more test cases to test your class thoroughly


    
    return 0;
}

// Do not modify this function
const Poly& Poly::operator= (const Poly& aPoly){

    if (this == &aPoly)
        return *this;

    if (coeff)
        delete [] coeff;
    
    arraySize = aPoly.arraySize;
    coeff = new int[arraySize];
    for (int i=0; i<arraySize; ++i){
        coeff[i] = aPoly.getCoeff(i);
    }

    return *this;
}



// Do not modify this function
void Poly::ouputPunnet(const Poly& aPoly, int** punnettArray){
	int squareSpace = SQUARESPACE;
    
    //Output first row
	for (int power = this->degree(); power >= 0; power--) {
        Poly aTerm(power);
        aTerm.setCoeff(this->getCoeff(power), power);
        cout << setw(squareSpace) << right << aTerm;

    }

    //Move to next row
    cout << endl;

    //Now output rest of the punnett square

    for (int power = aPoly.degree(); power >= 0; power--) {
        //First output first element of the column
        Poly aTerm(power);
        aTerm.setCoeff(aPoly.getCoeff(power), power);
        cout << right << setw(squareSpace) << aTerm;

        //Next output punnett square element
        for (int thisPower = this->degree(); thisPower >= 0; thisPower--) {
            int squarePower = thisPower + power;
            Poly squareTerm(squarePower);

            squareTerm.setCoeff(punnettArray[thisPower][power], squarePower);
            
            cout << right << setw(squareSpace) << squareTerm;

        }

        //Move to next row
        cout << endl;
    }
}

Poly::Poly(){
    arraySize = DEFAULTPOLY;
    coeff = new int[arraySize]();
}
Poly::Poly(int size){
     arraySize = size;
    coeff = new int[arraySize]();
}
Poly::Poly(const Poly& aPoly){
    int *newPoly = new int[arraySize]();
    for(int i=0; i<arraySize;i++){
        newPoly[i] = aPoly.getCoeff(i);
    }
}
Poly::~Poly(){
    delete [] coeff;
}
void Poly::grow(int newSize){
    if(newSize>arraySize){
        int *temp = new int[newSize]();
    for (int i=0; i<arraySize; ++i){
        temp[i] = coeff[i];
    }
    arraySize = newSize;
    delete [] coeff;
    coeff = temp; 
    }
}
int Poly:: degree() const{
    int high = 0; 
    for(int i =0; i<arraySize;i++){
        if(coeff[i]>0 && i>high){
            high = i; 
        }
    }
    return high; 
}
void Poly::setCoeff(int value,int i){
    coeff[i] = value; 
}
int Poly::getCoeff(int i) const{
    if(i>=arraySize){
        return 0;
    }
    else{
        return coeff[i];
    }
}
void Poly::negate(){
    for(int i=0;i<arraySize;i++){
        coeff[i] = -1*coeff[i];
    }
}
//Class function definitions
