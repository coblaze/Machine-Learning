#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tgmath.h> 

using namespace std;

//Function to Calculate Loogisitc Regression
double logReg(vector<double> a, vector <double> b, matrix t) 
{
	double gradDes = function();
	double weight, label, prop;
	double learningRate = 0.001;
	for (int i; i = 0; i++)
		{
			double prob = (sigmoid(a) %*% weight);
			double error = label - prop;
			weight = weight + learningRate * t(a) %*% error
		}
	return s;
}

//Function to Calculate Accuracy 
double calAcc(vector<double> a, vector<double> b, vector<double> c)
{
	double s,TP, FN, TN;
	s = ((TP+TN) / (TN +TN+FP+FN)) * 100;
	return s;
}

//Function to Calcualte Sensitivity
double calSen(vector<double> a, vector<double> b)
{
 	double s, TP, TN, FN;
	s = TP / (TN +FN) * 100;
	return s;
}


//Function to calculate specificity
double calSpec(vector<double> a, vector<double> b)
{
	double s, TN, FP;
	s = (TN/(TN+FP)) * 100;
}

//*******************MAIN FUNCTION***************
int agn5(int argc, char** argv) {
  //create instance of readinfile
	ifstream TiReadFile;
	string line;
	string rm_in, medv_in, ti_in;
	const int MAX_LEN = 800;
	vector<double> rm(MAX_LEN);
	vector<double> medv(MAX_LEN);
	vector<double> ti(MAX_LEN);

	//Opening file 
	TiReadFile.open("titanic_project.csv");
	if(!TiReadFile.is_open())
	{
		cout << "Could not open file titanic_project.csv" <<endl;
		return 1;
	}
	getline(TiReadFile, line);
	
	int numObservations = 0;
	while(TiReadFile.good()){
		getline(TiReadFile, rm_in, ',');
getline(TiReadFile, medv_in, '\n');
		getline(TiReadFile, ti_in, '\n');


rm.at(numObservations) = stof(rm_in);
medv.at(numObservations) = stof(medv_in);

numObservations++;
	} 

	rm.resize(numObservations);
	medv.resize(numObservations);

	//Closing File
TiReadFile.close(); 

//Outputs
cout <<"\nAccuracy: "<<endl;
calAcc(rm, medv, ti);

cout <<"\nSensitivity: "<<endl;
calSen(rm, medv);

cout<< "\n Specificity:  " << calSpec(rm, medv) <<endl;

cout<< "\n Regression Coefficient = " << logReg(rm, medv) <<endl;

	
	return 0;
}

/* Logistics  psudocode 
sigmoid <- function(z){
1.0 / (1+exp(-z))
}
# set up weight vector, label vector, and data matrix
weights <- c(1, 1)
data_matrix <- cbind(rep(1, nrow(train)), train$fibrinogen)
labels <- as.integer(train$ESR) - 1*/