//深度优先搜索模板

#include <stdio.h>
int tdi;
struct note
{
    int x;
    int y;
    int f;
    int s;
};
struct sg{
    int xs;
    int ys;
};
struct sg o[2501];
int top;
struct note que[2501];
int top=0;
int main()
{
    int a[51][51]={0},book[51][51]={0};
    int netx[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
        
    };
    int head,tail;
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&startx,&starty,&p,&q);
    head=1;
    tail=1;
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].s=0;
    tail++;
    que[tail].f=0;
    book[startx][starty]=1;
    flag=0;
    while(head<tail)
    {
      //  printf("1");
        for(k=0;k<=3;k++)
       {
            tx=que[head].x+netx[k][0];
              ty=que[head].y+netx[k][1];
        
             if(tx<1 ||tx>n || ty<1 || ty>m)
                 continue;
             if(a[tx][ty]==0&&book[tx][ty]==0)
             {
                 book[tx][ty]=1;
                 que[tail].x=tx;
               //  o[top].xs=tx;
             //    o[top].ys=ty;
            //     top++;
                 que[tail].y=ty;
                 que[tail].f=head;
                 printf("%d",que[tail].x);
                 printf("%d\n",que[tail].y);
                 que[tail].s=que[head].s+1;
                 tail++;
             }
           if(tx==p&&ty==q)
           {
            flag=1;
            break;
           }
      }
        if(flag==1)
            break;
   //     o[top].xs=que[head].x;
    //    o[top].ys=que[head].y;
     //   top++;
       
        head++;
    }
    printf("%d",que[tail-1].s);
    printf("\n");
    printf("%d",tdi);
  // for(i=0;i<que[tail-1].s;i++)
   //     printf("(%d)",que[i].f);
    return 0;
}
