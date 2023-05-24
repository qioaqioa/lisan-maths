#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<malloc.h>
#include<numeric>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<queue>
#include<set>
#include<bitset>
#include<stack>
#include<fstream>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, string>PII;
#define lowbit(x) x&(-x)​
map<string, int>s;
int main()
{
	ifstream f("log.txt");
	string line;
	while (!f.eof())
	{
		string s1, s2,s3; f>>line>>s3>> s1 >> s2;
		if (!s.count(s1))s[s1] = 1;
	}
	cout << s.size();
    system("pause");
    return 0;
}