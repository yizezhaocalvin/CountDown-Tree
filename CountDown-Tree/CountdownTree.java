package comp2402a4;

import java.util.Random;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.*;
/**
* An unfinished implementation of an Countdown tree (for exercises)
* @author morin
*
* @param <T>
*/
public class CountdownTree<T> extends
BinarySearchTree<CountdownTree.Node<T>, T> implements SSet<T> {

	// countdown delay factor
	double d;

	public static class Node<T> extends BSTNode<Node<T>,T> {
		int timer;  // the height of the node
	}

	public CountdownTree(double d) {
		this.d = d;
		sampleNode = new Node<T>();
		c = new DefaultComparator<T>();
	}

	public boolean add(T x) {
		Node<T> u = new Node<T>();
		u.timer = (int)Math.ceil(d);
		u.x = x;
		if (super.add(u)) {
            adjust(u);
			return true;
		}
		return false;
	}

    protected void adjust(Node<T> u) {
        Node<T> last = null;
        while (u != nil) {
            --u.timer;
            assert(u.timer >= 0);
            if (u.timer == 0) {
                last = u;
            }
            u = u.parent;
        }
        if (last != null) {
            explode(last);
        }
    }

	public void splice(Node<T> u) {
		Node<T> w = u.parent;
		super.splice(u);
        adjust(w);
    }

    public static class Pair<T> {
        Node<T> node;
        int size;
    }

    protected Pair<T> makeTreeNode(List<Node<T>> list, int offset, int length) {
        if (length == 0) {
            return null;
        }
        if (length == 1) {
            Node<T> root = list.get(offset);
            root.timer = (int)Math.ceil(d);
            root.left = nil;
            root.right = nil;
            Pair<T> p = new Pair<>();
            p.node = root;
            p.size = 1;
            return p;
        }
        int mid = offset + length / 2;
        Node<T> root = list.get(mid);
        Pair<T> left = makeTreeNode(list, offset, mid - offset);
        Pair<T> right = makeTreeNode(list, mid + 1, offset + length - mid - 1);
        if (left != null) {
            root.left = left.node;
            left.node.parent = root;
        } else {
            root.left = nil;
        }
        if (right != null) {
            root.right = right.node;
            right.node.parent = root;
        } else {
            root.right = nil;
        }
        root.timer = (int)Math.ceil(d * size(root));
        int size = 1 + (left == null ? 0 : left.size) + (right == null ? 0 : right.size);
        Pair<T> p = new Pair<>();
        p.node = root;
        p.size = size;
        return p;
    }

    boolean sorted(List<Node<T>> a) {
        for (int i = 0; i < a.size() - 1; ++i) {
            Integer a1 = (Integer)a.get(i).x;
            Integer a2 = (Integer)a.get(i + 1).x;
            if (a1.compareTo(a2) > 0) {
                return false;
            }
        }
        return true;
    }
    protected void dfs(List<Node<T>> a, Node<T> r) {
        if (r.left != nil) dfs(a, r.left);
        a.add(r);
        if (r.right != nil) dfs(a, r.right);
    }

    protected List<Node<T>> traverseToList(Node<T> r) {
        
        Stack<Node<T>> q = new Stack<>();
        Stack<Integer> s = new Stack<>();
		q.push(r);
        s.push(0);
        List<Node<T>> a = new ArrayList<>();
		while (!q.isEmpty()) {
			Node u = q.pop();
            int status = s.pop();
            if (status == 0) {
                q.push(u);
                s.push(1);
                if (u.left != nil) {
                    q.push((Node<T>)u.left);
                    s.push(0);
                }
            } else if (status == 1) {
                a.add(u);
    			if (u.right != nil) {
                    q.push((Node<T>)u.right);
                    s.push(0);
                }
            }
		}
        return a;
        /*
        List<Node<T>> a = new ArrayList<>();
        dfs(a, r);
        return a;
        */
    }

	protected void explode(Node<T> r) {

        Node<T> par = r.parent;
        int lr = 0;
        if (par != nil) {
            if (r == par.left) { lr = 1;} 
            else if (r == par.right) { lr = 2;}
            else assert(false);
        }

        List<Node<T>> a = traverseToList(r);
        Node <T> newr = makeTreeNode(a, 0, a.size()).node;
        if (lr == 0) {
            this.r = newr;
            newr.parent = par;
        } else if (lr == 1) {
            par.left = newr;
            newr.parent = par;
        } else if (lr == 2) {
            par.right = newr;
            newr.parent = par;
        }

	}

	// Here is some test code you can use
	public static void main(String[] args) {
//		Testum.sortedSetSanityTests(new SortedSSet<Integer>(new CountdownTree<Integer>(1)), 1000);
//		Testum.sortedSetSanityTests(new SortedSSet<Integer>(new CountdownTree<Integer>(2.5)), 1000);
   	
		Testum.sortedSetSanityTests(new SortedSSet<Integer>(new CountdownTree<Integer>(0.5)), 1000);

		java.util.List<SortedSet<Integer>> ell = new java.util.ArrayList<SortedSet<Integer>>();
		ell.add(new java.util.TreeSet<Integer>());
		ell.add(new SortedSSet<Integer>(new CountdownTree<Integer>(1)));
		ell.add(new SortedSSet<Integer>(new CountdownTree<Integer>(2.5)));
		ell.add(new SortedSSet<Integer>(new CountdownTree<Integer>(0.5)));
		Testum.sortedSetSpeedTests(ell, 1000000);
	}
}
