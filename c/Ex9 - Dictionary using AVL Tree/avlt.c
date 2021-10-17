#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct avlnode *position;
typedef struct avlnode *avltree;
typedef   char elementtype;

struct avlnode
{
     elementtype element[20],tamil[20],hindi[20];
	avltree left;
	avltree right;
	int height;

};

void preorder(avltree t)
{
  	if(t!=NULL)
  	{
   		printf("%s ",t->element);
   		preorder(t->left);
   		preorder(t->right);      
  	}
  
}
void postorder(avltree t)
{
	 if(t!=NULL)
 	 {
  			postorder(t->left);
  			postorder(t->right);
  			printf("%s ",t->element);
 	}
}
void inorder(avltree t)
{
  	if(t!=NULL)
 	{
  		inorder(t->left);
   		printf("%s ",t->tamil);
		printf("%s ",t->element);
   		printf("%s \n",t->hindi);
		inorder(t->right);
 	}
}


int height_fun(position p)
{
  if(p==NULL)
	return -1;
   return p->height;
}

int max(int h1,int h2)
{
  if(h1<h2)
    return h2;
  return h1;
}

position singlerotateleft(position k2)
{
	position k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=max(height_fun(k2->left),height_fun(k2->right))+1;
	k1->height=max(height_fun(k1->left),k2->height)+1;
	return k1;
}

position singlerotateright(position k2)
{
	position k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height=max(height_fun(k2->left),height_fun(k2->right))+1;
	k1->height=max(height_fun(k1->right),k2->height)+1;
	return k1;
}

position doublerotateleft(position k3)
{
	k3->left=singlerotateright(k3->left);
	return singlerotateleft(k3);
}

position doublerotateright(position k3)
{
	k3->right=singlerotateleft(k3->right);
	return singlerotateright(k3);
}

avltree insert(elementtype x[],elementtype ele1[],elementtype ele2[],avltree t)
{
	if(t==NULL)
	{
		t=(struct avlnode*)malloc(sizeof(struct avlnode));
		if(t==NULL)
			printf("memory is not allocted \n");
		else
		{
			strcpy(t->element,x);
			strcpy(t->tamil,ele1);
			strcpy(t->hindi,ele2);
			t->height=0;
			t->left=t->right=NULL;
		}
	}
	else if(strcmp(x,t->element)<0)
	{
		t->left=insert(x,ele1,ele2,t->left);
		if(height_fun(t->left)-height_fun(t->right)==2)
			if(strcmp(x,t->left->element)<0)
				t=sing lerotateleft(t);
			else
				t=doublerotateleft(t);
	
	}
	else if(strcmp(x,t->element)>0)
	{
		t->right=insert(x,ele1,ele2,t->right);
		if(height_fun(t->right)-height_fun(t->left)==2)
			if(strcmp(x,t->right->element)>0)
				t=singlerotateright(t);
			else
				t=doublerotateright(t);
	}
	t->height=max(height_fun(t->left),height_fun(t->right))+1;
	return t;
}

avltree search(char x[],avltree t)
{
	if(t==NULL)
	{	printf("is null\n");
    		return NULL;
	}
  	else if((strcmp(x,t->element))<0)
    	{	
		printf("moving left\n");
		search(x,t->left);
		
	} 	
	else if((strcmp(x,t->element))>0)
    	{
		printf("moving right\n");
		search(x,t->right);
		
	}
	else
	return t;

}
int main()
{
	int choice;char element[20],ele1[20],ele2[20];
	avltree head=NULL;
	
	avltree temp;
	while(1)
	{
		printf("\n1 --insert\n2 --inorder\n3 --preorder\n4 --search\nenter choice : ");
			scanf("%d",&choice);
		if(choice==1)
		{
			printf("enter  english word : ");
				scanf("%s",element);
			//printf("enter tamil word :  ");
				scanf("%s",ele1);
			//printf("enter  hindi word : ");
				scanf("%s",ele2);
				
			head=insert(element,ele1,ele2,head);
			//printf("head --%s\n",head->element);
			inorder(head);		
		}
		else if(choice==4)
		{
		printf("enter  english word to search : ");
				scanf("%s",element);
		temp=search(element,head);
		if(temp==NULL)
			printf("element is not found \n");
		else
			printf("tamil meaning %s\tEnglish meaning %s\n",temp->tamil,temp->hindi);
		
			
		}
		else if(choice==2)
		{
			inorder(head);
		}
		else if(choice ==3)
		{
			preorder(head);
		}
		else if(choice==-1)
			break;
	}
}

/*
SAMPLE I/O:
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex9$ gcc avlt.c -o 1
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex9$ ./1

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Algorithm
நெறிமுறை
 कलनविधि
நெறிமு�कलनविधि Algorithm कलनविधि 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Animation
அசைவூட்டம்
 एनीमेशन
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Bit
நுண்மி
बिट
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Browser
உலாவி
ब्राउज़र
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Clipboard
மறைப்பலகை
कर्तन पट्ट
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र@{��|U 
மறைப்ப�कर्तन Clipboard कर्तन 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : enter  english word : Compiler
தொகுப்பி
संकलक
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
Compiler पट्ट தொகுப்பி 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : enter  english word : Digital
எண்மின்
डिजिटल
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
Compiler पट्ट தொகுப்பி 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : enter  english word : Printer
அச்சுப்பொறி
छापनेवाला यंत्र
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : enter  english word : 1
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி�}��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Encoding
குறியாக்கம்
संकेतीकरण
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर Encoding संकेतीकर 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Gateway
நுழைவாயில்
प्रवेशद्वार
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर Encoding संकेतीकर 
நுழைவா�प्रवेशद् Gateway प्रवेशद् 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Hardware
வன்பொருள்
 हार्डवेयर
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर�{��|U Encoding संकेतीकर�{��|U 
நுழைவா�प्रवेशद् Gateway प्रवेशद् 
வன்பொர� हार्डवे� Hardware  हार्डवे� 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1 
enter  english word : Internet
இணையம்
अंतराजाल
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर�{��|U Encoding संकेतीकर�{��|U 
நுழைவா�प्रवेशद् Gateway प्रवेशद् 
வன்பொர� हार्डवे�@~��|U Hardware  हार्डवे�@~��|U 
இணையம் Internet अंतराजाल 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Memory
நினைவகம்
याददाश्त
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर�{��|U Encoding संकेतीकर�{��|U 
நுழைவா�प्रवेशद् Gateway प्रवेशद् 
வன்பொர� हार्डवे�@~��|U Hardware  हार्डवे�@~��|U 
இணையம் Internet अंतराजाल 
நினைவக�याददाश्त Memory याददाश्त 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Monitor
கணித்திரை
मॉनिटर
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर�{��|U Encoding संकेतीकर�{��|U 
நுழைவா�प्रवेशद् Gateway प्रवेशद् 
வன்பொர� हार्डवे�@~��|U Hardware  हार्डवे�@~��|U 
இணையம் Internet अंतराजाल 
நினைவக�याददाश्त Memory याददाश्त 
கணித்த�मॉनिटर Monitor मॉनिटर 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 1
enter  english word : Password
கடவுச்சொல்
 संकेत-शब्द
நெறிமு�कलनविधि Algorithm कलनविधि 
அசைவூட� एनीमेशन Animation  एनीमेशन 
நுண்மி Bit बिट 
உலாவி Browser ब्राउज़र�z��|U 
மறைப்ப�कर्तन Clipboard कर्तन 
குறியா�संकेतीकर�{��|U Encoding संकेतीकर�{��|U 
நுழைவா�प्रवेशद् Gateway प्रवेशद् 
வன்பொர� हार्डवे�@~��|U Hardware  हार्डवे�@~��|U 
இணையம் Internet अंतराजाल 
நினைவக�याददाश्त�~��|U Memory याददाश्त�~��|U 
கணித்த�मॉनिटर Monitor मॉनिटर 
கடவுச்� संकेत-शब Password  संकेत-शब 
यंत्र छापनेव�यंत्र 1 
Printer डिजिटल அச்சுப்ப 
Compiler पट्ट தொகுப்பி }��|U 
Digital संकलक எண்மின் 

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : 4
enter  english word to search : Password
tamil meaning கடவுச்� संकेत-शब	English meaning  संकेत-शब

1 --insert
2 --inorder
3 --preorder
4 --search
enter choice : -1

*/


