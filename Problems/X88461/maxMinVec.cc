#include <vector>
#include <iostream>
using namespace std;

void llegir(int n,vector<int> &v)
{
	for (int i=0;i<n;++i) cin>>v[i];
}
void evaluar(const vector<int> &v,int &max,int &min, int &n)
{
	for (int i=0;i<n;++i){
		if (max<v[i]) max=v[i];
		if (min>v[i]) min=v[i];
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	llegir(n,v);
	int max=-99;
	int min=99;
	evaluar(v,max,min,n);
	cout<<max<<" "<<min<<endl;
}
	
