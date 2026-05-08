class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    
  public:
  Node* start;
  Node* end;
  int siz;
    myQueue() {
        // Initialize your data members
        start=nullptr;
        end=nullptr;
        siz=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return siz==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
         Node* temp= new Node(x);
        if(start==nullptr){
            start=end=temp;
        }
       else{
           end->next=temp;
           end=temp;
       }
        siz++;
        
    }

    void dequeue() {
        // Removes the front element of the queue
        if(start==nullptr)return;
        Node* temp=start;
        start=start->next;
        delete(temp);
        siz--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(start==nullptr){
            return -1;
        }
        return start->data;
    }

    int size() {
        // Returns the current size of the queue.
        return siz;
    }
};