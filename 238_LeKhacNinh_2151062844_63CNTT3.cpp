#include<iostream>
#include<vector>
using namespace std;
class SanPham{
	private:
		string tenSanPham;
		string nhasanXuat;
	public:
		//Ham tao mac dinh 
		SanPham(){
			this->tenSanPham="";
			this->nhasanXuat="";
		}
		// Ham tao 2 tham so
		SanPham(string _tenSanPham,string _nhaSanXuat){
			this->tenSanPham=_tenSanPham;
			this->nhasanXuat=_nhaSanXuat;
		}
		//ham tra ve ten san pham
		string getTenSanPham(){
			return tenSanPham;
		}
		//ham tra ve ten cua nha  san xuat
		string getNhaSanXuat(){
			return nhasanXuat;
		}
		//ham bien doi bien ten san pham
		void setTenSanPham(string _tenSanPham){
			this->tenSanPham=_tenSanPham;
		}
		//Ham bien doi bien nha san xuat
		void settenNhaSanXuat(string _nhaSanXuat){
			this->nhasanXuat=_nhaSanXuat;
		}
		//ham ao nhap
		virtual void Nhap(){
			cout<<"Nhap vao ten san pham ";
			getline(cin,tenSanPham);
			cout<<"Nhap vao ten nha san xuat ";
			getline(cin,nhasanXuat);
		}
		//ham ao xuat
		virtual void Xuat(){
			cout<<tenSanPham<<"\t"<<nhasanXuat<<"\t";
		}
		//ham ao thanh toan
		virtual long long thanhtoan()=0;
};
class SPBanLe:public SanPham{
	private:
		double giaBan;
		int soLuong;
	public:
		//Ham tao mac dinh 
		SPBanLe():SanPham(){
			this->giaBan=0;
			this->soLuong=0;
		}
		//Ham tao 4  tham so
		SPBanLe(string _TenSp,string _nhaSanXuat,long _giaBan,int _soLuong):SanPham(_TenSp,_nhaSanXuat){
			this->giaBan=_giaBan;
			this->soLuong=_soLuong;
		}
		//Ham ttra ve gian ban le
		double getGiaBan(){
			return giaBan;
		}
		//Ham tra ve so luong
		int getSoLuong(){
			return soLuong;
		}
		//ham dat gia ban
		void setGiaBan(double _giaBan){
			this->giaBan=_giaBan;
		}
		//ham dat so luong
		void setSoLuong(int _soLuong){
			this->soLuong=_soLuong;
		}
		//Ham nhap
		void Nhap(){
			SanPham::Nhap();
			cout<<"Nhap vao gia ban ";
			cin>>giaBan;
			soLuong=-5;
			while(soLuong>=10||soLuong<=0){
				cout<<"Nhap vao so luong san pham ";
				cin>>soLuong;
				if(soLuong>=10||soLuong<0){
					cout<<"So luong san pham phai be hon 10 va lon hon 0"<<endl;
					cout<<"Moi nhap lai so luong "<<endl;
				}
			}
			cin.ignore();
		}
		//Ham xuat
		void Xuat(){
			SanPham::Xuat();
			cout<<giaBan<<"\t"<<soLuong;
		}
		//Ham thanh toan lam tron thanh so nguyen
		long long thanhtoan(){
			return giaBan*soLuong;
		}
};
class SPBanSi:public SanPham{
	private:
		double giaSi;
		int soLuong;
	public:
		//Ham tao mac dinh
		SPBanSi():SanPham(){
			this->giaSi=0;
			this->soLuong=0;
		}
		//Ham tao 4 tham so
		SPBanSi(string _tenSanPham,string _nhaSanXuat,long double _giaSi,int _soLuong):SanPham(_tenSanPham,_nhaSanXuat){
			this->giaSi=_giaSi;
			this->soLuong=_soLuong;
		}
		//ham tra ve gia ban si
		double getGiaBan(){
			return giaSi;
		}
		//ham ra ve so luong
		int getSoLuong(){
			return soLuong;
		}
		//ham dat gia ban si
		void setGiaBan(double _giaSi){
			this->giaSi=_giaSi;
		}
		//hamm dat so luong
		void setSoLuong(int _soLuong){
			this->soLuong=_soLuong;
		}
		//Ham nhap
		void Nhap(){
			SanPham::Nhap();
			cout<<"Nhap vao gia ban si ";
			cin>>giaSi;
			soLuong=0;
			while(soLuong<=100){
				cout<<"Nhap vao so luong san pham ban si ";
				cin>>soLuong;
				if(soLuong<=100){
					cout<<"So luong san pham phai lon hon 100"<<endl;
					cout<<"Moi nhap lai so luong "<<endl;
				}
			}
			cin.ignore();
		}
		//Ham xuat
		void Xuat(){
			SanPham::Xuat();
			cout<<giaSi<<"\t"<<soLuong;
		}
		//Ham thanh toan
		long long thanhtoan(){
			return giaSi*soLuong;
		}
};
int main(){
	vector<SanPham*>sp;
	int n;
	n=0;
	while(n<=0||n>=10){
		cout<<"So luong san pham ";
		cin>>n;
		if(n<=0||n>=10){
			cout<<"So luong san pham lon hon 0 va be hon 10 "<<endl;
			cout<<"Moi nhap lai "<<endl;
		}
	}
	int i=0;
	while(i<n){
		int j;
		cout<<"[1] De them vao ban le "<<endl;
		cout<<"[2] De them vao ban si "<<endl;
		cout<<"Moi nhap yeu cau ";
		cin>>j;
		cin.ignore();
		SanPham *p;
		switch (j){
			case 1:
				p= new SPBanLe;
				p->Nhap();
				sp.push_back(p);
				i=i+1;
				break;
			case 2:
				p= new SPBanSi;
				p->Nhap();
				sp.push_back(p);
				i=i+1;
				break;
			default:
				cout<<"Yeu cau khong hop le moi nhap lai"<<endl;
				break;
		}
	}
	long long tongTien=0;
	cout<<"Hien thi thong tin cua danh sach "<<n<<" san pham tren "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Thong tin cua san pham thu "<<i+1<<endl;
		sp[i]->Xuat();
		cout<<"\nTien cua san pham nay la "<<sp[i]->thanhtoan()<<endl;
		//Tinh tong tien cua n san pham
		tongTien=tongTien+sp[i]->thanhtoan();
	}
	cout<<"Tong so tien phai tra cua "<<n<<" san pham trong danh dach tren la "<<tongTien;
	return 0;
}
