#include <iostream>
using namespace std;
const int MAX_NODES = 1001; // Giới hạn tối đa số node
// Cấu trúc dữ liệu của node
struct TreeNode {
    int val;
    TreeNode* left;  // Con trái
    TreeNode* right; // Con phải
};
// Mảng lưu trữ các node
TreeNode nodes[MAX_NODES];
bool has_parent[MAX_NODES] = {false}; // Đánh dấu node nào có cha
// Tìm root của cây (node không có cha)
TreeNode* findRoot(int N) {
    for (int i = 1; i <= N; i++) {
        if (!has_parent[i]) {
            return &nodes[i];
        }
    }
    return nullptr;
}
// Hàm tính chiều cao của cây
int calculateHeight(TreeNode* root) {
    if (!root) return 0;
    int left_height = calculateHeight(root->left);
    int right_height = calculateHeight(root->right);
    return max(left_height, right_height) + 1;
}
// Duyệt Preorder
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
// Duyệt Postorder
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
// Kiểm tra cây có phải cây nhị phân không
bool isBinaryTree(int N) {
    for (int i = 1; i <= N; i++) {
        int child_count = 0;
        if (nodes[i].left) child_count++;
        if (nodes[i].right) child_count++;
        if (child_count > 2) return false; // Nếu có nhiều hơn 2 con, không phải cây nhị phân
    }
    return true;
}
// Duyệt Inorder
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    int N, M;
    cin >> N >> M;
    // Khởi tạo các node
    for (int i = 1; i <= N; i++) {
        nodes[i].val = i;
        nodes[i].left = nullptr;
        nodes[i].right = nullptr;
    }
    // Đọc dữ liệu cạnh và xây dựng cây
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        // Gán con trái hoặc phải tùy theo vị trí trống
        if (nodes[u].left == nullptr) {
            nodes[u].left = &nodes[v];
        } else {
            nodes[u].right = &nodes[v];
        }
        has_parent[v] = true; // Đánh dấu v có cha
    }
    // Tìm root của cây
    TreeNode* root = findRoot(N);
    if (!root) {
        cout << "Invalid tree input!" << endl;
        return 0;
    }
    // Tính chiều cao của cây
    cout << calculateHeight(root) - 1 << endl;
    // Duyệt Preorder
    preorder(root);
    cout << endl;
    // Duyệt Postorder
    postorder(root);
    cout << endl;
    // Kiểm tra cây nhị phân và duyệt Inorder nếu đúng
    if (isBinaryTree(N)) {
        inorder(root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
    return 0;
}
