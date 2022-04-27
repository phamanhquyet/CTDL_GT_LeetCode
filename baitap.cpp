//bai 1: cho mot mang A, chon ra 3 so A[i], A[j], A[k] (i<j<k) sao cho tong = m
//#include<iostream>
//#include<fstream>
//using namespace std;
//int *a, m ,n;
//void docflie(){
//    ifstream fi("BO3SO.txt");
//    if(!fi){cout<<"Loi doc file";return;}
//    fi>>n>>m;
//    a = new int[n];
//    for(int i = 0 ; i < n ; i++){
//        fi>>a[i];
//    }
//    fi.close();
//    cout<<"\nDoc xong file\n";
//}
//
//void sol_1(int *a){
//    for(int i = 0 ; i <= n-3; i++){ //n-3
//        for(int j = i+1; j <= n-2;j++){ //n-2
//            for(int k = j+1;k<=n-1; k++){ //n-1
//                if(a[i] + a[j] + a[k] == m)
//                    cout<<"{"<<a[i]<<" + "<<a[j]<<" + "<<a[k]<<"}"<<endl;
//            }
//        }
//    }
//}
//int main(){
//    freopen(stdout,"BO3SO_OUT.txt");
//    sol_1(a);
//    return 0;
//}

#include<algorithm>
#include<iostream>
#include <fstream>
#include<string>
#include<time.h>
typedef long long ll;
#define lap(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n, k;
int a[10005];
//
void Nhap() {
	cin >> n >> k;
	ifstream fi("BO3SO.txt");
	string size;
	getline(fi, size, '\n');
	for (int i = 0; i <= stoi(size); i++) {
		int tmp;
		fi >> tmp;
		a[i] = tmp;
		cout << tmp << " ";
	}

}

int NhiPhan(int l, int r, int x) {
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}
void XuLy() {
	int dem = 0;
	sort(a, a + n);
	lap(j, 0, n)
		lap(i, j + 1, n)
		if (NhiPhan(i + 1, n - 1, k - a[i] - a[j]) != -1) dem++;
	cout << "Ket qua: " << dem;
}

//dem co bao nhieu mang con co tong = m
int chon[1000],kq[1000],dem;
int vt, m;
void inkq(){
    cout<<"\ncach chon "<<++dem<<": ";
    for(int i = 0 ; i<vt;i++){
        cout<<kq[i]<<" ";
    }
}
void tim(int s, int vt){
    if(s==0){
        inkq();
    }
    else{
        for(int i =0 ; i < n ; i++){
            if(chon[i] == 0 && a[i] ==s){
                kq[vt] = a[i];
                chon[i] = 1;
                vt = vt+1;
                tim(s-a[i],vt);
                chon[i] = 0;
                vt = vt-1;
                kq[vt] = 0;
            }
        }
    }

}

int main() {
	Nhap();
//	cout << endl;
//	ll t1 = clock();
//	XuLy();
//	ll t2 = clock();
//	cout << "\nTime: " << t2 - t1;
    tim(m,vt);
	return 0;
}
//quyet vjp pro no 1
