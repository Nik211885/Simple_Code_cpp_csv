#include<bits/stdc++.h>
using namespace std;
class QuanLy{
	private:
		string masp;
		string tensp;
		long long giaTien;
		int soLuong;
		int soLuongMua;
	public:
		//Ham khoi tao khong tham so
		QuanLy(){
			this->masp="";
			this->tensp="";
			this->giaTien=0;
			this->soLuong=0;
			this->soLuongMua=0;
		}
		//Ham khoi tao co tham so
		QuanLy(string a, string b,long long c,int d,int e){
			this->masp=a;
			this->tensp=b;
			this->giaTien=c;
			this->soLuong=d;
			this->soLuongMua=e;
		}
		//Ham tra ve masp
		string getMaSp(){
			return masp;
		}
		//Ham tra ve ten sp
		string getTenSp(){
			return tensp;
		}
		//Ham tra ve gia tien cua san pham
		long long getGiaTien(){
			return giaTien;
		}
		//Ham tra ve so luong san pham
		int getSoLuong(){
			return soLuong;
		}
		//Ham tra ve so luong mua
		int getSoLuongMua(){
			return soLuongMua;
		}
		//Ham thay doi masp
		void setMaSp( string a){
			this->masp=a;
		}
		//Ham thay doi tensp
		void setTenSp(string b){
			this->tensp=b;
		}
		//Ham thay doi gia tien san pham 
		void setGiaTien(long long c){
			this->giaTien=c;
		}
		//Ham thay doi so luong san pham
		void setSoLuong(int d){
			this->soLuong=d;
		}
		//Ham thay doi so luong san pham mua
		void setSoLuongMua(int e){
			this->soLuongMua=e;
		}
		void Nhap(){
			cout<<"Nhap ma san pham ";
			getline(cin,masp);
			cout<<"Nhap vao ten san pham ";
			getline(cin,tensp);
			cout<<"Nhap vao gia tien san pham ";
			cin>>giaTien;
			cout<<"Nhap so luong san pham ";
			cin>>soLuong;
		}
		void Xuat(){
			cout<<masp<<"\t"<<tensp<<"\t"<<giaTien<<"\t"<<soLuong<<endl;
		}
};
int *SearchIndex(string a){
	int *temp = new int [2];
	int j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==44){
			temp[j]=i;
			j++;
		}
	}
	return temp;
}
class DanhSachSanPham:public QuanLy{
	private:
		vector<QuanLy*>ql;
		int n;
		vector<string>temp;
		vector<QuanLy*>bill;
	public:
		QuanLy *tmp;
		//Ham nhap vao danh sach cac san pham
		void Input(){
			char choose;
			int i=0;
			while(i==0){
				tmp =new QuanLy;
				tmp->Nhap();
				ofstream file;
                file.open("Kho.csv",ios::app);
                file<<tmp->getMaSp()<<","<<tmp->getTenSp()<<","<<tmp->getGiaTien()<<","<<tmp->getSoLuong()<<"\n";
                file.close();
                cout<<"Ban co muon them san pham khong ? y or n ";
                cin>>choose;
                cin.ignore();
                if(choose=='n'||choose=='N'){
                	i=1;
				}
			}
		}
		//Ham them san pham vao danh sach
		void Insert(){
			tmp = new QuanLy;
			tmp->Nhap();
			ofstream file;
            file.open("Kho.csv",ios::app);
            file<<tmp->getMaSp()<<","<<tmp->getTenSp()<<","<<tmp->getGiaTien()<<","<<tmp->getSoLuong()<<"\n";
            file.close();
		}
		//Ham doc va xu ly file
		void ReadFile(){
			ifstream file;
	    	file.open("Kho.csv");
	    	string line;
	    	getline(file, line);
	    	while (getline(file, line)) {
	        	temp.push_back(line);
	    	}
	    	file.close();
	    	for(int i=0;i<temp.size();i++){
	    		string masp;
	    		string tensp;
	    		string giaban;
	    		string soluong;
	    		int *index=SearchIndex(temp[i]);
		    	masp=temp[i].substr(0,index[0]);
		    	tensp=temp[i].substr(index[0]+1,index[1]-index[0]-1);
		    	giaban=temp[i].substr(index[1]+1,index[2]-index[1]-1);
		    	soluong=temp[i].substr(index[2]+1,temp.size()-index[2]);
		    	long long giaBan =  stoi(giaban);
		    	int soLuong= stoi(soluong);
		    	QuanLy *p;
		    	p=new QuanLy;
		    	p->setMaSp(masp);
		    	p->setTenSp(tensp);
		    	p->setGiaTien(giaBan);
		    	p->setSoLuong(soLuong);
		    	ql.push_back(p);
			}
		}
		//Ham output
		void Output(){
			for(int i=0;i<ql.size();i++){
				ql[i]->Xuat();
			}
		}
		//Ham xoa du lieu khoi file du lieu  bang masp
		void Erase(string &masp){
			cout<<"Nhap vao ma san pham can xoa ";
			getline(cin,masp);
			for(int i=0;i<ql.size();i++){
				if(ql[i]->getMaSp()==masp){
					ql.erase(ql.begin()+i);
				}
			}
			ofstream ofs("Kho.csv",ofstream::out);
			ofs.close();
			ofstream file;
            file.open("Kho.csv");
            for(int i=0;i<ql.size();i++){
            	file<<ql[i]->getMaSp()<<","<<ql[i]->getTenSp()<<","<<ql[i]->getGiaTien()<<","<<ql[i]->getSoLuong()<<endl;
			}
			cout<<"Xoa san pham co ma san pham la "<<masp<<" thanh cong";
		}
		//danh sach casc san pham  can mua co trong danh sach khong
		void Bill(string &tensp,int &soLuong){
			int i=0;
			char choose;
			while(i==0){
				cout<<"Nhap vao ten san pham ";
				getline(cin,tensp);
				int check=0;
				for(int i=0;i<ql.size();i++){
					if(ql[i]->getTenSp()==tensp){
						cout<<"Nhap vao so luong can mua ";
						cin>>soLuong;
						ql[i]->setSoLuongMua(soLuong);
						bill.push_back(ql[i]);
						check=check+1;
						break;
					}
				}
				if(check==0){
					cout<<"San pham nay hien khong co hoac da het hang "<<endl;
				}
				cout<<"Ban co muon mua them gi khong ? y or n";
                cin>>choose;
                cin.ignore();
                if(choose=='n'||choose=='N'){
                	i=1;
				}
			}
			long long total=0;
			for(int i=0;i<bill.size();i++){
				total=total+bill[i]->getSoLuongMua()*bill[i]->getGiaTien();
			}
			cout<<"Xuat Hoa Don "<<endl;
			for(int i=0;i<bill.size();i++){
				cout<<bill[i]->getSoLuongMua()<<" "<<bill[i]->getTenSp()<<"\t"<<bill[i]->getSoLuongMua()*bill[i]->getGiaTien()<<endl;
			}
			cout<<endl;
			cout<<"Tong Tien "<<total<<endl<<endl;
		}	
};
void Menu(){
	while(true){
		DanhSachSanPham a;
		string masp;
		string tensp;
		int soluong;
		cout<<"[1] Nhap san pham "<<endl;
		cout<<"[2] Them san pham "<<endl;
		cout<<"[3] In danh sach cac san pham"<<endl;
		cout<<"[4] Xoa san pham theo ma san pham "<<endl;
		cout<<"[5] In hoa don "<<endl;
		cout<<"[0] Thoa chuong trinh"<<endl;
		int n;
		cout<<"Nhap vao yeu cau cua ban ";
		cin>>n;
		cin.ignore();
		switch(n){
			case 1:
				a.Input();
				break;
			case 2:
				a.Insert();
				break;
			case 3:
				a.ReadFile();
				a.Output();
				break;
			case 4:
				a.ReadFile();
				a.Erase(masp);
				break;
			case 5:
				a.ReadFile();
				a.Bill(tensp,soluong);
				exit(0);
			case 0:
				exit(0);
				break;
			default:
				cout<<"Yeu cau khong hop le "<<endl;
				break;
		}
	}
}
int main(){
	Menu();
}
