struct node
{
	char val;
	int height;
	node *lchild,*rchild;
};
int Max(int a,int b);
node* new_Node(char val);
int get_Height(node* root);
int get_BF(node* root);
void update_Height(node* &root);
void L(node* &root);
void R(node &root);
void insert(node* &root,int val);
node* Create_AVL(char data[],int n);
