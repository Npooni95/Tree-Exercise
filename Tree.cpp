//
//  Tree.cpp
//  PA11
//
//  Created by Navi Pooni on 11/8/16.
//  Copyright © 2016 Navi Pooni. All rights reserved.
//

#include "Tree.hpp"

TreeNode* AddChild(TreeNode * ptr, string item)
{
    TreeNode * newnode = new TreeNode(item);
    ptr->children.push_back(newnode);
    return newnode;
}

void ListChildren(TreeNode * ptr)
{
    for (int i = 0; i < ptr->children.size(); i++)
    {
        cout << ptr->children[i]->data << endl;
    }
}

void ListDescendants(TreeNode * ptr)
{
    for (int i = 0; i < ptr->children.size(); i++)
    {
        cout << ptr->children[i]->data << endl;
        ListDescendants(ptr->children[i]);
    }
}

void RemoveChild(TreeNode * ptr, string item)
{
    /// remove child and all descendants
    for (int i = 0; i < ptr->children.size(); i++)
    {
        if (ptr->children[i]->data == item)
        {
            RemoveAllChildren(ptr->children[i]);
            delete ptr->children[i];
            ptr->children.erase(ptr->children.begin() + i);
            break;
        }
    }
}

void RemoveAllChildren(TreeNode * ptr)
{
    for (int i = 0; i < ptr->children.size(); i++)
    {
        RemoveAllChildren(ptr->children[i]);
        delete ptr->children[i];
    }
    ptr->children.clear();
}


TreeNode* Find(TreeNode *ptr, string target)
{
    TreeNode * Foundit;
    for (int i = 0; i < ptr->children.size(); i++)
    {
        if (ptr->children[i]->data == target)
        {
            Foundit = ptr->children[i];
            return Foundit;
            break;
        }
        
        Foundit = Find(ptr->children[i], target);
    }
    
    return Foundit; 
}


int NumChildren(TreeNode *ptr)
{
    return ptr->children.size(); 
}

int NumDescendants(TreeNode *ptr)
{
    int total = 0;
    for (int i = 0; i < ptr->children.size(); i++)
    {
        total++;
        total += NumDescendants(ptr->children[i]);
    }
    
    return total; 
}

bool IsAncestor(TreeNode *root, string personA, string personB)
{
    TreeNode * existA = Find(root, personA);
    
    if (existA->data == personA)
    {
        TreeNode * existB = Find(existA, personB);
        
        if (existB->data == personB)
        {
            return true;
        }
        
        else
        {
            return false;
        }
        
    }
    
    return false;
}


