#include"Check.h"
class InputForm{
    private:

    public:
        void Input(){
            string name;
            string password;
            string pass;
            cout<<"Chon yeu cau "<<endl;
            cout<<"[1] Dang nhap voi tai khoan User"<<endl;
            cout<<"[2] Dang nhap voi tai khoan Admin"<<endl;
            cout<<"[0] Dang ki tai khoan User "<<endl;
            cout<<"Chon yeu cau ";
            int n;
            cin>>n;
            cin.ignore();
            switch(n){
                case 2:
                    Form(name,password);
                    if(Check_Admin(name,password)==1){
                        cout<<"Dang nhap thanh cong ";
                    }
                    else{
                        cout<<"Tai khoan hoac mat khau khong dung";
                    }
                    break;
                case 1:
                    Form(name,password);
                    if(SetPass_User(name,password)==1){
                        cout<<"Dang nhap thanh cong ";
                    }
                    else{
                        cout<<"Tai khoan hoac mat khau khong dung";
                    }
                case 0:
                    cout<<"Form insert new user"<<endl;
                    while (true){
                        Form(name,password);
                        cout<<"Nhap vao mat khau xac nhan ";
                        getline(cin,pass);
                        if(checkPassWord(password,pass)){
                            ofstream file;
                            file.open("User.csv",ios::app);
                            file<<name<<","<<password<<"\n";
                            cout<<"Dang ki tai khoan thanh cong";
                            break;
                        }
                        else{
                            cout<<"Mat khau va mat khau xac nhan khong trung nhau "<<endl;
                            int n;
                            cout<<"[1] Thoat chuong trinh"<<endl;
                            cout<<"[2] Tiep tuc tao tai khoan "<<endl;
                            cout<<"Nhap vao yeu cau ";
                            cin>>n;
                            cin.ignore();
                            if(n==1){
                                break;
                            }
                            else{

                            }
                        }
                    }
                    break;
                default:
                    cout<<"Yeu cau khong hop le ";
            }
            
        }
        void Form(string &name,string &password){
            cout<<"Nhap vao ten tai khoan ";
            getline(cin,name);
            cout<<"Nhap vao mat khau ";
            getline(cin,password);
        }
        bool checkPassWord(string &a,string &b){
            if(a==b){
                return true;
            }
        }

};