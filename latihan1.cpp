#include <iostream>
#include <fstream>
using namespace std;


struct order {
	char kode;
	string menu;
	int jumlah, harga, subtotal;
};


//int n;
order ord[6];
int i = 0;
string bonus;
char confirm = 'y';
int total, total_bayar, bayar, diskon;

order* input (order ord[]) {
   while (confirm != 'n') {
        cout << "Silahkan masukkan pilihan anda : ";
        cin >> ord[i].kode;
            switch(ord[i].kode)
            {
            case 'D' :
                ord[i].menu = "Dada";
                ord[i].harga = 5000;
                cout << "Order #"<< i+1 << endl;
                cout << ord[i].menu << endl;
                cout << "Jumlah Order : ";
                cin >> ord[i].jumlah;
                ord[i].subtotal = ord[i].harga*ord[i].jumlah;
                total_bayar += ord[i].subtotal;
                i++;
            break;
            case 'P' :
                ord[i].menu = "Paha";
                ord[i].harga = 4000;
                cout << "Order #"<< i+1 << endl;
                cout << ord[i].menu << endl;
                cout << "Jumlah Order : ";
                cin >> ord[i].jumlah;
                ord[i].subtotal = ord[i].harga*ord[i].jumlah;
                total_bayar += ord[i].subtotal;
                i++;
            break;
            case 'S' :
                ord[i].menu = "Sayap";
                ord[i].harga = 3000;
                cout << "Order #"<< i+1 << endl;
                cout << ord[i].menu << endl;
                cout << "Jumlah Order : ";
                cin >> ord[i].jumlah;
                ord[i].subtotal = ord[i].harga*ord[i].jumlah;
                total_bayar += ord[i].subtotal;
                i++;
            break;
            case 'T' :
                ord[i].menu = "Teh";
                ord[i].harga = 3000;
                cout << "Order #"<< i+1 << endl;
                cout << ord[i].menu << endl;
                cout << "Jumlah Order : ";
                cin >> ord[i].jumlah;
                ord[i].subtotal = ord[i].harga*ord[i].jumlah;
                total_bayar += ord[i].subtotal;
                i++;
            break;
            case 'J' :
                ord[i].menu = "Jeruk";
                ord[i].harga = 4000;
                cout << "Order #"<< i+1 << endl;
                cout << ord[i].menu << endl;
                cout << "Jumlah Order : ";
                cin >> ord[i].jumlah;
                ord[i].subtotal = ord[i].harga*ord[i].jumlah;
                total_bayar += ord[i].subtotal;
                i++;
            break;
            case 'C' :
                ord[i].menu = "Sirup";
                ord[i].harga = 5000;
                cout << "Order #"<< i+1 << endl;
                cout << ord[i].menu << endl;
                cout << "Jumlah Order : ";
                cin >> ord[i].jumlah;
                ord[i].subtotal = ord[i].harga*ord[i].jumlah;
                total_bayar += ord[i].subtotal;
                i++;
            break;
            default:
                cout << "Menu tidak ditemukan \n";
            break;
            }
            cout << "Lanjut pesan ? (y/n) : ";
            cin >> confirm;
    }
}

invoice (order ord[]) {
   ofstream output("output.txt");

    if (!output.is_open()) {
        cerr << "Error opening the output file." << endl;
        return 1;
    }

    output << "| \t       Invoice          \t       |" << std::endl;
    output << "| \t Gerobak Fried Chicken  \t       |" << std::endl;
    output << "No.\tMenu\tHarga\t\tqty\tsubtotal \n";
    output << "===============================================\n";
    for (int a = 0; a < i; a++) {
        output <<a+1 << "\t" << ord[a].menu<< " " << "Rp. "<<ord[a].harga << "\t" << "\t" << ord[a].jumlah<< "\t" << ord[a].subtotal<<std::endl;
    }

    output << "\n\t----------Total \t"<<"Rp. "<<total_bayar<<std::endl;
    output << "\t----------PPN   \t"<<"Rp. "<<total_bayar*10/100<<std::endl;
    total = total_bayar + total_bayar*10/100;
    if (total < 50000) {
        diskon = 0;
        bonus = "-";
    } else if (total <= 100000) {
        diskon = total *5/100;
        bonus  = "Cangkir";
    } else if (total <= 200000) {
        diskon = total *10 /100;
        bonus = "Kaos";
    } else if (total <= 500000) {
        diskon = total * 15/100;
        bonus = "Payung";
    } else if (total >= 500000) {
        diskon = total * 20 / 100;
        bonus = "Tas Pinggang";
    }

    output << "\t----------Total Harga \t"<<"Rp. "<<total-diskon<<std::endl;
    output << "\tBonus yang anda peroleh\t"<<bonus <<std::endl;
    system("notepad output.txt");
    output.close();
}

int main()
{

    cout << "| \t       Daftar Menu      \t|" << endl;
    cout << "| \t Gerobak Fried Chicken  \t|" << endl;
    cout << " =======================================\n";
    cout << "|  Kode    |   Jenis   |   Harga        |"<< endl;
    cout << "|   D      |   Dada    |   Rp. 5000     |"<< endl;
    cout << "|   P      |   Paha    |   Rp. 4000     |"<< endl;
    cout << "|   S      |   Sayap   |   Rp. 3000     |"<< endl;
    cout << "|   T      |   Teh     |   Rp. 3000     |"<< endl;
    cout << "|   J      |   Jeruk   |   Rp. 4000     |"<< endl;
    cout << "|   C      |   Sirup   |   Rp. 5000     |"<< endl;
    cout << " =======================================\n";



    input(ord);
    invoice(ord);




    return 0;
};
