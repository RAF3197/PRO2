#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Equip{
	int id;
	int punts;
	int gols_favor;
	int gols_contra;
};

bool comp(const Equip &a,const Equip &b){
	if (a.punts==b.punts){
		int ga=a.gols_favor-a.gols_contra;
		int gb=b.gols_favor-b.gols_contra;
		if (ga==gb){
			return a.id<b.id;
		}
		return ga>gb;
	}
	return a.punts>b.punts;
}
	
	

int main(){
	int n;
	cin>>n;
	vector<Equip> v(n);
	for (int i=0;i<n;++i){
		v[i].id=i+1;
		v[i].punts=0;
		v[i].gols_contra=0;
		v[i].gols_favor=0;
	}
	for (int i=0;i<v.size();++i){
		for (int j=0;j<v.size();++j){
			int gl,gv;
			cin>>gl>>gv;
			if (i!=j){
				if (gl>gv) v[i].punts+=3;
				else if (gl==gv){
					 ++v[i].punts;
					 ++v[j].punts;
				 }
				 else v[j].punts+=3;
				 v[i].gols_favor+=gl;
				 v[i].gols_contra+=gv;
				 v[j].gols_favor+=gv;
				 v[j].gols_contra+=gl;
			 }
		 }
	 }
	 sort (v.begin(),v.end(),comp);
	 for (int i=0;i<n;++i){
		 cout<<v[i].id<<" "<<v[i].punts<<" "<<v[i].gols_favor<<" "<<v[i].gols_contra<<endl;
	 }
 }
			 
				 
