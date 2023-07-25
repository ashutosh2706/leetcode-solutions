class MyCircularQueue {
public:
    vector<int> cqueue;
    int front, rear, sz;
    MyCircularQueue(int k) {
        cqueue.resize(k, -1);
        front = -1, rear = -1, sz = k;
    }
    
    bool enQueue(int value) {
    if ((front == 0 and rear == sz-1) or (front == rear+1)) return 0;
    if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == sz - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   cqueue[rear] = value ;
   return 1;
    }
    
    bool deQueue() {
        if(front == -1) return 0;
        if(front == rear) {
            front = -1;
            rear = -1;
        }else {
            if(front == sz -1) {
                front = 0;
            }else front++;
        }
        return 1;
    }
    
    int Front() {
        if(front == -1) return -1;
        return cqueue[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        return cqueue[rear];
    }
    
    bool isEmpty() {
        return front == -1 and rear == -1;
    }
    
    bool isFull() {
        if((front == 0 and rear == sz-1) or front == rear+1) return 1;
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */