public class Main {
  public static void main(String[] args) throws FullException, EmptyException {
    int size = 3;
    MyQueue<Integer> queue = new Queue<>(size);
    queue.enqueue(1);
    queue.enqueue(2);
    System.out.println(queue.first());
    queue.dequeue();
    System.out.println(queue.first());
  }
}