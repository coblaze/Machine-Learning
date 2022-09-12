#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tgmath.h> 

using namespace std;

//Function for Stats
void print_stats(vector<double> vect)
{
	//Calculating Sum
	double sum = accumulate(vect.begin(), vect.end(), 0);
	cout << "Sum: " << sum <<endl;
	
	//Calculating Mean
	double mean = accumulate(vect.begin(), vect.end(), 0.0) / vect.size();
	cout << "Mean: " << mean <<endl;
	
	//Calculating Median
	sort (vect.begin(), vect.end());
	if((vect.size() % 2) == 0) 
	{
		double median = (0.5*(vect[vect.size() / 2 - 1] + vect[vect.size() / 2])); //even
		cout << "Median: " << median <<endl;
	} else {
		double median = vect[vect.size() / 2]; //odd
		cout << "Median: " << median <<endl;
	}
	
	//Calculating Range
	double range = (vect.back() - vect.front());
	cout << "Range: " << range <<endl;
}

double sum(vector<double> a)
{
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += a[i];
	}
	return s;
}

double sqsum(vector<double> a)
{
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += pow(a[i], 2);
	}
	return s;
}

double stdev(vector<double> nums)
{
	double N = nums.size();
	return pow(sqsum(nums) / N - pow(sum(nums) / N, 2), 0.5);
}


//Function to compute covariance
double covar(vector<double> rm, vector<double> medv)
{
	int i;
	double rm_sum = accumulate(rm.begin(), rm.end(), 0);
	double medv_sum = accumulate(rm.begin(), rm.end(), 0);
	
	double rmMean =  rm_sum/ rm.size();
	double medvMean =  medv_sum/ rm.size();
	
	return ((rm[i] - rmMean)*(medv[i] - medvMean)) / (rm.size()*stdev(rm)* stdev(medv));
}

//Function to compute correlation
double cor(vector<double> rm, vector<double> medv)
{
	return covar(rm, medv)/ (rm.size()*stdev(rm)* stdev(medv));
}

int main(int argc, char** argv) {
  //create instance of readinfile
	ifstream bosReadFile;
	string line;
	string rm_in, medv_in;
	const int MAX_LEN = 1000;
	vector<double> rm(MAX_LEN);
	vector<double> medv(MAX_LEN);

	//Opening file 
	bosReadFile.open("Boston.csv");
	if(!bosReadFile.is_open())
	{
		cout << "Could not open file Boston.csv" <<endl;
		return 1;
	}
	getline(bosReadFile, line);

	int numObservations = 0;
	while(bosReadFile.good()){
		getline(bosReadFile, rm_in, ',');
getline(bosReadFile, medv_in, '\n');

rm.at(numObservations) = stof(rm_in);
medv.at(numObservations) = stof(medv_in);

numObservations++;
	} 

	rm.resize(numObservations);
	medv.resize(numObservations);

	//Closing File
bosReadFile.close(); 

//Outputs
cout <<"\nStats for rm"<<endl;
print_stats(rm);

cout <<"\nStats for medv"<<endl;
print_stats(medv);

cout<< "\n Covariance = " << covar(rm, medv) <<endl;

cout<< "\n Correlation = " << cor(rm, medv) <<endl;

cout <<"\nProgram Terminated.";
	
	return 0;
}





