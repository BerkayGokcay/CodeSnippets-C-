#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <queue>
//Gerekli kütüphaneler

using namespace std ;

// 
class text
{
	public :
		// Kurucu fonksiyon
		text()
		{
			input = {} ;
			alt_input = {} ;
		}
		//Mainde getline fonksiyonu ile string olarak alınan satırı ayraçlara göre parçalayarak text dosyasından saniye kısmını bulmamızı sağlayan fonksiyon
		int FindPoint(const string& seperator) 
		{
			int p1, p2;
			p1 = input.find(seperator, 0);
			p2 = input.find(seperator, p1 + 1);
			return p2;
		}
		string input  ;    //Textten alınan ana string
		string alt_input ;  //Parçalanan stringin saniyeyi tutan alt stringi
		queue<string> Acq;	//Ac komutunu saklayan string
		queue<string> Kapatq;	//Kapat komutunu saklayan string
		queue<string> sagq;	//Sağ komutunu saklayan string
		queue<string> solq;	//Sol komutunu saklayan string
};

int main()
{
	//Class nesneleri 

	text sound ;
	text sound2 ;

	// Dosya açma işlemleri

	ifstream iPtr("outputI.txt", ios::in);
	ifstream aPtr("outputA.txt", ios::in);
	ofstream iacPtr("kisi1Ac.txt", ios::out);
	ofstream ikapatPtr("kisi1Kapat.txt", ios::out);
	ofstream isagPtr("kisi1Sag.txt", ios::out);
	ofstream isolPtr("kisi1Sol.txt", ios::out);
	ofstream aacPtr("kisi2Ac.txt", ios::out);
	ofstream akapatPtr("kisi2Kapat.txt", ios::out);
	ofstream asagPtr("kisi2Sag.txt", ios::out);
	ofstream asolPtr("kisi2Sol.txt", ios::out);
	ofstream ACptr("Aç-Kişi-1-2.txt",ios::out) ;
	ofstream KAPATptr("Kapat-Kişi-1-2.txt",ios::out) ;
	ofstream SAGptr("Sag-Kişi-1-2.txt",ios::out) ;
	ofstream SOLptr("Sol-Kişi-1-2.txt",ios::out) ;

	//Dosya kontrol 

	if (!iPtr && !aPtr && iacPtr && ikapatPtr && isagPtr && isolPtr && aacPtr && akapatPtr && asagPtr && asolPtr)
	{
		cerr << ("File could not be opened.");
		exit(EXIT_FAILURE);
	}

	//1. kişininin text dosyalarının incelenmesi
	while (!iPtr.eof())
	{
		getline(iPtr, sound2.input); //Satırın stringe alınması
		while (sound2.input != "\0")
		{
			sound2.alt_input = sound2.input.substr(0, sound2.FindPoint(".")); //Stringin saniyeye indirgenmesi

			if (sound2.alt_input > "0" && sound2.alt_input < "1.597") //Text dosyasına göre Aç komutunun alınması

			{
				sound2.Acq.push(sound2.input) ; //Alınan stringin queue pushlanması
				iacPtr<<sound2.Acq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			else if (sound2.alt_input > "1.597" && sound2.alt_input < "2.831") //Text dosyasına göre Kapat komutunun alınması
			{
				sound2.Kapatq.push(sound2.input); //Alınan stringin queue pushlanması
				ikapatPtr<<sound2.Kapatq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			else if (sound2.alt_input > "2.831" && sound2.alt_input < "3.897") //Text dosyasına göre Sağ komutunun alınması
			{
				sound2.sagq.push(sound2.input); //Alınan stringin queue pushlanması
				isagPtr<<sound2.sagq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			else if (sound2.alt_input > "3.897" && sound2.alt_input < "4.911") //Text dosyasına göre Sol komutunun alınması
			{
				sound2.solq.push(sound2.input); //Alınan stringin queue pushlanması
				isolPtr<<sound2.solq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			break;
		}
	}

	//2. kişininin text dosyalarının incelenmesi

	while (!aPtr.eof())
	{
		getline(aPtr, sound.input);
		while (sound.input != "\0")
		{
			sound.alt_input = sound.input.substr(0, sound.FindPoint(","));  //Stringin saniyeye indirgenmesi
			if (sound.alt_input > "0" && sound.alt_input < "0,7863") //Text dosyasına göre Aç komutunun alınması
			{
				sound.Acq.push(sound.input) ; //Alınan stringin queue'e pushlanması
				aacPtr<<sound.Acq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			else if (sound.alt_input > "0,7863" && sound.alt_input < "2,07") //Text dosyasına göre Kapat komutunun alınması
			{
				sound.Kapatq.push(sound.input); //Alınan stringin queue'e pushlanması
				akapatPtr<<sound.Kapatq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			else if (sound.alt_input > "2,07" && sound.alt_input < "3,607")	//Text dosyasına göre Sağ komutunun alınması
			{
				sound.sagq.push(sound.input); //Alınan stringin queue'e pushlanması
				asagPtr<<sound.sagq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			else if (sound.alt_input > "3,607" && sound.alt_input < "4,797") ////Text dosyasına göre Sol komutunun alınması
			{
				sound.solq.push(sound.input); //Alınan stringin queue'e pushlanması
				asolPtr<<sound.solq.front()<<endl ; //Alınan stringin dosyaya yazdırılması
				break;
			}
			break;
		}
	}
	//Dosyaların kapatılması
	iacPtr.close();
	ikapatPtr.close();
	isagPtr.close();
	isolPtr.close();
	aacPtr.close();
	akapatPtr.close();
	asagPtr.close();
	asolPtr.close();

	while(!sound.Acq.empty()) //Kişi-1'in Aç komutunun queueların kullanılarak toplu dosyaya yazdırılması
	{
		ACptr<<sound.Acq.front()<<endl ;
		sound.Acq.pop() ;		// queue'dan eleman eksiltme
	}
	ACptr<<endl<<"*********************************************************************"<<endl<<endl ;
	while(!sound2.Acq.empty()) //Kişi-2'in Aç komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		ACptr<<sound2.Acq.front()<<endl ;
		sound2.Acq.pop() ;		// queue'dan eleman eksiltme
	}

	while(!sound.Kapatq.empty()) //Kişi-1'in Kapat komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		KAPATptr<<sound.Kapatq.front()<<endl ;
		sound.Kapatq.pop() ;		// queue'dan eleman eksiltme
	}
	KAPATptr<<endl<<"*********************************************************************"<<endl<<endl ;
	while(!sound2.Kapatq.empty()) //Kişi-2'in Kapat komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		KAPATptr<<sound2.Kapatq.front()<<endl ;
		sound2.Kapatq.pop() ;			// queue'dan eleman eksiltme
	}

	while(!sound.solq.empty()) //Kişi-1'in Sol komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		SOLptr<<sound.solq.front()<<endl ;
		sound.solq.pop() ;		 // queue'dan eleman eksiltme
	}
	SOLptr<<endl<<"*********************************************************************"<<endl<<endl ;
	while(!sound2.solq.empty()) //Kişi-2'in Sol komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		SOLptr<<sound2.solq.front()<<endl ;
		sound2.solq.pop() ;		// queue'dan eleman eksiltme
	}
		
	while(!sound.sagq.empty()) //Kişi-1'in Sağ komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		SAGptr<<sound.sagq.front()<<endl ;
		sound.sagq.pop() ;		// queue'dan eleman eksiltme
	}
	SAGptr<<endl<<"*********************************************************************"<<endl<<endl ;
	while(!sound2.sagq.empty()) //Kişi-2'in Sağ komutunun queue kullanılarak toplu dosyaya yazdırılması
	{
		SAGptr<<sound2.sagq.front()<<endl ;
		sound2.sagq.pop() ;		// queue'dan eleman eksiltme
	}

	ACptr.close() ;
	KAPATptr.close() ;
	SAGptr.close() ;
	SOLptr.close() ;

	return 0;
}
