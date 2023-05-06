/*  * File:   main.cpp
 * Author:Pelin erdem
 *	No:101044036
 * Created on 27 Eylül 2012 Perşembe, 11:06
 */

#include <iostream>
/*#include<ctime>
#include<cstring>*/

using namespace std;
int my_strlen(char str[]);
int my_pow(int sayi,int us);
void sayiCozum(char str1[],int harfSayisi[],int harfDigit[]);/*sayilarin basamak degeri karsılıklarini bulduran fonksiyon*/
void outputOfProgram(int sayiCozumleme[],int str_bir_size,char str_bir_once[]);/*cozumlenen sayilarin varsa uygun katsayi(larini) bulur*/

int main()
{
    /*harfSayisi ve harfDigit arraylari girilen ilk iki input stringinin sayi basamak karsılığını tutar*/
    /*arrayin her digiti bir harfi temsil eder ve bunlarin cogu array doldurulmasina ragmen boşs kalacaktır*/
    /*harf sayisi arrayi her harf icin baslangıcta bostur kullanılan harf icin degeri sıfırdan farkli bir deger olacaktır*/
    int harfSayisi[27];
    int harfDigit[28];
    char str1[11];
    char str2[11];
    char str_result[12];
    int i;
    int j;
    	for(i=0;i<=25;++i)
        	harfSayisi[i]=0;
    int harfDigitResult[27];
    	for(i=0;i<=25;++i)
        	harfDigit[i]=0;
   	 	for(i=0;i<=25;++i)
        	harfDigitResult[i]=0;
      /*eger girilen stringlerin boyu 10 u asarsa tekrar isteyecektir*/
    do{
        cout<<"uc tane string giriniz";
    	cin>>str1>>str2>>str_result;
    /*ilk string in elemanlarindan kacar tane oldugunu mesela 4 tane a ve bunlarin sayi cozumlemesindeki karsiligini tutan(1111) arrayler eklendi*/
    }while(my_strlen(str1)>10 && my_strlen(str2)>10 && my_strlen(str_result)>10);
   
    /*sayiCozum fonksiyonu ornegin girilen AABI string i icin 0.indexe 1100 1. indexe 10 8. indexe 1 atar digerleri sıfırdır*/
    /*yani arrayin her digiti bir sayi basamak degeri alır eger o harf girilmisse*/
    sayiCozum(str1,harfSayisi,harfDigit);
    sayiCozum(str2,harfSayisi,harfDigit);
 
    /**ucuncu string icin ayni islem**/
   sayiCozum(str_result,harfSayisi,harfDigitResult);
   int farkliHarf=0;
   for(i=0;i<=25;++i)
       if(harfSayisi[i]!=0)
           ++farkliHarf;
   
   /*10dan fazla farkli harf olma durumunda cıkıs yapar*/
   if(farkliHarf>10)
   {
       cout<<"10dan fazla farkli harf girdiniz";
       return 0;
   }
   /**str_bir_once ve str_bir_sonra girilen ilk iki string degerleri bir araya toplar ve 0. indexten itibaren kullanılan harfler*/
   /* digitlere(string digiti) islenir iki kere ayni degeri yazmamayi saglar*/
   /*str_bir_sonra son string icin bu islemi yapar*/
   
    char str_bir_once[11];
    char str_bir_sonra[11];
   
    for(i=0;i<11;++i)
        str_bir_once[i]=0;
    j=0;
    for(i=0;i<my_strlen(str1);++i){
        if(str1[i]!=str_bir_once[0] && str1[i]!=str_bir_once[1] && str1[i]!=str_bir_once[2] && str1[i]!=str_bir_once[3] && str1[i]!=str_bir_once[4]
                && str1[i]!=str_bir_once[5] && str1[i]!=str_bir_once[6] && str1[i]!=str_bir_once[7] && str1[i]!=str_bir_once[8] && str1[i]!=str_bir_once[9] )
        {
            str_bir_once[j]=str1[i];
            ++j;
        }
    }
    
    int k;
    k=j;
    for(i=0;i<my_strlen(str2);++i){
        if(str2[i]!=str_bir_once[0] && str2[i]!=str_bir_once[1] && str2[i]!=str_bir_once[2] && str2[i]!=str_bir_once[3] && str2[i]!=str_bir_once[4]
                && str2[i]!=str_bir_once[5] && str2[i]!=str_bir_once[6] && str2[i]!=str_bir_once[7] && str2[i]!=str_bir_once[8] && str2[i]!=str_bir_once[9] )
        {
            str_bir_once[k]=str2[i];
            ++k;
        }
    }
    int h=0;
    for(i=0;i<my_strlen(str_result);++i){
        if(str_result[i]!=str_bir_sonra[0] && str_result[i]!=str_bir_sonra[1] && str_result[i]!=str_bir_sonra[2] && str_result[i]!=str_bir_sonra[3] && str_result[i]!=str_bir_sonra[4]
                && str_result[i]!=str_bir_sonra[5] && str_result[i]!=str_bir_sonra[6] && str_result[i]!=str_bir_sonra[7] && str_result[i]!=str_bir_sonra[8] && str_result[i]!=str_bir_sonra[9] )
        {
            str_bir_sonra[h]=str_result[i];
            ++h;
        }
    }
  /*sizeler hesaplanir*/
    int str_bir_size=k;
    int str_bir_son_size=h;    
   
    /*sayiCozumleme(ilk iki string icin) ve sayiCozumlemeSon(son string icin) girilen stringlerin digit olarak karsılıgını tutar*/
    /*ilk for icin str_bir_once de var olan harflere gore belirlenen ve her harfin digit karsılıgının index karsılıgının tutldugu */
    /*harfDigit arrayi kullanılır*/
    
    int sayiCozumleme[11];
    int sayiCozumlemeSon[11];
    for(i=0;i<11;++i)
    {
        sayiCozumleme[i]=0;
        sayiCozumlemeSon[i]=0;
    }
    
    for(i=0;i<my_strlen(str_bir_once);++i)
    {
        if(str_bir_once[i]=='A')
            sayiCozumleme[i]=harfDigit[0];
        else if(str_bir_once[i]=='B')
            sayiCozumleme[i]=harfDigit[1];
        else if(str_bir_once[i]=='C')
            sayiCozumleme[i]=harfDigit[2];
        else if(str_bir_once[i]=='D')
            sayiCozumleme[i]=harfDigit[3];
        else if(str_bir_once[i]=='E')
            sayiCozumleme[i]=harfDigit[4];
        else if(str_bir_once[i]=='F')
            sayiCozumleme[i]=harfDigit[5];
        else if(str_bir_once[i]=='G')
            sayiCozumleme[i]=harfDigit[6];
        else if(str_bir_once[i]=='H')
            sayiCozumleme[i]=harfDigit[7];
        else if(str_bir_once[i]=='I')
            sayiCozumleme[i]==harfDigit[8];
        else if(str_bir_once[i]=='J')
            sayiCozumleme[i]=harfDigit[9];
        else if(str_bir_once[i]=='K')
            sayiCozumleme[i]=harfDigit[10];
        else if(str_bir_once[i]=='L')
            sayiCozumleme[i]=harfDigit[11];
        else if(str_bir_once[i]=='M')
            sayiCozumleme[i]=harfDigit[12];
        else if(str_bir_once[i]=='N')
            sayiCozumleme[i]=harfDigit[13];
        else if(str_bir_once[i]=='O')
            sayiCozumleme[i]=harfDigit[14];
        else if(str_bir_once[i]=='P')
            sayiCozumleme[i]=harfDigit[15];
        else if(str_bir_once[i]=='R')
            sayiCozumleme[i]=harfDigit[16];
        else if(str_bir_once[i]=='S')
            sayiCozumleme[i]=harfDigit[17];
        else if(str_bir_once[i]=='T')
            sayiCozumleme[i]=harfDigit[18];
        else if(str_bir_once[i]=='U')
            sayiCozumleme[i]=harfDigit[19];
        else if(str_bir_once[i]=='V')
            sayiCozumleme[i]=harfDigit[20];
        else if(str_bir_once[i]=='Y')
            sayiCozumleme[i]=harfDigit[21];
        else if(str_bir_once[i]=='Z')
            sayiCozumleme[i]=harfDigit[22];
        else if(str_bir_once[i]=='Q')
            sayiCozumleme[i]=harfDigit[23];
        else if(str_bir_once[i]=='W')
            sayiCozumleme[i]=harfDigit[24];
        else if(str_bir_once[i]=='X')
            sayiCozumleme[i]=harfDigit[25];
       
    }
  
    /*ikinci for da sonuc stringi icin aynı uygulama yapılır yani str_bir_Sonradaki harfler kullanılan harfler elimde bu harflerin */
    /*sayi karsılıgı var ve bunlar sayiCozumleme(ilk iki string icin) ve sayiCozumlemeSon(son str) arraylarinde tutuluyor*/
      for(i=0;i<my_strlen(str_bir_sonra);++i)
    {
        if(str_bir_sonra[i]=='A')
            sayiCozumlemeSon[i]=harfDigitResult[0];
        else if(str_bir_sonra[i]=='B')
            sayiCozumlemeSon[i]=harfDigitResult[1];
        else if(str_bir_sonra[i]=='C')
            sayiCozumlemeSon[i]=harfDigitResult[2];
        else if(str_bir_sonra[i]=='D')
            sayiCozumlemeSon[i]=harfDigitResult[3];
        else if(str_bir_sonra[i]=='E')
            sayiCozumlemeSon[i]=harfDigitResult[4];
        else if(str_bir_sonra[i]=='F')
            sayiCozumlemeSon[i]=harfDigitResult[5];
        else if(str_bir_sonra[i]=='G')
            sayiCozumlemeSon[i]=harfDigitResult[6];
        else if(str_bir_sonra[i]=='H')
            sayiCozumlemeSon[i]=harfDigitResult[7];
        else if(str_bir_sonra[i]=='I')
            sayiCozumlemeSon[i]=harfDigitResult[8];
        else if(str_bir_sonra[i]=='J')
            sayiCozumlemeSon[i]=harfDigitResult[9];
        else if(str_bir_sonra[i]=='K')
            sayiCozumlemeSon[i]=harfDigitResult[10];
        else if(str_bir_sonra[i]=='L')
            sayiCozumlemeSon[i]=harfDigitResult[11];
        else if(str_bir_sonra[i]=='M')
            sayiCozumlemeSon[i]=harfDigitResult[12];
        else if(str_bir_sonra[i]=='N')
            sayiCozumlemeSon[i]=harfDigitResult[13];
        else if(str_bir_sonra[i]=='O')
            sayiCozumlemeSon[i]=harfDigitResult[14];
        else if(str_bir_sonra[i]=='P')
            sayiCozumlemeSon[i]=harfDigitResult[15];
        else if(str_bir_sonra[i]=='R')
            sayiCozumlemeSon[i]=harfDigitResult[16];
        else if(str_bir_sonra[i]=='S')
            sayiCozumlemeSon[i]=harfDigitResult[17];
        else if(str_bir_sonra[i]=='T')
            sayiCozumlemeSon[i]=harfDigitResult[18];
        else if(str_bir_sonra[i]=='U')
            sayiCozumlemeSon[i]=harfDigitResult[19];
        else if(str_bir_sonra[i]=='V')
            sayiCozumlemeSon[i]=harfDigitResult[20];
        else if(str_bir_sonra[i]=='Y')
            sayiCozumlemeSon[i]=harfDigitResult[21];
        else if(str_bir_sonra[i]=='Z')
            sayiCozumlemeSon[i]=harfDigitResult[22];
        else if(str_bir_sonra[i]=='Q')
            sayiCozumlemeSon[i]=harfDigitResult[23];
        else if(str_bir_sonra[i]=='W')
            sayiCozumlemeSon[i]=harfDigitResult[24];
        else if(str_bir_sonra[i]=='X')
            sayiCozumlemeSon[i]=harfDigitResult[25];
    }
  
    /*for(i=0;i<h;++i)
        cout<<sayiCozumlemeSon[i]<<endl;*/
   /*eger str_bir_once ile str_bir_sonra stringlerinde ortak harfler varsa bunlarin sayi degeri karsılıkları birbirlerinden cıkarılıyor*/
    /*sonuc sayiCozumleme arrayinde tutuluyor yeni harf varsa eksilisi sayiCozumlemede tutulup harf str_bir_once arrayine aktariliyor */
    /*mantık su:ABQW+NHMB=HTGF olsun ABQW+NHMB-HTGF=0 seklinde isleme sokuluyor*/
   for(i=0;i<str_bir_son_size;++i){   
           if(str_bir_sonra[i]==str_bir_once[0] || str_bir_sonra[i]==str_bir_once[1] || str_bir_sonra[i]==str_bir_once[2] ||
                   str_bir_sonra[i]==str_bir_once[3] || str_bir_sonra[i]==str_bir_once[4] || str_bir_sonra[i]==str_bir_once[5] ||
                   str_bir_sonra[i]==str_bir_once[6] || str_bir_sonra[i]==str_bir_once[7] || str_bir_sonra[i]==str_bir_once[8]
              || str_bir_sonra[i]==str_bir_once[9] || str_bir_sonra[i]==str_bir_sonra[10]){
               if(str_bir_sonra[i]==str_bir_once[0])
                   sayiCozumleme[0]=sayiCozumleme[0]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[1])
                   sayiCozumleme[1]=sayiCozumleme[1]-sayiCozumlemeSon[i];
               else if( str_bir_sonra[i]==str_bir_once[2])
                   sayiCozumleme[2]=sayiCozumleme[2]-sayiCozumlemeSon[i];
               else if( str_bir_sonra[i]==str_bir_once[3])
                  sayiCozumleme[3]=sayiCozumleme[3]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[4])
                   sayiCozumleme[4]=sayiCozumleme[4]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[5])
                   sayiCozumleme[5]=sayiCozumleme[5]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[6])
                    sayiCozumleme[6]=sayiCozumleme[6]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[7])
                    sayiCozumleme[7]=sayiCozumleme[7]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[8])
                   sayiCozumleme[8]=sayiCozumleme[8]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_once[9])
                   sayiCozumleme[9]=sayiCozumleme[9]-sayiCozumlemeSon[i];
               else if(str_bir_sonra[i]==str_bir_sonra[10])
                   sayiCozumleme[10]=sayiCozumleme[10]-sayiCozumlemeSon[i];}
           else
           {
               str_bir_once[str_bir_size]=str_bir_sonra[i];
               sayiCozumleme[str_bir_size]=(-1)*sayiCozumlemeSon[i];
               ++str_bir_size;
           }
        }
   
    /*bu programda kullanılan degisik fark sayisina gorer kosullar belirleniyor ve uygun kosula girdiginde rakamlarin farkli */
    /*olmasi gerektigi bilinerek uygun harfer bulunuyor yoksa bulunamadı mesajı bastırılıyor*/
    outputOfProgram(sayiCozumleme,str_bir_size,str_bir_once);

    
   }


int my_strlen(char str[])
{
    int count=0;
    for(int i=0;str[i]!='\0';++i)
        ++count;
    
    return count;
}
int my_pow(int sayi,int us)
{
    int result=1;
    for(int i=0;i<us;++i)
        result = result*sayi;
    return result;
}
void sayiCozum(char str1[],int harfSayisi[],int harfDigit[])
{int i,j;
    for( i=0,j=0;i<my_strlen(str1) && j<9;++i,++j)
    {
        if(str1[i]=='A')
        {
            harfDigit[0] += my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[0];
        }
        else if(str1[i]=='B')
        {
            harfDigit[1] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[1];
        }
        else if(str1[i]=='C')
        {
            harfDigit[2] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[2];
        }
         else if(str1[i]=='D')
        {
            harfDigit[3] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[3];
        }
           else if(str1[i]=='E')
        {
            harfDigit[4] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[4];
        }
         else if(str1[i]=='F')
        {
            harfDigit[5] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[5];
        }
         else if(str1[i]=='G')
        {
            harfDigit[6] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[6];
        }
         else if(str1[i]=='H')
        {
            harfDigit[7] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[7];
        } 
        else if(str1[i]=='I')
        {
            harfDigit[8] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[8];
        }
         else if(str1[i]=='J')
        {
            harfDigit[9] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[9];
        }
         else if(str1[i]=='K')
        {
            harfDigit[10] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[10];
        }
         else if(str1[i]=='L')
        {
            harfDigit[11] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[11];
        }
        else if(str1[i]=='M')
        {
            harfDigit[12] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[12];
        }
         else if(str1[i]=='N')
        {
            harfDigit[13] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[13];
        }
         else if(str1[i]=='O')
        {
            harfDigit[14] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[14];
        }
         else if(str1[i]=='P')
        {
            harfDigit[15] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[15];
        }
         else if(str1[i]=='R')
        {
            harfDigit[16] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[16];
        }
         else if(str1[i]=='S')
        {
            harfDigit[17] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[17];
        }
         else if(str1[i]=='T')
        {
            harfDigit[18] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[18];
        }
         else if(str1[i]=='U')
        {
            harfDigit[19] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[19];
        }
         else if(str1[i]=='V')
        {
            harfDigit[20] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[20];
        }
         else if(str1[i]=='Y')
        {
            harfDigit[21] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[21];
        }
         else if(str1[i]=='Z')
        {
            harfDigit[22] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[22];
        }
         else if(str1[i]=='Q')
        {
            harfDigit[23] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[23];
        }
         else if(str1[i]=='W')
        {
            harfDigit[24] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[24];
        }
         else if(str1[i]=='X')
        {
            harfDigit[25] +=my_pow(10,my_strlen(str1)-j-1);
            ++harfSayisi[25];
        }
}

}
void outputOfProgram(int sayiCozumleme[],int str_bir_size,char str_bir_once[])
{
        int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
        int h=0,j=0,i=0,k=0;
        
    int flag=0;
    if(str_bir_size==10)
    {
        for(a=0;a<=9;++a)
        for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d)
                    for(e=0;e<=9;++e)
                        for(f=0;f<=9;++f)
                            for(g=0;g<=9;++g)
                                for(h=0;h<=9;++h)
                                    for(k=0;k<=9;++k)
                                        for(i=0;i<=9;++i)
                                        {
                                           if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d+
                                                   sayiCozumleme[4]*e+sayiCozumleme[5]*f+sayiCozumleme[6]*g+sayiCozumleme[7]*h
                                                   +sayiCozumleme[8]*k+sayiCozumleme[9]*i==0)
                                           {
                                               if(a !=b && a!=c && a!=d && a!=e && a!=f && a !=g && a !=h && a !=k && a !=i &&
                                                   b!=c && b!=d && b !=e && b!=f && b!=g && b!=h && b!=k && b!=i &&
                                                       c!=d && c!=e && c!=f && c!=g && c!=h && c!=k && c!=i &&
                                                       d !=e && d!=f && d!=g && d!=h && d!=k && d!=i &&
                                                       e!=f && e !=g && e!=h && e!=k && e!=i &&
                                                       f!=g && f!=h && f!=k && f!=i &&
                                                       g!=h && g!=k && g!=i &&
                                                       h!=k && h!= i &&k!=i){
                                                   cout<<str_bir_once[0]<<"="<<a<<endl;
                                                   cout<<str_bir_once[1]<<"="<<b<<endl;
                                                   cout<<str_bir_once[2]<<"="<<c<<endl;
                                                   cout<<str_bir_once[3]<<"="<<d<<endl;
                                                   cout<<str_bir_once[4]<<"="<<e<<endl;
                                                   cout<<str_bir_once[5]<<"="<<f<<endl;
                                                   cout<<str_bir_once[6]<<"="<<g<<endl;
                                                   cout<<str_bir_once[7]<<"="<<h<<endl;
                                                   cout<<str_bir_once[8]<<"="<<k<<endl;
                                                   cout<<str_bir_once[9]<<"="<<i<<endl;
                                                   cout<<endl<<endl;
                                                   flag=1;
                                               }
                                               
                                           }
                                           
                                        }
        if(flag==0)
            cout<<"uygun sayi bulunamadi\n";
    }
    else if(str_bir_size==9)
    {
        for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d)
                    for(e=0;e<=9;++e)
                        for(f=0;f<=9;++f)
                            for(g=0;g<=9;++g)
                                for(h=0;h<=9;++h)
                                    for(k=0;k<=9;++k)
                                        {
                                           if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d+
                                                   sayiCozumleme[4]*e+sayiCozumleme[5]*f+sayiCozumleme[6]*g+sayiCozumleme[7]*h
                                                   +sayiCozumleme[8]*k==0)
                                           {
                                               if(a!=b && a!=c && a!=d && a !=e && a!=f && a!=g && a!=h && a!=k &&
                                                       b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=k &&
                                                       c!=d && c !=e && c!=f && c!=g && c!=h && c!=k &&
                                                       d !=e && d!=f && d!=g && d!=h && d!=k &&
                                                       e!=f && e!=g && e!=h && e!=k &&
                                                       f!=g && f!=h && f!=k && 
                                                      g!=h && g!=k &&h !=k)
                                               {
                                                   cout<<str_bir_once[0]<<"="<<a<<endl;
                                                   cout<<str_bir_once[1]<<"="<<b<<endl;
                                                   cout<<str_bir_once[2]<<"="<<c<<endl;
                                                   cout<<str_bir_once[3]<<"="<<d<<endl;
                                                   cout<<str_bir_once[4]<<"="<<e<<endl;
                                                   cout<<str_bir_once[5]<<"="<<f<<endl;
                                                   cout<<str_bir_once[6]<<"="<<g<<endl;
                                                   cout<<str_bir_once[7]<<"="<<h<<endl;
                                                   cout<<str_bir_once[8]<<"="<<k<<endl;
                                                    cout<<endl<<endl;
                                                   flag=1;
                                               }
                                               
                                                   
                                           }
                                           if(flag=0)
                                               cout<<"sayilar bulunamadi\n";
    }
    }
    else if(str_bir_size==8)
    {
         for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d)
                    for(e=0;e<=9;++e)
                        for(f=0;f<=9;++f)
                            for(g=0;g<=9;++g)
                                for(h=0;h<=9;++h)
                                    {
                                           if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d+
                                                   sayiCozumleme[4]*e+sayiCozumleme[5]*f+sayiCozumleme[6]*g+sayiCozumleme[7]*h
                                                   ==0){
                                               if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h &&
                                                     b!=c  && b!=d && b!=e && b!=f && b!=g && b!=h &&
                                                       c!=d && c!=e && c!=f && c!=g && c!=h &&
                                                       d!=e && d!=f && d!=g && d!=h &&
                                                       e!=f && e!=g && e!=h &&
                                                     f!=g && f!=h && g!=h)
                                               {
                                                   cout<<str_bir_once[0]<<"="<<a<<endl;
                                                   cout<<str_bir_once[1]<<"="<<b<<endl;
                                                   cout<<str_bir_once[2]<<"="<<c<<endl;
                                                   cout<<str_bir_once[3]<<"="<<d<<endl;
                                                   cout<<str_bir_once[4]<<"="<<e<<endl;
                                                   cout<<str_bir_once[5]<<"="<<f<<endl;
                                                   cout<<str_bir_once[6]<<"="<<g<<endl;
                                                   cout<<str_bir_once[7]<<"="<<h<<endl;
                                                    cout<<endl<<endl;
                                                   flag=1;
                                               }
                                              
                                               
                                           }
                                           
        }
         if(flag=0)
             cout<<"uygun sayi yok";
    }
    else if(str_bir_size==7)
    {
        for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d)
                    for(e=0;e<=9;++e)
                        for(f=0;f<=9;++f)
                            for(g=0;g<=9;++g)
                               {
                                           if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d+
                                                   sayiCozumleme[4]*e+sayiCozumleme[5]*f+sayiCozumleme[6]*g==0)
                                           {
                                               if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g &&
                                                       b!=c && b!=d && b!=e && b!=f && b!=g &&
                                                       c!=d && c!=e && c!=f && c!=g && 
                                                       d!=e && d!=f && d!=g &&
                                                       e!=f && e!=g &&f!=g)
                                               {
                                                   cout<<str_bir_once[0]<<"="<<a<<endl;
                                                   cout<<str_bir_once[1]<<"="<<b<<endl;
                                                   cout<<str_bir_once[2]<<"="<<c<<endl;
                                                   cout<<str_bir_once[3]<<"="<<d<<"\n";
                                                   cout<<str_bir_once[4]<<"="<<e<<endl;
                                                   cout<<str_bir_once[5]<<"="<<f<<endl;
                                                   cout<<str_bir_once[6]<<"="<<g<<endl;
                                                    cout<<endl<<endl;
                                                   flag=1;
                                               }
                                               
                                               
                                           }
                                           
                            }
        if(flag=0)
            cout<<"bulunamadi";
    }
    
    else if(str_bir_size==6)
    {
       for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d)
                    for(e=0;e<=9;++e)
                        for(f=0;f<=9;++f){
                            if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d+
                               sayiCozumleme[4]*e+sayiCozumleme[5]*f==0){
                                if(a!=b && a!=c && a!=d && a!=e && a!=f &&
                                    b!=c && b!=d && b!=e && b!=f &&
                                        c!=d && c!=e && c!=f &&
                                        d!=e && d!=f && 
                                        e!=f)
                                {
                                    cout<<str_bir_once[0]<<"="<<a<<endl;
                                    cout<<str_bir_once[1]<<"="<<b<<endl;
                                    cout<<str_bir_once[2]<<"="<<c<<endl;
                                    cout<<str_bir_once[3]<<"="<<d<<endl;
                                    cout<<str_bir_once[4]<<"="<<e<<endl;
                                    cout<<str_bir_once[5]<<"="<<f<<endl;
                                     cout<<endl<<endl;
                                    flag=1;
                                }
                               
                        
                        
                        }
                            
                        }
       if(flag=0)
           cout<<"uygun sayi bulunamadi";
    }
    else if(str_bir_size==5)
    {
        for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d)
                    for(e=0;e<=9;++e){
                            if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d+
                               sayiCozumleme[4]*e==0)
                            {
                                if(a!=b && a!=c && a!=d &&a!=e &&
                                        b!=c && b!=d && b!=e && 
                                        c!=d && c!=e && d!=e)
                                {
                                    cout<<str_bir_once[0]<<"="<<a<<endl;
                                    cout<<str_bir_once[1]<<"="<<b<<endl;
                                    cout<<str_bir_once[2]<<"="<<c<<endl;
                                    cout<<str_bir_once[3]<<"="<<d<<endl;
                                    cout<<str_bir_once[4]<<"="<<e<<endl;
                                     cout<<endl<<endl;
                                    flag=1;
                                }
                               
                            }
                           
                    }
        if(flag==0)
            cout<<"sayi yok";
    }
    else if(str_bir_size==4)
    {
       for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c)
                for(d=0;d<=9;++d){
                            if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c+sayiCozumleme[3]*d==0)
                            {
                                if(a!=b && a!=c && a!=d &&
                                        b!=c && b!=d &&
                                        c!=d)
                                {
                                    cout<<str_bir_once[0]<<"="<<a<<endl;
                                    cout<<str_bir_once[1]<<"="<<b<<endl;
                                    cout<<str_bir_once[2]<<"="<<c<<endl;
                                    cout<<str_bir_once[3]<<"="<<d<<endl;
                                     cout<<endl<<endl;
                                    flag=1;
                                }
                                
                            }
                            if(flag==0)
                                cout<<"sayilar uygun degil";
                }
       
                    
    }
    else if(str_bir_size==3)
    {
        for(a=0;a<=9;++a)
          for(b=0;b<=9;++b)
            for(c=0;c<=9;++c){
                            if(sayiCozumleme[0]*a+sayiCozumleme[1]*b+sayiCozumleme[2]*c==0){
                                if(a!=b && a!=c && b!=c)
                                {
                                    cout<<str_bir_once[0]<<"="<<a<<endl;
                                    cout<<str_bir_once[1]<<"="<<b<<endl;
                                    cout<<str_bir_once[2]<<"="<<c<<endl;
                                     cout<<endl<<endl;
                                    flag=1;
                                }
                                
                            }
                            
                            if(flag==0)
                                cout<<"bulunamadi";
                            
            }
        
    }
    else if(str_bir_size==2)
    {
        for(a=0;a<=9;++a)
          for(b=0;b<=9;++b){
              if(sayiCozumleme[0]*a+sayiCozumleme[1]*b==0)
              {
                  if(a!=b){
                      cout<<str_bir_once[0]<<"="<<a<<endl;
                  cout<<str_bir_once[1]<<"="<<b<<endl;
                   cout<<endl<<endl;
                  flag=1;}
                  
                  
              }
              
              
          }
        if(flag==0)
            cout<<"deger yok";
    }
}

