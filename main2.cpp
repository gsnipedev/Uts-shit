#include<iostream>
#include<map>
#include<iterator>
#include<string>


class RumahSakit {



public:

	//attribute
	std::map<int, int> Kelas;
	std::map<int, std::string> Status;
	std::string NamaPasien;

	int HargaDokter = 75000;
	int Diskon = 0;
	int isRawatInap = 0;
	int isBpjs = 2;
	int LamaMenginap = 0;
	int KelasPilihan = 0;

	bool bIsBpjs = false;

	//getter

	int getHargaDokter()
	{
		return this->HargaDokter;
	}

	void NormalizeStatus(int status)
	{
		if (status == 1) return;

		ProcessRawatJalan();
	}

	int getHargaRawatInap(int kelas, bool isBpjs, int hari)
	{
		if (isBpjs) return HargaDokter + Kelas[kelas] * 0.5;

		return HargaDokter + Kelas[kelas] * 1;

	}

	void ProcessRawatInap()
	{

		std::cout << "Pakai BPJS [1. Ya | 2. Tidak]: ";
		std::cin >> this->isBpjs;

		if (isBpjs == 1) this->bIsBpjs = true;

		std::cout << "Berapa Hari Menginap: ";
		std::cin >> this->LamaMenginap;


		std::cout << "1. Kelas 1" << std::endl;
		std::cout << "2. Kelas 2" << std::endl;
		std::cout << "3. Kelas 3" << std::endl;
		std::cout << "4. Kelas VIP" << std::endl;

		std::cout << "Pilih Kelas: ";
		std::cin >> this->KelasPilihan;



		std::cout << "============================================================" << std::endl;
		std::cout << "Nama                 | \t" << this->NamaPasien << std::endl;
		std::cout << "Harga Dokter         | \t Rp." << 75000 << std::endl;
		std::cout << "Harga Kamar/Hari     | \t Rp." << Kelas[KelasPilihan] << std::endl;
		std::cout << "Lama Menginap (Hari) | \t" << LamaMenginap << std::endl;

		if (bIsBpjs) std::cout << "Diskon BPJS          | \t Rp." << Kelas[KelasPilihan] * 0.3 << std::endl;
		else std::cout << "Diskon BPJS          | \t Rp." << Kelas[KelasPilihan] * 0 << std::endl;

		std::cout << "============================================================" << std::endl;
		std::cout << "Total Harga          | \t Rp." << getHargaRawatInap(bIsBpjs, KelasPilihan) << std::endl;
		std::cout << "============================================================" << std::endl;

	}

	void ProcessRawatJalan()
	{
		std::cout << "Pakai BPJS [1. Ya | 2. Tidak]: ";
		std::cin >> isBpjs;

		if (this->isBpjs == 1)
		{
			std::cout << "===========================================" << std::endl;
			std::cout << "Nama           | \t" << this->NamaPasien << std::endl;
			std::cout << "Harga          | \t Rp." << 100000 << std::endl;
			std::cout << "Diskon BPJS    | \t Rp." << 30000 << std::endl;
			std::cout << "===========================================" << std::endl;
			std::cout << "Total Harga    | \t Rp." << getHargaRawatJalan(true) << std::endl;
			std::cout << "===========================================" << std::endl;
		}
		else
		{
			std::cout << "===========================================" << std::endl;
			std::cout << "Nama           | \t" << this->NamaPasien << std::endl;
			std::cout << "Harga          | \t Rp." << 100000 << std::endl;
			std::cout << "Diskon BPJS    | \t Rp." << 0 << std::endl;
			std::cout << "===========================================" << std::endl;
			std::cout << "Total Harga    | \t Rp." << getHargaRawatJalan(false) << std::endl;
			std::cout << "===========================================" << std::endl;
		}
	}


	//constructor
	RumahSakit()
	{
		Kelas[1] = 100000;
		Kelas[2] = 75000;
		Kelas[3] = 50000;
		Kelas[4] = 200000;
	}

private:
	int getHargaRawatJalan(bool isBpjs)
	{
		if (!isBpjs) return 100000;

		return 100000 - 100000 * 0.3;
	}

	int getHargaRawatInap(bool isBpjs, int levelKelas)
	{

		if (!isBpjs) return (75000 + LamaMenginap * Kelas[levelKelas]) * 0.5;

		return 75000 + LamaMenginap * Kelas[levelKelas];
	}

};



int main()
{
	RumahSakit rumahSakit;

	char shouldStop[1];

	while (true)
	{
		std::cout << "Masukkan Nama: ";
		std::getline(std::cin, rumahSakit.NamaPasien);

		std::cout << "Ingin rawat inap [1. Ya | 2. Tidak]: ";
		std::cin >> rumahSakit.isRawatInap;

		if (rumahSakit.isRawatInap == 2)
		{
			rumahSakit.ProcessRawatJalan();
		}
		else
		{
			rumahSakit.ProcessRawatInap();
		}

		std::cout << "Try Again [y/n]: ";
		std::cin >> shouldStop;

		if (strcmp(shouldStop, (const char*)'n') == 0 || strcmp(shouldStop, (const char*)'N') == 0) break;
	}
}