#ifndef _NODE_H
#define _NODE_H

template <class Player> class TreeNode
{
        friend class Tree<Player>;
    public:
        TreeNode(const Player &);
        Player get_data();
    protected:
        TreeNode* left;           /* ��������� �� ������ ������� */
        TreeNode* right;          /* ��������� �� ������� ������� */
        TreeNode* parent;         /* ��������� �� �������� */
        Player data;            /* ���� */
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