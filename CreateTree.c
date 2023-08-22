#define _CRT_SECURE_NO_WARNINGS

/*
链接：https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
来源：牛客网（原题：清华大学考研复试题：二叉树遍历）

编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

输入描述:
输入包括1行字符串，长度不超过100。


输出描述:
可能有多组测试数据，对于每组数据，
输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
每个输出结果占一行。
示例1
输入
abc##de#g##f###
输出
c b e g d f a
*/



#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}TNode;


TNode* CreateTree(char* a, int* pi) {
	if (a[*pi] == '#') {
		(*pi)++;
		return NULL;
	}

	TNode* root = (TNode*)malloc(sizeof(TNode));
	root->val = a[*pi];
	(*pi)++;

	root->left = CreateTree(a, pi);
	root->right = CreateTree(a, pi);

	return root;
}

void InOrder(TNode* root) {
	if (root == NULL) return;

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main() {
	char str[100];
	printf("请输入：");
	scanf("%s", str);

	int i = 0;
	TNode* root = CreateTree(str, &i);

	InOrder(root);

	return 0;
}