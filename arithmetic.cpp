#include<iostream>
#include<string>
using namespace std;
void print(string string, int n){
	int flag = 0,fl = 0;
	for(int i = 0; i <= n; i++){
		if(flag == 0 && (string[i] > '0' || string[i] == '-'))flag = 1;
		if(flag == 1)
			if(string[i] != '-' && string[i] != '0'){
				fl = 1;
				break;
			}
	}
	flag = 0;
	for(int i = 0; i <= n; i++){
		if(string[i] > '0' || string[i] == '-' || i == n)flag = 1;
		if(flag == 1 && fl == 1)cout << string[i];
	}
	if(fl == 0)cout << 0;
	cout << endl;
}
void add(string s1, string s2, int n1, int n2, int n, char* addition){
	int carry = 0,sum,f = 0;
	if(s1[0] == '-' && s2[0] == '-'){
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) > 0 && (i-n+n2-1) > 0)
				//both strings are available
				sum = s1[i-n+n1-1]+s2[i-n+n2-1]+carry-'0'-'0';
			else if((i-n+n1-1) > 0)
				sum = s1[i-n+n1-1]+carry-'0';
			else if((i-n+n2-1) > 0)
				sum = s2[i-n+n2-1]+carry-'0';
			else{
				sum = carry;
			}
			// cout << sum << endl;
			addition[i] = '0'+(sum)%10;
			carry = sum/10;
		}
		for(int i = 0; i <= n; i++){
			if(addition[i] > '0'){
				addition[i-1] = '-';
				break;
			}
		}
	}
	else if(s1[0] == '-'){
		f = 0;
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) > 0 && (i-n+n2-1) >= 0)
				//both strings are available
				sum = -s1[i-n+n1-1]+s2[i-n+n2-1]+carry+'0'-'0';
			else if((i-n+n1-1) > 0)
				sum = -s1[i-n+n1-1]+carry+'0';
			else if((i-n+n2-1) >= 0)
				sum = s2[i-n+n2-1]+carry-'0';
			else{
				sum = carry;
				if(sum < 0 && f == 0){
					f = 1;
					addition[i] = '-';
					continue;
				}
			}
			// cout << sum << endl;
			addition[i] = '0'+(sum)%10;
			// cout << addition[i] << endl;
			carry = sum/10;
			if(addition[i] < '0'){
				addition[i] = '0'+(sum)%10+10;
				carry = (sum/10)-1;
			}
			// cout << addition[i] << endl;

		}
		if(f == 1){
			// cout << "HI\n";
			f = 0; carry = 0;
			for(int i = n; i >= 0; i--){
				if((i-n+n1-1) > 0 && (i-n+n2-1) >= 0)
					//both strings are available
					sum = s1[i-n+n1-1]-s2[i-n+n2-1]+carry+'0'-'0';
				else if((i-n+n1-1) > 0)
					sum = s1[i-n+n1-1]+carry-'0';
				else if((i-n+n2-1) >= 0)
					sum = -s2[i-n+n2-1]+carry+'0';
				else{
					sum = carry;
				}
				// cout << sum << endl;
				addition[i] = '0'+(sum)%10;
				carry = sum/10;
				if(addition[i] < '0'){
					addition[i] = '0'+(sum)%10+10;
					carry = (sum/10)-1;
				}
			}
			for(int i = 0; i <= n; i++){
				if(addition[i] > '0'){
					addition[i-1] = '-';
					break;
				}
			}
		}
	}
	else if(s2[0] == '-'){
		f = 0;
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) >= 0 && (i-n+n2-1) > 0)
				//both strings are available
				sum = s1[i-n+n1-1]-s2[i-n+n2-1]+carry+'0'-'0';
			else if((i-n+n1-1) >= 0)
				sum = s1[i-n+n1-1]+carry-'0';
			else if((i-n+n2-1) > 0)
				sum = -s2[i-n+n2-1]+carry+'0';
			else{
				sum = carry;
				if(sum < 0 && f == 0){
					f = 1;
					addition[i] = '-';
					continue;
				}
			}
			// cout << sum << endl;
			addition[i] = '0'+(sum)%10;
			// cout << addition[i] << endl;
			carry = sum/10;
			if(addition[i] < '0'){
				addition[i] = '0'+(sum)%10+10;
				carry = (sum/10)-1;
			}
			// cout << addition[i] << endl;

		}
		if(f == 1){
			f = 0; carry = 0;
			for(int i = n; i >= 0; i--){
				if((i-n+n1-1) >= 0 && (i-n+n2-1) > 0)
					//both strings are available
					sum = -s1[i-n+n1-1]+s2[i-n+n2-1]+carry+'0'-'0';
				else if((i-n+n1-1) >= 0)
					sum = -s1[i-n+n1-1]+carry+'0';
				else if((i-n+n2-1) > 0)
					sum = s2[i-n+n2-1]+carry-'0';
				else{
					sum = carry;
				}
				// cout << sum << endl;
				addition[i] = '0'+(sum)%10;
				carry = sum/10;
				if(addition[i] < '0'){
					addition[i] = '0'+(sum)%10+10;
					carry = (sum/10)-1;
				}
			}
			for(int i = 0; i <= n; i++){
				if(addition[i] > '0'){
					addition[i-1] = '-';
					break;
				}
			}
		}
	}
	else{
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) >= 0 && (i-n+n2-1) >= 0)
				//both strings are available
				sum = s1[i-n+n1-1]+s2[i-n+n2-1]+carry-'0'-'0';
			else if((i-n+n1-1) >= 0)
				sum = s1[i-n+n1-1]+carry-'0';
			else if((i-n+n2-1) >= 0)
				sum = s2[i-n+n2-1]+carry-'0';
			else sum = carry;
			// cout << sum << endl;
			addition[i] = '0'+(sum)%10;
			carry = sum/10;
		}
	}
	cout << "\x1b[33maddition:\x1b[0m" << endl;
	print(addition, n);
}
void subtract(string s1, string s2, int n1, int n2, int n, char* subtraction){
	int carry = 0,sum,f = 0;
	if(s1[0] == '-' && s2[0] != '-'){
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) > 0 && (i-n+n2-1) >= 0)
				//both strings are available
				sum = s1[i-n+n1-1]+s2[i-n+n2-1]+carry-'0'-'0';
			else if((i-n+n1-1) > 0)
				sum = s1[i-n+n1-1]+carry-'0';
			else if((i-n+n2-1) >= 0)
				sum = s2[i-n+n2-1]+carry-'0';
			else{
				sum = carry;
			}
			// cout << sum << endl;
			subtraction[i] = '0'+(sum)%10;
			carry = sum/10;
		}
		for(int i = 0; i <= n; i++){
			if(subtraction[i] > '0'){
				subtraction[i-1] = '-';
				break;
			}
		}
	}
	else if(s1[0] == '-' && s2[0] == '-'){
		f = 0;
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) > 0 && (i-n+n2-1) > 0)
				//both strings are available
				sum = -s1[i-n+n1-1]+s2[i-n+n2-1]+carry+'0'-'0';
			else if((i-n+n1-1) > 0)
				sum = -s1[i-n+n1-1]+carry+'0';
			else if((i-n+n2-1) > 0)
				sum = s2[i-n+n2-1]+carry-'0';
			else{
				sum = carry;
				if(sum < 0 && f == 0){
					f = 1;
					subtraction[i] = '-';
					continue;
				}
			}
			// cout << sum << endl;
			subtraction[i] = '0'+(sum)%10;
			// cout << subtraction[i] << endl;
			carry = sum/10;
			if(subtraction[i] < '0'){
				subtraction[i] = '0'+(sum)%10+10;
				carry = (sum/10)-1;
			}
			// cout << subtraction[i] << endl;

		}
		if(f == 1){
			f = 0; carry = 0;
			for(int i = n; i >= 0; i--){
				if((i-n+n1-1) > 0 && (i-n+n2-1) > 0)
					//both strings are available
					sum = s1[i-n+n1-1]-s2[i-n+n2-1]+carry+'0'-'0';
				else if((i-n+n1-1) > 0)
					sum = s1[i-n+n1-1]+carry-'0';
				else if((i-n+n2-1) > 0)
					sum = -s2[i-n+n2-1]+carry+'0';
				else{
					sum = carry;
				}
				// cout << sum << endl;
				subtraction[i] = '0'+(sum)%10;
				carry = sum/10;
				if(subtraction[i] < '0'){
					subtraction[i] = '0'+(sum)%10+10;
					carry = (sum/10)-1;
				}
			}
			for(int i = 0; i <= n; i++){
				if(subtraction[i] > '0'){
					subtraction[i-1] = '-';
					break;
				}
			}
		}
	}
	else if(s1[0] != '-' && s2[0] != '-'){
		f = 0;
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) >= 0 && (i-n+n2-1) >= 0)
				//both strings are available
				sum = s1[i-n+n1-1]-s2[i-n+n2-1]+carry+'0'-'0';
			else if((i-n+n1-1) >= 0)
				sum = s1[i-n+n1-1]+carry-'0';
			else if((i-n+n2-1) >= 0)
				sum = -s2[i-n+n2-1]+carry+'0';
			else{
				sum = carry;
				if(sum < 0 && f == 0){
					f = 1;
					subtraction[i] = '-';
					continue;
				}
			}
			// cout << sum << endl;
			subtraction[i] = '0'+(sum)%10;
			// cout << subtraction[i] << endl;
			carry = sum/10;
			if(subtraction[i] < '0'){
				subtraction[i] = '0'+(sum)%10+10;
				carry = (sum/10)-1;
			}
			// cout << subtraction[i] << endl;

		}
		if(f == 1){
			f = 0; carry = 0;
			for(int i = n; i >= 0; i--){
				if((i-n+n1-1) >= 0 && (i-n+n2-1) >= 0)
					//both strings are available
					sum = -s1[i-n+n1-1]+s2[i-n+n2-1]+carry+'0'-'0';
				else if((i-n+n1-1) >= 0)
					sum = -s1[i-n+n1-1]+carry+'0';
				else if((i-n+n2-1) >= 0)
					sum = s2[i-n+n2-1]+carry-'0';
				else{
					sum = carry;
				}
				// cout << sum << endl;
				subtraction[i] = '0'+(sum)%10;
				carry = sum/10;
				if(subtraction[i] < '0'){
					subtraction[i] = '0'+(sum)%10+10;
					carry = (sum/10)-1;
				}
			}
			for(int i = 0; i <= n; i++){
				if(subtraction[i] > '0'){
					subtraction[i-1] = '-';
					break;
				}
			}
		}
	}
	else if(s2[0] == '-' && s1[0] != '-'){
		for(int i = n; i >= 0; i--){
			if((i-n+n1-1) >= 0 && (i-n+n2-1) > 0)
				//both strings are available
				sum = s1[i-n+n1-1]+s2[i-n+n2-1]+carry-'0'-'0';
			else if((i-n+n1-1) >= 0)
				sum = s1[i-n+n1-1]+carry-'0';
			else if((i-n+n2-1) > 0)
				sum = s2[i-n+n2-1]+carry-'0';
			else sum = carry;
			// cout << sum << endl;
			subtraction[i] = '0'+(sum)%10;
			carry = sum/10;
		}
	}
	cout << "\x1b[33msubtraction:\x1b[0m" << endl;
	print(subtraction, n);
}
void multiply(string s1, string s2, int n1, int n2, int n, char* product){
	int carry = 0,sum = 0;
	if(s1[0] == '-' && s2[0] == '-'){
		for(int i = 2*n; i >= 0; i--){
			sum = 0;
			for(int j = 0; j <= 2*n-i; j++)
				if(n1-1-j > 0 && i-2*n+n2-1+j > 0)
					sum += (s1[n1-1-j]-'0')*(s2[i-2*n+n2-1+j]-'0');
			sum += carry;
			product[i] = '0' + sum%10;
			carry = sum/10;
		}
	}
	else if(s1[0] == '-'){
		for(int i = 2*n; i >= 0; i--){
			sum = 0;
			for(int j = 0; j <= 2*n-i; j++)
				if(n1-1-j > 0 && i-2*n+n2-1+j >= 0)
					sum += (s1[n1-1-j]-'0')*(s2[i-2*n+n2-1+j]-'0');
			sum += carry;
			product[i] = '0' + sum%10;
			carry = sum/10;
		}
		for(int i = 0; i <= 2*n; i++){
			if(product[i] > '0'){
				product[i-1] = '-';
				break;
			}
		}
	}
	else if(s2[0] == '-'){
		for(int i = 2*n; i >= 0; i--){
			sum = 0;
			for(int j = 0; j <= 2*n-i; j++)
				if(n1-1-j >= 0 && i-2*n+n2-1+j > 0)
					sum += (s1[n1-1-j]-'0')*(s2[i-2*n+n2-1+j]-'0');
			sum += carry;
			product[i] = '0' + sum%10;
			carry = sum/10;
		}
		for(int i = 0; i <= 2*n; i++){
			if(product[i] > '0'){
				product[i-1] = '-';
				break;
			}
		}
	}
	else{
		for(int i = 2*n; i >= 0; i--){
			sum = 0;
			for(int j = 0; j <= 2*n-i; j++)
				if(n1-1-j >= 0 && i-2*n+n2-1+j >= 0)
					sum += (s1[n1-1-j]-'0')*(s2[i-2*n+n2-1+j]-'0');
			sum += carry;
			product[i] = '0' + sum%10;
			carry = sum/10;
		}
	}
	cout << "\x1b[33mmultiplication:\x1b[0m" << endl;
	print(product, 2*n);
}
void divide(string s1, string s2, int n1, int n2, int n, char* division){
	int carry = 0,sum = 0,neg = 0,digits = 500;
	int flag = 0,fl = 0,flo = 0,in = 0;
	char decimal[digits+1];
	decimal[0] = '.';
	for(int i = 1; i <= digits; i++)decimal[i] = '0';
	for(int i = 0; i < n2; i++){
		if(flag == 0 && (s2[i] > '0' || s2[i] == '-'))flag = 1;
		if(flag == 1)
			if(s2[i] != '-' && s2[i] != '0'){
				fl = 1;
				break;
			}
	}
	if(fl == 0){
		cout << "\x1b[33mdivision:\x1b[0m\ninf\n";
		return;
	}
	for(in = (s2[0] == '-') ? 1 : 0; in < n2; in++)if(s2[in] > '0')break;
	int n2p = n2-in,n1pp = (s1[0] == '-')?(n1-1):n1;
	char s2p[n2p],s1pp[n1pp];
	for(int i = 0; i < n2p; i++)s2p[i] = s2[i+in];
	for(int i = 0; i < n1pp; i++)s1pp[i] = (s1[0] == '-') ? s1[i+1] : s1[i];
	int arr[10][n2p+1];
	for(int j = 0; j < 10; j++){
		carry = 0; sum = 0;
		for(int i = n2p; i >= 0; i--){
			if(i-1 >= 0)sum = (s2p[i-1]-'0')*j+carry;
			else sum = carry;
			// if(i-1 >= 0)cout << "j:" << j << " i:" << i 
			// << " s2p[i-1]:" << s2p[i-1] << " carry:" << carry 
			// << " sum:" << sum << endl;
			arr[j][i] = sum%10;
			carry = sum/10;
			// cout << sum << endl;
		}
		// for(int i = 0; i <= n2p; i++)cout << arr[j][i];
		// cout << endl;
	}
	for(int i = 0; i <= n; i++)division[i] = '0';
	if(n1pp < n2p){
		carry = 0; sum = 0;
		char s1p[n2p];
		for(int i = 0; i < n2p; i++)s1p[i] = '0';
		for(int i = n2p-n1pp; i < n2p; i++)s1p[i] = s1pp[i-n2p+n1pp];
		int j;
		for(j = 0; j < 10; j++){
			if(arr[j][0] > 0)break;
			int flag = 0;
			for(int k = 0; k < n2p; k++){
				if(arr[j][k+1] < s1p[k]-'0')break;
				if(arr[j][k+1] > s1p[k]-'0'){
					flag = 1;
					break;
				}
			}
			if(flag == 1)break;
		}
		division[n] = '0'+j-1;
		carry = 0; sum = 0;
		for(int k = n2p-1; k >= 0; k--){
			sum = s1p[k]-arr[j-1][k+1]+carry-'0';
			s1p[k] = '0'+sum%10;
			carry = sum/10;
			if(s1p[k] < '0'){
				s1p[k] = '0'+(sum)%10+10;
				carry = (sum/10)-1;
			}
		}
		carry = 0; sum = 0;
		char s11[n2p+1];
		for(int i = 0; i <= n2p; i++){
			if(i == n2p){
				s11[i] = '0';
				// cout << s11[n1pp] << "HI";
			}
			else s11[i] = s1p[i];
		}
		// for(int i = n1pp-n2p; i <= n1pp; i++)cout << s11[i];
		// cout << s11[n1pp];
		// cout << endl;
		for(int i = 1; i <= digits; i++){
			int j;
			// for(int k = 0; k < n1pp; k++)cout << s1pp[k];
			// cout << endl;
			// for(int i = n1pp-n2p; i <= n1pp; i++)cout << s11[i];
			// cout << endl;
			for(j = 0; j < 10; j++){
				// if(arr[j][0] > 0)break;
				int flag = 0;
				for(int k = n2p-n2p; k <= n2p; k++){
					// cout << i << k << endl;
					if(arr[j][k-n2p+n2p] < s11[k]-'0')break;
					if(arr[j][k-n2p+n2p] > s11[k]-'0'){
						flag = 1;
						// cout << j << " arr:" << arr[j][k-i-n1pp+n2p+1];
						break;
					}
				}
				if(flag == 1)break;
			}
			decimal[i] = '0'+j-1;
			carry = 0; sum = 0;
			for(int k = n2p; k >= 0; k--){
				if(k-n2p+n2p >= 0)
					sum = s11[k]-arr[j-1][k-n2p+n2p]+carry-'0';
				else sum = s11[k]+carry-'0';
				s11[k] = '0'+sum%10;
				carry = sum/10;
				if(s11[k] < '0'){
					s11[k] = '0'+(sum)%10+10;
					carry = (sum/10)-1;
				}
			}
			for(int k = 0; k < n2p; k++){
				s11[k] = s11[k+1];
			}
			s11[n2p] = '0';
		}
	}
	else{
		carry = 0; sum = 0;
		for(int i = n-n1pp+n2p; i <= n; i++){
			if(i == n-n1pp+n2p){
				int j;
				for(j = 0; j < 10; j++){
					if(arr[j][0] > 0)break;
					int flag = 0;
					for(int k = 0; k < n2p; k++){
						if(arr[j][k+1] < s1pp[k]-'0')break;
						if(arr[j][k+1] > s1pp[k]-'0'){
							flag = 1;
							break;
						}
					}
					if(flag == 1)break;
				}
				division[i] = '0'+j-1;
				carry = 0; sum = 0;
				for(int k = n2p-1; k >= 0; k--){
					sum = s1pp[k]-arr[j-1][k+1]+carry-'0';
					s1pp[k] = '0'+sum%10;
					carry = sum/10;
					if(s1pp[k] < '0'){
						s1pp[k] = '0'+(sum)%10+10;
						carry = (sum/10)-1;
					}
				}
			}
			else{
				int j;
				// for(int k = 0; k < n1pp; k++)cout << s1pp[k];
				// cout << endl;
				for(j = 0; j < 10; j++){
					// if(arr[j][0] > 0)break;
					int flag = 0;
					for(int k = i-n+n1pp-n2p-1; k < n2p+i-n+n1pp-n2p; k++){
						// cout << i << k << endl;
						if(arr[j][k-i+n-n1pp+n2p+1] < s1pp[k]-'0')break;
						if(arr[j][k-i+n-n1pp+n2p+1] > s1pp[k]-'0'){
							flag = 1;
							break;
						}
					}
					if(flag == 1)break;
				}
				division[i] = '0'+j-1;
				carry = 0; sum = 0;
				for(int k = n2p-1+i-n+n1pp-n2p; k >= 0; k--){
					if(k+1-i+n-n1pp+n2p >= 0)
						sum = s1pp[k]-arr[j-1][k+1-i+n-n1pp+n2p]+carry-'0';
					else sum = s1pp[k]+carry-'0';
					s1pp[k] = '0'+sum%10;
					carry = sum/10;
					if(s1pp[k] < '0'){
						s1pp[k] = '0'+(sum)%10+10;
						carry = (sum/10)-1;
					}
				}
			}
		}
		carry = 0; sum = 0;
		char s11[n1pp+1];
		for(int i = 0; i <= n1pp; i++){
			if(i == n1pp){
				s11[i] = '0';
				// cout << s11[n1pp] << "HI";
			}
			else s11[i] = s1pp[i];
		}
		// for(int i = n1pp-n2p; i <= n1pp; i++)cout << s11[i];
		// cout << s11[n1pp];
		// cout << endl;
		for(int i = 1; i <= digits; i++){
			int j;
			// for(int k = 0; k < n1pp; k++)cout << s1pp[k];
			// cout << endl;
			// for(int i = n1pp-n2p; i <= n1pp; i++)cout << s11[i];
			// cout << endl;
			for(j = 0; j < 10; j++){
				// if(arr[j][0] > 0)break;
				int flag = 0;
				for(int k = n1pp-n2p; k <= n1pp; k++){
					// cout << i << k << endl;
					if(arr[j][k-n1pp+n2p] < s11[k]-'0')break;
					if(arr[j][k-n1pp+n2p] > s11[k]-'0'){
						flag = 1;
						// cout << j << " arr:" << arr[j][k-i-n1pp+n2p+1];
						break;
					}
				}
				if(flag == 1)break;
			}
			decimal[i] = '0'+j-1;
			carry = 0; sum = 0;
			for(int k = n1pp; k >= 0; k--){
				if(k-n1pp+n2p >= 0)
					sum = s11[k]-arr[j-1][k-n1pp+n2p]+carry-'0';
				else sum = s11[k]+carry-'0';
				s11[k] = '0'+sum%10;
				carry = sum/10;
				if(s11[k] < '0'){
					s11[k] = '0'+(sum)%10+10;
					carry = (sum/10)-1;
				}
			}
			for(int k = 0; k < n1pp; k++){
				s11[k] = s11[k+1];
			}
			s11[n1pp] = '0';
		}
	}
	if(s1[0] == '-' && s2[0] != '-' || s1[0] != '-' && s2[0] == '-'){
		neg = 1;
		for(int i = 0; i <= n; i++){
			if(division[i] > '0'){
				division[i-1] = '-';
				break;
			}
		}
	}
	cout << "\x1b[33mdivision:\x1b[0m" << endl;
	flag = 0,fl = 0;
	for(int i = 0; i <= n; i++){
		if(flag == 0 && (division[i] > '0' || division[i] == '-'))flag = 1;
		if(flag == 1)
			if(division[i] != '-' && division[i] != '0'){
				fl = 1;
				break;
			}
	}
	flag = 0,flo = 0;
	for(int i = 0; i <= n; i++){
		if(division[i] > '0' || division[i] == '-' || i == n)flag = 1;
		if(flag == 1 && fl == 1)cout << division[i];
	}
	for(int i = 1; i <= digits; i++)if(decimal[i] > '0')flo = 1;
	if(fl == 0){
		if(flo == 0 || (flo == 1 && neg == 0))cout << 0;
		if(flo == 1 && neg)cout << "-0";
	}
	int d;
	for(d = digits; d >= 1; d--)if(decimal[d] > '0')break;
	for(int i = 0; i <= d; i++)if(flo == 1)cout << decimal[i];
	cout << endl;
}
int main(){
	string s1, s2;
	cout << "\x1b[33mEnter 1st number: \x1b[0m";
	cin >> s1;
	cout << "\x1b[33mEnter 2nd number: \x1b[0m";
	cin >> s2;						
	// cout << s1 << endl << s2 << endl;
	// cout << s1[0] << endl << s2[0] << endl;
	int n1 = s1.size(), n2 = s2.size();
	int n = (n1 >= n2) ? n1 : n2;
	n = n+1;
	char addition[n+1], subtraction[n+1], product[2*n+1], division[n+1];
	cout << "n1: " << n1 << " n2: " << n2 
		 << " n: " << n << " 2n: " << 2*n << endl;
	//now addition starts
	add(s1, s2, n1, n2, n, addition);
	//now subtraction starts
	cout << "\x1b[33m(1st number-2nd number)\x1b[0m";
	subtract(s1, s2, n1, n2, n, subtraction);
	cout << "\x1b[33m(2nd number-1st number)\x1b[0m";
	subtract(s2, s1, n2, n1, n, subtraction);
	//now multiplication starts
	multiply(s1,s2,n1,n2,n,product);
	//now division starts
	cout << "\x1b[33m(1st number/2nd number)\x1b[0m";
	divide(s1, s2, n1, n2, n, division);
	cout << "\x1b[33m(2nd number/1st number)\x1b[0m";
	divide(s2, s1, n2, n1, n, division);
	return 0;
}