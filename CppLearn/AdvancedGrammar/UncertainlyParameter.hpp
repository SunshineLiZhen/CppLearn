#pragma once
#include <iostream>
#include <vector>
using namespace std;

///不定参数
class UncertainlyParameter
{
public:
	UncertainlyParameter();
	~UncertainlyParameter();

	long long add(int n, ...) {
		va_list arg_ptr;
		va_start(arg_ptr, n);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += va_arg(arg_ptr, int);
		}
		va_end(arg_ptr);
		return ans;
	}
};

