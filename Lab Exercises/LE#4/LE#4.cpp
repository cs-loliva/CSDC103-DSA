/*
PROBLEM DESCRIPTION
Brice wants to communicate with aliens and she is aware that math is the universal language. But the problem is, these aliens understand a different form of number system.
Help her send signals to these aliens by converting a bunch of decimal numbers into another number system.

INPUT FORMAT
The input consists of a series of integer pairs x and y, where x is a number and in base 10 (decimal form) and y is the base number x will be converted to.

CONSTRAINTS
0 <= x < 10^5
2 <= y <= 36

OUTPUT FORMAT
For each x y pair, display the base y equivalent of x. If the output involves letters, display them in their lowercase format.

PROGRAM SPECIFICATIONS
The problem must be solved using a linked list stack implementation. You may utilize the previous linked list implementation video as a starting point.

SAMPLE INPUT                                                    SAMPLE OUTPUT
7921 2                                                          1111011110001
2428 5                                                          34203
576 3                                                           210100
52368 16                                                        cc90

*/

/*
GEMINI: outputs are a mix of base-2, base-3, base-5, and hexadecimal values.

working source code: 
#include <iostream>
using namespace std;

//LL implementation of STACK
struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;
    
    public:
        Stack(){
            top = nullptr; //empty condition
        }
        bool isEmpty(){
            return top == nullptr;
        }
        void push (int value){
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = top;
            
            top = newNode;
        }
        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow\n";
                return -1;
            }
            Node* temp = top;
            int value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
        int peek(){
            if(isEmpty()){
                return -1;
            }
            return top->data;
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    
    return 0;
}
*/

