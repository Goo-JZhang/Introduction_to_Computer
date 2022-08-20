#include <iostream>
#include <assert.h>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>
#include <ctime>
#include<stdio.h>
using namespace std;
int main()
{
	int p[1001];
	for (int i = 0; i < 1001; i++)
	{
		p[i] = 1;
	}
	int n = 0;
	cin >> n;
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < i / 2 + 1; j++)
		{
			p[i] = p[i] + p[j];
		}
	}
	cout << p[n];
	return 0;
}
