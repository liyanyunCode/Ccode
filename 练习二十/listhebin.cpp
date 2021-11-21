#include<iostream>
#include<string>
using namespace std;



struct ListNode
{
	int val;
	ListNode* next;
	
};
class Solution {
public:
	ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
	{
		ListNode* head, * tail;
		head = tail = new ListNode;

		//ÄÃÐ¡µÄ½øÐÐÎ²²å
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				tail->next = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		if (l1 != NULL)
		{
			tail->next = l1;
		}
		else if(l2!=NULL)
		{
			tail->next = l2;
		}

		//·ÀÖ¹ÄÚ´æÐ¹Â©
		ListNode* l = head->next;
		delete head;
		return l;
	}
};