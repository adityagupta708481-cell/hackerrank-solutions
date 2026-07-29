// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true
// Problem     Find Merge Point of Two Lists
// Difficulty  Easy
// Subdomain   Linked Lists
// Platform    HackerRank
// Language    cpp14
// Status      Accepted
// Submitted   2026-07-29, 11:38 a.m.
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

