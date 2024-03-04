#include <iostream>
#include <queue>


class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

    TreeNode (int val)
  {
	data = val;
	left = right = NULL;
  }

};

void levelOrderTraversal (TreeNode * root) {

  std::queue < TreeNode * > queue;
  queue.push(root);

  while (!queue.empty()){

	  std::cout << queue.front()->data << " ";
	  

	  if (queue.front()->left != NULL)
		queue.push (queue.front()->left);
	  if (queue.front()->right != NULL)
		queue.push (queue.front()->right);
		
	queue.pop();
	}
}

void printTree(TreeNode * root, int level){

    if(root->right != NULL) printTree(root->right, level+1);
    for(int i = 0; i < level; i++) std::cout<<"  ";
    std::cout<<"-"<<root->data<<std::endl;
    if(root->left != NULL) printTree(root->left, level+1);

}

int main ()
{

  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(2);
  TreeNode *c = new TreeNode(3);
  TreeNode *d = new TreeNode(4);
  TreeNode *e = new TreeNode(5);
  TreeNode *f = new TreeNode(6);
  TreeNode *g = new TreeNode(7);
  TreeNode *h = new TreeNode(8);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  d->left = h;
  c->left = f;
  c->right = g;

  std::cout<<"This is the tree\n";
  printTree(a, 0);
  std::cout << "\n";

  std::cout << "tree traversal bfs - level order traversal\n";
  levelOrderTraversal(a);
  std::cout << "\npress any key to continue";
  std::cin.get();

  return 0;
}
