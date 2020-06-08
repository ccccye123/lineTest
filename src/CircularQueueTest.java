public class CircularQueueTest {
    public static void main(String[] args) {
        MyCircularQueue queue = new MyCircularQueue(3);
        boolean b = queue.enQueue(3);
        System.out.println(b);
        b = queue.enQueue(9);
        System.out.println(b);
        b = queue.enQueue(1);
        System.out.println(b);
        b = queue.enQueue(2);
        System.out.println(b);

        b = queue.deQueue();
        System.out.println(b);
        b = queue.enQueue(2);
        System.out.println(b);

        b = queue.deQueue();
        System.out.println(b);
        b = queue.deQueue();
        System.out.println(b);
        b = queue.deQueue();
        System.out.println(b);
        b = queue.deQueue();
        System.out.println(b);
    }
}
