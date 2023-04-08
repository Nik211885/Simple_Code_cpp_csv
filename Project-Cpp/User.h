#include<bits/stdc++.h>
using namespace std;
class Ql_User{
    private:
        string id;
        string password;
    public:
        Ql_User(){};
        Ql_User(string _id,string _password){
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