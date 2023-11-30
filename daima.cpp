#include <iostream>

// 二叉树节点定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 栈节点定义
struct StackNode {
    TreeNode* treeNode;
    StackNode* next;

    StackNode(TreeNode* node) : treeNode(node), next(nullptr) {}
};

// 栈定义
class Stack {
private:
    StackNode* top;

public:
    Stack() : top(nullptr) {}

    // 判断栈是否为空
    bool isEmpty() {
        return top == nullptr;
    }

    // 入栈操作
    void push(TreeNode* treeNode) {
        StackNode* newNode = new StackNode(treeNode);
        newNode->next = top;
        top = newNode;
    }

    // 出栈操作
    TreeNode* pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return nullptr;
        }

        StackNode* temp = top;
        TreeNode* treeNode = temp->treeNode;
        top = top->next;

        delete temp;
        return treeNode;
    }
};

// 非递归中序遍历
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    Stack stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.isEmpty()) {
        // 将左子树所有节点入栈
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // 出栈并访问节点
        current = stack.pop();
        std::cout << current->data << " ";

        // 处理右子树
        current = current->right;
    }
}

// 测试
int main() {
    // 构建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 非递归中序遍历
    std::cout << "Inorder Traversal: ";
    inOrderTraversal(root);

    // 释放内存
    // 这里只是为了示例，实际应用中可能需要更复杂的内存管理
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
