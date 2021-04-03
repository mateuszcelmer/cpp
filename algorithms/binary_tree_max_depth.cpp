#include <iostream>
#include <memory>

using namespace std;

struct Node
{
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};

int maxDepth(std::shared_ptr<Node> nodePtr)
{
    int depth{0};
    if (!nodePtr->left && !nodePtr->right)
    {
        return depth;
    }

    int leftDepth{0}, rightDepth{0};
    if (nodePtr->left)
    {
        leftDepth = maxDepth(nodePtr->left);
    }

    if (nodePtr->right)
    {
        rightDepth = maxDepth(nodePtr->right);
    }

    return std::max(leftDepth, rightDepth) + 1;
}

int main()
{
    auto n1 = std::make_shared<Node>();
    n1->left = std::make_shared<Node>();
    n1->right = std::make_shared<Node>();
    n1->left->left = std::make_shared<Node>();
    n1->left->right = std::make_shared<Node>();
    n1->left->right->right = std::make_shared<Node>();

    std::cout << maxDepth(n1) << std::endl;

    return 0;
}