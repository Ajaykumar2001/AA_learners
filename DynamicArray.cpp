#include<iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

// Define a class named DynamicArray
class DynamicArray {
    private:
    int size; // Variable to store the size of the array
    int* arr; // Pointer to dynamically allocated array
    int index; // Variable to keep track of the current index

    public:
    // Parameterized constructor
    DynamicArray(int sizeArg): size{sizeArg}, index{0} {
        this->arr = new int[size]; // Allocate memory for the array
    }

    // Method to add an integer value to the array
    void add(int intergerValue) {
        if(this->index < this->size) {
            this->arr[this->index] = intergerValue; // Add value to the array
            this->index++; 
        } else {
            // If the array is full, create a new array with increased size
            size += 1;
            int *newArr = new int[size]; 
            for(int i = 0; i < size - 1; i++) {
                newArr[i] = arr[i]; // Copy elements to the new array
            }
            newArr[index - 1] = intergerValue; // Add the new value to the new array
            this->index++; 
            delete[] arr; 
            arr = newArr; // Point to the new array
        }
    }

    // Destructor to free the dynamically allocated memory
    ~DynamicArray() {
        cout << "Destructor called" << endl;
        delete[] arr;
    }

    // Overload the subscript operator to access array elements
    int operator[](int indexArg) {
        return this->arr[indexArg]; // Return the element at the given index
    }
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& operand2);
};
std::ostream& operator<<(std::ostream& os, const DynamicArray& printobj){
    for(int i = 0; i < printobj.size; i++) {
        os << printobj.arr[i] << " "; // Print each element
    }
    return os;
}
// Main function
int main() {
    DynamicArray numbers(2); // Create a DynamicArray object with size 2
    numbers.add(10); // Add 10 to the array
    numbers.add(20); 
    numbers.add(30); 
    numbers.add(40); 
    numbers.add(10); 
    numbers.add(20); 
    numbers.add(30); 
    numbers.add(40); 

    // Access the element at index 1
    int value = numbers[1];
    cout<<"value : "<<value<<endl;
    cout<<numbers<<endl;

    return 0;
}
