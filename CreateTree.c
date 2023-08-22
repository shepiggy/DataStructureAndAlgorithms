#define _CRT_SECURE_NO_WARNINGS

/*
���ӣ�https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
��Դ��ţ������ԭ�⣺�廪��ѧ���и����⣺������������

��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������

��������:
�������1���ַ��������Ȳ�����100��


�������:
�����ж���������ݣ�����ÿ�����ݣ�
����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
ÿ��������ռһ�С�
ʾ��1
����
abc##de#g##f###
���
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
	printf("�����룺");
	scanf("%s", str);

	int i = 0;
	TNode* root = CreateTree(str, &i);

	InOrder(root);

	return 0;
}