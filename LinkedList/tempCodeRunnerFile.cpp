Node *a = reverse(l1);
        cout << endl;
        Node *b = reverse(l2);
        Node *head = new Node(0);
        Node *curr = head;
        int carry = 0;
        int x, y;
        while (a != NULL || b != NULL)
        {
            if (a == NULL)
                x = 0;
            else
                x = a->data;

            if (b == NULL)
                y = 0;
            else
                y = b->data;

            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            // cout<<sum;
            curr->next = new Node(sum);
            curr = curr->next;
            if (a != NULL)
                a = a->next;
            if (b != NULL)
                b = b->next;
        }
        if (carry > 0)
            curr->next = new Node(carry);
        return reverse(head->next);