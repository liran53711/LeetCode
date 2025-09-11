/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result  = new ListNode(0);
        ListNode cur = result ;
        int carry = 0 ;
        while ( l1 !=null || l2 != null ) {
            int tem = (l1 == null ? 0 :l1.val) + (l2==null ? 0:l2.val)  + carry;
            carry = tem / 10;
            result.next  = new ListNode ( tem % 10   ,null );
            result = result.next ;

            if (l1 != null) l1 = l1.next ;
            if (l2 != null) l2 = l2.next ;


        }
        if (carry > 0) result.next = new ListNode(carry);


        return cur.next ;
    }
}