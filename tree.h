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
        Tree();                                                    /* конструктор */
        int insert_node(const Player &);                         /* вставляет узел */
        TreeNode<Player>* delete_node(TreeNode<Player> *);     /* удаляет узел */
        void inorder_walk(TreeNode<Player>*);                    /* печатает все ключи в неубывающем порядке */
        TreeNode<Player>* find_max(TreeNode<Player>*);         /* находит узел с минимальным значением ключа и возвращает указатель на него */                                                         
        TreeNode<Player>* find_min(TreeNode<Player>*);
        TreeNode<Player>* find_node(TreeNode<Player>*,const Player &);
        TreeNode<Player>* find_succsessor(const Player &);     /* находит элемент с ключем, следующим за данным числом */   
        TreeNode<Player> *get_root();                            /* возвращает указатель на корень дерева */
    private:
        TreeNode<Player> *root;                                  /* собственно, сам корень */
};

template<class Player>
Tree<Player>::Tree()
{
        root=0;                      /* в начале дерево пусто */
}
template<class Player>
int Tree<Player>::insert_node(const Player &x)
{
        TreeNode<Player>* n=new TreeNode<Player>(x);  /* создаем новый узел, его мы будем вставлять */
        TreeNode<Player>* ptr;
        TreeNode<Player>* ptr1;

        n->parent=n->left=n->right=0;          /* он - лист */
        ptr=root;
        while(ptr!=0)                     /* идем от корня и ищем подходящее место для нашего нового элемента, оно должно быть свободно */
        {
                ptr1=ptr;                 /* будущий родитель нового узла */
                if(x < ptr->get_data() )  /* по определению нашего дерева - слева значение ключа меньше родителя, */
                        ptr=ptr->left;
                else
                        ptr=ptr->right;   /* справа - больше */
        }
        n->parent=ptr1;
        if(ptr1==0)                       /* дерево было пусто? */
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
  
/* возможны три случая - если у z нет детей, то помещаем 0 в соответствующее поле
 * родителя z, если у z есть один ребенок, то можно вырезать z, соединив его родителя напрямую с
 * его ребенком. Если же детей двое, то требуются некоторые приготовления: мы находим следующий 
 * (в смысле порядка на ключах) за z элемент y; у него нет левого ребенка (всегда). Теперь можно 
 * скопировать ключ и дополнительные данные из вершины y в вершину z, а саму вершину y удалить
 * описанным выше способом */

template<class Player>
TreeNode<Player>* Tree<Player>::delete_node(TreeNode<Player> *z)
{
        TreeNode<Player>* y;
        TreeNode<Player>* x;
        if(z->left == 0 || z->right == 0)               /* в этой и следующих двух строках ищем вершину y, которую мы потом вырежем из дерева. Это либо z, либо следующий за z */
                y=z;
        else
                y=find_succsessor(z->get_data());
        if(y->left!=0)                                  /* x - указатель на существующего ребенка y или 0 если таковых нет */ 
                x=y->left;
        else
                x=y->right;
        if(x!=0)                                        /* эта и следующие 9 строк - вырезание y */ 
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
        if(y!=z)                                        /* если мы вырезали вершин, отличную от z, то ее данные перемещаем в z */
                z->data=y->get_data();
        return y;
}
template<class Player>
TreeNode<Player>* Tree<Player>::find_max(TreeNode<Player>* x)
{
        while(x->right!=0)                              /* здесь все очевидно - самыое максимальное значение у самого правого */
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
        TreeNode<Player>* x=find_node(root,val);                     /* получим указатель на ноду с ключем val */
        TreeNode<Player>* y;
        if(x == 0)
                return 0;
        if(x->right!=0)                                                /* если у нее есть правые дети, то следующий элемент - минимальный в правом поддереве */
                return find_min(x->right);
        y=x->parent;
        while(y!=0 && x == y->right)                                   /* иначе - идем вверх и ищем первый элемент, являющийся левым
потомком своего родителя */
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
