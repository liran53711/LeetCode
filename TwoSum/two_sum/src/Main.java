//TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
// 点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
public class Main {
    public static void main(String[] args) {

        ListNode node1 = new ListNode(2);
        ListNode node2 = new ListNode(4);
        ListNode node3 = new ListNode(9);
        ListNode node4 = new ListNode(5);
        ListNode node5 = new ListNode(6);
        ListNode node6 = new ListNode(4);
        ListNode node7 = new ListNode(9);
        node1.next = node2;
        node2.next = node3;
        node4.next = node5;
        node5.next = node6;
        node6.next = node7;
        Solution solution = new Solution();
        ListNode nodes = solution.addTwoNumbers(node1, node4);
        while (nodes != null) {
            System.out.println(nodes.val);
            nodes = nodes.next;
        }




    }
}