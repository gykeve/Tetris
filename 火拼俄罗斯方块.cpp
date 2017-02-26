#include <iostream>
#include <string>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
class Cshape				//������
{
private:
	int headx,heady;				//�ڵ����е����Ͻ����꣨���У�     
	int look[4][4];					//��״
	int color;
public:
	Cshape()
	{
		headx=0;
		heady=0;
		look[0][0]=0;
	}

	~Cshape()
	{
	}

	int getheadx()
	{
		return headx;
	}

	int getheady()
	{
		return heady;
	}

	void setheadx(int x)
	{
		headx=x;
	}

	void setheady(int y)
	{
		heady=y;
	}

	Cshape(Cshape& shape)			//����
	{
		headx=shape.headx;
		heady=shape.heady;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				look[i][j]=shape.look[i][j];
		color=shape.color;
	}

	void setshape  (int num)					//7�ַ���  19����̬
	{
		int i,j;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++) 
				look[i][j]=0;
		if(num==1)
			{
				look[0][0]=1;
				look[1][0]=1;
				look[2][0]=1;
				look[3][0]=1;
				color=RED;
			}
		else if(num==2)
			{
				look[3][0]=1;
				look[3][1]=1;
				look[3][2]=1;
				look[3][3]=1;
				color=RED;
			}
		else if(num==3)
			{
				look[2][1]=1;
				look[2][2]=1;
				look[3][1]=1;
				look[3][2]=1;
				color=BROWN;
			}
		else if(num==4)
			{
				look[2][0]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[1][1]=1;
				color=MAGENTA;
			}
		else if(num==5)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[3][1]=1;
				look[2][2]=1;
				color=MAGENTA;
			}
		else if(num==6)
			{
				look[2][0]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[3][1]=1;
				color=MAGENTA;
			}
		else if(num==7)
			{
				look[2][0]=1;
				look[1][1]=1;
				look[2][1]=1;
				look[3][1]=1;
				color=MAGENTA;
			}
		else if(num==8)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[2][3]=1;
				color=YELLOW;
			}
		else if(num==9)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[3][1]=1;
				look[1][2]=1;
				color=YELLOW;
			}
		else if(num==10)
			{
				look[1][0]=1;
				look[1][1]=1;
				look[1][2]=1;
				look[2][2]=1;
				color=YELLOW;
			}
		else if(num==11)
			{
				look[2][1]=1;
				look[2][2]=1;
				look[1][2]=1;
				look[0][2]=1;
				color=YELLOW;
			}
		else if(num==12)
			{
				look[1][2]=1;
				look[2][0]=1;
				look[2][1]=1;
				look[2][2]=1;
				color=CYAN;
			}
		else if(num==13)
			{
				look[1][1]=1;
				look[1][2]=1;
				look[2][2]=1;
				look[3][2]=1;
				color=CYAN;
			}
		else if(num==14)
			{
				look[2][0]=1;
				look[1][0]=1;
				look[1][1]=1;
				look[1][2]=1;
				color=CYAN;
			}
		else if(num==15)
			{
				look[0][1]=1;
				look[1][1]=1;
				look[2][1]=1;
				look[2][2]=1;
				color=CYAN;
			}
		else if(num==16)
			{
				look[1][1]=1;
				look[2][1]=1;
				look[2][2]=1;
				look[3][2]=1;
				color=GREEN;
			}
		else if(num==17)
			{
				look[1][2]=1;
				look[1][1]=1;
				look[2][1]=1;
				look[2][0]=1;
				color=GREEN;
			}
		else if(num==18)
			{
				look[1][2]=1;
				look[2][2]=1;
				look[2][1]=1;
				look[3][1]=1;
				color=RGB(255,192,203);					//�ۺ�
			}
		else if(num==19)
			{
				look[1][1]=1;
				look[1][2]=1;
				look[2][2]=1;
				look[2][3]=1;
				color=RGB(255,192,203);
			}
	}

	int getlook(int i,int j)
	{
		return look[i][j];
	}

	int getcolor()
	{
		return color;
	}

	void setcolor(int c)
	{
		color=c;
	}

	int shapeid()		//�жϷ���������๲7�֣���1 2Ϊ��һ�� 3   4567   891011     1213141516  1718 1920
	{
		if(look[0][0]==1)  return 1;
		else if(look[3][0]==1) return 2;
		else if(look[2][1]==1&&look[2][2]==1&&look[3][1]==1&&look[3][2]==1) return 3;
		else if(look[2][0]==1&&look[2][1]==1&&look[2][2]==1&&look[1][1]==1) return 4;
		else if(look[1][1]==1&&look[2][1]==1&&look[3][1]==1&&look[2][2]==1) return 5;
		else if(look[2][0]==1&&look[2][1]==1&&look[2][2]==1&&look[3][1]==1) return 6;
		else if(look[2][0]==1&&look[1][1]==1&&look[2][1]==1&&look[3][1]==1) return 7;
		else if(look[1][1]==1&&look[2][1]==1&&look[2][2]==1&&look[2][3]==1)	return 8;
		else if(look[1][1]==1&&look[2][1]==1&&look[3][1]==1&&look[1][2]==1) return 9;
		else if(look[1][0]==1&&look[1][1]==1&&look[1][2]==1&&look[2][2]==1) return 10;
		else if(look[2][1]==1 && look[2][2]==1 && look[1][2]==1 && look[0][2]==1) return 11;
		else if(look[1][2]==1 && look[2][0]==1 && look[2][1]==1 && look[2][2]==1) return 12;
		else if(look[1][1]==1 && look[1][2]==1 && look[2][2]==1 && look[3][2]==1) return 13;
		else if(look[2][0]==1 && look[1][0]==1 && look[1][1]==1 && look[1][2]==1) return 14;
		else if(look[0][1]==1 && look[1][1]==1 && look[2][1]==1 && look[2][2]==1) return 15;
		else if(look[1][1]==1 && look[2][1]==1 && look[2][2]==1 && look[3][2]==1) return 16;
		else if(look[1][2]==1 && look[1][1]==1 && look[2][1]==1 && look[2][0]==1) return 17;
		else if(look[1][2]==1 && look[2][2]==1 && look[2][1]==1 && look[3][1]==1) return 18;
		else if(look[1][1]==1 && look[1][2]==1 && look[2][2]==1 && look[2][3]==1) return 19;
	}

	void change()						//��ת����
	{
		int num=shapeid();
		if(num==1)  setshape(2);
		else if(num==2)  setshape(1);
		else if(num==3)  return ;
		else if(num==4||num==5||num==6) setshape(num+1);
		else if(num==7)  setshape(4);
		else if(num==8||num==9||num==10) setshape(num+1);
		else if(num==11) setshape(8);
		else if(num==12||num==13||num==14) setshape(num+1);
		else if(num==15) setshape(12);
		else if(num==16) setshape(17);
		else if(num==17) setshape(16);
		else if(num==18) setshape(19);
		else if(num==19) setshape(18);
	}

};

class Cplace              //������
{
private:
	int base[27][14];					//��Ϸ������4-25����1-10
	int hx,hy;							//�����������Ͻ�����Ļ�ϵ��������꣨���������ԭ�㣩
	int tipx,tipy;						//��һ��������ʾ�������Ͻ��������꣨���������ԭ�㣩
public:
	
	Cplace()
	{
		int i,j;
		for( i=0;i<27;i++)
			for(j=0;j<14;j++)
				base[i][j]=0;
	}

	~Cplace()
	{
	}   

	int gethx()
	{
		return hx;
	}

	void  sethx(int x)
	{
		hx=x;
	}

	int gethy()
	{
		return hy;
	}

	void sethy(int y)
	{
		hy=y;
	}

	void settipx(int x)
	{
		tipx=x;
	}

	void settipy(int y)
	{
		tipy=y;
	}

	int getbase(int i,int j)
	{
		return base[i][j];
	}

	Cplace (Cplace& place)						//����
	{
		int i,j;
		for(i=0;i<25;i++)
			for(j=0;j<14;j++)
				base[i][j]=place.base[i][j];
		hx=place.hx;
		hy=place.hy;
		tipx=place.tipx;
		tipy=place.tipy;
	}

	void startbase()				//��ʼ����Ϸ���� ����ȫ����0,ȫ������ɫ
	{
		int i,j;
		for(i=0;i<27;i++)
			for(j=0;j<14;j++)
				base[i][j]=0;
		setfillcolor(BLUE);
		for(i=4;i<26;i++)
			for(j=1;j<11;j++)
				bar(hx+j*20,hy+i*20,hx+(j+1)*20-1,hy+(i+1)*20-1);
	}

	void cancelshape(Cshape &shape)						//����Ļ��Ĩ��һ������,��������������Ͻ�����Ļ�ϵ��������꣨���������ԭ�㣩
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1&&(k+i)>3)
					{
						setfillcolor(BLUE);
						bar(hx+(l+j)*20,hy+(k+i)*20,hx+(l+j+1)*20-1,hy+(k+i+1)*20-1);
					}
	}

	void setshape(Cshape &shape)							//����Ϸ��������ʾһ������
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1&&(k+i)>3)
					{
						setfillcolor(shape.getcolor());
						bar3d(hx+(j+l)*20+2,hy+(k+i)*20+2,hx+(j+l+1)*20-4,hy+(k+i+1)*20-4,3,true);
					}
	}

	void setline(int i,int color,int color2)										//����Ļ����ʾ��i�У�����������У�,���������ɫ,��1����ɫ
	{
		int j=1;
		for(j;j<=10;j++)
			if(base[i][j]==1)
			{
				setfillcolor(color2);
				bar3d(hx+j*20+2,hy+i*20+2,hx+(j+1)*20-4,hy+(i+1)*20-4,3,true);
			}
			else if(base[i][j]==0)
			{
				setfillcolor(color);
				bar(hx+j*20,hy+i*20,hx+(j+1)*20-1,hy+(i+1)*20-1);
			}
	}	

	void inshape(Cshape &shape)							//�ѷ�����������  ͨ���޸�1,0,����ʾ
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1)
						base[k+i][l+j]=1;
		setshape(shape);
	}

	void movenewshape(Cshape &shape)					//���µķ����Ƶ���Ϸ�����Ϸ�
	{
		for(int i=4;i>0;i--)								
		{
			int yon=0;
			for(int j=0;j<4;j++)
				if(shape.getlook(i,j)==1)
					yon=1;
			if(!yon)
				movedown(shape);
			else break;
		}
	}  

	void outshape (Cshape &shape)						//ɾ��ĳ���ڵ����еķ���
	{
		int i,j,k=shape.getheadx(),l=shape.getheady();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
					if(shape.getlook(i,j)==1)
						base[k+i][l+j]=0;
		cancelshape(shape);
	}

	bool candown (Cshape shape)						//�ж��ܷ����Ʒ���
	{
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		for(i=0;i<4;i++)
		{
			for(j=3;shape.getlook(j,i)!=1&&j>0;j--) { }
			if(shape.getlook(j,i)==1)
				if(x+j+1>25||base[x+j+1][y+i]==1)
					return false;
		}
		return true;
	}

	bool canleft (Cshape shape)							//�ж��ܷ����Ʒ���
	{
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		for(i=0;i<4;i++)
		{
			for(j=0;shape.getlook(i,j)!=1&&j<3;j++) { }
			if(shape.getlook(i,j)==1)
				if(y+j-1<1||base[x+i][y+j-1]==1)
					return false;
		}
		return true;
	}

	bool canright (Cshape shape)			//�жϷ����ܷ�����
	{
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		for(i=0;i<4;i++)
		{
			for(j=3;shape.getlook(i,j)!=1&&j>0;j--) { }
			if(shape.getlook(i,j)==1)
				if(y+j+1>10||base[x+i][y+j+1]==1)
					return false;
		}
		return true;
	}

	bool canchange (Cshape shape)						//�жϷ����ܷ�任
	{
		outshape(shape);
		int x=shape.getheadx(),y=shape.getheady(),i,j;
		shape.change();
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(shape.getlook(i,j)==1)
					if(x+i>25||y+j<1||y+j>10||base[x+i][y+j]==1)
						return false;
		return true;
	}

	bool candeleline (int i)
	{
		int j;
		for(j=1;j<=10;j++)
			if(base[i][j]==0)
				return false;
		return true;
	}

	void movedown(Cshape &shape)					//��������
	{
		if(candown(shape))
		{
			outshape(shape);
			shape.setheadx(shape.getheadx()+1);
			inshape(shape);
		}
	}

	void movedownend(Cshape &shape)					//�ѷ����ƶ������·�
	{
		while(candown(shape))
			movedown(shape);
	}

	void moveleft(Cshape &shape)
	{
		if(canleft(shape))
		{
			outshape(shape);
			shape.setheady(shape.getheady()-1);
			inshape(shape);
		}
	}

	void moveright(Cshape &shape)
	{
		if(canright(shape))
		{
			outshape(shape);
			shape.setheady(shape.getheady()+1);
			inshape(shape);
		}
	}

	void shapechange(Cshape &shape)
	{
		if(canchange(shape))
		{
			shape.change();
			inshape(shape);
		}
		inshape(shape);
	}

	void deleteline(int i)					//ɾ����i��
	{
		if(candeleline(i))
		{
			int j,k;
			for(j=0;i-j>4;j++)
				for(k=1;k<=10;k++)
					base[i-j][k]=base[i-j-1][k];
			for(k=1;k<=10;k++)
					base[i-j][k]=0;
			setfillcolor(BLUE);
			bar(hx+20,hy+i*20+10,hx+220,hy+i*20+13);				//��Ǳ���������
			PlaySound("music\\bomb.wav", NULL, SND_FILENAME | SND_ASYNC); 
			Sleep(300);
			for(i;i>3;i--)
				setline(i,BLUE,BLACK);
		}
	}

	Cshape newshape(int i)             //�������һ������		,�������������
	{
		Cshape shape;
		shape.setheadx(0);
		shape.setheady(4);
		srand(i);
		int id=0;					//����id
		while(true)					//����ÿ�ַ�����ֵĸ���һ��				
		{
			id=rand()%19+1;
			if(id==1||id==3||id==4||id==8||id==12||id==16||id==18)
				break;
		}
		shape.setshape(id);
		return shape;
	}

	void setnewshape(Cshape &shape)               //���·��������ʾ��
	{
		int i,j;
		setfillcolor(BLACK);
		bar(tipx,tipy,tipx+4*20-1,tipy+4*20-1);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(shape.getlook(i,j)==1)
				{
					setfillcolor(shape.getcolor());
					bar3d(tipx+j*20+2,tipy+i*20+2,tipx+(j+1)*20-1-4,tipy+(i+1)*20-4,3,true);
				}
	}

	void newline(int*line)				//�������һ�����У�1,0���飩˫�˶�սʱ���ڸ��������ѹ��
	{
		srand(GetTickCount());
		for(int i=0;i<10;i++)
			line[i]=rand()%2;
	}

	bool die()									//�ж��Ƿ��һ��ֱ�ӹ�
	{
		int i,j,yon;
		for(i=4;i<=25;i++)
		{
			yon=0;
			for(j=1;j<=10;j++)
			{
				if(base[i][j]==1) 
				{
					yon+=1;
					break;
				}
			}
			if(yon==0)   return false;
		}
		return true;
	}

	void  downnewline(Cplace & place,int & yon)							//���·����һ��
	{
		if(die())  yon=gameover(place);						//�Ƿ�ֱ�ӹ���
		int line[10];
		newline(line);
		int i=26,j;
		for(j=1;j<=10;j++)
			base[i][j]=line[j-1];						//�Ȱ�����з������·�һ�У�����ʾ����Ļ�ϣ����صĵ�26�У�
		for(i=4;i<=25;i++)
			for(j=1;j<=10;j++)
				base[i][j]=base[i+1][j];					//��һ�и�ֵΪ��һ�� 
		for(j=1;j<=10;j++)									//�ٰ����ص�����0
			base[i][j]=0;
		for(i=25;i>=4;i--)
			setline(i,BLUE,BLACK);											//��ʾ����Ļ��
	}

	void  overnewline(Cplace&place,int & yon)					//���Ϸ����һ��
	{
		if(die())  yon=gameover(place);		//�ж��Ƿ��һ��ֱ�ӹ�
		int line[10];
		newline(line);
		int yon2,i,j;
		for(i=5;i<=25;i++)
			{
				yon2=0;
				for(j=1;j<=10;j++)
					if(base[i][j]==1)  yon2=1;
				if(yon2==1)		break;
			}
		for(j=1;j<=10;j++)
			base[i-1][j]=line[j-1];
		setline(i-1,BLUE,BLACK);
	}

	int endshape(Cshape & pnow,Cshape & pnext,Cplace place,int &yon)							//�������䵽��󣬹̶�Ϊ��ɫ,���·��������Ϸ���򣬲��Ҳ����·�����ʾ����ʾ��,�����ж��з�����
	{   
		int c=0;																					//cΪһ�������˶�����
		int i=4,j;
		for(j=1;j<=10;j++)
			if(base[i][j]==1)   yon=gameover(place);						//�ж��Ƿ����
		pnow.setcolor(BLACK);
		setshape(pnow);
		for(i=4;i<=25;i++)
			if(candeleline(i))
			{
				deleteline(i);
				++c;
				i=3;
			}
		inshape(pnext);
		movenewshape(pnext);
		pnow=pnext;
		pnext=newshape(GetTickCount());
		setnewshape(pnext);
		return c;
	}

	int gameover(Cplace &place)						//������Ϸ  ����ʾlogo,����Ӯ��һ������Ϸ��start��
	{
		mciSendString("close MUSIC", NULL, 0, NULL);
		PlaySound("music\\end.wav", NULL, SND_FILENAME | SND_ASYNC); 
		int i,j;
		for(i=4;i<=25;i++)
		{
			for(j=1;j<=10;j++)
			{
				base[i][j]=0;
				place.base[i][j]=0;
			}
		}
		for(i=25;i>3;i--)				
		{
			setline(i,RED,YELLOW);
			place.setline(29-i,RED,BLACK);
			Sleep(100);
		}							//��һ��logo
		
		base[5][4]=1;base[5][5]=1;base[6][3]=1;base[6][6]=1;base[7][2]=1;base[7][7]=1;						//�ڵ��������ϱ��ڶ���logoͼ��(���һ����)
		base[8][6]=1;base[9][6]=1;base[10][4]=1;base[10][5]=1;base[11][3]=1;
		i=12;
		for(j=2;j<=7;j++)
			base[i][j]=1;
		base[14][4]=1;base[14][5]=1;base[15][6]=1;base[16][7]=1;base[17][7]=1;base[18][5]=1;base[18][6]=1;
		base[19][4]=1;base[20][5]=1;base[20][6]=1;base[21][7]=1;base[22][7]=1;base[24][5]=1;base[23][6]=1;base[24][4]=1;
		j=3;
		for(i=14;i<=24;i++)
			base[i][j]=1;
																									//Ӯ��һ����logo
		place.base[6][7]=1;place.base[11][6]=1;place.base[11][8]=1;place.base[12][5]=1;place.base[12][9]=1;
		i=7;
		for(j=4;j<=10;j++)
			place.base[i][j]=1;
		for(i=8;i<=10;i++)
			for(j=6;j<=8;j++)
				place.base[i][j]=1;
		i=13;
		for(j=5;j<=10;j++)
			place.base[i][j]=1;
		i=18;
		for(j=5;j<=9;j++)
			place.base[i][j]=1;
		i=21;
		for(j=6;j<=8;j++)
			place.base[i][j]=1;
		i=24;
		for(j=3;j<=10;j++)
			place.base[i][j]=1;
		place.base[14][4]=1;place.base[15][4]=1;place.base[16][3]=1;place.base[17][3]=1;place.base[18][3]=1;
		place.base[19][2]=1;place.base[19][7]=1;place.base[20][2]=1;place.base[20][7]=1;place.base[21][2]=1;
		place.base[22][1]=1;place.base[22][7]=1;place.base[23][1]=1;place.base[23][7]=1;place.base[24][1]=1;place.base[25][1]=1;
		
		for(i=4;i<=25;i++)							//�ڶ���logo
			{
				setline(i,RED,YELLOW);
				place.setline(29-i,RED,BLACK);
				Sleep(150);   
			}
		while(true)
			{
				if(kbhit())
					getch();
				else 
					break;
			}
		HWND wnd = GetHWnd();
		if (MessageBox(wnd, _T("��Ϸ������\n����������һ����"), _T("��Ϸ����"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			return 1;
		}
		exit(0);
	}
}; 

class start                  //��Ϸʵ�ֹ�����
{
private:
	Cshape p1now,p1next;
	Cshape p2now,p2next;				//p1 p2��ǰ����һ������
	int gametime;						//��Ϸ��ʼ��ʱ��
	int p1oldtime,p2oldtime;			//p1p2�ϴβ���ʱ��,�״�Ĭ��Ϊ��Ϸ��ʼʱ��
public:
	start(){}

	~start (){}

	void myouttextxy(int x, int y, LPCTSTR s)
{
	static IMAGE tmp;						// �������汻���ָ��ǵ����򱳾�
	if (s == NULL)
	{
		putimage(x, y, &tmp);				// �ָ�����
	}
	else
	{
		int w=textwidth(s);					// ��ȡ�ַ���ռ�õĿ��
		int h=textheight(s);				// ��ȡ�ַ���ռ�õĸ߶�
		getimage(&tmp, x, y, w, h);				// ��������
		outtextxy(x, y, s);							// �������	
	}
}

	void startshow()								//��������
{
	PlaySound("music\\Railgun.wav", NULL, SND_FILENAME | SND_ASYNC);
	TCHAR s[] =_T("��ƴ����˹����");			// �����ַ���									
	initgraph(1100, 600);					// ������ͼ����
	setfillcolor(RED);						//����С����
	bar(0,0,1100-1,600-1);
	setfillcolor(BLACK);
	for(int i=0;i<=55;i++)
	{
		bar(550-(i+1)*10,0,550-i*10,600);
		bar(550+i*10,0,550+(i+1)*10,600);
		Sleep(60);
	}
	int w = textwidth(s);		// ��ȡ�ַ���ռ�õĿ��
	int h = textheight(s);		// ��ȡ�ַ���ռ�õĸ߶�
	IMAGE tmp;					// ������ʱ���󣬱��汻�����ƻ��ı���						// ���Ʊ���
	for(int i = 0; i < 1100; i++)
	{
		setlinecolor( HSLtoRGB((float)i, 1.0, 0.25) );
		line(i, 0, 1100, 1100);
	}
								// ��������Ч��
	setcolor(YELLOW);			// ����������ɫΪ��ɫ
	setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
	
								// �����ƶ�������
	for(int j = 0; j < 290; j++)
	{
										// ��������
		setfont(70,0,("����"));
		myouttextxy(j, 100, s);
		Sleep(20);
										// ��������
		myouttextxy(j, 100, NULL);
	}
	while(true)							//���ǰ��������
	{
		if(kbhit())
			getch();
		else 
			break;
	}
	setfont(70,0,("����"));
	myouttextxy(290, 100, s);
	setfont(40,0,("����"));
	outtextxy(300,350,_T("�������������Ϸ"));
	_getch();
}

	void endshow()
	{
		TCHAR s[] =_T("�˳���Ϸ   �ټ�");
		int w = textwidth(s);		
		int h = textheight(s);		
		IMAGE tmp;
		setcolor(YELLOW);			
		setbkmode(TRANSPARENT);						
		for(int j = 0; j < 290; j++)
		{								
			setfont(70,0,("����"));
			myouttextxy(j, 100, s);
			Sleep(20);							
			myouttextxy(j, 100, NULL);
		}
		while(true)							//���ǰ��������
		{
			if(kbhit())
				getch();
			else 
				break;
		}
		setfont(70,0,("����"));
		myouttextxy(290, 100, s);
		outtextxy(300,450,_T("��������˳�"));
		_getch();
	}

	void ready(Cplace &place1,Cplace & place2)					//��ʼ��
	{
		initgraph(1100, 600);						//��������
		srand((unsigned)time(NULL));

		setfont(14, 0, _T("����"));					//����˵��
		outtextxy(20, 330, _T("1p����˵��"));
		outtextxy(20, 350, _T("W����ת"));
		outtextxy(20, 370, _T("A������"));
		outtextxy(20, 390, _T("R������"));
		outtextxy(20, 410, _T("S������"));
		outtextxy(20, 430, _T("�ո񣺳���"));
		outtextxy(20, 450, _T("G��Ͷ��"));
		outtextxy(500, 30, _T("ESC���˳���Ϸ"));
		outtextxy(640, 330, _T("2p����˵��"));
		outtextxy(640, 350, _T("�ϣ���ת"));
		outtextxy(640, 370, _T("������"));
		outtextxy(640, 390, _T("�ң�����"));
		outtextxy(640, 410, _T("�£�����"));
		outtextxy(640, 430, _T("0������"));
		outtextxy(640, 450, _T("5��Ͷ��"));
		setorigin(150, 100);							//��������ԭ��

		rectangle(-1,-1,10*20,22*20);		// ������Ϸ���߽�
		rectangle(11*20-1,-1,15*20,4*20);
		rectangle(30*20-1,-1,40*20,22*20);
		rectangle(25*20-1,-1,29*20,4*20);
		
		place1.sethx(-20);						//���������Ϸ����
		place1.sethy(-80);
		place1.settipx(11*20);
		place1.settipy(0);
		place1.startbase();
		place2.sethx(580);
		place2.sethy(-80);
		place2.settipx(25*20);
		place2.settipy(0);
		place2.startbase();

		p1now=place1.newshape(GetTickCount());					//������ʼ�ķ���
		p1next=place1.newshape(GetTickCount()+1);
		p2now=place2.newshape(GetTickCount()+2);
		p2next=place2.newshape(GetTickCount()+3);
		gametime=GetTickCount();					//��¼��Ϸ��ʼ��ʱ��
		p1oldtime=gametime;
		p1oldtime=gametime;							//p1p2��һ�β���ʱ������Ϊϵͳʱ��
	}

	void esc ()							 //�˳���Ϸʱ�Ķ���(��ª��)
	{
		mciSendString("close MUSIC", NULL, 0, NULL);
		PlaySound("music\\jieshu.wav", NULL, SND_FILENAME | SND_ASYNC); 
		setorigin(0,0);
		int i,j;
		setfillcolor(RED);
		for(i=0;i<=15;i++)
		{
			bar(0+i*40,0,0+(i+1)*40,600);
			bar(1100-i*40,0,1100-(i+1)*40,600);
			Sleep(150);
		}	
		endshow();
	}	

	int getcmd()						//���ղ���ָ��
	{		
		while(true)
		{
			int newtime=GetTickCount();
			if(newtime-p1oldtime>=500){p1oldtime=newtime;return 11;}			//1p��ʱ��11:1p����һ��
			if(newtime-p2oldtime>=500){p2oldtime=newtime;return 21;}			//2p��ʱ��21:2p����һ��
			if(kbhit())															//�����ָ��
			{
				switch(getch())
				{
				case'w':
				case'W':		return 12;									//12:1p�任����
				case'a':
				case'A':		return 13;									//13:1p��������
				case's':
				case'S':		return 11;
				case'd':
				case'D':        return 14;									//14:2p��������
				case'g':
				case'G':		return 10;									//1pͶ��
				case 27:         return 0;									//�˳���Ϸ
				case' ':         return 15;									//1p����
				case 72:		return 22;									//2p����ָ��
				case 75:		return 23;
				case 77:		return 24;
				case 80:		return 21;
				case'0':        return 25;
				case '5':		return 20;
				}
			}
			Sleep(15);
		}
	}

	void cmd(Cplace &p1,Cplace &p2,int i)					//�������ָ��,iΪ����ָ��
	{
		switch (i)
		{
		case 0: 
			{
				esc();
				exit(0);
			}
		case 10: 
			{
				int yon=p1.gameover(p2);
				if(yon==1)
					go();
			}
		case 20:
			{
				int yon=p2.gameover(p1);
				if(yon==1)
					go();
			}
		//1p������
		case 11:
			{
				int yon=0;
				if(!p1.candown(p1now))
				{
					int c=p1.endshape(p1now,p1next,p2,yon);
					if(yon==1)
						go();
					if(c==1)								//����һ�������������и����ֳͷ�
						p2.movedownend(p2now);
					if(c==2)
						{
							p2.movedownend(p2now);
							p2.downnewline(p1,yon);
							if(yon==1)
								go();
						}
					if(c==3)
					{
						p2.movedownend(p2now);
						p2.overnewline(p1,yon);
						if(yon==1)
							go();
					}
					if(c==4)
					{
						p2.movedownend(p2now);
						p2.downnewline(p1,yon);
						if(yon==1)
							go();
						p2.overnewline(p1,yon);
						if(yon==1)
							go();
					}
				}
				else 
					p1.movedown(p1now);
				break;
			}
		case 12: p1.shapechange(p1now);		break;
		case 13: p1.moveleft(p1now);		break;
		case 14: p1.moveright(p1now);		break;
		case 15: 
			{
				int yon=0;
				p1.movedownend(p1now);
				int c=p1.endshape(p1now,p1next,p2,yon);
				if(yon==1)
					go();
				if(c==1)								//����һ�������������и����ֳͷ�
					p2.movedownend(p2now);
				if(c==2)
				{
					p2.movedownend(p2now);
					p2.downnewline(p1,yon);
					if(yon==1)
						go();
				}
				if(c==3)
				{
					p2.movedownend(p2now);
					p2.overnewline(p1,yon);
					if(yon==1)
						go();
				}
				if(c==4)
				{
					p2.movedownend(p2now);
					p2.downnewline(p1,yon);
					if(yon==1)
						go();
					p2.overnewline(p1,yon);
					if(yon==1)
						go();
				}
				break;
			}
		//2p����:
		case 21:
			{
				if(!p2.candown(p2now))
				{
					int yon=0;
					int c=p2.endshape(p2now,p2next,p1,yon);
					if(yon==1)
						go();
					if(c==1)								//����һ�������������и����ֳͷ�
						p1.movedownend(p1now);
					if(c==2)
						{
							p1.movedownend(p1now);
							p1.downnewline(p2,yon);
							if(yon==1)
								go();
						}
					if(c==3)
					{
						p1.movedownend(p1now);
						p1.overnewline(p2,yon);
						if(yon==1)
							go();
					}
					if(c==4)
					{
						p1.movedownend(p1now);
						p1.downnewline(p2,yon);
						if(yon==1)
							go();
						p1.overnewline(p2,yon);
						if(yon==1)
							go();
					}
				}
				else 
					p2.movedown(p2now);
				break;
			}
		case 22: p2.shapechange(p2now);		 break;
		case 23: p2.moveleft(p2now);		break;
		case 24: p2.moveright(p2now);		break;
		case 25: 
			{
				int yon=0;
				p2.movedownend(p2now);
				int c=p2.endshape(p2now,p2next,p1,yon);
				if(yon==1)
					go();
				if(c==1)								//����һ�������������и����ֳͷ�
					p1.movedownend(p1now);
				if(c==2)
					{
						p1.movedownend(p1now);
						p1.downnewline(p2,yon);
						if(yon==1)
							go();
					}
				if(c==3)
				{
					p1.movedownend(p2now);
					p1.overnewline(p2,yon);
					if(yon==1)
						go();
				}
				if(c==4)
				{
					p1.movedownend(p1now);
					p1.downnewline(p2,yon);
					if(yon==1)
						go();
					p1.overnewline(p2,yon);
					if(yon==1)
						go();   
				}
				break;
			}
		}
	}

	void go()							//��ʼ��Ϸ
	{
		char buf[255];
        mciSendString(("open music\\1.mp3 alias MUSIC"),buf,sizeof(buf),0);
        mciSendString("play MUSIC repeat",NULL,0,0); 
		PlaySound("music\\2.wav", NULL, SND_FILENAME | SND_ASYNC); 
		Cplace p1,p2;			//�������12
		ready(p1,p2);    		//��ʼ��
		p1.inshape(p1now);
		p1.movenewshape(p1now);
		p1.setnewshape(p1next);
		p2.inshape(p2now);
		p2.movenewshape(p2now);
		p2.setnewshape(p2next);
		while(true)
			cmd(p1,p2,getcmd());
	}				
};

void main()
{
	start play;
	play.startshow();
	play.go();
}
