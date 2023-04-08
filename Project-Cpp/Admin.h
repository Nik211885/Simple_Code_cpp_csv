#include<bits/stdc++.h>
using namespace std;
class Admin{
    private:
        string id;
        string password;
    public:
        Admin(){};
        Admin(string _id,string _password){
            this->id=_id;
            this->password=_password;
        }
        string getId(){
            return id;
        }
        string getPassword(){
            return password;
        }
        void setId(string _id){
            this->id=_id;
        }
        void setPassword(string _password){
            this->password=_password;
        }

};