package structure;

public class ListNode {
    public int val;
    public ListNode next = null;
    public ListNode(int x) { val = x; }

    public static int[] stringToIntegerArray(String input){
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) return new int[0];

        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for (int i = 0; i < parts.length; ++i) output[i] = Integer.parseInt(parts[i].trim());
        return output;
    }

    public static ListNode stringToListNode(String input){
        int[] nodeValues = stringToIntegerArray(input);

        ListNode dummyRoot = new ListNode(0);
        ListNode ptr = dummyRoot;
        for (int item : nodeValues){
            ptr.next = new ListNode(item);
            ptr = ptr.next;
        }
        return dummyRoot.next;
    }

    public static void prettyPrintLinkedList(ListNode node){
        while (node != null && node.next != null){
            System.out.print(node.val + " -> ");
            node = node.next;
        }

        if (node != null){
            System.out.println(node.val);
        } else {
            System.out.println("Empty LinkedList");
        }
    }
}
