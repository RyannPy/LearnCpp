#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Pendonor {
    int golonganDarah;
    int volumeDarah;
};

int main() {
    int jumlahPendonor, jumlahDesa;

    cout << "Jumlah pendonor: ";
    cin >> jumlahPendonor;
    cout << "Jumlah desa: ";
    cin >> jumlahDesa;

    // Membuat struktur data untuk menyimpan data pendonor per desa
    vector<map<int, pair<int, int>>> dataDesa(jumlahDesa + 1); // Index dimulai dari 1

    for (int i = 1; i <= jumlahPendonor; ++i) {
        int desa, golonganDarah, volumeDarah;
        cout << "Pendonor ke-" << i << endl;
        cout << "Desa (1-" << jumlahDesa << "): ";
        cin >> desa;
        cout << "Golongan darah (A=1, B=2, AB=3, O=4): ";
        cin >> golonganDarah;
        cout << "Volume darah: ";
        cin >> volumeDarah;

        dataDesa[desa][golonganDarah].first++; // Tambah jumlah pendonor
        dataDesa[desa][golonganDarah].second += volumeDarah; // Tambah total volume
    }

    // Menampilkan hasil
    for (int desa = 1; desa <= jumlahDesa; ++desa) {
        cout << "Desa " << desa << endl;
        for (int golonganDarah = 1; golonganDarah <= 4; ++golonganDarah) {
            cout << "Golongan darah " << golonganDarah << ": "
                 << dataDesa[desa][golonganDarah].first << " : "
                 << dataDesa[desa][golonganDarah].second << endl;
        }
    }

    return 0;
}
