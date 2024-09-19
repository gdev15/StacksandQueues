/**
 * Description: Reads elements from a file and pushes the values to a stack object and queue object. Displays the contents of both the queue and stack.
 * Author: Gabriel
 * Date: 9/17/2024
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Value to initialize the size of the array
const int MAX_SIZE = 4;

// Stack class
class Stack {
private:
	int array[MAX_SIZE];
	// Used to point to the index
	int index;
public:
	// Creates an empty stack and starts the Top index at -1
	Stack() {
		index = -1;
	}

	// Check if the stack is Empty
	// Returns true or false
	bool isEmpty() {
		// If the top does = -1 then this will return true
		return index == -1;
	}

	// Check if the stack is Full
	bool isFull() {
		// If the top is 4, in this case, then the array has used up all the space and returns true
		return index == MAX_SIZE - 1;
	}

	// Insert values into the array
	void push(int x) {
		// First, check if the stack is full otherwise there is no more space
		// If the stack is full leave the method
		if (isFull()) {
			// cout << "Stack is full. " << endl;
			return;
		}

		// Add the value to the array
		// Increment the index pointer top
		index++;
		// Initialize the value in the index the top is pointing to
		array[index] = x;
		// cout << "Stack Inserted: " << x << endl;
	}

	int pop() {
		if (isEmpty()) {
			// cout << "The Stack is empty. " << endl;
			// Returns a value of -1 since the method an int
			return -1;
		}

		//Store the current value
		int x = array[index];
		// Decrement the top pointer
		index--;
		return 0;
	}

	// Returns the current value
	int top() {
		if (isEmpty()) {
			// cout << "Error: stack is empty." << endl;
			return -1;
		}
		int current = array[index];
		return current;
	}

	//Iterate through all the values and display everything stored in the stack.
	void displayStack() {
		if (isEmpty()) {
			return;
		}

		cout << "Stack Array: " << endl;
		for (int i = 0; i <= index; i++) {
			cout << array[i] << endl;
		}
		cout << "Top Value: " << array[index] << endl;
		cout << endl;
	}


};

// Queue Class
class Queue {
private:
	int array[MAX_SIZE];
	int head;
	int tail;

public:
	// Constructor that creates an empty queue and sets both pointers to the -1 index of the array
	Queue() {
		head = tail = -1;
	}

	// Check if the queue is empty and return true or false
	bool isEmpty() {
		return head == -1;
	}

	//Check if the queue is full and return true or false
	bool isFull() {
		return head == MAX_SIZE - 1;
	}

	// Insert values
	void push(int x) {
		if (isFull()) {
			// cout << "Error: Queue is full. " << endl;
			// Get out of the method
			return;
		}

		// If the list is empty 
		// Set the tail to index 0
		// This ensures we are able to implement first in first out
		if (isEmpty()) {
			tail++;
		}

		// Increment the head and store the value
		head++;
		array[head] = x;
		// cout << "Queue Inserted: " << array[head] << endl;
	}

	// Remove values
	int pop() {
		// Check if the list is empty to see if there are values to remove
		if (isEmpty()) {
			// cout << "Error: Queue is empty. " << endl;
			return -1;
		}

		// Remove the values but start at the tail since that is pointing to the first in queue
		int removeValue = array[tail];
		tail++;
		return 0;
	}

	// Show the last in queue
	int top() {
		if (isEmpty()) {
			// cout << "Error: stack is empty." << endl;
			return -1;
		}
		return array[head];
	}

	// Show the first in queue
	int front() {
		if (isEmpty()) {
			// cout << "Error: stack is empty." << endl;
			return -1;
		}
		return array[tail];
	}

	//Iterate through all the values and display everything stored in Queue.
	void displayQueue() {
		if (isEmpty()) {
			return;
		}
		cout << "Queue Array: " << endl;
		for (int i = 0; i <= array[MAX_SIZE]; i++) {
			cout << array[i] << endl;
		}

		cout << "Tail Value: " << array[tail] << endl;
		cout << "Head Value: " << array[head] << endl;
		cout << endl;
	}
};



int main() {
	// Create a Stack object
	Stack S;
	// Create a Queue object
	Queue Q;

	// Variable to store what is being read from the file
	string textValue;

	// Open the file "Text.txt" to read
	ifstream readFile("Text.txt");

	// Read each line from the file until the end
	while (getline(readFile, textValue)) {
		// Explicit type casting
		// stoi function converts string to an integer
		int value = stoi(textValue);
		// Push the integer value onto the stack
		S.push(value);
		// Push the integer value onto the queue
		Q.push(value);
	}

	// Displays all the data in the stack
	S.displayStack();
	// Displays all the data in the Queue
	Q.displayQueue();

	return 0;

}