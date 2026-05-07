/*/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
 Node* top;
int siz; 
    myStack() {
        // Initialize your data members
        top=nullptr;
        siz=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return siz==0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp=new Node(x);
        temp->next=top;
        top=temp;
        siz++;
    }

    void pop() {
        // Removes the top element of the stack
        Node * temp=top;
        top=top->next;
        delete(temp);
        siz--;
        
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(siz==0)return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return siz;
    }
};