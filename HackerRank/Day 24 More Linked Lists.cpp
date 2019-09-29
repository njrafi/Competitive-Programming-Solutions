

          Node* removeDuplicates(Node *head)
          {
            //Write your code here
            if( head == NULL) return head;
            if( head -> next != NULL && head->next->data == head->data)
                return removeDuplicates(head->next);
            head -> next = removeDuplicates(head->next);
            return head;
          }

