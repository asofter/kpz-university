// Описати шаблон класу Matrix, який визначає матрицю елементів будь-якого типу. Написати програму тестування цього шаблону дійсних і цілих чисел.

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class matrix
{
  private:
	std::vector<std::vector<T> > arr;

  public:
    matrix(int rows, int cols) : arr(rows)
    {
      for (int i = 0; i < rows; ++i)
        arr[i].resize( cols );  
    }
 
    void fill(int m, int n, T value)
    {
		for (std::size_t i = 0; i<arr.size(); i++) {
			if(i == m-1) {
			    for (std::size_t j=0; j<arr[i].size(); j++) {
	                if(j == n-1) {
						arr[i][j] = value;
					}
		        }
			}
		}
    }

    void output() const {
       for (std::size_t i = 0; i<arr.size(); i++) {
          for (std::size_t j=0; j<arr[i].size(); j++)
             std::cout<<arr[i][j]<<' ';
         
          std::cout<<std::endl;
       }
    }
 
};

int _tmain(int argc, _TCHAR* argv[])
{
	matrix<int>matrix1( 3, 3 );
	matrix1.fill(1,1, 3);
	matrix1.fill(1,2, 6);
	matrix1.fill(1,3, 2);
	matrix1.fill(2,3, 4);
    matrix1.output();

	cout<<endl;

    matrix<double>matrix2( 3, 3 );
	matrix2.fill(1,1, 3.2);
	matrix2.fill(1,2, 6.4);
	matrix2.fill(1,3, 2.3);
	matrix2.fill(2,3, 4.2);
    matrix2.output();


	int n = 0;
	cin>>n;
	return 0;
}

