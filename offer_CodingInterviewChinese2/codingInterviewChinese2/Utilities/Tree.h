/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

#pragma once

#ifndef __TREE_H__
#define __TREE_H__

#include <vector>

struct TreeNode 
{
    int                       m_nValue;    
    std::vector<TreeNode*>    m_vChildren;    
};

__declspec( dllexport ) TreeNode* CreateTreeNode(int value);
__declspec( dllexport ) void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
__declspec( dllexport ) void PrintTreeNode(const TreeNode* pNode);
__declspec( dllexport ) void PrintTree(const TreeNode* pRoot);
__declspec( dllexport ) void DestroyTree(TreeNode* pRoot);

#endif
