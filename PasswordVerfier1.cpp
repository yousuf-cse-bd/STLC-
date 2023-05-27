/**
 * @file PasswordVerfier1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Verify Password Requirements | C++ Programming Example
 * @version 0.1
 * @date 2022-05-27
 * @since SaturDay; 08:24 AM
 * @copyright Copyright (c) 2022
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * At least 8 characters long.
 * At least 1 UpperCase letter.
 * At least 1 LowertCase letter.
 * At least 1 digit.
 * At least 1 symbol
 */

bool passwordVerifier(const string &password){
	
	constexpr unsigned int stdPassLenMin{8};
	if(password.length() < stdPassLenMin){
		cerr<<"Passoword Too Small."<<endl;
		return false;
	}
	
	bool hasUpperCase{false};
	bool hasLowerCase{false};
	bool hasDigit{false};
	bool hasSymbol{false};
	
	for(const char &x: password){
		if(isupper(x)){
			hasUpperCase = true;
		}
		else if(islower(x)){
			hasLowerCase = true;
		}
		else if(isdigit(x)){
			hasDigit = true;
		}
		else if(ispunct(x)){
			hasSymbol = true;
		}
	}
	
	if(hasUpperCase && hasLowerCase && hasDigit && hasSymbol){
		return true;
	}
	else{
		return false;
	}
}


int main(int argc, const char *const argv[]){
    /* code */
    system("cls");
	
	const string password{"Ax@5abcdefgh"};
	
	if(passwordVerifier(password)){
		cout<<"Verified Password!"<<endl;
	}
	else{
		cout<<"Invalid Password!"<<endl;
	}
	
	system("pause>0");
    return 0;
}