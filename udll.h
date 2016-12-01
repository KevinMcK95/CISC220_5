union Data {
	int i; //type is 0
	int* iP; //type is 1
	float f; //type is 2
	float* fP; //type is 3
	char c; //type is 4
	char* cP; //type is 5
};

struct Node{
	union Data data;
//	int type; //0=int, 1=intPtr, 2=float, 3=floatPtr, 4=char, 5=charPtr
	struct Node* next;
	struct Node* previous;
};

typedef struct Node Node;

Node head;
Node last;


void insert(int index, union Data data);

void removes(int index);

union Data get(int index);

int length();


