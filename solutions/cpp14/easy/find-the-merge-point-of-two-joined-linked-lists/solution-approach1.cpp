// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true
// Problem     Find Merge Point of Two Lists
// Difficulty  Easy
// Subdomain   Linked Lists
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-07-29, 11:38 a.m.
// Technique   two-pointers-cycle-traversal
// Time        O(N+M)
// Space       O(1)
// Insight     By resetting each pointer to the opposite head upon reaching the end of its respective list, both pointers traverse an equal distance and meet at the merge node.
// Interview   Before: "I would use a hash set to store visited nodes." After: "Using two pointers that swap heads upon reaching null allows finding the merge point in O(N+M) time and O(1) space, effectively normalizing the path lengths for both lists."
// Pitfalls    (1) Assuming the lists must be of equal length, which is not guaranteed by the problem statement.  (2) Failing to account for the case where the lists merge at the very last node.  (3) Infinite looping if the lists do not actually merge, though the problem guarantees a merge point exists.
// ──────────────────────────────────────────────────



// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* l1=head1;
    SinglyLinkedListNode* l2=head2;
    while(l1!=l2){
        if(l1!=NULL)l1=l1->next;
        else l1=head2;
        if(l2!=NULL)l2=l2->next;
        else l2=head1;
    }
    return l1->data;
    
}

