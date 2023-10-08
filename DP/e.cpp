#include <bits/stdc++.h>
using namespace std;

void subsetsUtil(vector<int>& A, vector<vector<int> >& res, vector<int>& subset, int index) {

	res.push_back(subset);

	for (int i = index; i < A.size(); i++) {

		subset.push_back(A[i]);
		subsetsUtil(A, res, subset, i + 1);
		subset.pop_back();
	}

	return;
}

vector<vector<int> > subsets(vector<int>& A) {
	vector<int> subset;
	vector<vector<int>> res;

	int index = 0;
	subsetsUtil(A, res, subset, index);

	return res;
}


int main() {

	vector<int> array = { 1, 5, 3};

	vector<vector<int> > res = subsets(array);

	vector<int>nums;
	map<int, int>m;

	for (int i = 0; i < res.size(); i++) {
		int sum = 0;
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
			//sum += res[i][j];
		}
		cout << "\n";
		// nums.push_back(sum);
		//++m[sum];
	}


	// for (auto q : nums) {
	// 	++m[q];
	// 	cout << q << " ";
	// }

	// for (auto q : m) {
	// 	cout << q.first << " " << q.second << "\n";
	// }
	// cout << "\n\nThe Total number Of subset: " << nums.size() << "\n";
	return 0;
}









Deepanshu Goyal
ALOK SRIVASTAVA
Aashish Daga
Abhishek Anand
Aditya Gajanan Zope
Ajoy Mohanta
Akshay Babbar
Amandeep Singh
Amit Pandey
Arshi Mustafa
Ashish Kumar Patel
Ashish Pal
Ashutosh Chandra
Ashwani Yadav
Birendra Rai
Darshan R
Divyanshu Gairola
Fahad Naeem Khan
Gaurav KHUBCHANDANI
Gunaseelan R
Hari Nagarjuna Chowdary Polavarapu
Harsh Vijay
Hitanshu Dhawan
Jagdish Amrutkar
Jayant Kumar
Jayesh Dahiwale
Kiran
Kishansingh Rathore
Kumar
Mohita U
NITESH MISHRA
Nishriti Kukkar
Piyush Mishra
Prabeen
Prabhu R
Pradipkumar Gheewala
Pradyumna Jha
Prateek
Pritish Godse
R Bharadwaj
Ragul V
Ravi Prakash Singh
Rishi Tiwari
SARITA CHAUHAN
SHASHI KUMAR M N
SWAPNIL GARG
Sai Santhosh
Salil Prakash Ekka
Sandeep
Sangram Badi
Shashwat Pratap
Shawon Roy
Shreya Sivakumar
Shuvajyoti
Subramanian S
Suchitra Swain
Sumit Negi
Suraj kumar
Surya Prakash Singh
Sushant Ganiga
Swarnim Indraguru
Tanu Goel
VIJAY KUMAR GARG
Ved Prakash
Venkateswara Reddy Thanubuddi
Vishal Kataria
Yogesh Kumar Verma
akash swarnkar
jayaprasad
karthik parshi
kashish sharma
santanu pradhan