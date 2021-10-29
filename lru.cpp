#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* insertAtEnd(Node *head,Node* &tail, int data){
Node *temp=new Node(data);

if(head==NULL){
	head=temp;
	tail=temp;
	return head;
	}
tail->next=temp;
tail=temp;
return head;
}

Node* removePage(Node *head, Node* &tail, int data){
temp=head;

if(head->data==data){
delete temp;
head=head->next;
return head;
}

while(temp->next->data!=data)
	temp=temp->next;

Node* curr=temp->next;
temp->next=curr->next;
if(curr->next==NULL)
	tail=temp;
delete curr;
return head;
}


int searchincache(int cache[][2],int val){
int i = 0;
while(cache[i][1]!=val && i<10){
i++;
	}
if(i==10)	
	return -1;
return i;
}


int searchin(int ram[],int val){
int i = 0;
while(ram[i]!=val && i<100){
	i++;
	}
if(i==100)
	return -1;
return i;		
	}


void read(int cache[][2],int ram[],int val,int& cacheNext){
int cacheInd = searchincache(cache,val);

if(cacheInd==-1){
cout<<"cache miss"<<" searching in ram.... "<<endl;
int ramInd = searchin(ram,val);
	if(ramInd==-1)
		cout<<"Not found in ram"<<endl;
	
	else{   cacheNext = cacheNext %10;
		cache[cacheNext][0]=ramInd;
		cache[cacheNext][1]=ram[ramInd];
		cout<<val<<" found at ram index "<<ramInd<<endl;	
		cacheNext++;		
		}
		

}

else{ 
	cout<<cache[cacheInd][1]<<" cache hit at cache index "<<cacheInd<<" and is at ram index "<<cache[cacheInd][0] <<endl;
	
}



int main(void){

int ram[100], cache[10][2],val;
int cacheNext = 0;
//Initializing the ram
for(int i = 0; i<100;i++)
	ram[i]=100-i;

//Initializing cache
for(int i =0;i<10;i++){
cache[i][0]=-1;
cache[i][1]=-1;
	}
int choice;

do{
	cout<<endl;
cout<<"0: quit    1: read    2: displayRam    3:displayCache"<<endl;
cin>>choice;

if(choice==0){
cout<<"Exiting the program..... "<<endl;
continue;
}

switch(choice){
	case 1:cout<<"What value you want to read?"<<endl;
		cin>>val;	
		read(cache,ram,val,cacheNext);
		break;

	case 2:for(int i =0; i<100;i++){
		cout<<ram[i]<<" ";
		}
		cout<<endl;
		break;
	
	
	case 3:	cout<<"ramInd          value"<<endl;
		for(int i =0;i<10 ;i++){
			cout<<"  "<<cache[i][0]<<"             "<<cache[i][1]<<endl;	
		}
		break;
	default : cout<<"Please enter a valid choice"<<endl;	
	}

}while(choice!=0);


return 0;
	}

