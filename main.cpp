//Blend Saiti
//Detyra Projektuse
//Detyra 5 - Krijoni konvertuesin e orës, nga lloji 24-orësh në 12 orësh dhe e kundërta!
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;


void convert24to12(string koha,string ndaresiKohes) //Fuknsioni per te konvertuar oren prej 24 ne 12, kemi perdoru void funksion pershkak se konvertimi behet dhe shtypet permes cout konvertimit
{
    int ora =  stoi(koha.substr(0,koha.find(ndaresiKohes))); //Funksioni i thirrur stoi do te thot qe string-un e konverton ne int,ndersa substr() e ben ndarjen e stringut ku parametri i par eshte
    //indexi,ndersa parametri i dyt deri ku deshirojm ta ndajm string-un
    int minutat = stoi(koha.substr(3,koha.find(ndaresiKohes)));
    int sekondat = stoi(koha.substr(6,koha.find(ndaresiKohes)));

    if(ora==0&&ora!=12) //nese ora==0&&ora!=12 shtyp ket mesazh
    {
        ora=12;
        cout<<ora<<":"<<minutat<<":"<<sekondat<<" AM" << endl;
    }
    else if(ora==12&&ora!=0)//nese ne te kunderten ora==12&&ora!=0 shtyp ket mesazh
    {
        ora=12;
        cout<<ora<<":"<<minutat<<":"<<sekondat<<" PM" << endl;

    }
    else if(ora<12&&ora!=0)//nese ne te kunderten ora<12&&ora!=0 shtyp ket mesazh
    {
        ora=ora;
        cout<<ora<<":"<<minutat<<":"<<sekondat<<" AM" << endl;

    }
    else if(ora>12&&ora!=0)//nese ne te kunderten ora>12&&ora!=0 shtyp ket mesazh
    {
        ora=ora-12;
        cout<<ora<<":"<<minutat<<":"<<sekondat<<" PM" << endl;

    }

}

void convert12to24(string koha,string ndaresiKohes)
{
    int ora =  stoi(koha.substr(0,koha.find(ndaresiKohes))); ////Funksioni i thirrur stoi do te thot qe string-un e konverton ne int,ndersa substr() e ben ndarjen e stringut ku parametri i par eshte
    //indexi,ndersa parametri i dyt deri ku deshirojm ta ndajm string-un
    int minutat = stoi(koha.substr(3,koha.find(ndaresiKohes)));
    int sekondat = stoi(koha.substr(6,koha.find(ndaresiKohes)));

    string PMAM = koha.substr(9,koha.find("-"));
    if (PMAM == "AM") //nese PMAM== AM
    {
        if (ora == 12) //neser ora == 12 shtyp ket mesazh
        {
            cout<<"00"<<":"<<minutat<<":"<<sekondat<<endl;
        }
        else//ne te kunderten shtyp ket mesazh
        {

            cout<<ora<<":"<<minutat<<":"<<sekondat<<endl;
        }
    }
    else //ne te kunderten
    {
        if (ora == 12) //nese ora == 12 shtyp ket mesazh
        {
            cout<<ora<<":"<<minutat<<":"<<sekondat<<endl;
        }
        else //ne te kunderten shtyp ket mesazh
        {
            ora += 12;
            cout<<ora<<":"<<minutat<<":"<<sekondat<<endl;

        }
    }
}

int main()
{
    int konvertimi;
    cout << "Shtyp 1 nese don te transfrohesh kohen nga 24-format ne 12-format\nShtyp 2 nese don te transferoesh nga 12-format ne 24-format\n";
    //Kjo variabel eshte per te mar se cilin nga mundesit qe i ka klienti e deshiron
    cin >> konvertimi;


    string ndaresiKohes = ":"; //Na mundeson qe ta ndajm kohen qe eshte futur si string permes substr


    if(konvertimi == 1) // nese flag == 1 ateher do te thot se deshirot nga 24-format ne 12-format
        //dhe gjithashtu e njoftojm se si duhet te futet koha ne input
    {

        cout<< "Shkruaj kohen ne kete menyr HH:MM:SS" << endl;

        //Koha qe klienti deshiron ta konvertoj
        string koha; //Koha qe klienti deshiron ta konvertoj
        cin >> koha; //jepet vlera nga perdoruesi
        convert24to12(koha,ndaresiKohes);
    }
    else if(konvertimi == 2)// ne te kunderten nese flag == 2 ateher do te thot se deshiron nga 12-format ne 24-format
        //dhe gjithashtu e njoftojm se si duhet te futet koha ne input
    {

        cout << "Shkruaj kohen ne kete menyr HH:MM:SS-PM/AM" << endl;

        string koha; //Koha qe klienti deshiron ta konvertoj
        cin >> koha; //jepet vlera nga perdoruesi
        convert12to24(koha,ndaresiKohes);
    }

    else //ne te kunderten shtyp ket mesaszh
    {
        cout<< "Keni zgjedhur numrin e gabuar shtyp 1,2 ose 3"<<endl;
    }




    return 0;
}



