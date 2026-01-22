class node 
{
public:
    int data;
    node * prev;
    node * next;
    node(){prev=next=0;}
    node (int x) {data=x;prev=next=0;}
};

class Solution {
public:
    bool isSorted(node* rug)
    {
        if (!rug || !rug->next) return true;
        node* temp = rug;
        while (temp->next)
        {
            if (temp->data > temp->next->data) return false;
            temp = temp->next;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums)
    {
        node* rug = new node();
        node* c = rug;

        for (int num : nums)
        {
            node* newNode = new node(num);
            c->next = newNode;
            newNode->prev = c;
            c = newNode;
        }

        int count = 0;

        while (!isSorted(rug->next))
        {
            c = rug->next;
            node* veda = c;
            int minSum = INT_MAX;

            while (c && c->next)
            {
                int x = c->data + c->next->data;
                if (x < minSum)
                {
                    minSum = x;
                    veda = c;
                }
                c = c->next;
            }

            node* temp2 = veda->next;
            veda->data = minSum;
            veda->next = temp2->next;

            if (temp2->next)
            {
                temp2->next->prev = veda;
            }

            delete temp2;
            count++;
        }

        c = rug;
        while (c != 0)
        {
            node* next = c->next;
            delete c;
            c = next;
        }

        return count;
    }
};
