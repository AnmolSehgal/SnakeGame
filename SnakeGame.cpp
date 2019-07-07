#include<iostream>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<bits/stdc++.h>
//hello
using namespace std;
void check();
char board[21][41];
class border
{
public:
    int i,j;
void print_border()
{
    for(i=0;i<21;i++)
    {
        for(j=0;j<41;j++)
        {
            if(i==0||i==20)
            {
                board[i][j]='-';
            }
            else if(j==0||j==40)
            {
                board[i][j]='|';
            }
            else
            {
                board[i][j]=' ';
            }
        }
    }
}
void print()
{
for(i=0;i<21;i++)
    {
        for(j=0;j<41;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
};
class food: public border
{
public:
    int r;
    int c;
    char value;
    food()
    {}
    food(int x,int y,char val)
    {
        r=x;
        c=y;
        value=val;
        board[r][c]=value;
    }
    void locator()
    {
        srand(time(0));
        r = (rand() % 19)+1;
        c = (rand() % 39)+1;
        board[r][c] = value;
    }
};
class Snake
{
public:
    int row,col,svalue;
};
int check(vector<Snake> snake, food fd)
{
    if(fd.r==snake[0].row && fd.c==snake[0].col)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int i,j;
    border p;
    p.print_border();
    food f(4,4,'*');
    vector<Snake> v;
    Snake s;
    s.row=10;
    s.col=10;
    s.svalue='O';

    Snake s1;
    s1.row=10;
    s1.col=11;
    s1.svalue='+';

    Snake s2;
    s2.row=10;
    s2.col=12;
    s2.svalue='+';

    Snake s3;
    s3.row=10;
    s3.col=13;
    s3.svalue='+';

    v.push_back(s);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    for(i=0;i<v.size();i++)
    {
        board[v[i].row][v[i].col]=v[i].svalue;
    }
    p.print();
    int flag=0;
    while(board[v[0].row][v[0].col]!='+')
    {

        char input;
        if(kbhit())
        {
            //cout<<"Enter the direction using W A S D keys press X to end"<<endl;
            input = getch();
        }
        if(input=='w')
        {
           Snake temp = v[v.size()-1];
           board[v[v.size()-1].row][v[v.size()-1].col] = ' ';
           for(int i = v.size() -1;i>0;i--)
           {
                 v[i].row=v[i-1].row;
                 v[i].col=v[i-1].col;
           }
            v[0].row=v[0].row-1;
           /* if(check_quit(v,v[0].row,v[0].col))
            {
                flag==1;
                break;
            }*/
            if(check(v,f))
            {
                v.push_back(temp);
                f.locator();
            }
            if(v[0].row == 0)
                v[0].row = 19;
        }
        if(input=='a')
        {
             Snake temp = v[v.size()-1];
            board[v[v.size()-1].row][v[v.size()-1].col] = ' ';
          for(int i = v.size() -1;i>0;i--)
          {
                 v[i].row=v[i-1].row;
                 v[i].col=v[i-1].col;
          }
            v[0].col=v[0].col-1;
                 if(check(v,f))
                 {
                        f.locator();
                        v.push_back(temp);
                    }
           if(v[0].col == 0)
                v[0].col = 39;
        }
        if(input=='s')
        {
             Snake temp = v[v.size()-1];
                board[v[v.size()-1].row][v[v.size()-1].col] = ' ';
          for(int i = v.size() -1;i>0;i--)
          {
                 v[i].row=v[i-1].row;
                 v[i].col=v[i-1].col;
          }
            v[0].row=v[0].row+1;
            /* if(check_quit(v,v[0].row,v[0].col))
            {
                flag==1;
                break;
            }*/
               if(check(v,f))
               {
                    f.locator();
                v.push_back(temp);
               }
           if(v[0].row == 20)
                v[0].row = 1;
        }
        if(input=='d')
        {
             Snake temp = v[v.size()-1];
                board[v[v.size()-1].row][v[v.size()-1].col] = ' ';
          for(int i = v.size() -1;i>0;i--)
          {
                 v[i].row=v[i-1].row;
                 v[i].col=v[i-1].col;
          }
            v[0].col+=1;
             /*if(check_quit(v,v[0].row,v[0].col))
            {
                flag==1;
                break;
            }*/
               if(check(v,f))
               {
                    f.locator();
                v.push_back(temp);
            }
         if(v[0].col == 40)
            v[0].col = 1;
        }
       /* if(input=='x')
        {
            break;
        }
        */
        for(i=0;i<v.size();i++)
        {
            board[v[i].row][v[i].col]=v[i].svalue;
        }
        Sleep(80);
        system("cls");
        p.print();
    }
        system("cls");
        cout<<("SORRY YOU CAN'T EAT YOURSELF")<<endl;
        cout<<("CONGRATULATIONS YOUR SCORE IS: ")<<(5*(v.size()-4));
    return 0;
}