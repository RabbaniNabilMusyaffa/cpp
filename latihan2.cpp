#include <iostream>
#include <fstream>
using namespace std;

struct order {
	char ukuran;
	string nama;
	int jumlah, jumlah_data, jumlah_beli, harga, total, diskon = 0;
};

int i = 0;
int n;
int jumlah, total, total_bayar, bayar;

order* input(order ord[])
{
    for (int i = 0; i < jumlah; i++)
    {
        switch (ord[i].ukuran)
        {
        case 'S':
            ord[i].nama = "Small";
            ord[i].harga = 36000;
            break;
        case 'M':
            ord[i].nama = "Medium";
            ord[i].harga = 43000;
            break;
        case 'L':
            ord[i].nama = "Large";
            ord[i].harga = 62000;
            break;
        default:
            break;
        }

        ord[i].total = ord[i].harga * ord[i].jumlah;
        if (ord[i].jumlah > 10)
        {
            ord[i].diskon = (ord[i].total * 20 / 100);
            ord[i].total -= ord[i].diskon;
        }

        total += ord[i].total;
    }

    return ord;
}

void nota(order ord[])
{
    ofstream output ("nota.txt");

    output << "\t\t\tInvoice Order" << endl;
    output << "\t\tToko Laris\t" << endl;
    output << "\tNo \tNama Menu \tHarga \t\t QTY \t Diskon \t     SubTotal \t" << endl;
    for (int a = 0; a < jumlah; a++) {
    output << "\t" << a + 1 << "\t" << ord[a].nama << "\t\tRp. " << ord[a].harga << "\t" << ord[a].jumlah << "\t" << ord[a].diskon<< "\t" << "\t" << ord[a].total << endl;
    output << "\t------------------------------------------------\t" << endl;
}


    output <<"\t--------------------------------Total   :"<<"Rp. "<< total<< endl;
    output <<"\t--------------------------------PPN     :"<<"Rp. "<< total*10/100 << endl;

    output.close();

}


int main()
{
    cout << "|===============================================================================|\n";
    cout << "| \t                        Toko Laris                                     \t|" << endl;
    cout << "| \t                       Daftar Harga                                    \t|" << endl;
    cout << "|===============================================================================|\n";
    cout << "|\t Ukuran Baju \t|\t Nama Ukuran \t|\t Harga per potong \t|"<< endl;
    cout << "|===============================================================================|\n";
    cout << "|\t    S   \t|\t Small  \t|\t Rp. 36.000 \t\t|"<< endl;
    cout << "|\t    M   \t|\t Medium \t|\t Rp. 43.000 \t\t|"<< endl;
    cout << "|\t    L   \t|\t Large  \t|\t Rp. 62.000 \t\t|"<< endl;
    cout << " ===============================================================================\n";


    cout << "Dapatkan diskon 20% untuk pembelian lebih dari 10 potong...\n";
    cout << "Jangan lupa, pajaknya ya...<10% x <harga-diskon>\n";

    cout << "Berapa jumlah data <maks 3> ? :  ";
    cin >> jumlah;

    if (jumlah > 3) {
        cout << "Jumlah tidak valid";
        return 0;
    }

    order ord[jumlah];

        for (int n = 0; n < jumlah; n++) {
        cout << "Data Ke " << n + 1 << endl;
        cout << "Ukuran (S/M/L) : ";
        cin >> ord[n].ukuran;
        cout << "Jumlah Beli : ";
        cin >> ord[n].jumlah;
    }

    input(ord);
    nota(ord);

    system("notepad nota.txt");
};
