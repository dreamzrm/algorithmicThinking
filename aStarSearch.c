#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int n;
char start, end;


struct connection{
    char nextPosition;
    int distance;
    /*
    bool isStart;
    bool isEnd;
    */
};
bool hasConnection(int distance){
    if(distance!='\0'||distance!=0){
        return true;
    }
    return false;
}

struct priority{
    char position;
    int length;
    struct priority *next;
};
int intCurrentNode(char currentNode, char a[]){
    for(int i=0;i<n;i++){
        if(a[i]==currentNode)
        return i;
    }
}

char isClosest(struct priority *root){
    int max=-1;
    char node;
    struct priority *temp=root;
    while(temp!=NULL){
        if(temp->length>max){
            max=temp->length;
            node=temp->position;
            temp=temp->next;
        }
    }
    return node;
}

int main(){ 
    int found=0;
    scanf("%d", &n);
    char a[n];
    int distanceFromEnd[n];
    for(int i=0;i<n;i++){
        scanf("%c", &a[i]);
    }
    struct connection b[n][n];
    for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
        printf("Enter the connection for %c. The second position and distance between them", a[j]);
        scanf("%c%d",  &b[j][i].nextPosition, &b[j][i].distance);
        /*printf("Is it the starting point or the end point?");
        bool yes, no;
        scanf("%s%s", &yes, &no);
        b[i].isStart=yes;
        b[i].isEnd=no;
*/
    }
    }
    for(int i=0;i<n;i++){
        printf("Enter the distance from the end for node %c", a[i]);
        scanf("%d", distanceFromEnd[i]);
    }
    //pritnf("%c%c%d", b[1].firstPosition, b[1].nextPosition, b[1].distance);
    //char start, end;
/*for(int i=0;i<n;i++){
    if(b[i].isStart==true){
        start=a[i];
    }
    else if(b[i].isEnd==true){
        end=a[i];
    }
}
int j=0;
for(j=0;j<n;j++){
    if(start==a[j])
    break;    
}*/
struct priority *root=NULL;
struct priority *temp;
temp= (struct priority*)malloc(sizeof(struct priority));
temp->position=a[0];
temp->length=b[0][n-1].distance;
temp->next=NULL;
root=temp;
char path[n];
path[0]=a[0];
int counter=1;
while(found==0){
    //priorityQueue
    char currentNode= isClosest(root);
    int currentNodeInt = intCurrentNode(currentNode,a);
    for(int i=0; i<n; i++){
        if(currentNode==a[n-1]){
            path[counter]=currentNode;
            printf("The path is : ");
            for(int j=0;j++;j<counter){
                if(j==counter-1)
                    printf("%c", path[j]);
                else
                    printf("%c->", path[j]);
            }
            exit(0);
        }
        else if(b[currentNodeInt][i].distance!=0){
            int length= b[currentNodeInt][i].distance + distanceFromEnd[i];
            struct priority *t = (struct priority*)malloc(sizeof(struct priority));
            t->position=a[i];
            t->length=length;
            struct priority *traverse=root;
            while(traverse->next!=NULL)
            traverse = traverse->next;
            traverse->next=t;
        }
    }//end of for
    struct priority *traverse;
    while(traverse->position!=temp->position)
    traverse=traverse->next;
    traverse->next=temp->next;
    temp->next=NULL;
    free(temp);
    path[counter++]=a[currentNodeInt];
}//end of while


}//end of main
