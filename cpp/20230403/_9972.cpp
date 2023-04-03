#include <iostream>
using namespace std;
char input[27];
int x[6][4][2]={{{1,0},{2,0},{3,0},{4,0}},{{0,0},{4,4},{5,7},{2,3}},{{0,3},{1,4},{5,3},{3,3}},{{0,7},{2,4},{5,0},{4,3}},{{0,4},{3,4},{5,4},{1,3}},{{2,6},{1,6},{4,6},{3,6}}};
int z[8][3]={{0,1,2},{2,1,0},{0,3,6},{6,3,0},{2,5,8},{8,5,2},{6,7,8},{8,7,6}};
char q[6][9];
int y[8]={0,1,2,5,8,7,6,3};
void B(int n,char r)
{
	int s=r=='+'?-1:1;
	int i=r=='+'?7:0;
	char w=q[n][y[i]];
	char p=q[n][y[i+s]];
	for (int j=0;j<6;j++)
		q[n][y[i+j*s]]=q[n][y[i+(j+2)*s]];
	q[n][y[7-i-s]]=w;
	q[n][y[7-i]]=p;

	i=r=='+'?0:3;
	s=r=='+'?1:-1;
	char A[3];
	for (int j=0;j<3;j++)
		A[j] = q[x[n][i][0]][z[x[n][i][1]][j]];
	for (int j=0;j<3;j++)
		for (int k=0;k<3;k++)
			q[x[n][i+j*s][0]][z[x[n][i+j*s][1]][k]]=q[x[n][i+(j+1)*s][0]][z[x[n][i+(j+1)*s][1]][k]];
	for (int j=0;j<3;j++)
		q[x[n][3-i][0]][z[x[n][3-i][1]][j]]=A[j];
}
void Q()
{
	for (int i=0;i<9;i++)
		cin>>q[0][i];
	int side[]={2,3,4,1};
	for (int i=0;i<3;i++)
		for (int j=0;j<12;j++)
			cin>>q[side[j/3]][3*i+j%3];
	for (int i=0;i<9;i++)
		cin>>q[5][i];
}
string P()
{
	for (int i=0;i<6;i++)
		for (int j=0;j<9;j++)
			if (q[i][j]!=q[i][0])
				return "No\n";
	return "Yes\n";
}
int main()
{
	while (1)
	{
		string s;
		cin>>s;
		if (s[0]=='E')
			break;
		Q();
		while(1)
		{
			string h,r;
			cin>>h;
			if (h[0]=='E')
				break;
			cin>>r;
			char a,t;
			if (h[0]=='f')
				a=3;
			else if (h[0]=='l')
				a=2;
			else if (h[0]=='r')
				a=4;
			else if (h=="back")
				a=1;
			else if (h[0]=='t')
				a=0;
			else if (h=="bottom")
				a=5;
			if (r[0]=='l')
				t ='-';
			else if (r[0]=='r')
				t='+';
			B(a,t);
		}
		cout<<P();
	}
}
