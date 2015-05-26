
#include <iostream>
using namespace std;
int main(){
	cout << 1 << "\n" << endl;
	cout << 400 << endl;
	cout << 400 << endl;
	for (int i = 0; i < 400; i++){
		for (int j = 0; j < i; j++){
			cout << 0;
		}
		for (int j = i; j < 400; j++){
			cout << 1;
		}
		cout << endl;
	}
}