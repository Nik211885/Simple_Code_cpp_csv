#include"User.h"
#include"Admin.h"
vector<string>temp;
vector<Ql_User>Ur;
int SearchIndex(string &a){
	int temp;
	for(int i=0;i<a.size();i++){
		while(a[i]==44){
			temp=i;
			break;
		}
	}
	return temp;
}
int SetPass_User(string &name,string &passworld){
    ifstream file;
    file.open("User.csv");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        temp.push_back(line);
    }
    for(int i=0;i<temp.size();i++){
    	string name="";
		string PassWord="";	
    	int index=SearchIndex(temp[i]);
    	name= temp[i].substr(0,index);
    	PassWord=temp[i].substr(index+1,temp[i].size());
    	Ql_User p;
        p.setId(name);
        p.setPassword(PassWord);
    	Ur.push_back(p);
	}
    for(int i=0;i<temp.size();i++){
		if(Ur[i].getId()==name && Ur[i].getPassword()==passworld){
            return 1;
            break;
        }
	}
	file.close();
}
vector<string>tmp;
vector<Admin>ad;
int Check_Admin(string &name,string &password){
	ifstream file;
	file.open("Admin.csv");
	string line;
	getline(file,line);
	while(getline(file,line)){
		tmp.push_back(line);
	}
	for(int i=0;i<tmp.size();i++){
		string name="";
		string password="";
		int index=SearchIndex(tmp[i]);
		name=tmp[i].substr(0,index);
		password=tmp[i].substr(index+1,tmp[i].size());
		Admin a;
		a.setId(name);
		a.setPassword(password);
		ad.push_back(a);
	}
	for(int i=0;i<tmp.size();i++){
		if(ad[i].getId()==name&&ad[i].getPassword()==password){
			return 1;
			break;
		}
	}

}