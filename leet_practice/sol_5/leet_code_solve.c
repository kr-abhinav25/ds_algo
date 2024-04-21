// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

//    struct ListNode* tmp1 = l1;
//    struct ListNode* tmp2 = l2;
//    struct ListNode* sum_node;
//    int carry_over = 0;
//    int count = 0;
//    int sum = 0;
//    struct ListNode* array_to_return;
//    struct ListNode* pp;
//    struct ListNode* xx;
//    struct ListNode* yy;


//    while ((tmp1 != NULL) && (tmp2 != NULL))
//    {
//       sum = tmp1->val + tmp2->val + carry_over;
//       carry_over = 0;
//       if (sum > 9) {
//          int mma = sum%10;
//          tmp1->val = mma;
//          tmp2->val = mma;
//          carry_over = sum/10;
//       }
//       else {
//          tmp1->val = sum;
//          tmp2->val = sum;
//       }
//       tmp1 = tmp1->next;
//       tmp2 = tmp2->next;
//    }
//    if(tmp1 == NULL) {
//       array_to_return = tmp2;
//       xx = l2;
//       yy=l1;
//    }
//    else {
//       array_to_return = tmp1;
//       xx = l1;
//       yy=l2;
//    }
//    while (array_to_return != NULL) {
//       sum = array_to_return->val + carry_over;
//       carry_over = 0;
//       if (sum > 9) {
//          int mma = sum%10;
//          array_to_return->val = mma;
//          carry_over = sum/10;
//       }
//       else {
//          array_to_return->val = sum;
//       }
//       if (array_to_return->next == NULL)
//       {
//         if (carry_over > 0) {
//             yy->val = carry_over;
//             yy->next = NULL;
//             array_to_return->next = yy;
//             carry_over = 0;
//         }
//         break;
//       }
//       array_to_return = array_to_return->next;
//    }
//       if (carry_over > 0) {
//          struct ListNode* tmp = xx;
//          while (tmp->next != NULL)
//          {
//             tmp = tmp->next;
//          }         
//             yy->val = carry_over;
//             yy->next = NULL;
//             tmp->next = yy;
//             carry_over = 0;
//         }   
//    return xx;
   
// }