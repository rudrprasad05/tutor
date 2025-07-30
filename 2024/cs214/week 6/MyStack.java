import java.util.Vector;
import java.util.EmptyStackException;


class MyStack{
  private Vector items;

  public MyStack() {
    items = new Vector();
  }

  public Object push(Object item) {
	  items.addElement(item);
    return item;
  }
  
  public Object pop() {
	  Object	obj;
	  int	len = items.size();
 	  obj = peek();
	  items.removeElementAt(len - 1);
    return obj;
  }

  public Object peek() {
    int	len = items.size();
    if (len == 0)
      throw new EmptyStackException();
    return items.elementAt(len - 1);
  }

  public int size() {
    // ???
    return 0;
  }

  public String toString() {
    return items.toString();
  }


  public static void main(String[] args) throws CloneNotSupportedException {
    //TODO..
  }
}