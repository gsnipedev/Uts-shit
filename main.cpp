#include<iostream>
#include<iomanip>


int main()
{

	double_t gaji = 4000000;
	int pilihan_jabatan = 0;

	int pilihan_apakah_sudah_menikah = 0;

	std::cout << "Pilih jabatan :" << std::endl;
	std::cout << "1. Manajer \n2. Karyawan" << std::endl;

	std::cout << "Pilih : ";
	std::cin >> pilihan_jabatan;

	//baris ini akan dieksekusi apabila pilihan "Sudah Menikah" dipilih
	//dan akan memperbarui nilai awal gaji menjadi 3.500.000,00
	if (pilihan_jabatan == 2) gaji = 3500000;

	std::cout << "Apakah sudah menikah :" << std::endl;
	std::cout << "1. Sudah \n2. Belum" << std::endl;

	std::cout << "Pilih: ";
	std::cin >> pilihan_apakah_sudah_menikah;


	//baris ini akan dieksekusi apabila pilihan "Sudah Menikah" dipilih
	//dan akan memperbarui nilai dari variabel gaji
	if (pilihan_apakah_sudah_menikah == 1) gaji = gaji + gaji * 0.4;


	//terakhir, total gaji akan ditampilkan ke konsol
	std::cout << "Total gaji: " << std::fixed << std::setprecision(2) << gaji << std::endl;



	return 0;
}