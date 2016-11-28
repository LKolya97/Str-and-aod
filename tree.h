#ifndef _TREE_H
#define _TREE_H

template <class Player> class Tree;
#include "node.h"
#include "player.h"
#include<iostream>
using namespace std;
template <class Player>
class Tree
{
    public:
        Tree();                                                    /* ����������� */
        int insert_node(const Player &);                         /* ��������� ���� */
        TreeNode<Player>* delete_node(TreeNode<Player> *);     /* ������� ���� */
        void inorder_walk(TreeNode<Player>*);                    /* �������� ��� ����� � ����������� ������� */
        TreeNode<Player>* find_max(TreeNode<Player>*);         /* ������� ���� � ����������� ��������� ����� � ���������� ��������� �� ���� */                                                         
        TreeNode<Player>* find_min(TreeNode<Player>*);
        TreeNode<Player>* find_node(TreeNode<Player>*,const Player &);
        TreeNode<Player>* find_succsessor(const Player &);     /* ������� ������� � ������, ��������� �� ������ ������ */   
        TreeNode<Player> *get_root();                            /* ���������� ��������� �� ������ ������ */
    private:
        TreeNode<Player> *root;                                  /* ����������, ��� ������ */
};

template<class Player>
Tree<Player>::Tree()
{
        root=0;                      /* � ������ ������ ����� */
}
template<class Player>
int Tree<Player>::insert_node(const Player &x)
{
        TreeNode<Player>* n=new TreeNode<Player>(x);  /* ������� ����� ����, ��� �� ����� ��������� */
        TreeNode<Player>* ptr;
        TreeNode<Player>* ptr1;

        n->parent=n->left=n->right=0;          /* �� - ���� */
        ptr=root;
        while(ptr!=0)                     /* ���� �� ����� � ���� ���������� ����� ��� ������ ������ ��������, ��� ������ ���� �������� */
        {
                ptr1=ptr;                 /* ������� �������� ������ ���� */
                if(x < ptr->get_data() )  /* �� ����������� ������ ������ - ����� �������� ����� ������ ��������, */
                        ptr=ptr->left;
                else
                        ptr=ptr->right;   /* ������ - ������ */
        }
        n->parent=ptr1;
        if(ptr1==0)                       /* ������ ���� �����? */
                root=n;
        else
        {
                if(x < ptr1->get_data() )
                        ptr1->left=n;
                else
                        ptr1->right=n;
        }
        return 0;
}
  
/* �������� ��� ������ - ���� � z ��� �����, �� �������� 0 � ��������������� ����
 * �������� z, ���� � z ���� ���� �������, �� ����� �������� z, �������� ��� �������� �������� �
 * ��� ��������. ���� �� ����� ����, �� ��������� ��������� �������������: �� ������� ��������� 
 * (� ������ ������� �� ������) �� z ������� y; � ���� ��� ������ ������� (������). ������ ����� 
 * ����������� ���� � �������������� ������ �� ������� y � ������� z, � ���� ������� y �������
 * ��������� ���� �������� */

template<class Player>
TreeNode<Player>* Tree<Player>::delete_node(TreeNode<Player> *z)
{
        TreeNode<Player>* y;
        TreeNode<Player>* x;
        if(z->left == 0 || z->right == 0)               /* � ���� � ��������� ���� ������� ���� ������� y, ������� �� ����� ������� �� ������. ��� ���� z, ���� ��������� �� z */
                y=z;
        else
                y=find_succsessor(z->get_data());
        if(y->left!=0)                                  /* x - ��������� �� ������������� ������� y ��� 0 ���� ������� ��� */ 
                x=y->left;
        else
                x=y->right;
        if(x!=0)                                        /* ��� � ��������� 9 ����� - ��������� y */ 
                x->parent=y->parent;
        if(y->parent == 0)
                root=x;
        else
        {
                if (y== (y->parent)->left)
                        (y->parent)->left=x;
                else
                        (y->parent)->right=x;
        }
        if(y!=z)                                        /* ���� �� �������� ������, �������� �� z, �� �� ������ ���������� � z */
                z->data=y->get_data();
        return y;
}
template<class Player>
TreeNode<Player>* Tree<Player>::find_max(TreeNode<Player>* x)
{
        while(x->right!=0)                              /* ����� ��� �������� - ������ ������������ �������� � ������ ������� */
                x=x->right;
        return x;
}

template<class Player>
TreeNode<Player>* Tree<Player>::find_min(TreeNode<Player>* x)
{
        while(x->left!=0)
                x=x->left;
        return x;
}

template<class Player>
TreeNode<Player>* Tree<Player>::find_succsessor(const Player & val)
{
        TreeNode<Player>* x=find_node(root,val);                     /* ������� ��������� �� ���� � ������ val */
        TreeNode<Player>* y;
        if(x == 0)
                return 0;
        if(x->right!=0)                                                /* ���� � ��� ���� ������ ����, �� ��������� ������� - ����������� � ������ ��������� */
                return find_min(x->right);
        y=x->parent;
        while(y!=0 && x == y->right)                                   /* ����� - ���� ����� � ���� ������ �������, ���������� �����
�������� ������ �������� */
        {
                x=y;
                y=y->parent;
        }
        return y;
}
template<class Player>
TreeNode<Player>* Tree<Player>::find_node(TreeNode<Player>* n,
                                        const Player & val)
{
        if(n==0 || val==n->get_data())
                return n;
        if(val > n->get_data() )
                return find_node(n->right,val);
        else
                return find_node(n->left,val);
}
template<class Player>
void Tree<Player>::inorder_walk(TreeNode<Player>* n)
{
        if(n!=0)
        {
                inorder_walk(n->left);
                cout<<n->get_data()<<endl;
                inorder_walk(n->right);
        }
}

template<class Player>
TreeNode<Player>* Tree<Player>::get_root()
{
        return root;
}
#endif
