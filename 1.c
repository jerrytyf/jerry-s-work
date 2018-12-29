//迷宫路径
#include <stdio.h>
struct h
{
    int nx;
    int ny;
};
int u=0;
int intr=0;
struct h r[201];
int t=1;
//int u;
int tx=0,ty=0,k;
int lx,ly;
int n,m,p,q,min=9999999;
int a[201][201],book[201][201];
int direction[4][2]={ {1,0},
    {0,1},
    {-1,0},
    {0,-1}};
void dfs(int x,int y,int quantity)
{
    
    u++;
    /*  if(u>n*m)
     {
     intr=1;
     return;
     }*/
    if(x==p&&y==q )
    {
        if(quantity<min)
            min=quantity;
        intr=0;
        return ;
    }
    for(k=0;k<=3;k++)
    {
        tx=x+direction[k][0];
        ty=y+direction[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)
            continue;
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            book[tx][ty]=1;
            //     nxy[t].lp[1][1]=book[tx][ty];
            r[t].nx=tx;
            r[t].ny=ty;
            t++;
            dfs(tx,ty,quantity+1);
            book[tx][ty]=0;
            //  if(intr==1)
        }
    }
    return;
    
}
int main()
{
    printf("******************\n");
    printf("欢迎使用计算最短路径系统\n");
    printf("******************\n");
    printf("输入第一行：迷宫的行数和列数\n");
    printf("接下来输入：输入迷宫，0表示空地、1表示障碍物\n");
    printf("最后输入：迷宫入口的x坐标、y坐标、出口x坐标、y坐标\n");
    int i,j,kaishix,kaishiy;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&kaishix,&kaishiy,&p,&q);
    if(a[kaishix][kaishiy]==0 &&a[p][q]==0)
    {
        book[kaishix][kaishiy]=1;
        dfs(kaishix,kaishiy,0);
        // if(lx!=p || ly!=q)
        //    intr=1;
        if(intr==1)    printf("不能走出迷宫！\n");
        else
        {
            printf("可以走出迷宫！\n");
            printf("加上出口，步数如下：%d\n",min+1);
            printf("不加出口，步数如下：%d\n",min);
            printf("路线如下：\n");
            for(i=1;i<=min;i++)
            {
                printf("(%d",r[i].nx);
                printf("%d),",r[i].ny);
                printf("\n");
            }
        }
    }
    else {printf("输入的格式不对！\n");
        printf("起始点和重点都应该为0，否则无法运行程序");}
    
    return 0;
}
