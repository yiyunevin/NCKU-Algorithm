#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int getMaxOne(vector<int> arr);
void Merge(vector<int> &arr, int startt, int midd, int endd);
void MergeSort(vector<int> &arr, int start, int end);

int main(){

    // Open Files
    ifstream in_file("input.txt", ios::in);
    if(!in_file){
        cerr << "Fail to input." << endl;
        exit(1);
    }
    ofstream out_file("output.txt", ios::out);
    if(!out_file){
        cerr << "Fail to ioutput." << endl;
        exit(1);
    }

    vector<int> A; 
    int key;        // number of elements

    // Read input file ----------------------------------
    
    in_file >> key;
    for(int n=0; n < key; ++n){
        int i;
        in_file >> i;
        A.push_back(i);
    }
    
    // for(int n = 0; n < key; ++n)
    //     cout << A[n] <<" ";
    // cout << endl;

    // Merge Sort ---------------------------------------    

    MergeSort(A, 0, key-1);


    // Write output file --------------------------------

    // for(int n = 0; n < key; ++n)
    //     cout << A[n] <<" ";
    
    out_file << key <<"\n";
    for(int n=0; n < key; ++n)
        out_file << A[n] <<"\n";

    return 0;
}

// Setting Flag
int getMaxOne(vector<int>arr){
    int max = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if (arr[i] > max)
            max = arr[i];
    }
    //cout << "flag/ max: " << max <<endl;
    return (max+1000);
}

void Merge(vector<int> &arr, int startt, int midd, int endd){
    int size_L = midd - startt + 1;
    int size_R = endd - midd;
    int flag = getMaxOne(arr);

    vector<int>L(arr.begin() + startt, arr.begin() + startt + size_L);
    vector<int>R(arr.begin() + startt + size_L, arr.begin() + startt + size_L + size_R);
    L.push_back(flag);
    R.push_back(flag);

    int i = 0;
    int j = 0;
    for(int k = startt; k <= endd; k++){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i ++;
        }else{
            arr[k] = R[j];
            j ++;
        }
    }
}

void MergeSort(vector<int> &arr, int start, int end){
    if(end > start){
        int middle = (end + start) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle+1, end);
        Merge(arr, start, middle, end);
    }
}
