#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int id,sets,area,group,height;
	struct _Node *left,*right;
} Node;

int MAX(int a,int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int HEIGHT(Node *root) {
	if (root == NULL) {
		return 0;
	} else {
		return root->height;
	}
}

Node* ll(Node *root) {
	Node *p;

	p = root->left;
	root->left = p->right;
	p->right = root;

	root->height = MAX( HEIGHT(root->left), HEIGHT(root->right)) + 1;
	p->height = MAX( HEIGHT(p->left), root->height) + 1;

	return p;
}

Node* rr(Node *root) {
	Node *p;

	p = root->right;
	root->right = p->left;
	p->left = root;

	root->height = MAX( HEIGHT(root->left), HEIGHT(root->right)) + 1;
	p->height = MAX( HEIGHT(p->right), root->height) + 1;

	return p;
}

Node* lr(Node *root) {
	root->left = rr(root->left);

	return ll(root);
}

Node* rl(Node *root) {
	root->right = ll(root->right);

	return rr(root);
}

Node* add(Node* root,int x) {
	if (root) {
		if (x < root->id) {
			root->left = add(root->left,x);
			if (HEIGHT(root->left) - HEIGHT(root->right) == 2) {
				if (x < root->left->id)
					root = ll(root);
				else
					root = lr(root);
			}
		} else if (x > root->id) {
			root->right = add(root->right,x);
			if (HEIGHT(root->right) - HEIGHT(root->left) == 2) {
				if (x < root->right->id)
					root = rl(root);
				else
					root = rr(root);
			}
		}
	} else {
		root = (Node*)malloc(sizeof(Node));
		root->id = x;
		root->left = NULL;
		root->right = NULL;
	}
	root->height = MAX(HEIGHT(root->left),HEIGHT(root->right))+1;
	return root;
}

//Node* findmax(Node *root) {
//	Node *p = NULL;
//	if (root) {
//		if (root->right) {
//			p = findmax(root->right);
//		} else {
//			p = root;
//		}
//	}
//	return p;
//}

Node* findmax(Node *root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

Node* findmin(Node *root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* delet(Node* root,int x) {
	Node *min,*max;
	if (root) {
		if (x < root->id) {
			root = delet(root->left,x);
			if (HEIGHT(root->right) - HEIGHT(root->left) == 2) {
				Node *r =  root->right;
				if (HEIGHT(r->left) > HEIGHT(r->right))
					root = rl(root);
				else
					root = rr(root);
			}
		} else if (x > root->id) {
			root = delet(root->right,x);
			if (HEIGHT(root->right) - HEIGHT(root->left) == -2) {
				Node *r =  root->left;
				if (HEIGHT(r->left) > HEIGHT(r->right))
					root = ll(root);
				else
					root = lr(root);
			}
		} else {
			if ((root->left) && (root->right)) {
				if (HEIGHT(root->left) > HEIGHT(root->right)) {
					max = findmax(root->left);
					root->id = max->id;
					root->left = delet(root->left,max->id);
				} else {
					min = findmin(root->left);
					root->id = min->id;
					root->left = delet(root->left,min->id);
				}
			} else {
				Node *tmp = root;
				root = root->left ? root->left : root->right;
				free(tmp);
			}
		}
	}
	return root;
}

int main(void) {
	int i,x,n;
	Node *root = NULL;

	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&x);
		root = add(root,x);
	}

	return 0;
}
