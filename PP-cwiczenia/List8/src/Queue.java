import java.util.ArrayList;
import java.util.List;

public class Queue<E> implements MyQueue<E> {

  private List<E> queue = new ArrayList<>();
  private int f;
  private int r;


  public Queue (int size) {
    for (int i = 0; i < size; i++)
      queue.add(null);
    this.f = 0;
    this.r = 0;
  }

  @Override
  public void enqueue (E x) throws FullException {
    if (isFull())
      throw new FullException("Queue is full");
    queue.set(r, x);
    r = (r + 1) % queue.size();
  }

  @Override
  public void dequeue () {
    if (!(f == r)) {
      queue.set(f, null);
      f = (f + 1) % queue.size();
    }
  }

  @Override
  public E first () throws EmptyException {
    if (f == r)
      throw new EmptyException("queue is empty");
    return queue.get(f);
  }

  @Override
  public boolean isEmpty () {
    return f == r;
  }

  @Override
  public boolean isFull () {
    return (r + 1) % queue.size() == f;
  }
}
