#include <iostream>

using namespace std;

/*struct ListNode {
    int val;
    ListNode *next;
};*/

class ListNode
{
  public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

bool isPalindrome(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *temp;
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next)
    { //  Get the mid pointer of list
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
        cout << "fast :" << fast->val << " slow :" << slow->val << " prev :" << prev->val << endl;
    }

    /**
        fast : 0 2 4 6                    prev  slow        fast
        slow : 0 1 2 3              0 <-1 <-2   3-> 4-> 5-> 6
    **/
    if (fast)              // check whether list id even or odd
        slow = slow->next; // odd

    while (slow)
    {
        if (prev->val != slow->val)
            return false;
        cout << "slow :" << slow->val << " prev :" << prev->val << endl;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);
    cout << "List is : " << isPalindrome(head) << endl;

    return 0;
}