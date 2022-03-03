#include <stdlib.h>
#include <math.h>
#define size 16

//int a[10], b[10];

//Use array tree

struct point{
    int x,y;
}c[size];

struct point d[size];

int firstX, lastX, firstY, lastY;//use the tree, take number of elements to be cut get it in factors of 2. Move to the level number determined by factors.

void sortx(){
    for(int i=0;a[i+1]!='/0';i++){
        for(int j=1;a[j+i+1]!='/0';j++){
            if(a[j]<a[i]){
                a[j]+=a[i];
                a[i]=a[j]-a[i];
                a[j]-=a[i];
            }
        }
    }
}

void sorty(){
    for(int i=0;a[i+1]!='/0';i++){
        for(int j=1;a[j+i+1]!='/0';j++){
            if(a[j]<a[i]){
                a[j]+=a[i];
                a[i]=a[j]-a[i];
                a[j]-=a[i];
            }
        }
    }
}


int split(int a[]){
int n, length=0;
for(int i=0;a[i]!='\0';i++)
length++;
if(length%2==0)
n=length/2;
else
n=length+1/2;
return a[n];
}

struct position{
    int index;
    struct position *l, *r, *parent;
    char cutDirection;
};
struct position *root=NULL;

int searchYIndex(int x){
    int index;
    for(int i=0;i<size;i++){
        if(c[i].x==x)
        index=i;
    }
    return index;
}

int searchXIndex(int y){
    int index;
    for(int i=0;i<size;i++){
        //no two point should have the same x or y
        if(c[i].y==y)
        index=i;
    }
    return index;
}

int a[1024];

int updatePoint(int starty, int endy, int startx, int endx, int key){
    int flag=0, prog=0;
    for(int i=0; i<size; i++){
        if(c[i].x>startx && c[i].x<endx && c[i].y>starty && c[i].y<endx){
            if(key==0)
            a[prog++]=c[i].x;
            else
            a[prog++]=c[i].y;
        }
    }
    if(key==0)
    sortx();
    else
    sorty();
    return a[prog/2];
}

void init(){
    for(int i=0;a[i]!='/0';i++){
        a[i]='/0';
    }
}

int tree[1024];

int main(){
    printf("Enter the points in ascending order of x\n");
    for(int i=0;i<size;i++){
        scanf("%d%d",&c[i].x, &c[i].y);
        //a[i]=c[i].x;
        d[i].x=c[i].x;
        d[i].y=c[i].y;
    }
    /*int count=0;
    int div=1;
    int sizing=size;
    for(int i=1;i<=size;i*=2){
        int start=0;
        int last=i;
            for(int j=1;j<=i;j++){
                struct position *temp=(struct position*)malloc(sizeof(struct position)); 
                if(div%2!=0){
                if(root==NULL){
                    temp->parent=NULL;
                    temp->index=sizing/2;
                    temp->l=temp->r=NULL;
                    root=temp;
                }
                else{//y-axis is not aligned
                }
            }
        }
    }
*/
int pro=0;
for(int i=0; i<size/2; i=i*2+1){
    //int sizing;
    for(int j=0; j<=i; j++){
        if(i%2==0){
            if(tree[0]=='/0'){
                tree[pro++]=d[size/2].x;
               //d[size/2].x = d[size/2].y = '/0';
            }
            else{
                int starty, startx, endy, endx;
                int key=0;
                double parentF=(pro-1)/2;
                int parentI = floor(parentF);
                double godParentF = (parentI-1)/2;
                int godParentI = floor(godParentF); 
                if(parentI==parentF){
                    if(godParentI==godParentF){
                        tree[pro++]=updatePoint(0, tree[parentI], 0, tree[godParentI], 0);
                        init();
                    }
                    else{
                        tree[pro++]=updatePoint(0, tree[parentI], tree[godParentI], tree[godParentI+1], 0);
                        init();
                    }
                }
                else{
                    if(godParentI==godParentF){
                        tree[pro++]=updatePoint(tree[parentI], tree[parentI+1], 0, tree[godParentI], 0);
                        init();
                    }
                    else{
                        tree[pro++]=updatePoint(tree[parentI], tree[parentI++], tree[godParentI], tree[godParentI+1], 0);
                        init();
                    }
                }
            }
        }
        else{
            if(tree[1]=='/0'||tree[2]=='/0')
            {
                int starty, startx, endy, endx;
                int key=0;
                double parentF=(pro-1)/2;
                int parentI = floor(parentF); 
                if(parentF==parentI){
                    tree[pro++]=updatePoint(0, INT16_MAX, 0, tree[parentI], 1);
                    init();
                }
                else{
                    tree[pro++]=updatePoint(0, INT16_MAX, tree[parentI], tree[parentI+1], 1);
                    init();
                }              
            }
            else{
                int starty, startx, endy, endx;
                int key=0;
                double parentF=(pro-1)/2;
                int parentI = floor(parentF);
                double godParentF = (parentI-1)/2;
                int godParentI = floor(godParentF); 
                if(parentI==parentF){
                    if(godParentI==godParentF){
                        tree[pro++]=updatePoint(0, tree[godParentI], 0, tree[parentI], 0);
                        init();
                    }
                    else{
                        tree[pro++]=updatePoint(0, tree[godParentI], tree[parentI], tree[parentI+1], 0);
                        init();
                    }
                }
                else{
                    if(godParentI==godParentF){
                        tree[pro++]=updatePoint(tree[godParentI], tree[godParentI+1], 0, tree[parentI], 0);
                        init();
                    }
                    else{
                        tree[pro++]=updatePoint(tree[godParentI], tree[godParentI++], tree[parentI], tree[parentI+1], 0);
                        init();
                    }
                }
            }
            
        }
    }
}

}