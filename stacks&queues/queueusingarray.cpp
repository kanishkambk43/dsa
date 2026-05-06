class myQueue {

  public:
  int start;
  int rear;
  int *qu;
  int cap;
  int size;
    myQueue(int n) {//constructor
        // Define Data Structures
        start=0;
        rear=-1;
        qu=new int[n];
        cap=n;
        size=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return size==0;
    }

    bool isFull() {
        // check if the queue is full
        return size==cap;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())return;
        rear=(rear+1) % cap;
        qu[rear]=x;
        size++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        start=(start+1)%cap;
        size--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(size==0)return -1;
        return qu[start];
    }

    int getRear() {
        // Return the last element of queue
        if(size==0)return -1;
        return qu[rear];
    }
};