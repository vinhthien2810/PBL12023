#include<bits/stdc++.h>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<iomanip>
using namespace std;
class quanly{
  private:
  string tenkhachhang,masinhvien,lop,biensoxe,sdt;
  public:
  quanly(){ // ham khoi tao mac dinh khong tham so
    tenkhachhang="";
    masinhvien="";
    lop="";
    biensoxe="";
  }
  quanly(string tenkhachhang,string masinhvien,string lop,string biensoxe){ // ham khoi tao co tham so
    this->tenkhachhang=tenkhachhang;
    this->masinhvien=masinhvien;
    this->lop=lop;
    this->biensoxe=biensoxe;
  }
  void settenkhachhang(string tenkhachhang){ // setter getter
    this->tenkhachhang=tenkhachhang;
  }
  string gettenkhachhang(){
    return tenkhachhang;
  }
  void setmasinhvien(string masinhvien){
    this->masinhvien=masinhvien;
  }
  string getmasinhvien(){
    return masinhvien;
  }
  void setlop(string lop){
    this->lop=lop;
  }
  string getbiensoxe(){
    return biensoxe;
  }
  void setsdt(string sdt){
    this->sdt=sdt;
  }
  string getstd(){
    return sdt;
  }
  void nhapthongtin(){  // ham nhap thong tin cho khach hang
    cout<<"Nhap ten khach hang: ";
    cin.ignore();
    getline(cin,tenkhachhang);
    cout<<"Nhap masinhvien: ";
    getline(cin,masinhvien);
    cout<<"Nhap lop cua khach hang: ";
    getline(cin,lop);
    cout<<"Nhap so dien thoai khach hang: ";
    getline(cin,sdt);
    cout<<"Nhap bien kiem soat cua khach hang: ";
    getline(cin,biensoxe);
  }
  void chuanhoaten(){ // ham chuan hoa ten khach hang
     string res="";
     stringstream ss(tenkhachhang);
     string token;
     while(ss>>token){
      res+=toupper(token[0]);
      for(int i=1;i<token.length();i++){
        res+=tolower(token[i]);
      }
      res+=" ";
     }
     res.erase(res.length()-1);
     tenkhachhang=res;
  }
  void chuanhoa(string&lop){ // ham chuan hoa lop
    for(size_t i=0;i<lop.length();i++){
         if(islower(lop[i])){
            lop[i]=toupper(lop[i]);
         }
      }
  }
  void xuatthongtin(){  // ham xuat thong tin cho khach hang( in ve xe)
    chuanhoaten();
    cout<<"Ten khach hang: "<<tenkhachhang<<endl;
    cout<<"Ma sinh vien: "<<masinhvien<<endl;
    chuanhoa(lop);
    cout<<"Lop: "<<lop<<endl;
    cout<<"So dien thoai: "<<sdt<<endl;
    chuanhoa(biensoxe);
    cout<<"Bien so xe: "<<biensoxe<<endl;
  }
  void suathongtin(){ // ham sua thong tin khach hang
    cin.ignore();
    cout<<"Nhap ho ten cua khach hang moi: ";
    getline(cin,tenkhachhang);
    cout<<"Nhap ma sinh vien moi: ";
    getline(cin,masinhvien);
    cout<<"Nhap lop moi: ";
    getline(cin,lop);
    cout<<"Nhap so dien thoai moi: ";
    getline(cin,sdt);
    cout<<"Nhap bien so xe moi: ";
    getline(cin,biensoxe);
    
  }
  void nhapfile(){// ham nhap file
       ifstream file("khachhang.txt",ios::app);
       if(file.is_open()){
        getline(file,tenkhachhang);
        getline(file,masinhvien);
        getline(file,lop);
        getline(file,sdt);
        getline(file,biensoxe);
        file.close();
       }
       else{
        cout<<"Loi! Khong the mo duoc file"<<endl;
       }
  }
  void xuatfile(){// ham xuat file
  ofstream file("khachhang.txt",ios::app);
       if(file.is_open()){
        file<<"Ho Ten Khach Hang: "<<tenkhachhang<<endl;
        file<<"Ma Sinh Vien: "<<masinhvien<<endl;
        file<<"Lop: " << lop<<endl;
        file<<"So dien thoai: "<<sdt<<endl;
        file<<"Bien so xe: "<<biensoxe<<endl;
        file.close();
       }
       else{
        cout<<"Loi! Khong the mo duoc file"<<endl;
       }
  }
  void suathongtinfile(){ // ham sua thong tin khi khach hang nhap sai
    ifstream file("khachhang.txt",ios::app);
    if(file.is_open()){
      string line;
      string content;
      while(getline(file,line)){
        if(line.find("Ho Ten Khach Hang: ")==0){
          content+="Ho Ten Khach Hang: "+tenkhachhang +"\n";
        }
        else if(line.find("Ma Sinh Vien: ")==0){
          content+="Ma Sinh Vien: "+masinhvien+"\n";
        }
        else if(line.find("Lop: ")==0){
          content+="Lop: "+lop+"\n";
        }
        else if(line.find("So dien thoai: ")==0){
          content+="So dien thoai: "+sdt+"\n";
        }
        else if(line.find("Bien so xe: ")==0){
          content+="Bien so xe: "+biensoxe+"\n";
        }
        else{
          content+=line+"\n";
        }
      }
      file.close();
      ofstream xuatfile("khachhang.txt",ios::app);
      if(xuatfile.is_open()){
        xuatfile<<content;
        xuatfile.close();
        cout<<"Cap nhat file thanh cong. "<<endl;

      }
      else{
        cout<<"Loi! Khong the mo duoc file. "<<endl;
      }
    }
    else{
      cout<<"Loi! Khong the mo duoc file. "<<endl;
    }
  }
  void luufile(){ /// ham luu file
  ofstream file("khachhang.txt",ios::app);
       if(file.is_open()){
        file<<"Ho Ten Khach Hang: "<<tenkhachhang<<endl;
        file<<"Ma Sinh Vien: "<<masinhvien<<endl;
        file<<"Lop: " << lop<<endl;
        file<<"So dien thoai: "<<sdt<<endl;
        file<<"Bien so xe: "<<biensoxe<<endl;
        file.close();
       }
       else{
        cout<<"Loi! Khong the mo duoc file"<<endl;
       }
  }
  ~quanly(){
    //ham huy 
  }
};
class khachhang{
    private: 
    string loaixe;
    int sotien1,sotien2,sotien3,sotien4;
    int sosao;
    char *phanhoi;   
    public:
    khachhang(){  // ham khoi tao mac dinh     
      loaixe="";
      sosao=0;
      sotien1=0;
      sotien2=0;
      sotien3=0;
      sotien4=0;
      phanhoi=new char[100];
      
    }
    void setloaixe(string loaixe){ // setter, getter cho lop khach hang
      this->loaixe=loaixe;
    }
    string getloaixe(){
      return loaixe;
    }
    void setsosao(int sosao){
      this->sosao=sosao;
    }
    int getsosao(){
      return sosao;
    }
    void setsotien1(int sotien1){
      this->sotien1=sotien1;
    }
    int getsotien1(){
      return sotien1;
    }
    void setsotien2(int sotien2){
      this->sotien2=sotien2;
    }
    int getsotien2(){
      return sotien2;
    }
    void setsotien3(int sotien3){
      this->sotien3=sotien3;
    }
    int getsotien3(){
      return sotien3;
    }
    void setsotien4(int sotien4){
      this->sotien4=sotien4;
    }
    int getsotien4(){
      return sotien4;
    }
    khachhang(string loaixe,int sotien1,int sotien2,int sotien3,int sotien4){ // ham khoi tao co tham so
      this->loaixe=loaixe;
      this->sotien1=sotien1;
      this->sotien2=sotien2;
      this->sotien3=sotien3;
      this->sotien4=sotien4;
    }
    void xuatbang(){ //ham xuat bang gia
      cout<<loaixe<<"\t\t\t   "<<sotien1<<"\t\t\t\t"<<sotien2<<"\t\t    "<<sotien3<<"\t\t"<<sotien4<<endl;
    }
    void danhgia(){ // ham danh gia so sao cho dich vu
      cout<<"Ban danh gia bao nhieu sao ve dich vu cua chung toi: ";
      while(true){
        cin>>sosao;
        if(sosao>=0&&sosao<=5){
          if(sosao==0||sosao==1||sosao==2||sosao==3){
            cout<<"Xin loi! Chung toi se co gang phat trien dich vu tot hon. "<<endl;
            break;
          }
          else if(sosao==4){
            cout<<"Cam on quy khach da danh gia! "<<endl;
            break;
          }
          else if(sosao==5){
            cout<<"Cam on quy khach da danh gia chung toi 5 sao. "<<endl;
            break;
          }
        }
        else{
          cout<<"So sao khong hop le! Vui long nhap lai: ";
        }
      }
    }
    void phanhoikhachhang(){ // phan hoi cua khach hang ve dich vu
      cout<<"Nhap phan hoi cua ban ve dich vu cua chung toi: ";
      cin.ignore();
      cin.getline(phanhoi,100);
    }
    void luufile(){ // ham luu so sao, phan hoi cua khach hang vao file
      ofstream file("phanhoi.txt",ios::app);
      if(file.is_open()){
        file<<"So sao danh gia: "<<sosao<<endl;
        file<<"Phan hoi khach hang: "<<phanhoi<<endl;
        file<<"------------------------------------"<<endl;
        file.close();
      }
      else{
        cout<<"Loi! Khong the mo duoc file";
      }  
    }
    ~khachhang(){
      //ham huy
      delete[]phanhoi;
    }
};
class nhanvien{
    private:
    string tennhanvien,lop1,masinhvien1,sdt1;
    public:
    nhanvien(){ // ham khoi tao mac dinh cho lop nhanvien
      tennhanvien="";
      lop1="";
      masinhvien1="";
      sdt1="";
    }
    nhanvien(string tennhanvien,string masinhvien1,string sdt1){ // ham khoi tao co tham so cho lop nhan vien
      this->tennhanvien=tennhanvien;
      this->masinhvien1=masinhvien1;
      this->sdt1=sdt1;
    }
    void settennhanvien(string tennhanvien){ // setter, getter cho lop nhan vien
      this->tennhanvien=tennhanvien;
    }
    string gettiennhanvien(){
      return tennhanvien;
    }
    void setlop1(string lop1){
      this->lop1=lop1;
    }
    string getlop1(){
      return lop1;
    }
    void setmasinhvien1(string masinhvien1){
      this->masinhvien1=masinhvien1;
    }
    string getmasinhvien1(){
      return masinhvien1;
    }
    void setsdt1(string sdt1){
      this->sdt1=sdt1;
    }
    string getsdt1(){
      return sdt1;
    }
    void xuatthongtin(){ // ham xuat thong tin nhan vien bai gui xe
      cout<<"\t"<<left<<setw(20)<<"Nhan vien : "<<left<<setw(25)<<tennhanvien<<left<<setw(20)<<masinhvien1<<left<<setw(20)<<sdt1<<endl;
    }
    ~nhanvien(){
      //ham huy
    }
};
class baidoxe:public quanly{
    private:
    static int dem;
    static int doanhthu;
    string ngaygui,ngaynhan,loaixe,id;
    int tien;
    string thoigiangui;
    public:
    baidoxe(){
      ngaygui="";
      ngaynhan="";
      loaixe="";
      tien=0;
      thoigiangui="";
      doanhthu+=tien;  
    }
    baidoxe(string ngaygui,string ngaynhan,string loaixe,int tien,string thoigiangui,string id){ // ham khoi tao co tham so
      this->ngaygui=ngaygui;
      this->ngaynhan=ngaynhan;
      this->loaixe=loaixe;
      this->tien=tien;
      this->thoigiangui=thoigiangui;
      this->id=id;
    }
    void setid(string id){
      this->id=id;
    }
    string getid(){
      return id;
    }
    void setngaygui(string ngaygui){ // setter, getter cho class quan ly
      this->ngaygui=ngaygui;

    }
    string getngaygui(){
      return ngaygui;
    }
    void setngaynhan(string ngaynhan){
      this->ngaynhan=ngaynhan;
    }
    string getngaynhan(){
      return ngaynhan;
    }
    void setloaixe(string loaixe){
      this->loaixe=loaixe;
    }
    string getloaixe(){
      return loaixe;
    }
    void settien(int tien){
      this->tien=tien;
    }
    int gettien(){
      return tien;
    }
    void setthoigiangui(string thoigiangui){
      this->thoigiangui=thoigiangui;
    }
    string getthoigiangui(){
      return thoigiangui;
    }
    void cungcapid(){
      ++dem;
      this->id ="nhaxe"+string(4-to_string(dem).length(),'0')+to_string(dem);
    }
    void suathongtin(){
      quanly::suathongtin();
    }
    void suathongtinfile(){
      quanly::suathongtinfile();
    }
    void luachonxedap(){
      int luachon1=0;
      cout<<setw(32)<<"Thoi gian quy khach muon gui: "<<endl;
      cout<<setw(15)<<"1. Trong ngay (7h den 17h): 1000 dong. "<<endl;
      cout<<setw(15)<<"2. Qua dem (18h den 7h ): 3000 dong. "<<endl;
      cout<<setw(15)<<"3. 1 Ngay: 4000 dong. "<<endl;
      cout<<setw(15)<<"4. 1 Tuan: 10000 dong. "<<endl;
      cout<<setw(15)<<"5. 1 Thang: 40000 dong. "<<endl;
      cout<<"Moi quy khach nhap lua chon cua minh: ";
      while(true){
        cin>>luachon1;
        if(luachon1>=1&&luachon1<=5){
          if(luachon1==1){
            cout<<"Thoi gian gui cua quy khach la: Trong ngay ( 7h den 17h )"<<endl;
            cout<<"So tien quy khach phai thanh toan la: 1000 dong. "<<endl;
            thoigiangui="Trong ngay ( 7h den 17h )";
            tien=1000;
            doanhthu+=tien;
            break;
          }
          else if(luachon1==2){
            cout<<"Thoi gian gui cua quy khach la: Qua dem (18h den 7h)"<<endl;
            cout<<"So tien quy khach phai thanh toan la: 3000 dong. "<<endl;
            thoigiangui="Qua dem ( 18h den 7h )";
            tien=3000;
            doanhthu+=tien;
            break;
          }
          else if(luachon1==3){
          cout<<"Thoi gian gui cua quy khach la: 1 ngay. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 4000 dong. "<<endl;
          thoigiangui="1 ngay";
          tien=4000;
          doanhthu+=tien;
          break;
        }
        else if(luachon1==4){
          cout<<"Thoi gian gui cua quy khach la: 1 tuan. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 10000 dong. "<<endl;
          thoigiangui="1 tuan";
          tien=10000;
          doanhthu+=tien;
          break;
        }
        else if(luachon1==5){
          cout<<"Thoi gian gui cua quy khach la: 1 thang. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 40000 dong. "<<endl;
          thoigiangui="1 thang ";
          
          tien=40000;
          doanhthu+=tien;
          break;
        }
        }
        else{
          cout<<"Quy khach da nhap sai!Moi quy khach nhap lai: ";
        }
        
      }
  }
  void luachonxemay(){
    int luachon2=0;
    cout<<setw(32)<<"Thoi gian quy khach muon gui: "<<endl;
    cout<<setw(15)<<"1. Trong ngay (7h den 17h): 2000 dong. "<<endl;
      cout<<setw(15)<<"2. Qua dem (18h den 7h ): 5000 dong. "<<endl;
      cout<<setw(15)<<"3. 1 Ngay: 7000 dong. "<<endl;
      cout<<setw(15)<<"4. 1 Tuan: 20000 dong. "<<endl;
      cout<<setw(15)<<"5. 1 Thang: 50000 dong. "<<endl;
      cout<<"Moi quy khach nhap lua chon cua minh: ";
      while(true){
        cin>>luachon2;
        if(luachon2>=1&&luachon2<=5){
          if(luachon2==1){
            cout<<"Thoi gian gui cua quy khach la: Trong ngay ( 7h den 17h )"<<endl;
            cout<<"So tien quy khach phai thanh toan la: 2000 dong. "<<endl;
            thoigiangui="Trong ngay ( 7h den 17h )";
            tien=2000;
            doanhthu+=tien;
            break;

          }
          else if(luachon2==2){
            cout<<"Thoi gian gui cua quy khach la: Qua dem (18h den 7h)"<<endl;
            cout<<"So tien quy khach phai thanh toan la: 5000 dong. "<<endl;
            thoigiangui="Qua dem ( 18h den 7h )";
            tien=5000;
            doanhthu+=tien;
            break;
          }
          else if(luachon2==3){
          cout<<"Thoi gian gui cua quy khach la: 1 ngay. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 7000 dong. "<<endl;
          thoigiangui="1 ngay";
          tien=7000;
          doanhthu+=tien;
          break;
        }
        else if(luachon2==4){
          cout<<"Thoi gian gui cua quy khach la: 1 tuan. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 20000 dong. "<<endl;
          thoigiangui="1 tuan";
          tien=20000;
          doanhthu+=tien;
          break;
        }
        else if(luachon2==5){
          cout<<"Thoi gian gui cua quy khach la: 1 thang. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 50000 dong. "<<endl;
          thoigiangui="1 thang ";
          
          tien=50000;
          doanhthu+=tien;
          break;
        }
        }
        else{
          cout<<"Quy khach da nhap sai!Moi quy khach nhap lai: ";
        }

      }
  }
  void luachonoto(){
    int luachon3=0;
    cout<<setw(32)<<"Thoi gian quy khach muon gui: "<<endl;
    cout<<setw(15)<<"1. Trong ngay (7h den 17h): 5000 dong. "<<endl;
      cout<<setw(15)<<"2. Qua dem (18h den 7h ): 10000 dong. "<<endl;
      cout<<setw(15)<<"3. 1 Ngay: 15000 dong. "<<endl;
      cout<<setw(15)<<"4. 1 Tuan: 40000 dong. "<<endl;
      cout<<setw(15)<<"5. 1 Thang: 80000 dong. "<<endl;
      cout<<"Moi quy khach nhap lua chon cua minh: ";
      while(true){
        cin>>luachon3;
        if(luachon3>=1&&luachon3<=5){
          if(luachon3==1){
            cout<<"Thoi gian gui cua quy khach la: Trong ngay ( 7h den 17h )"<<endl;
            cout<<"So tien quy khach phai thanh toan la: 5000 dong. "<<endl;
            thoigiangui="Trong ngay ( 7h den 17h )";
            tien=5000;
            doanhthu+=tien;
            break;

          }
          else if(luachon3==2){
            cout<<"Thoi gian gui cua quy khach la: Qua dem (18h den 7h)"<<endl;
            cout<<"So tien quy khach phai thanh toan la: 10000 dong. "<<endl;
            thoigiangui="Qua dem ( 18h den 7h )";
            tien=10000;
            doanhthu+=tien;
            break;
          }
          else if(luachon3==3){
          cout<<"Thoi gian gui cua quy khach la: 1 ngay. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 15000 dong. "<<endl;
          thoigiangui="1 ngay";
          tien=15000;
          doanhthu+=tien;
          break;
        }
        else if(luachon3==4){
          cout<<"Thoi gian gui cua quy khach la: 1 tuan. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 40000 dong. "<<endl;
          thoigiangui="1 tuan";
          tien=40000;
          doanhthu+=tien;
          break;
        }
        else if(luachon3==5){
          cout<<"Thoi gian gui cua quy khach la: 1 thang. "<<endl;
          cout<<"So tien quy khach phai thanh toan la: 80000 dong. "<<endl;
          thoigiangui="1 thang ";
          
          tien=80000;
          doanhthu+=tien;
          break;
        }
        }
        else{
          cout<<"Quy khach da nhap sai!Moi quy khach nhap lai: ";
        }

      }
  }
    void luachon(){
      int luachon=0;
      cout<<setw(32)<<"Loai xe cua quy khach la: "<<endl;
      cout<<setw(15)<<"1. Xe Dap"<<setw(15)<<"2. Xe May"<<setw(15)<<"3. O to"<<endl;
      cout<<"Moi quy khach nhap lua chon cua minh: ";
      while(true){
        cin>>luachon;
        if(luachon>=1&&luachon<=3){
          if(luachon==1){
            cout<<"Xe cua quy khach la: Xe Dap"<<endl;
            loaixe="Xe Dap";
            luachonxedap();
            break;
          }
          else if(luachon==2){
            cout<<"Xe cua quy khach la: Xe May"<<endl;
            loaixe="Xe May";
            luachonxemay();
            break;
          }
          else if(luachon==3){
            cout<<"Xe cua quy khach la: O To"<<endl;
            loaixe="O To";
            luachonoto();
            break;
          }
        }
        else{
          cout<<"Quy khach nhap sai cu phap! Moi quy khach nhap lai: ";
        }
      }
    }
    void thongtinkhachhang(){
       quanly::nhapthongtin();
       cungcapid();
       luachon();
    }
    void xuatthongtin(){
      quanly::xuatthongtin();
      cout<<"ID cua quy khach la: "<<id<<endl;
      cout<<"Loai xe cua quy khach la: "<<loaixe<<endl;
      cout<<"Thoi gian gui: "<<thoigiangui<<endl;
      cout<<"So tien da thanh toan: "<<tien<<" dong"<<endl;  
    }
    void sovedoanhthu(){
      cout<<"So ve xe da ban trong ngay hom nay la: "<<dem<<endl;
      cout<<"Doanh thu trong ngay hom nay la: "<<doanhthu<<endl;
    }
    void luufile(){
      quanly::luufile();
      ofstream file("khachhang.txt",ios::app);
      if(file.is_open()){
        file<<"ID khach hang la: "<<id<<endl;
        file<<"Loai xe: "<<loaixe<<endl;
        file<<"Thoi gian gui: "<<thoigiangui<<endl;
        file<<"So tien da thanh toan: "<<tien<<" dong"<<endl;
        file<<"-------------------------------------" << endl;
        file.close();
      }
      else{
        cout<<"Khong the mo duoc file!";
      }
    }
    static bool kiemtramasinhvien(const string& masv) {
        ifstream file("khachhang.txt");
        string line;
        while (getline(file, line)) {
            if (line.find("Ma Sinh Vien: " + masv) != string::npos) {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    static bool kiemtraid(const string&id){
      ifstream file("khachhang.txt");
      string line1;
      while(getline(file,line1)){
        if(line1.find("ID khach hang la: "+ id)!=string::npos){
          file.close();
          return true;
        }
      }
      file.close();
      return false;
    }
    static bool kiemtrahovaten(const string&hoten){
      ifstream file("khachhang.txt");
      string line;
      while(getline(file,line)){
        if(line.find("Ho Ten Khach Hang: "+hoten)!=string::npos){
          file.close();
          return true;
        }
      }
      file.close();
      return false;
    }
    void giamatvexe(){
      doanhthu+=50000;
    }
    ~baidoxe(){
      // ham huy
      
    }
};
void menubaixe(){
  cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"\t\t\t\t\t______________________________________________"<<endl;
  cout<<"\t\t\t\t\t~                  Ban la:                   ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~ 1.       ~  Quan ly bai xe.                ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~ 2.       ~  Khach hang.                    ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
}
void menuquanly(){
  cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~Menu Quan Ly~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    1. Nhap va in ve xe cho khach hang.     ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    2. Sua thong tin khach hang.            ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    3. In ra doanh thu va so ve hom nay.    ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    4. Tim ve (khi khach hang mat ve).       "<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t     0. Thoat khoi chuong trinh.              "<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  
}
void menukhachhang(){
  cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~Menu Khach Hang~~~~~~~~~~~~~~~~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    1. Xem bang gia va thoi gian gui.       ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    2. Danh gia va viet phan hoi.           ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
  cout<<"\t\t\t\t\t~    0. Thoat khoi chuong trinh.             ~"<<endl;
  cout<<"\t\t\t\t\t----------------------------------------------"<<endl;
}
void chuanhoaten(string&hoten){ // ham chuan hoa ten khach hang
     string res="";
     stringstream ss(hoten);
     string token;
     while(ss>>token){
      res+=toupper(token[0]);
      for(int i=1;i<token.length();i++){
        res+=tolower(token[i]);
      }
      res+=" ";
     }
     res.erase(res.length()-1);
     hoten=res;
  }
bool dangnhap() {
    string username;
    string password;
    cout << "Nhap tai khoan: ";
    cin >> username;
    cout << "Nhap mat khau: ";
    password = "";
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;
    if (username == "admin" && password == "123456") {
        cout << "Dang nhap thanh cong!" << endl;
        return true;
    } else {
        cout << "Tai khoan hoac mat khau khong dung." << endl;
        cout << "Nhap phim E hoac e de thoat ve man hinh chon truoc." << endl;
        cout << "Nhan phim bat ki de tiep tuc nhap." << endl;
        char choice;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        if (choice == 'E' || choice == 'e') {
            return false;
        } else {
            return dangnhap();
        }
    }
}
int baidoxe::dem=0;
int baidoxe::doanhthu=0;
int main(){
  cout<<"\t\t\t\t\t========NHAN VIEN DANG LAM VIEC========"<<endl;
  cout<<"\n\n\n";
  nhanvien x("Nguyen Thi Minh Ngoc","107220276","0702555812");
  nhanvien y("Truong Vinh Thien","106220235","09813135018");
  x.xuatthongtin();
  y.xuatthongtin();
  cout<<"\n\n\n\n\n";
  menubaixe();
  int luachon=0;
  while(true){
    cout<<"\n\n\t\t\t\t\tNhap vao lua chon cua ban: ";
    cin>>luachon;
    switch(luachon){
      case 1:{
        system("cls");
        int luachon1=0;
        if(dangnhap()){
          while(true){
            system("cls");
            menuquanly();
            baidoxe x;
            cout<<"\n\n\t\t\t\t\tNhap vao lua chon cua ban: ";
            cin>>luachon1;
            switch(luachon1){
              case 1:{
                system("cls");
                x.thongtinkhachhang();
                x.xuatthongtin();
                x.luufile();
                cout<<"Nhan phim bat ki de tiep tuc: ";
                _getch();
                break;
              }
              case 2:{
               system("cls");
               x.suathongtin();
               x.suathongtinfile();
               cout<<"Nhan phim bat ky de tiep tuc: ";
               _getch();
               break;
              }
              case 3:{
                system("cls");
                x.sovedoanhthu();
                cout<<"Nhan phim bat ky de tiep tuc: ";
                _getch();
                break;
              }
              case 4:{
                system("cls");
                int dem=0;
                string hoten;
                cout<<"Nhap ho va ten can kiem tra: ";
                getline(cin>>ws,hoten);
                chuanhoaten(hoten);
                if(baidoxe::kiemtrahovaten(hoten)){
                  ++dem;
                }
                string masv;
                cout<<"Nhap ma sinh vien can kiem tra: ";
                getline(cin>>ws,masv);
                if(baidoxe::kiemtramasinhvien(masv)){
                  ++dem;
                }
                string id;
                cout<<"Nhap id nha xe da cung cap cho ban: ";
                getline(cin>>ws,id);
                if(baidoxe::kiemtraid(id)){
                  ++dem;
                }
                if(dem==3){
                  cout<<"Thong tin trung khop voi xe cua ban! "<<endl;
                  cout<<"Mat ve thanh toan voi quan ly 50000 dong (tien phi mat ve) !"<<endl;
                  x.giamatvexe();
                }
                else{
                  cout<<"Khong tim thay ve xe! Ban co su nham lan trong qua trinh nhap xuat ?"<<endl;
                }
                dem=0;
                cout<<"Nhap phim bat ky de tiep tuc: ";
                _getch();
                break;
              }
              case 0:{
                cout<<"Ban da chon thoat khoi chuong trinh. ";
                exit(0);
              }
              default:{
                cout<<"Khong co chuc nang nay !"<<endl;
                cout<<"Nhan phim bat ky de tiep tuc. ";
                _getch();
                system("cls");
                break;
              }
            }
          }
        }
      }
      case 2:{
        system("cls");
        int luachon2=0;
        while(true){
          system("cls");
          khachhang y;
          menukhachhang();
          cout<<"\n\n\t\t\t\t\tNhap vao lua chon cua ban: ";
          cin>>luachon2;
          switch(luachon2){
            case 1:{
              system("cls");
              cout<<"Don vi tien te: (dong)"<<endl;
              cout<<"------------------------------------------------------------------------------------------------------"<<endl;
              cout<<setw(20)<<"Loai xe"<<setw(30)<<"Trong ngay(7h den 17h)"<<setw(25)<<"Qua dem(18h den 7h)"<<setw(20)<<"1 tuan"<<setw(15)<<"1 thang"<<endl;
              khachhang x("Xe dap",2000,4000,10000,50000);
              cout<<"------------------------------------------------------------------------------------------------------"<<endl;
              x.xuatbang();
              khachhang y("Xe May",4000,6000,20000,80000);
              cout<<"------------------------------------------------------------------------------------------------------"<<endl;
              y.xuatbang();
              khachhang z("O To  ",7000,14000,70000,300000);
              cout<<"------------------------------------------------------------------------------------------------------"<<endl;
              z.xuatbang();
              cout<<"------------------------------------------------------------------------------------------------------"<<endl;
              cout<<"Nhan phim bat ki de tiep tuc: ";
              _getch();
              break;
            }
            case 2:{
              system("cls");
              y.danhgia();
              y.phanhoikhachhang();
              cout<<"Nhap phim bat ki de tiep tuc. ";
              _getch();
              break;
            }
            case 3:{
              cout<<"Ban da thoat khoi chuong trinh. ";
              exit(0);
            }
            default:{
              cout<<"Khong co chuc nang nay! "<<endl;
              cout<<"Nhan phim bat ky de quay ve menu ";
              _getch();
              system("cls");
              break;
            }
          }
        }
      }
      default:{
        cout<<"Khong co chuc nang nay! "<<endl;
        cout<<"Nhan phim bat ki de tiep tuc. "<<endl;
        _getch();
        break;
      }
    }
  }
  system("pause");
  return 0;
}
