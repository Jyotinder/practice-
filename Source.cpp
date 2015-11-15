#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<long long > lv;
typedef pair<long long, long long> plonglong;
typedef pair<long long, plonglong> pminlonglong;
typedef vector<pminlonglong> vpminlonglong;



bool compare(pminlonglong first, pminlonglong second)
{
	return first.first < second.first;
}


string min(string str)
{
	lv num;
	stringstream ss(str);
	long long buf;
	vpminlonglong vlongm;
	while (ss>>buf)
	{
		//cout << buf<<endl;
		num.push_back(buf);
	}

	sort(num.begin(), num.end());
	long long min = LLONG_MAX;
	for (int i = 0; i < (int)num.size() -1 ; i++){
		plonglong n(num[i], num[i + 1]);

		min = abs(abs(num[i]) - abs(num[i+1]));
		pminlonglong m(min, n);
		vlongm.push_back(m);
		//cout << num[i]<<endl;
	}
	sort(vlongm.begin(),vlongm.end(),compare);
	min = LLONG_MAX;
	string rstr;
	string buf1;
	stringstream rst;
	for (int i = 0; i < vlongm.size() - 1; i++)
	{
		pminlonglong x = vlongm[i];
		plonglong y = x.second;
		//cout << x.first << " " << y.first <<","<< y.second << endl;
		if (min >= x.first){
			min = x.first;
			rst << y.first << " " << y.second<<" ";

		}
	}
	while (rst >> buf1)
		rstr += buf1+" ";
	//cout << rstr;
	

	
	return ( rstr);
}



int main() {
	string str = "-20 -357930 -3620601 7374819 30 1 -345 -356 32 3 -347  ";

	cout<<min(str);




#if 0
	std::string s = "scott>=tiger>=mushroom";
	std::string delimiter = ">=";
	lv array;
	stringstream ss(str);
	string buf;
	while (ss >> buf){
		long i = atol(buf.c_str());
		array.push_back(i);
	}
	return buf;

	size_t pos=0;
	size_t prevpos = 0;
	string token;
	while ((pos =s.find(delimiter,pos+1)) !=std::string::npos){
		cout << prevpos<<" "<<pos << endl;
		token = s.substr(prevpos, pos-prevpos);
		cout<<token<<endl;
		token.clear();
		prevpos = pos+ 2;
	}
	token = s.substr(prevpos);
	cout<<token<<endl;
#endif
#if 0
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		std::cout << token << std::endl;
		s.erase(0, pos + delimiter.length());
	}
	std::cout << s << std::endl;
# endif
#if 0
	string str("-20 -357930 -3620601 7374819 30");
	string buf; 
	stringstream ss(str); 

	vector<long long> array;
	vector<long long>::iterator it;

	while (ss >> buf){
		long i = atol(buf.c_str());
		array.push_back(i);
	}
	std::sort(array.begin(), array.end());

	long long min = _ULLONG_MAX;
	long long xmin = _ULLONG_MAX;
	vector<long long> minarray;
	vector<pair<long long,pair<long, long>>> x;

	int count=array.size;

	for (int i = 0; i < count-1; i++)
	{
		pair<long, long> xx;
		xx.first = array[i];
		xx.second = array[i+1];
		if (array[i] < 0)
			array[i] *= (long long)-1;
		if (array[i+1] < 0)
			array[i+1] *= (long long)-1;
		min = array[i] - array[i + 1];
		if (min < 0)
			min *= (long long)-1;
		if (xmin > min){
			pair<long long, pair<long, long>> jx(min,xx);
			xmin = min;
			x.push_back(jx);
		}
	}

	vector<pair<long long, pair<long, long>>> *itx;
	string str1;
	for (itx = x.begin(); itx != x.end(); itx++){
		cout << *it << endl;

	}
#endif
}