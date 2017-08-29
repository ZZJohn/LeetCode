#include <iostream>
#include <vector>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode* result = new ListNode(0);
	ListNode* curr = result;
    int sum = 0;
    while (1)
    {
        if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
        curr->val = (sum)%10;
		sum = sum / 10;
		if (l1 == NULL && l2 == NULL && sum==0) break;
		curr->next = new ListNode(0);
		curr = curr->next;
    }
    return result;
}

int main()
{
	ListNode* l1 = new ListNode(0);
	ListNode* l2 = new ListNode(0);
	ListNode* curr1 = l1;
	ListNode* curr2 = l2;
	int v1[] = {2, 4, 3};
	int v2[] = {5, 6, 4};
	for (int i = 0; i < 3; i++)
	{
		curr1->val = v1[i];
		curr1->next = new ListNode(0);
		curr1 = curr1->next;
	}
	for (int i = 0; i < 4; i++)
	{
		curr2->val = v2[i];
		curr2->next = new ListNode(0);
		curr2 = curr2->next;
	}
	ListNode* result = addTwoNumbers(l1, l2);
	for (int i = 0; i < 3; i++)
	{
		cout << result->val << ends;
		result = result->next;
	}
	cout << endl;
	return 0;
}