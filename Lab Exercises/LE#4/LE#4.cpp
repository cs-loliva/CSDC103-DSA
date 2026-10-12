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
conversion from hex  formula: from https://hexcalculator.org/decimal-to-hexadecimal/
NEED/GOAL: int to char mapping. no longer needed!!


working source code: 
*/
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

int main() { //edits to be made here
    int x, y;
    const string key = "0123456789abcdefghijklmnopqrstuvwxyz"; // alternative to ai-generated code, uses lookup string to map out the output character!

    while (cin >> x >> y) {
        //when x is 0 print nothing .. and continue?
        if (x == 0) {
            cout << 0 << "\n";
            continue;
        }
        
    
        Stack s;

        //mod of x & y return r use as conversion factor conversion from hex and other bases formula: from https://hexcalculator.org/decimal-to-hexadecimal/
        while(x > 0) {
            s.push(x % y);
            x = x / y;
        }

        while(!s.isEmpty()) {
            cout << key[s.pop()];
            /*int temp = s.pop(); //hold popped val as temp and work through values of input
            if (d < 10) 
                cout << temp;
            else
                cout << (char)('a' + (temp - 10)); /*gemini generated code, i further asked gemini how this works 
                    and it returned to me a response about the hexatrigesimal system which i noticed coincides directly with the constraints of the y value 
                    (mind blown at this point) so with the concept of the base-36 i opted for an alternative approach below 
                    ^^^^^^^^ also added const string "key" below main as a lookup string!*/
        
        }
        cout << "\n";
    }
    
    return 0;
}


