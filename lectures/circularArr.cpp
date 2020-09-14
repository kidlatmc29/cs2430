// Basic Queue array implementations

using namespace std;

class Queue {
public:
  void Queue::enqueue(int x)
  {
    if (size +1 > maxSize) {
      // resize();
    }
    arr[(front+size)%maxSize] = x;
    size++;
  }

  int Queue::dequeue()
  {
    /**
     * would check if the queue is empty before attempting to dequeue
    if(empty) {
      cout << " this queue is empty! ");
    }
    **/
    int x = arr[front];
      front = (front+1)&maxSize;
      size--;
      return x;
     }

private: 
  int maxSize;
  int size; 
  int front; 
  int arr[10] = {0};

};