#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

double T(double x) {
	std::string file_name = "";
	if(abs(x) <= 1) {
		file_name = "dat_X_1_1.dat";
	} else if(x<-1) {
		x=1/x;
		file_name = "dat_X_00_1.dat";
	} else if(x>1) {
		x=1/x;
		file_name = "dat_X_1_00.dat";
	} 

	ifstream is(file_name);
	if( !is ) 
		throw "File not open";
	double ti,ui,xi,res=0;
	
	bool find = false;
	while( !is.eof()) {
		is>>xi;
		is>>ti;
		is>>ui;
		
		if (xi==x) { 
			res = ui; 
			find = true;
			break; 
		}
	}

	if(!find) {
		is.clear();
		is.seekg(0, ios::beg);

		double ti1, xi1, ui1;
		is>>xi;
	    is>>ti;
        is>>ui;

		while( !is.eof()) {
			ti1 = ti;
			ui1 = ui;
			xi1 = xi;

		    is>>xi;
		    is>>ti;
		    is>>ui;

			if(xi1<x && x<xi) {
				res = T(xi1)+(T(xi)-T(xi))*(x-xi1)/(xi-xi1);
			}

	    }
	}

	is.close();
	return res;
}

double U(double x) {
	std::string file_name = "";
	if(abs(x) <= 1) {
		file_name = "dat_X_1_1.dat";
	} else if(x<-1) {
		x=1/x;
		file_name = "dat_X_00_1.dat";
	} else if(x>1) {
		x=1/x;
		file_name = "dat_X_1_00.dat";
	} 
	
	ifstream is(file_name);
	if( !is ) 
		throw "File not open";
	double ti,ui,xi,res=0;

	bool find = false;
	while( !is.eof()) {
		is>>xi;
		is>>ti;
		is>>ui;
		
		if (xi==x) { 
			find = true;
			res = ui; 
			break; 
		}
	}

	if(!find) {
		is.clear();
		is.seekg(0, ios::beg);

		double ti1, xi1, ui1;
		is>>xi;
	    is>>ti;
        is>>ui;

		while( !is.eof()) {
			ti1 = ti;
			ui1 = ui;
			xi1 = xi;

		    is>>xi;
		    is>>ti;
		    is>>ui;

			if(xi1<x && x<xi) {
				res = U(xi1)+(U(xi)-U(xi))*(x-xi1)/(xi-xi1);
			}

	    }
	}

	is.close();
	return res;
}

double Gold(double x, double y) {
	if(x>y && y!=0) {
		return x/y;
	} else if(x<y && x!=0) {
		return y/x;
	} else {
		throw 5;
	}
}

double Gold1(double x, double y) {
	if(x>y && abs(y)>0.1) {
		return x/y;
	} else if(x<=y && abs(x)>0.1) {
		return y/x;
	} else if(x<y && abs(x)>0.1) {
		return 0.15;
	} else if(y==0) {
		return 0.1;
	}
}

double Glr(double x, double y) {
	if(abs(x)<1) {
		return x;
	} else if(abs(x)>=1 && abs(y)<1) {
		return y;
	} else if(abs(x)>=1 && abs(y)>=1 && sqrt(x*x+y*y-4)>0.1) {
		return y/sqrt(x*x+y*y-4);
	} else if(sqrt(x*x+y*y-4)<0.1) {
		throw 5;
	}
}

double Glrl(double x, double y) {
	if(abs(x)<1) {
		return x;
	} else if(abs(x)>=1) {
		return x;
	}
}

double Srz(double x, double y, double z) {
	if(x>y) {
		return T(x)+U(z)-T(y);
	} else if(x<=y) {
		return T(y)+U(y)-U(z);
	}
}

double Grs(double x, double y) {
	return 0.1389*Srz(x+y, Gold(x,y), Glr(x, x*y)) + 1.8389*Srz(x-y, Gold(y,x/5), Glr(5*x, x*y)) + 0.83*Srz(x-0.9, Glr(y,x/5), Gold(5*y, y));
}

double Grsl(double x, double y) {
	return 0.14*Srz(x+y, Gold1(x,y), Glrl(x,x*y)) + 1.83*Srz(x-y, Gold1(y,x/5), Glrl(4*x, x*y)) + 0.83*Srz(x,Glrl(y,x/4), Gold1(4*y,y));
}

double fun(double x,double y,double z)
{
     double temp;
     try {
        temp = x*x*Grs(y,z)+y*y*Grs(x,z)+0.33*x*y*Grs(x,z);
     }
     catch (int r)
     {
		 if(r == 5) {
			 temp = x*Grsl(x,y)+y*Grsl(y,z)+z*Grsl(z,x);
		 }     
	 }
	 catch (char *s) 
	 {
         cout<<" \n This is a catch : file is not open ";
         temp=1.3498*z+2.2362*y-2.348*x*y;
     }

     return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{

	double x,y,z,f;
    cout<<" Input x y z "<<endl;
    cin>>x>>y>>z;

    f=fun(x,y,z);
	
	cout<<"\n fun = "<<f<<endl;

    cin>>x;
	return 0;
}

