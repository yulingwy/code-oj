#include <iostream>
#include <vector>
using namespace std;
//计算有多少个尾零，  也就是 2*5    算出 多少2，5  
int data[] ={5650,4542,3554,473,946,4114,3871,
9073,90,4329, 2758,7949,6113,5659,5245,7432,3051,
4434,6704,3594, 9937,1173,6866,3397,4759,7557,3070,
2287,1453,9899, 1486,5722,3135,1170,4014,5510,
5120,729,2880,9019, 2049,698,4582,4346,4427,646,9742,
7340,1230,7683, 5693,7015,6887,7381,4172,4341,2909,2027,7355,
5649, 6701,6645,1671,5978,2704,9926,295,3125,3878,6785, 2066,
4247,4800,1578,6652,4616,1113,6205,3264,2915, 3966,5291,2904,
1285,2193,1428,2265,8730,9436,7074, 689,5510,8243,6114,337,4096,
8199,7313,3685,211};
struct node{
	int a,b;
};
node count(int num)
{
	node temp;
	for(int i = 2 ; i*i < num ; i++)
	{
		int cnt = 0;
		while(num%i == 0)
		{
			cnt++;
			num/=i;
		}
		if(i == 2) temp.a = cnt;
		else if(i == 5) temp.b = cnt;	
	}
	if(num != 1)
	{
		if( num == 2) temp.a = 1;
		else if( num == 5) temp.b = 1;
	}
	return temp;
}
int main()
{
	
	int a = 0,a2 = 0,a5 = 0;
	for(int i = 0 ; i < sizeof(data)/sizeof(int) ; i++)
	{
		a2 += count(data[i]).a;
		a5 += count(data[i]).b;	
	}
	a = a2 < a5 ? a2 : a5;
	cout << a ;
	return 0;
} 
