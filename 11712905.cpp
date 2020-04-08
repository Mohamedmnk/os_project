#include<iostream>
#include<math.h>
 
using namespace std;
 
float encrypt[2][1], decrypt[2][1], a[2][2], b[2][2], mes[10][1], c[2][2];
 
void encryption();	//encrypts the message
void decryption();	//decrypts the message
void getKeyMessage();	//gets key and message from user
void inverse();		//finds inverse of key matrix
 
int main() {
	getKeyMessage();
	encryption();
	decryption();
}
 
void encryption() {
	int i, j, k;
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
	
	cout<<"\nEncrypted string is: ";
	for(i = 0; i < 10; i++)
		cout<<(char)(fmod(encrypt[i][0], 26) + 97);
}
 
void decryption() {
	int i, j, k;
	
	inverse();
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
	
	cout<<"\nDecrypted string is: ";
	for(i = 0; i < 10; i++)
		cout<<(char)(fmod(decrypt[i][0], 26) + 97);
	
	cout<<"\n";
}
 
void getKeyMessage() {
	int i, j;
	char msg[2];
 
	cout<<"Enter 2x2 matrix for key (It should be inversible):\n";
	
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++) {
			cin>>a[i][j];
			c[i][j] = a[i][j];
		}
	
	cout<<"\nEnter a letter string: ";
	cin>>msg;
	
	for(i = 0; i < 10; i++)
		mes[i][0] = msg[i] - 97;
}
 
void inverse() {
	int i, j, k;
	float p, q;
	
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++) {
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
		
	for(k = 0; k < 2; k++) {
		for(i = 0; i < 2; i++) {
			p = c[i][k];
			q = c[k][k];
				
			for(j = 0; j < 2; j++) {
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}
	
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			b[i][j] = b[i][j] / c[i][i];
	
	cout<<"\n\nInverse Matrix is:\n";
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++)
			cout<<b[i][j]<<" ";
		
		cout<<"\n";
	}
}
