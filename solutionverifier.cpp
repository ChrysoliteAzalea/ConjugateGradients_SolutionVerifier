#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc,char *argv[]) {
	if (argc<3) {
		cout <<"Not enough arguments given. The first argument should be the name of the task file and the second argument should be the name of the solution file.\n";
		return 2;
	}
	int n;
	char readthis[100];
// Чтение файла
	ifstream source(argv[1]);
	source>>readthis;
	n=atoi(readthis);
	double **leftpart;
	leftpart=new double*[n];
	for (int i=0;i<n;i++) leftpart[i]=new double[n];
	double *rightpart;
	rightpart=new double[n];
	double *start;
	start=new double[n];
	double *solution;
	solution=new double[n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			source>>readthis;
			leftpart[i][j]=atof(readthis);
		}			
		source>>readthis;
		rightpart[i]=atof(readthis);
	}
	source.close();
	ifstream approx(argv[2]);
	for (int i=0;i<n;i++) {
		approx>>readthis;
		solution[i]=atof(readthis);
	}
	double leftsum;
	for (int i=0;i<n;i++) {
		leftsum=0;
		cout <<"Checking the equation n. "<<i<<":\n";
		for (int j=0;j<n;j++) leftsum+=leftpart[i][j]*solution[j];
		cout <<" Got "<<leftsum<<", should be "<<rightpart[i]<<"\n";
	}
	return 0;
}
