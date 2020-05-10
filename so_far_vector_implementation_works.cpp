

// ADS HOMEWORK PROJECT 1??
//made by raul grosan g3 sg4

#include <iostream>
#include <cstdlib>
using namespace std; 

//FIRST I will implement the vector class similar to stl

class vectorClass { 
  
    // address of our vector 
    int* arr; 
  
    // total storage of the vector
    int capacity; 
  
    // total no. of elements in the vector
    int current; 
  
public: 
  	//constructor
    vectorClass();

    // funct to add an element at the end
    void push(int data);

    // funct to add element at any given index 
    void push(int data, int index);

    // funct to extract element at any index 
    int get(int index);

    // funct to delete last element 
    void pop();

    // funct to get size of the vector 
    int size();

    // funct to get capacity of the vector 
    int getcapacity();

    // funct to print all elements
    void print(); 
    //the infamous sort
    void sort();
};

vectorClass::vectorClass(){
        arr = new int[1]; 
        capacity = 1; // an initial capacity of 1 element
        current = 0;
        // allocating storage using dynamic allocation
    }

void vectorClass::push(int data){ 
  
        // if the number of elements is equal to the capacity, 
        // that means we don't have space 
        // to accommodate more elements. 
        // We need to double the capacity 
        if (current == capacity) { 
            int* temp = new int[2 * capacity];
            // copying old array elements to new array 
            for (int i = 0; i < capacity; i++) { 
                temp[i] = arr[i]; 
            }
            // deleting previous array 
            delete[] arr; 
            capacity *= 2; 
            arr = temp; 
        }
        // Inserting data 
        arr[current] = data; 
        current++; 
    } 

void vectorClass::push(int data, int index){ 
  
        // if index is equal to capacity then this 
        // function is same as push defined above 
        if (index == capacity) 
            push(data); 
        else
            arr[index] = data; 
    } 
  
int vectorClass::get(int index){ 
        // if index is within the range 
        if (index < current) 
            return arr[index]; 
    } 

void vectorClass::pop(){ 
        current--; 
    } 

int vectorClass::size(){ 
        return current; 
    }

int vectorClass::getcapacity(){ 
        return capacity; 
    } 
  
void vectorClass::print(){ 
        for (int i = 0; i < current; i++) { 
            cout << arr[i] << " "; 
        } 
        cout << endl; 
    }
    
void vectorClass::sort(){
    int aux;
    for (int i = 0; i < current-1; i++){
        for (int j = i+1; j < current; j++){
            if(arr[i] > arr[j]){
                aux = arr[i];
                arr[i] = arr[j];            //haha
                arr[j] = aux;
            }
        }
    }
}
//main
int main() 
{ 
    //testing for the vector class works so good so far
    vectorClass v; 
    v.push(10); 
    v.push(20); 
    v.push(30); 
    v.push(40); 
    v.push(50); 
    cout << "Vector elements : "; 
    v.print(); 
    v.sort();
    cout << "Vector elements after sorting them: ";
    v.print();
    return 0; 
} 