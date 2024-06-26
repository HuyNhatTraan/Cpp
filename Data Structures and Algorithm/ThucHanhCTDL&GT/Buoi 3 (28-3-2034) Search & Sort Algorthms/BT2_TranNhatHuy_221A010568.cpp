#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CATHUCHANH{
private:
    vector<string> MaHP;
    vector<string> TenHP;
    vector<int> SL;
    vector<string> PhongHoc;
public:
    template<typename T> // Đặt template để swap nhanh
    void swapNe(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void nhapThongTin(){
        string ma, ten, phong;
        int n, sl;
        cout << "Hay nhap so lop thuc hanh ban muon them vao: "; cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin lop hoc phan thu " << i + 1 << ": " << endl;
            cout << "Hay nhap ma lop hoc phan: "; 
            getline(cin, ma);
            MaHP.push_back(ma);
            cout << "Hay nhap ten lop hoc phan: ";
            getline(cin, ten);
            TenHP.push_back(ten);
            cout << "Hay nhap so sinh vien: "; cin >> sl;
            SL.push_back(sl);
            cin.ignore();
            cout << "Hay nhap phong hoc: ";
            getline(cin, phong);
            PhongHoc.push_back(phong);
        }
    }

    void xuatThongTin() {
        cout << "Thong tin cac ca hoc: " << endl;
        for (int i = 0; i < MaHP.size(); i++) {
            cout << i + 1 << ". MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
        }
    }

    void timKiemMaHP() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap MaHP ma ban muon tim kiem: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaHP.size(); i++) {
            if (MaHP[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << ". MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void timKiemTenHP() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap TenHP ma ban muon tim kiem: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaHP.size(); i++) {
            if (TenHP[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << ". MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void inRaKhiBietPH() {
        string key;
        bool daTimThay = false;
        cout << "Hay nhap phong hoc ma ban muon tim kiem: ";
        cin.ignore();
        getline(cin, key);
        for (int i = 0; i < MaHP.size(); i++) {
            if (PhongHoc[i] == key) {
                daTimThay = true;
                cout << "Da tim thay thong tin hoc phan nay: " << endl;
                cout << i + 1 << ". MaHP: " << MaHP[i] << " | TenHP: " << TenHP[i] << " | Sinh vien: " << SL[i]
            << " | Phong: " << PhongHoc[i] << endl;
            }
            if (!daTimThay) {
                cout << "Khong tim thay hoc phan nay! Vui long thu lai." << endl;
            }
        }
    }

    void sapXepCaHocTangDan(){
        int min_idx;
        for (int i = 0; i < MaHP.size() - 1; i++) { 
            min_idx = i; 
            for (int j = i + 1; j < MaHP.size(); j++) { 
                if (MaHP[j] < MaHP[min_idx]) 
                    min_idx = j; 
            } 
            if (min_idx != i) 
                swapNe(MaHP[min_idx], MaHP[i]);
                swapNe(TenHP[min_idx], TenHP[i]);
                swapNe(PhongHoc[min_idx], PhongHoc[i]);
                swapNe(SL[min_idx], SL[i]);
        } 
        cout << "Sau khi sort: " << endl;
        xuatThongTin();
    }

};

void Menu() {
    cout << "================= Menu =====================" << endl;
    cout << "1. Nhap danh sach ca thuc hanh." << endl;
    cout << "2. Xuat danh sach ca thuc hanh." << endl;
    cout << "3. Tim kiem khi biet ma hoc phan." << endl;
    cout << "4. Tim kiem khi biet ten hoc phan." << endl;
    cout << "5. In ra cac ca hoc khi biet phog hoc." << endl;
    cout << "6. Sap xep ca hoc theo thu tu tang dan." << endl;
    cout << "7. Thoát khỏi menu!" << endl;
    cout << "============================================" << endl;
}

int main() {
    CATHUCHANH CTH;
    int choices;
    do {
        Menu();
        cout << "Hay nhap lua chon cua ban: "; cin >> choices;
        switch (choices)
        {
        case 1:
            CTH.nhapThongTin();
            break;
        case 2:
            CTH.xuatThongTin();
            break;
        case 3:
            CTH.timKiemMaHP();
            break;
        case 4:
            CTH.timKiemTenHP();
            break;
        case 5:
            CTH.inRaKhiBietPH();
            break;
        case 6:
            CTH.sapXepCaHocTangDan();
            break;
        case 7:
            cout << "Thoat khoi menu!." << endl;
            break;
        default:
            cout << "Nhap sai roi! Ban vui long nhap lai." << endl;
            break;
        }
    } while (choices != 7);
    return 0;
}
