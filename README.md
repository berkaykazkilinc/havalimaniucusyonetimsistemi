# Havalimanı Uçuş Yönetim Sistemi

Bu projede öncelikli kuyruk (priority queue) kullanarak bir havalimanı uçuş yönetimsistemi oluşturulmuştur.

1 iniş 1 kalkış olmak üzere 2 pisti bulunan İstanbul Havalimanı’nda gün içerisinde (1-24 saat
dilimi boyunca) yapılan uçuşların yönetimi için bir sistem geliştirilmiştir. Havalimanında aynı anda
sadece 1 uçak kalkış yapabiliyorken sadece 1 uçak iniş yapabilmektedir. Uçakların her biri iniş ve
kalkışta farklı önceliklere sahiptir ve 1 günde maksimum 24 uçak iniş için izin isteyebilmektedir.
Havalimanındaki uçakların öncelik sırası, iniş saati, gecikme süresi ve kalkış saati bilgileri kullanılarak;
iniş pistini ve kalkış pistini kullanım sırasının belirlenmesi hedeflenmektedir.
- Havalimanına iniş yapacak uçaklar öncelikle kuleden iniş yapabilmek için izin talep etmelidir.
- İniş izni talep eden her bir uçak için havalimanında yeterli kapasite olup olmadığı kontrol
edilmelidir (inis_pisti_kullanim_sirasi öncelikli kuyruğunda yeni uçak eklemek için boş alan
var mı?).
- Kuleden iniş izni talep eden uçaklar için öncelikle, iniş talep edilen saatte pistin dolu mu boş
mu olduğu kontrol edilmelidir. Pist boş ise iniş yapılmak istenen saate izin verilmeli ve
inis_pisti_kullanim_sirasi’nda uygun yere eklenmelidir. Aksi halde uçakların iniş sıralaması
önceliğe göre belirlenmelidir.
- İniş izni talep eden her uçak için “İniş izin talebiniz onaylanmıştır” veya “… nedeniyle iniş izni
verilememektedir.” şeklinde ekranda yazdırılmalıdır.
- Uçakların iniş ve kalkış saatleri önceliğe göre belirlenecektir. Uçakların öncelik (oncelik_id)
sıralaması şu şekildedir (yüksekten düşüğe):
1. Ambulans uçağı
2. Savaş uçağı
3. Yolcu uçağı
4. Kargo uçağı
- Havalimanına iniş talep eden uçakların önceliği (oncelik_id), uçak numarası (ucak_id) ve talep
ettiği iniş saati (talep_edilen_inis_saati) input.txt dosyasından okunacaktır.
- Tüm uçakların iniş ve kalkış süreleri eşittir ve hesaplamalara dâhil edilmeyecektir.
- Havalimanına iniş yapan her uçağın, kalkış için bekleme süresi 1 saattir. Uçakların kalkış
saatine, ötelenmeden dolayı oluşan gecikme süreleri dâhil edilmelidir. Kalkış saati bu bilgiler
göz önünde bulundurularak hesaplanmalıdır.
- Aynı önceliğe sahip iki uçak, aynı saatte kalkış yapacaksa öncelik ilk iniş yapan uçağa
verilmelidir.
- Önceliği yüksek olan uçaklar nedeniyle önceliği düşük olan herhangi bir uçağın uçuşu,
maksimum 3 kez ertelenebilir. Eğer 3’ten fazla ertelenme durumu söz konusuysa, öncelik
gözetilmeksizin beklemede olan uçağın kalkışı gerçekleştirilmelidir.
- Kuleden bir günde maksimum 24 uçak iniş için izin talep edebilir. Eğer bu kapasite dolmuşsa;
- İniş için onay alan uçaklardan en az birinin önceliği (X uçağı olsun), iniş izni onayı
bekleyen uçağın (Y uçağı olsun) önceliğinden düşükse; yüksek öncelikli yeni uçağa (Y)
iniş onayı verilir. Daha önce onay almış ve önceliği düşük olan uçak (X) başka bir
havalimanına yönlendirilmelidir.
- İniş izni daha önceden onaylanan uçağın (X) izni iptal edilmişse; “Acil iniş yapması
gereken …(Y) uçağı nedeniyle iniş izniniz iptal edilmiştir, iniş için Sabiha Gökçen
Havalimanı’na yönlendiriliyorsunuz.” şeklinde ekranda yazdırılmalıdır.
- İniş izni talep eden uçakların her biri satır satır input.txt’den okunmalıdır. Okunan her bir satır
ekranda gösterilmelidir.
- Her yeni input satırı okunduğunda, kalkış yapacak olan uçakların bulunduğu output.txt dosyası güncellenmeli ve güncel kalkis_pisti_kullanim_sirasi öncelikli kuyruğu ekranda gösterilmelidir.
