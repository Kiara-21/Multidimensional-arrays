#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  const int n = 7, m = 49;
  double average = 0;
  int i=0, j=0;
  int s = 0;
  int c = 0;
  int arr[n][n];

cout << "Load matrix" << endl;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
     cin >> arr[i][j];
  }
  
cout << "----------------------------"<<endl;

  
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
     cout << setw(5) << arr[i][j]; 
    cout << "\n";
  }
  
cout << "----------------------------"<<endl;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    if (arr[i][j]>0){
      s = s + arr[i][j];
      c++;
    }
  }

  average = s / c;
  
  cout << "Average: " << average << endl;
  for (i = 0; i < n; i++)
  {
      if (arr[i][3]==6)
        arr[i][3] = 100;
  }

cout << "----------------------------"<<endl;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
     cout << setw(5) << arr[i][j]; 
    cout << "\n";
  }
  
cout << "----------------------------"<<endl;

  int G[m];
  int k = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
        if (arr[i][j]<(-5)){
            G[k] = arr[i][j];
            k++;
        }
    }
  }
  

for (int i = 0; i<k; i++){
    cout << G[i] <<" ";
}

cout << "----------------------------"<<endl;

int F[m];
int u = 0;
int sum = 0;
for (j = 0; j < n; j++)
{
sum = 0;
for (i = 0; i < n; i++)
{
if (j>=i&&j<=n-i-1) {
sum = sum + arr[i][j]; 
}
}
F[u] = sum; 
u++;
}

for (int i = 0; i < u; i++){
    cout << F[i] << " ";
}
  system("pause");
  return 0;
}