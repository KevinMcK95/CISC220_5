union Data {
	int i;
	int* iP;
	float f;
	float* fP;
	char c;
	char* cP;
};

struct Node{
	union Data data;
	struct Node* next;
	struct Node* previous;
};

typedef struct Node Node;

void insert(int index, union Data data);

void removes(int index);

union Data get(int index);

int length();


