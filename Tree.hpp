//
//  Tree.hpp
//  PA11
//
//  Created by Navi Pooni on 11/8/16.
//  Copyright © 2016 Navi Pooni. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    string data;
    vector<TreeNode *> children;
    TreeNode(string data)
    {
        this->data = data;
    }
};

TreeNode* AddChild(TreeNode * ptr, string item);

void ListChildren(TreeNode * ptr);

void ListDescendants(TreeNode * ptr);

void RemoveChild(TreeNode * ptr, string item);

void RemoveAllChildren(TreeNode * ptr);

TreeNode* Find(TreeNode *ptr, string target);


int NumChildren(TreeNode *ptr);

int NumDescendants(TreeNode *ptr);

bool IsAncestor(TreeNode *root, string personA, string personB);


#endif /* Tree_hpp */
