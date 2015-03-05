#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

int r1=0,r2=0;
int x[4][4]={0};
int x1[4][4]={0};
int score=0;

void out()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<x[i][j]<<"\t";
        cout<<endl;
    }
}

void start()
{
    int num=0;
    int t[4][4]={0};
    srand(time(NULL)%100);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(x[i][j]==0)
            {
                num++;
                t[i][j]=num;
            }
        }
    }
    r1=rand()%num+1;
    r2=rand()%8;
///
    for(int a=0;a<4;a++)
    {
        for(int j=0;j<4;j++)
        {
            if(t[a][j]==r1)
            {
                if(r2==0){x[a][j]=4;break;}
                if(r2!=0){x[a][j]=2;break;}
            }
        }
    }
}

void check()
{
    int f=1;//0通过 1结束 2胜利
    for(int i=0;i<16;i++)
    {
        if(x[i/4][i%4]==2048)
        {
            cout<<"You Win!"<<endl;
            f=2;
            break;
        }
    }
    if(f==1)
    for(int i=0;i<9;i++)
    {
        if(x[i/3][i%3]==x[i/3][i%3+1] ||x[i/3][i%3]==x[i/3+1][i%3])
        {f=0;break;}
        if(x[3][i%3]==x[3][i%3+1] || x[i/3][3]==x[i/3+1][3])
        {f=0;break;}
    }
    if(f==1)
    {
        for(int i=0;i<16;i++)
            if(x[i/4][i%4]==0)
            {f=0;break;}
    }
    if(f==1)cout<<"Game Over"<<endl;
    out();
    cout<<"score:"<<score<<endl;
    if(f==1 || f==2)system("pause");
}

void in()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            x1[i][j]=x[i][j];
}

int compare()
{
    int f=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(x[i][j]!=x1[i][j])
            {
                f=1;
                break;
            }
    return f;
}
//
void move(int way)
{
    if(way==1)//right 
    {
        for(int i=0;i<4;i++)
        for(int m=0;m<3;m++)
            for(int j=3;j>0;j--)
            {
                if(x[i][j]==0)
                {
                    for(int k=j;k>0;k--)
                        x[i][k]=x[i][k-1];
                    x[i][0]=0;
                }
            }
        for(int a=0;a<4;a++)
        {
            for(int j=3;j>0;j--)
            {
                if(x[a][j]==x[a][j-1])
                {
                    x[a][j]=x[a][j]+x[a][j-1];
                    score+=x[a][j];
                    for(int k=j-1;k>0;k--)
                        x[a][k]=x[a][k-1];
                    x[a][0]=0;
                }
            }
        } 
    }
/////////////////////////////
    if(way==2)//down 
    {
        for(int i=0;i<4;i++)
        for(int m=0;m<3;m++)
            for(int j=3;j>0;j--)
            {
                if(x[j][i]==0)
                {
                    for(int k=j;k>0;k--)
                        x[k][i]=x[k-1][i];
                    x[0][i]=0;
                }
            }
        for(int a=0;a<4;a++)
        {
            for(int j=3;j>0;j--)
            {
                if(x[j][a]==x[j-1][a])
                {
                    x[j][a]=x[j][a]+x[j-1][a];
                    score+=x[j][a];
                    for(int k=j-1;k>0;k--)
                        x[k][a]=x[k-1][a];
                    x[0][a]=0;
                }
            }
        } 
    }
////////////////////////
    if(way==3)//left
    {
        for(int i=0;i<4;i++)
        for(int m=0;m<3;m++)
            for(int j=0;j<3;j++)
            {
                if(x[i][j]==0)
                {
                    for(int k=j;k<3;k++)
                        x[i][k]=x[i][k+1];
                    x[i][3]=0;
                }
            }
        for(int a=0;a<4;a++)
        {
            for(int j=0;j<3;j++)
            {
                if(x[a][j]==x[a][j+1])
                {
                    x[a][j]=x[a][j]+x[a][j+1];
                    score+=x[a][j];
                    for(int k=j+1;k<3;k++)
                        x[a][k]=x[a][k+1];
                    x[a][3]=0;
                }
            }
        } 
    }
////////////////////////
    if(way==4)//up
    {
        for(int i=0;i<4;i++)
        for(int m=0;m<3;m++)
            for(int j=0;j<3;j++)
            {
                if(x[j][i]==0)
                {
                    for(int k=j;k<3;k++)
                        x[k][i]=x[k+1][i];
                    x[3][i]=0;
                }
            }
        for(int a=0;a<4;a++)
        {
            for(int j=0;j<3;j++)
            {
                if(x[j][i]==x[j+1][a])
                {
                    x[j][a]=x[j][a]+x[j+1][a];
                    score+=x[j][a];
                    for(int k=j+1;k<3;k++)
                        x[k][a]=x[k+1][a];
                    x[3][a]=0;
                }
            }
        } 
    }
}

int main()
{
    char con;
    start();
    start();
    out();
    for(;;)
    {
        in();
        cin>>con;
        system("cls");
        if(con=='w')move(4);
        if(con=='a')move(3);
        if(con=='s')move(2);
        if(con=='d')move(1);
        out();
        Sleep(500);
        system("cls");
        if(compare()==1)
            start();
        else{}
        check();
    }
    /*x[0][0]=0;x[0][1]=0;x[0][2]=0;x[0][3]=0;
    x[1][0]=2;x[1][1]=2;x[1][2]=0;x[1][3]=4;
    x[2][0]=2;x[2][1]=0;x[2][2]=3;x[2][3]=0;
    x[3][0]=2;x[3][1]=0;x[3][2]=2;x[3][3]=0;
    //move(2);
    start();
    out();
    cout<<endl;*/
    system("pause");
    return 0;
}
