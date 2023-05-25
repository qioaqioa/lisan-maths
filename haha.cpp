#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<queue>
#include<algorithm>
#include<string.h>
#define endl '\n'
using namespace std;
/*
主要任务：
使用简单代码实现简单无向图各顶点度的计算(邻接矩阵)
同时验证握手定则
并验证奇度顶点的个数一定是偶数
*/
// int nm[100][100];   //邻接矩阵
// int ret[100];       //结果
int main()
{
    int n;          //顶点的数量
    int m;          //边的数量
    cout<<"Please input the numbers of vertex and edge apart:"<<endl;
    cin>>n>>m;
    cout<<endl;
    
    int **nm=new int*[n];
    for(int i=0;i<n;++i)
    {
        nm[i]=new int[n];
        memset(nm[i],0,n*sizeof(int));
    }
    int *ret=new int[n];

    if(nm==NULL || ret==NULL) exit(1);

    memset(ret,0,n*sizeof(int));

    int bg,ed;
    int sum=0,sum1=0;      //图的度数,奇度顶点的个数

    cout<<"Please input two integers represent the two endpoints of an edge:"<<endl;
    cout<<"(from zero)"<<endl<<endl;

    //输入相连的顶点
    for(int i=0;i<m;++i)
    {
        cin>>bg>>ed;
        nm[bg][ed]=1;
        nm[ed][bg]=1;
    }
    cout<<endl;
    //计算各个顶点的度
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            ret[i]+=nm[i][j];
            sum+=nm[i][j];                                              //计算该图的度
        }
        if(ret[i]%2==1)++sum1;                                          //计算奇度顶点的个数 
    }
    //输入要查询的点
    cout<<"Input the vertex which you want to index ( end with -1 ):"<<endl;
    int index;
    while((cin>>index)&&(index!=-1))
    {
        cout<<"The degree of vertices with ordinal "<<index<<" :"<<ret[index]<<endl;
    }
    cout<<endl;


    cout<<"Number of Singularity Vertices :"<<sum1<<endl<<endl;         //输出奇度顶点的个数

    cout<<"Sum of the degrees :"<<sum<<endl;                            //输出该图的度

    if(sum==2*m)cout<<"Handshake lemma holds"<<endl;                    //验证握手定则
    else cout<<"Input Wrong!"<<endl;

    for(int i=0;i<n;++i)
    {
        delete[] nm[i];
        nm[i]=NULL;
    }
    delete[] nm;
    delete[] ret;
    nm=NULL;
    ret=NULL;

    system("pause");
    return 0;
}