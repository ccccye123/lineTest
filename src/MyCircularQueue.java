public class MyCircularQueue {
    private static int[] myQueue;
    private int head = -1;
    private int trail = -1;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        myQueue = new int[k];
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        // 1、如果没有满允许插入

        // 2、如果是空队列，head=0 trail=0，否则+1

        if (isFull()){
            return false;
        }


        if (isEmpty()){
            myQueue[0] = value;

            head = 0;
            trail = 0;
        }else{
            trail++;
            trail = trail % myQueue.length;

            myQueue[trail] = value;
        }

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        // 取一个队头的元素
        // 判断是否为空
        // 取了该元素后是否为空
        if (isEmpty()){
            return false;
        }

        myQueue[head] = 0;
        if (head == trail){
            head = -1;
            trail = -1;
        }else{
            head++;
            head = head % myQueue.length;
        }

        return true;
    }

    /** Get the front item from the queue. */
    public int Front() {
        if (isEmpty()){
            return -1;
        }

        return myQueue[head];
    }

    /** Get the last item from the queue. */
    public int Rear() {
        if (isEmpty()){
            return -1;
        }

        return myQueue[trail];
    }

    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        if (head == -1 || trail == -1){
            return true;
        }
        return false;
    }

    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        if ((trail+1) % myQueue.length == head){
            return true;
        }
        return false;
    }
}
