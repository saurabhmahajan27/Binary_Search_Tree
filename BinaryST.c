/*write a program to perform following operations on binary tree
1.create
2.display(preorder,inorder,postorder)
3.search
4.delete
*/
#include<stdio.h>
#include<stdlib.h>
int data;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *create(int data)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
struct node *insert(struct node *root,int data)
{
		if(root==NULL)
		{
			return create(data);
		}
		else if(data>root->data)
		{
			root->right=insert(root->right,data);
		}
		else
		{
			root->left=insert(root->left,data);
		}
		return root;
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
int search(struct node *root,int data)
{
	
	
	if(root==NULL)
	{
		printf("Invalid\n");
	}	
	else if(root->data==data)
	{
		printf("\nVALUE FOUND\n");
	}
	else if(data>root->data)
	{
		search(root->right,data);
	}
	else
	{
		search(root->left,data);
	}
}
struct node *minimum(struct node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->left!=NULL)
	{
		return minimum(root->left);
	}
	return root;
}
struct node *delete(struct node *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data>root->data)
	{
		root->right=delete(root->right,data);
	}
	else if(data<root->data)
	{
		root->left=delete(root->left,data);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)//deleting a node having no child
		{
			free(root);
			root=NULL;
			printf("\nDELETED\n");

		}
		else if(root->left==NULL)// deleting a node having one child
		{
			struct node *temp=root;
			root=temp->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			struct node *temp=root;
			root=temp->left;
			free(temp);
		}
		else
		{
			struct node *temp=minimum(root->right);//deleting a node having 2 childrens
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
}
			
			
void display(struct node *root)
{
	int ch1;
	do
	{
		printf("\n***Enter your choice***\n1.preorder\n2.inorder\n3.postorder\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1:preorder(root);
				break;
			case 2:inorder(root);	
				break;
			case 3:postorder(root);
				break;
			default:printf("Invalid");
		}
	}while(ch1!=4);
}
int main()
{

	struct node *root=NULL;
	int ch2,data,n,i;
	do
	{
		

		printf("\n***Enter your choice***\n1:create\n2.display\n3.search\n4.delete\n");
		scanf("%d",&ch2);
		switch(ch2)
		{
			case 1:	
				printf("Enter total number of elements: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("enter data: ");	
					scanf("%d",&data);
					root=insert(root,data);
				}
				break;
			case 2:display(root);
				break;
			case 3:	printf("Enter element you want to search: ");
				scanf("%d",&data);
				search(root,data);
				break;
			case 4:printf("Enter element you want to delete: ");
				scanf("%d",&data);
				delete(root,data);
				break;
			default:printf("Error");
		}
	}while(ch2!=5);
}
/* OUTPUT
***Enter your choice***
1:create
2.display
3.search
4.delete
1
Enter total number of elements: 5
enter data: 40
enter data: 20
enter data: 50
enter data: 10
enter data: 80

***Enter your choice***
1:create
2.display
3.search
4.delete
2

***Enter your choice***
1.preorder
2.inorder
3.postorder
1
40	20	10	50	80	
***Enter your choice***
1.preorder
2.inorder
3.postorder

2
10	20	40	50	80	
***Enter your choice***
1.preorder
2.inorder
3.postorder

3
10	20	80	50	40	
***Enter your choice***
1.preorder
2.inorder
3.postorder

4
Invalid
***Enter your choice***
1:create
2.display
3.search
4.delete
3
Enter element you want to search: 20

VALUE FOUND

***Enter your choice***
1:create
2.display
3.search
4.delete
4
Enter element you want to delete: 80

DELETED

***Enter your choice***
1:create
2.display
3.search
4.delete
2

***Enter your choice***
1.preorder
2.inorder
3.postorder
1
40	20	10	50	
***Enter your choice***
1.preorder
2.inorder
3.postorder
2
10	20	40	50	
***Enter your choice***
1.preorder
2.inorder
3.postorder
3
10	20	50	40	
***Enter your choice***
1.preorder
2.inorder
3.postorder

*/
