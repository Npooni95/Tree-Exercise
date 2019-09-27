//
//  LinkedList.h
//  PA11
//
//  Created by Navi Pooni on 11/7/16.
//  Copyright © 2016 Navi Pooni. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct ListNode
{
    T data;
    ListNode<T> * next;
    
    ListNode()
    {
        data = T();
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
private:
    ListNode<T> * head;
    
public:
    LinkedList()
    {
        head = new ListNode<T>;
    }
    
    void InsertFront(T item)
    {
        ListNode<T> * newNode = new ListNode<T>;
        newNode->data = item;
        newNode->next = head->next;
        head->next = newNode;
    }
    
    void Print() const
    {
        ListNode<T> * current = head->next;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
        
    }
    
    T Get(int i) const
    {
        ListNode<T> * current = head->next;
        if (current == NULL)
        {
            cout << "*** Fatal error: List is empty" << endl;
            exit(-1);
        }
        
        for (int k = 0; k < i; k++)
        {
            if (current->next == NULL)
            {
                cout << "*** Fatal error: List size is < " << (i+1) << endl;
                exit(-1);
            }
            current = current->next;
        }
        
        return current->data;
    }
    
    void DeleteItem(T target)
    {
        ListNode<T> * assassin = head;
        
        while (assassin->next != NULL && assassin->next->data != target)
        {
            assassin = assassin->next;
        }
        
        if (assassin->next != NULL)
        {
            ListNode<T> * victim = assassin->next;
            assassin->next = victim->next;
            delete victim;
        }
    }
    
    void InsertItem(T item, int i)
    {
        /// Insert a NEW node with the given data
        /// *before* item #i.
        
        /// (If i is beyond the end of the list, just add to the end of the list)
        
        ListNode<T> * prior = head;
        int counter = 0;
        
        
        while (prior->next != NULL && counter < i)
        {
            prior = prior->next;
            counter++;
        }
        
        ListNode<T> * newnode = new ListNode<T>;
        newnode->data = item;
        
        newnode->next = prior->next;
        prior->next = newnode;
    }
    
    void InsertBack(T item)
    {
        // Insert a New node to the end of the list
        ListNode<T> * prior = head;
        
        while (prior->next != NULL)
        {
           prior = prior->next;
        }
        
        ListNode<T> * newnode = new ListNode<T>;
        newnode->data = item;
        newnode->next = prior->next;
        prior->next = newnode;
        
        
    }
    
    T MinItem() const
    {
        ListNode<T> * current = head->next;
        if (current == NULL)
        {
            cout << "*** Fatal error: List is empty" << endl;
            exit(-1);
        }
        
        if (current->next == NULL)
        {
            return current->data;
        }
        
        ListNode<T> * mini =  new ListNode<T>;
        mini = current;
        while (current!= NULL)
        {
            if (mini->data > current->data)
            {
                mini = current;
            }
            
            current = current->next;
        }
        
        return mini->data;
    }
    
    void InsertSorted(T item)
    {
        ListNode<T> * current = head->next;
        ListNode<T> * LessthanItem = new ListNode<T>;
        ListNode<T> * MorethanItem = new ListNode<T>;
        ListNode<T> * newNode = new ListNode<T>;
        newNode->data = item;
        
        while (current != NULL)
        {
            if (current->data < item && item < current->next->data)
            {
                LessthanItem = current;
                MorethanItem = current->next;
                break;
            }
            current = current->next; 
        }
        
        newNode->next = MorethanItem;
        LessthanItem->next = newNode; 
        
    }
  
};


#endif /* LinkedList_h */
