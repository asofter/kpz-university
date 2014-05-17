// 8.	Задано текст українською (російською, англійською) мовою в форматі ASCII / UNICODE. 
// Використовуючи контейнер   set   побудувати множину речень, впорядкувати у алфавітному порядку за першим словом та роздрукувати.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
#include <locale>
using namespace std;

vector<string> explode( const string &delimiter, const string &explodeme);

void print(const std::string &item)
{
    std::cout << item << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	system("chcp 1251");

	string str = "D have a lovely bunch of cocoa nuts. Born українською мовою. Простий текст. Я такий. Мій на украинском языке.";
	str += " ";

    vector<string> v = explode(". ", str);
	std::set<string> sentences;

    for(int i=0; i<v.size(); i++)
		sentences.insert(v[i]); 

	std::for_each(sentences.begin(), sentences.end(), &print);

	cin>>str;

	return 0;
}

vector<string> explode( const string &delimiter, const string &str)
{
    vector<string> arr;
 
    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0)
        return arr;//no change
 
    int i=0;
    int k=0;
    while( i<strleng )
    {
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        if (j==delleng)//found delimiter
        {
            arr.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        }
        else
        {
            i++;
        }
    }
    arr.push_back(  str.substr(k, i-k) );
    return arr;
}
