#include <stdio.h>
#include <stdlib.h>

// YASAR BERKAY KAZKILINC

struct ucak
{
    int oncelik_id;
    int ucak_id;
    int talep_edilen_inis_saati;
    int gecikme_suresi;
    int inis_saati;
    int kalkis_saati;
};

int ilk_ucak=0;
int son_ucak=0;
int eleman=0;
struct ucak ucaklar[100];
struct ucak gecici[1];
struct ucak inis_listesi[100];
struct ucak kalkis_listesi[100];

void Add(int yeni_oncelik,int yeni_id,int yeni_talep,int yeni_gecikme)
{
    if(yeni_gecikme>3)
    {
        printf("%d ID'li ucak maksimum ertelemeden dolayi Sabiha Gokcen Havalimani'na yonlendiriliyor.\n",yeni_id);
        return;
    }
    if(yeni_gecikme+yeni_talep >24)
    {
        return;
    }
    if(eleman==0) // KUYRUK BOS
    {
        inis_listesi[ilk_ucak].oncelik_id = yeni_oncelik;
        inis_listesi[ilk_ucak].ucak_id = yeni_id;
        inis_listesi[ilk_ucak].talep_edilen_inis_saati = yeni_talep;
        inis_listesi[ilk_ucak].gecikme_suresi = yeni_gecikme;
        eleman++;
        printf("%d id'li ucak saat %d icin inis talebiniz onaylandi\n",yeni_id,(yeni_talep+yeni_gecikme));
        InisListele();
    }
    else // KUYRUK DOLU
    {
        int i=0;
        int kontrol=0;
        while(i<eleman)
        {
            if(yeni_talep+yeni_gecikme == inis_listesi[i].talep_edilen_inis_saati+inis_listesi[i].gecikme_suresi)
            {
                kontrol=1;
                break;
            }
            i++;
        }
        if(kontrol==0) // ISTENEN SAAT BOS
        {
            if(yeni_gecikme+yeni_talep <= inis_listesi[ilk_ucak].gecikme_suresi+inis_listesi[ilk_ucak].talep_edilen_inis_saati) //basa ekle
            {
                int i;
                for(i=0; i<eleman; i++)
                {
                    inis_listesi[son_ucak-i+1]=inis_listesi[son_ucak-i];

                }
                /*   inis_listesi[son_ucak+1]=inis_listesi[son_ucak];
                     inis_listesi[son_ucak]=inis_listesi[son_ucak-1];
                     inis_listesi[son_ucak-1]=inis_listesi[son_ucak-2];*/

                inis_listesi[ilk_ucak].oncelik_id = yeni_oncelik;
                inis_listesi[ilk_ucak].ucak_id = yeni_id;
                inis_listesi[ilk_ucak].talep_edilen_inis_saati = yeni_talep;
                inis_listesi[ilk_ucak].gecikme_suresi = yeni_gecikme;
                son_ucak++;
                eleman++;
                printf("%d ID'li ucak saat %d icin inis talebiniz onaylandi\n",yeni_id,(yeni_talep+yeni_gecikme));
                InisListele();
                printf("\n");
                return;
            }

            if(yeni_gecikme+yeni_talep > inis_listesi[son_ucak].gecikme_suresi+inis_listesi[son_ucak].talep_edilen_inis_saati) // sona ekle
            {
                inis_listesi[eleman].oncelik_id= yeni_oncelik;
                inis_listesi[eleman].ucak_id=yeni_id;
                inis_listesi[eleman].talep_edilen_inis_saati=yeni_talep;
                inis_listesi[eleman].gecikme_suresi=yeni_gecikme;
                printf("%d ID'li ucak saat %d icin inis talebiniz onaylandi\n",yeni_id,yeni_talep);
                eleman++;
                son_ucak++;
                InisListele();
                printf("\n");
                return;
            }

            int n=0;
            if(yeni_gecikme+yeni_talep > inis_listesi[ilk_ucak].gecikme_suresi+inis_listesi[ilk_ucak].talep_edilen_inis_saati && yeni_gecikme+yeni_talep <= inis_listesi[son_ucak].gecikme_suresi+inis_listesi[son_ucak].talep_edilen_inis_saati)
            {
                while(n<eleman)  // ortaya ekle
                {
                    if(yeni_talep+yeni_gecikme >= inis_listesi[n].gecikme_suresi+inis_listesi[n].talep_edilen_inis_saati)
                    {
                        n++;
                    }
                    else
                    {
                        int j;
                        for(j=0; j<eleman-n; j++)
                        {
                            inis_listesi[son_ucak-j+1]=inis_listesi[son_ucak-j];

                        }
                        inis_listesi[n].oncelik_id=yeni_oncelik;
                        inis_listesi[n].ucak_id=yeni_id;
                        inis_listesi[n].talep_edilen_inis_saati=yeni_talep;
                        inis_listesi[n].gecikme_suresi=yeni_gecikme;
                        printf("%d ID'li ucak saat %d icin inis talebiniz onaylandi\n",inis_listesi[n].ucak_id,inis_listesi[n].talep_edilen_inis_saati+inis_listesi[n].gecikme_suresi);
                        eleman++;
                        son_ucak++;
                        InisListele();
                        break;

                    }
                }
            }
        }

        else  // ISTENEN SAAT DOLU
        {
            int i=0;
            while(1)
            {
                if(yeni_talep+yeni_gecikme == inis_listesi[i].talep_edilen_inis_saati+inis_listesi[i].gecikme_suresi)
                {
                    break;
                }
                i++;
            }

            if(yeni_oncelik < inis_listesi[i].oncelik_id) // ONCELIK YETIYOR
            {
                if(inis_listesi[i].gecikme_suresi !=3)
                {
                    gecici[0]=inis_listesi[i];
                    inis_listesi[i].oncelik_id=yeni_oncelik;
                    inis_listesi[i].ucak_id=yeni_id;
                    inis_listesi[i].talep_edilen_inis_saati=yeni_talep;
                    inis_listesi[i].gecikme_suresi=yeni_gecikme;
                    printf("%d ID'li ucak saat %d icin inis talebiniz onaylandi\n",inis_listesi[i].ucak_id,inis_listesi[i].talep_edilen_inis_saati+inis_listesi[i].gecikme_suresi);
                    printf("%d ID'li ucak erteleniyor\n",gecici[0].ucak_id);
                    gecici[0].gecikme_suresi++;
                    Add(gecici[0].oncelik_id,gecici[0].ucak_id,gecici[0].talep_edilen_inis_saati,gecici[0].gecikme_suresi);
                    return;

                }
                else if(inis_listesi[i].gecikme_suresi == 3)
                {
                    yeni_gecikme++;
                    Add(yeni_oncelik,yeni_id,yeni_talep,yeni_gecikme);
                    return;
                }
                else if(yeni_gecikme !=3 && inis_listesi[i].gecikme_suresi == 3)
                {
                    yeni_gecikme++;
                    Add(yeni_oncelik,yeni_id,yeni_talep,yeni_gecikme);
                }
                else if(yeni_gecikme == 3 && inis_listesi[i].gecikme_suresi == 3)
                {
                    if(yeni_id<inis_listesi[i].ucak_id)
                    {
                        gecici[0]=inis_listesi[i];
                        inis_listesi[i].oncelik_id=yeni_oncelik;
                        inis_listesi[i].ucak_id=yeni_id;
                        inis_listesi[i].talep_edilen_inis_saati=yeni_talep;
                        inis_listesi[i].gecikme_suresi=yeni_gecikme;
                        gecici[0].gecikme_suresi++;
                        Add(gecici[0].oncelik_id,gecici[0].ucak_id,gecici[0].talep_edilen_inis_saati,gecici[0].gecikme_suresi);

                    }
                    else
                    {
                        yeni_gecikme++;
                        return;
                    }
                }
            }
            if(yeni_oncelik == inis_listesi[i].oncelik_id) // ONCELIK AYNIYSA
            {
                if(yeni_gecikme == 3 && inis_listesi[i].gecikme_suresi==3)
                {
                    if(yeni_id<inis_listesi[i].ucak_id)
                    {
                        gecici[0]=inis_listesi[i];
                        inis_listesi[i].oncelik_id=yeni_oncelik;
                        inis_listesi[i].ucak_id=yeni_id;
                        inis_listesi[i].talep_edilen_inis_saati=yeni_talep;
                        inis_listesi[i].gecikme_suresi=yeni_gecikme;
                        gecici[0].gecikme_suresi++;
                        Add(gecici[0].oncelik_id,gecici[0].ucak_id,gecici[0].talep_edilen_inis_saati,gecici[0].gecikme_suresi);

                    }
                    else
                    {
                        yeni_gecikme++;
                        return;
                    }

                }
                else if(yeni_gecikme !=3 && inis_listesi[i].gecikme_suresi == 3)
                {
                    yeni_gecikme++;
                    Add(yeni_oncelik,yeni_id,yeni_talep,yeni_gecikme);
                }

                else
                {
                    if(yeni_id < inis_listesi[i].ucak_id)
                    {
                        gecici[0]=inis_listesi[i];
                        inis_listesi[i].oncelik_id=yeni_oncelik;
                        inis_listesi[i].ucak_id=yeni_id;
                        inis_listesi[i].talep_edilen_inis_saati=yeni_talep;
                        inis_listesi[i].gecikme_suresi=yeni_gecikme;
                        gecici[0].gecikme_suresi++;
                        Add(gecici[0].oncelik_id,gecici[0].ucak_id,gecici[0].talep_edilen_inis_saati,gecici[0].gecikme_suresi);
                    }
                    else
                    {
                        yeni_gecikme++;
                        Add(yeni_oncelik,yeni_id,yeni_talep,yeni_gecikme);
                    }

                }
                return;
            }
            if(yeni_oncelik > inis_listesi[i].oncelik_id) // ONCELIK YETMIYOR
            {
                if(yeni_gecikme == 3 && inis_listesi[i].gecikme_suresi!=3)
                {
                    printf("%d ID'li ucak maksimum ertelemeden dolayi %d ID'li ucagin yerine geciyor\n",yeni_id,inis_listesi[i].ucak_id);
                    gecici[0]=inis_listesi[i];
                    inis_listesi[i].oncelik_id=yeni_oncelik;
                    inis_listesi[i].ucak_id=yeni_id;
                    inis_listesi[i].talep_edilen_inis_saati=yeni_talep;
                    inis_listesi[i].gecikme_suresi=yeni_gecikme;
                    gecici[0].gecikme_suresi++;
                    Add(gecici[0].oncelik_id,gecici[0].ucak_id,gecici[0].talep_edilen_inis_saati,gecici[0].gecikme_suresi);
                    return;
                }
                if(yeni_gecikme == 3 && inis_listesi[i].gecikme_suresi == 3)
                {
                    if(yeni_id<inis_listesi[i].ucak_id)
                    {
                        gecici[0]=inis_listesi[i];
                        inis_listesi[i].oncelik_id=yeni_oncelik;
                        inis_listesi[i].ucak_id=yeni_id;
                        inis_listesi[i].talep_edilen_inis_saati=yeni_talep;
                        inis_listesi[i].gecikme_suresi=yeni_gecikme;
                        gecici[0].gecikme_suresi++;
                        Add(gecici[0].oncelik_id,gecici[0].ucak_id,gecici[0].talep_edilen_inis_saati,gecici[0].gecikme_suresi);

                    }
                    else
                    {
                        yeni_gecikme++;
                        return;
                    }

                }
                else if(yeni_gecikme !=3 && inis_listesi[i].gecikme_suresi == 3)
                {
                    yeni_gecikme++;
                    Add(yeni_oncelik,yeni_id,yeni_talep,yeni_gecikme);
                }
                else
                {
                    yeni_gecikme++;
                    Add(yeni_oncelik,yeni_id,yeni_talep,yeni_gecikme);
                    return;
                }
            }
        }

    }

}
void KalkisListele()
{
    int i=0,j=0,k=0;
    for(i=0; i<eleman; i++)
    {
        kalkis_listesi[i]=inis_listesi[i];
        kalkis_listesi[i].inis_saati=kalkis_listesi[i].talep_edilen_inis_saati+kalkis_listesi[i].gecikme_suresi;
        kalkis_listesi[i].kalkis_saati=kalkis_listesi[i].inis_saati+1;
    }
    printf("\nKalkis Listesi \n********************\n");
    printf("UCAK ONCELIK   UCAK ID\tTALEP EDILEN INIS SAATI\t UCAK INIS SAATI   GECIKME SURESI   UCAK KALKIS SAATI\n");
    for(j=0; j<eleman; j++)
    {
        if(kalkis_listesi[j].kalkis_saati>24)
        {
            kalkis_listesi[j].kalkis_saati=kalkis_listesi[j].kalkis_saati-24;
            printf("     %d\t\t  %d\t            %d\t\t\t %d\t\t %d\t \t   %d\n",kalkis_listesi[j].oncelik_id,kalkis_listesi[j].ucak_id,kalkis_listesi[j].talep_edilen_inis_saati,kalkis_listesi[j].inis_saati,kalkis_listesi[j].gecikme_suresi,kalkis_listesi[j].kalkis_saati);
        }
        else
        {
            printf("     %d\t\t  %d\t            %d\t\t\t %d\t\t %d\t \t   %d\n",kalkis_listesi[j].oncelik_id,kalkis_listesi[j].ucak_id,kalkis_listesi[j].talep_edilen_inis_saati,kalkis_listesi[j].inis_saati,kalkis_listesi[j].gecikme_suresi,kalkis_listesi[j].kalkis_saati);
        }

    }
    FILE * fp;
    if((fp=fopen("output.txt","w"))== NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }
    for(k=0; k<eleman; k++)
    {
        fprintf(fp,"%d %d %d %d %d %d\n",kalkis_listesi[k].oncelik_id,kalkis_listesi[k].ucak_id,kalkis_listesi[k].talep_edilen_inis_saati,kalkis_listesi[k].inis_saati,kalkis_listesi[k].gecikme_suresi,kalkis_listesi[k].kalkis_saati);
    }
    fclose(fp);



}
void InisListele()
{
    printf("\nInis Listesi \n**********\n");
    printf("UCAK ONCELIK\t UCAK ID\t UCAK INIS SAATI\n");
    int i=0;
    for(i=0; i<eleman; i++)
    {
        printf("%d\t   \t %d\t \t    %d\n",inis_listesi[i].oncelik_id,inis_listesi[i].ucak_id,(inis_listesi[i].talep_edilen_inis_saati+inis_listesi[i].gecikme_suresi));
    }
}
int main()
{
    int i=0,j;

    FILE *dosya;
    if((dosya=fopen("input.txt","r"))== NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }
    while(!feof(dosya))
    {
        fscanf(dosya,"%d %d %d\n",&ucaklar[i].oncelik_id,&ucaklar[i].ucak_id,&ucaklar[i].talep_edilen_inis_saati);
        ucaklar[i].gecikme_suresi=0;
        i++;
    }
    fclose(dosya);
    //printf("%d %d %d",ucaklar[2].oncelik_id,ucaklar[2].ucak_id,ucaklar[2].talep_edilen_inis_saati);
    for(j=0; j<i; j++)
    {
        Add(ucaklar[j].oncelik_id,ucaklar[j].ucak_id,ucaklar[j].talep_edilen_inis_saati,ucaklar[j].gecikme_suresi);
    }
    InisListele();
    KalkisListele();


    return 0;

}
