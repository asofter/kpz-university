// Задана дійсна матриця A(n, n) , n <= 20. Розробити програму, яка будує
// вектор X(n) за правилом: X(i) (i=1,2,...,n) дорівнює півсумі модулів
// максимального і мінімального елементів i -го рядка.

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

int max_array(int a[], int num_elements)
{
   int i, max=a[0];
   for (i=1; i<num_elements; i++)
   {
	 if (a[i]>max)
	    max=a[i];
   }
   return(max);
}

int min_array(int a[], int num_elements)
{
   int i, min=a[0];
   for (i=1; i<num_elements; i++)
   {
	 if (a[i]<min)
	    min=a[i];
   }
   return(min);
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int MAX = 20;

	// Enter N
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;

	// Check N
	if(n>20) {
		cout<<"N must be not more than 20"<<endl;
		return 0;
	}

	// Enter array
	int a[MAX][MAX];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<"A["<<i<<"]["<<j<<"]"<<endl;
			cin>>a[i][j];
	    }
	}

	// Calculations
	double b[MAX];
	for(int i = 0; i<n; i++) {
		int max = max_array(a[i], n);
		int min = min_array(a[i], n);

		b[i] = (abs(max) + abs(min)) / 2;
	}

	// Output
	for(int i = 0; i<n; i++) {
		cout<<"B["<<i<<"]= "<<b[i]<<endl;
	}

	cin>>n;
	return 0;
}
