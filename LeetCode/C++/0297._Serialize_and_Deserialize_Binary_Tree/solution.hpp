#include <sstream>
using std::istringstream;
using std::ostringstream;

using std::string;
using std::stoi;
#include "../data_structures.hpp"

class Codec {
    public:
        string serialize(TreeNode* root) {
            ostringstream out;
            serialize(root, out);
            return out.str();
        }

        TreeNode* deserialize(string data) {
            istringstream in(data);
            return deserialize(in);
        }
    private:
        void serialize(TreeNode* root, ostringstream &out) {
            if (!root) {
                out << "# ";
                return ;
            }
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }

        TreeNode* deserialize(istringstream &in) {
            string s;
            in >> s;
            if (s == "#") return nullptr;
            TreeNode *root = new TreeNode(stoi(s));
            root->left = deserialize(in);
            root->right = deserialize(in);
            return root;
        }
};
