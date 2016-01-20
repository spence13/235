#pragma once
#include "LinkedListInterface.h"
#include <stdexcept>
#include <iostream>

using namespace std;




template <class T>

class LinkedList:public LinkedListInterface<T>
{

    private:
        struct node
        {
            T data;
            node* next;

            node (T value)
            {
                next = NULL;
                data = value;
            }
            ~node ()
            {

            }

        };
        node* head;
        int listsize;


    public:
        LinkedList()
    {
            listsize = 0;
            head = NULL;
    }
        ~LinkedList()
        {
            clear();
        }

            /*
                insertHead

                A node with the given value should be inserted at the beginning of the list.

                Do not allow duplicate values in the list.
             */
            void insertHead(T value)
            {
                node*temp = head;


                    while(temp != NULL)
                    {

                            if(temp->data == value)
                            {
                                return;
                            }
                            else
                            {
                                temp = temp->next;
                            }

                    }
                    		node* ptr = new node (value);
                            ptr->next = head;
                            head = ptr;
                            listsize++;
            }

            /*
                insertTail

                A node with the given value should be inserted at the end of the list.

                Do not allow duplicate values in the list.
             */
             void insertTail(T value)
            {
                 node*temp = head;

                 	 if (listsize == 0)
                 	 {
                 		 node * ptr = new node (value);
                 		 head = ptr;
                 		 listsize++;
                 		 return;
                 	 }
                                     while(temp->next != NULL)
                                     {

                                             if(temp->data == value)
                                             {
                                                 return;

                                             }
                                             else
                                             {
                                                 temp = temp->next;
                                             }
                                     }

                                     if (temp->data == value)
                                     {
                                         return;
                                     }
									node* ptr = new node (value);
                                     ptr->next = NULL;
                                     temp->next = ptr;
                                     listsize++;

            }

            /*
                insertAfter

                A node with the given value should be inserted immediately after the
                node whose value is equal to insertionNode.

                A node should only be added if the node whose value is equal to
                insertionNode is in the list. Do not allow duplicate values in the list.
             */
             void insertAfter(T value, T insertionNode)
            {


                  node*temp = head;
                 while(temp != NULL)
                 {

                     if(temp->data == value)
                     {
                         return;
                     }
                     else
                     {
                         temp = temp->next;
                     }

                 }




                     node*retemp = head;

                         while (retemp != NULL )
                         {
                             if (retemp->data == insertionNode)
                             {
                              node* ptr = new node (value);
                            	 ptr->next = retemp->next;
                                retemp->next = ptr;
                                listsize++;
                                return;

                             }

                             else
                             {
                                 retemp = retemp->next;
                             }


                         }



            }

            /*
                remove

                The node with the given value should be removed from the list.

                The list may or may not include a node with the given value.
             */
             void remove(T value)
            {
                 node* temp = head;

                 while(temp != NULL)
                     {

                        if(temp->data == value)
                             {
                                            node*retemp = head;
                                             node* r = retemp->next;
                                              if (head->data == value)
                                                     {
                                                         head = head->next;
                                                         delete retemp;
                                                         listsize--;
                                                         return;

                                                     }
                                            while(r->data != value)
                                                 {

                                                        retemp = r;
                                                        r = r->next;
                                                 }


                                                     if(r->data == value)
                                                     {
                                                         retemp->next = r->next;
                                                         delete r;
                                                         listsize--;
                                                         return;

                                                     }


                             }

                             else
                             {
                                 temp = temp->next;
                             }
                   }

            }



            /*
                clear

                Remove all nodes from the list.
             */
             void clear()
            {


                 while (head != NULL)
                 {
                      node* temp = head;

                         head = head->next;
                         delete temp;


                 }
                 listsize = 0;
            }

            /*
                at

                Returns the value of the node at the given index. The list begins at
                index 0.

                If the given index is out of range of the list, throw an out of range exception.
             */
             T at(int index)
            {
                    if(index > (listsize - 1) || index < 0 || listsize == 0)
                {
                throw out_of_range ("you are out of range");
                }

                node * temp = head;
                for(int i = 0; i < index; i++)
                {
                temp = temp->next;
                }

                return temp->data;

            }

            /*
                size

                Returns the number of nodes in the list.
             */
             int size()
            {
                      return listsize;
            }


};