#ifndef _NODE_H
#define _NODE_H

template <class Player> class TreeNode
{
        friend class Tree<Player>;
    public:
        TreeNode(const Player &);
        Player get_data();
    protected:
        TreeNode* left;           /* указатель на левого ребенка */
        TreeNode* right;          /* указатель на правого ребенка */
        TreeNode* parent;         /* указатель на родителя */
        Player data;            /* ключ */
};

template<class Player>
TreeNode <Player>::TreeNode(const Player &a)
{
        data=a;
        left=right=0;
}
template <class Player>
Player TreeNode <Player>::get_data()
{
        return data;
}
#endif