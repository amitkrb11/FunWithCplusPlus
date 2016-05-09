//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<string>
//#include<stdio.h>
//using namespace std;
//
//int main() {
//	int t=0, N=0, D=0,E=0, prev=0;
//	int str[200];
//	int i = 0, j = 0, C = 1;
//	scanf("%d", &t);
//	while (t--)
//	{
//		cin >> N >> D >> E;
//		for (int x = 0; x < E; x++){
//			cin >> str[x];
//		}
//		while(C != E)
//		{
//			int prev = str[i];
//			while (prev <= D && (N > 0)){
//				j = i;
//				j++;
//				C++;
//				if (N)
//					N--;
//				prev = prev * 10 + str[j];
//			}
//
//			if (N == 0){
//				cout << "Abort" << endl;
//				break;
//			}
//			i++;
//		}
//		
//		
//
//	}
//	return 0;
//}