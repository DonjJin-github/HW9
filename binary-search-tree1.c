#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h); //노드를 동적할당하여 초기화 하는 함수

void inorderTraversal(Node* ptr);	  //중위순회트리 함수
void preorderTraversal(Node* ptr);    //전위순회트리 함수
void postorderTraversal(Node* ptr);	  //후위순회트리 함수
int insert(Node* head, int key);  //노드를 트리에 삽입하는 함수
int deleteLeafNode(Node* head, int key);  //리프노드를 삭제하는 함수
Node* searchRecursive(Node* ptr, int key);  //순환법 방식으로 노드를 찾는 함수
Node* searchIterative(Node* head, int key);  //반복법 방식으로 노드를 찾는 함수
int freeBST(Node* head); //메모리를 해제하는 함수

int main()
{
	printf("[----- [최동진]  [2019038016] -----]\n"); 
	char command; //사용자에게 메뉴를 입력받을 변수
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) { //commad의 값에 따라 실행
		case 'z': case 'Z': //command가 z  or Z일때
			initializeBST(&head); //initailizeBST 함수 호출
			break;
		case 'q': case 'Q': //command가 q  or Q일때
			freeBST(head); //freeBST 함수 호출
			break;
		case 'n': case 'N': //command가 n  or N일때
			printf("Your Key = ");
			scanf("%d", &key); //사용자에게 key값을 입력받는다
			insert(head, key); //insert 함수 호출
			break;
		case 'd': case 'D': //command가 d  or D일때
			printf("Your Key = ");
			scanf("%d", &key); //사용자에게 key값을 입력받는다
			deleteLeafNode(head, key); //deleteLeafNode 함수 호출
			break;
		case 'f': case 'F': //command가 f  or F일때
			printf("Your Key = "); 
			scanf("%d", &key); //사용자에게 key값을 입력받는다
			ptr = searchIterative(head, key); //ptr에 searchIterative 함수 호출 후 리턴값 저장
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr); //ptr의 값이 존재하는 경우 출력
			else
				printf("\n Cannot find the node [%d]\n", key); //ptr의 값이 존재하지 않을때
			break;
		case 's': case 'S': //command가 s  or S일때
			printf("Your Key = ");
			scanf("%d", &key); //사용자에게 key값을 입력받는다
			ptr = searchRecursive(head->left, key); //ptr에 searchIterative 함수 호출 후 리턴값 저장
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr); //ptr의 값이 존재하는 경우 출력
			else
				printf("\n Cannot find the node [%d]\n", key); //ptr의 값이 존재하지 않을때
			break;

		case 'i': case 'I': //command가 i or I일때
			inorderTraversal(head->left); //inorderTraversal 함수 호출
			break;
		case 'p': case 'P': //command가 p or P일때
			preorderTraversal(head->left); //preorderTraversal 함수 호출
			break;
		case 't': case 'T': //command가 t or T일때
			postorderTraversal(head->left); //postorderTraversal 함수 호출
			break;
		default: //command가 위의 값들과 다를때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); //command가 q or Q일때 반복문 종료

	return 1;
}

int initializeBST(Node** h) {

	if(*h != NULL) //*h가 NULL이 아니면 메모리 해제
		freeBST(*h);

	*h = (Node*)malloc(sizeof(Node)); //*h를 동적할당한다
	(*h)->left = NULL;	//h의 멤버 구조체 left에 NULL저장
	(*h)->right = *h; //h의 멤버 구조체 right에 *h 저장
	(*h)->key = -9999; //h의 멤버변수 key에 -9999저장
	return 1; //함수종료
}



void inorderTraversal(Node* ptr)
{
	if(ptr) { //재귀호출을 통해 노드를 왼쪽노드->뿌리-> 오른쪽 노드 순으로 출력한다
		inorderTraversal(ptr->left);
		printf(" [%d] ", ptr->key);
		inorderTraversal(ptr->right); 
	}
}

void preorderTraversal(Node* ptr)
{
	if(ptr) { //재귀호출을 통해 노드를 뿌리-> 왼쪽노드 ->오른쪽 노드 순으로 출력한다
		printf(" [%d] ", ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)
{
	if(ptr) {  //재귀호출을 통해 왼쪽 노드 -> 오른쪽 노드 -> 뿌리 순으로 출력한다
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf(" [%d] ", ptr->key);
	}
}


int insert(Node* head, int key)
{
	
}

int deleteLeafNode(Node* head, int key) //리프노드를 삭제하는 함수
{
	
}

Node* searchRecursive(Node* ptr, int key)
{
	
}
Node* searchIterative(Node* head, int key)
{
	
}

void freeNode(Node* ptr)
{
	

int freeBST(Node* head)
{

}





