# Akıllı Ev Projesi (Arduino)
<img src="https://raw.githubusercontent.com/BedirZanaDemir/AKILLI_EV_ARDUINO/master/resimler/4.jpg"></img>
![visitors](https://visitor-badge.laobi.icu/badge?page_id=bedirdemir.akilli_ev_arduino)

**Arduino İle Bluetooth Kontrollü Akıllı Ev Yapımı**

Günümüzde adını sıkça duymaya başladığımız uzaktan kontrollü akıllı evler ve cihazlar hayatımıza hızla girmiş durumda. Şüphesiz ki ilerleyen süreçte daha gelişmiş versiyonlarıyla karşılaşmaya devam edeceğiz.

Bu projemde akıllı evlerin ve uzaktan kontrol edilebilen akıllı cihazların çalışma mantığını basitçe anlatmak amacıyla Arduino kart ile bu devreyi ve yazılımı geliştirdim. Yapabildikleri şu şekilde:

- Android uygulama aracılığıyla (bkz:appinventor) Bluetooth bağlantısını kurup veri iletişimini sağlar ve gelen veriler doğrultusunda işlem yapar. (Android uygulama ve uygulamanın geliştirme dosyası proje dosyalarında mevcuttur)
- Sıcaklığı hesaplayıp LCD ekrana ve android uygulamasına yazdırır.
- Servo motor kullanarak evin kapısını açıp/kapatır.
- İç lambaları açıp/kapatır.
- Evin içerisindeki fanı (klima) açıp/kapatır.
- LDR aracılığıyla gece veya gündüz olduğunu algılar. Gece ise evin dışındaki lambayı otomatik açar, gündüz ise kapatır.
- Her işlem yaptığında buzzer kullanarak bip sesi çıkarır.
- Yaptığı işlemleri LCD ekrana yazarak kullanıcıyı bilgilendirir.

## Proje Dosyalarını İndir
<a href="https://github.com/BedirDemir/AKILLI_EV_ARDUINO/archive/master.zip">Akıllı-Ev-Projesi-Arduino-Download</a>

**Android uygulamasını düzenlemek için apk proje geliştirme dosyasını (android/proje.aia uzantılı dosya) AppInventor'a yükleyerek bunu kolayca yapabilirsiniz.**
Bunun için aşağıdaki talimatları izleyin:

1) http://ai2.appinventor.mit.edu/ adresine gidin. ***NOT: Eğer appinventor'un ne olduğunu ve nasıl kullanıldığını bilmiyorsanız şu videoyu izleyebilir > https://www.youtube.com/watch?v=SgH3H6jMbak veya şu yazıyı okuyabilirsiniz > https://maker.robotistan.com/app-inventor-dersleri-1-tanitim-ilk-uygulama/***

2) Giriş yaptıktan sonra ana ekranda sol üstte yer alan "Projects > Import project (.aia) from my computer" a tıklayın.

<img src="https://raw.githubusercontent.com/bedirdemir/Akilli_Ev_Arduino/master/resimler/t1.jpg"></img>

3) Daha sonra "Dosya Seç" butonuna tıklayarak Android klasörünün içerisinde yer alan **"proje.aia"** dosyasını seçin. Ardından "OK" butonuna basarak dosyayı import edin.

<img src="https://raw.githubusercontent.com/bedirdemir/Akilli_Ev_Arduino/master/resimler/t2.jpg"></img>

İşlem bu kadar. Artık projede kullanılan Android uygulamasını isteğinize göre düzenleyebilirsiniz. Düzenlediğiniz uygulamayı bilgisayara apk dosyası olarak indirmek için üstteki "Build > App ( save .apk to my computer )" a tıklayın.

<img src="https://raw.githubusercontent.com/bedirdemir/Akilli_Ev_Arduino/master/resimler/t6.jpg"></img>

**Bluetooth bağlantısını kurmak için iki farklı yöntem vardır.**

**1.YOL(Kolay olan):** İlk önce telefonunuz ile projenizdeki bluetooth modülünü eşleştirin. Eşleşme kodu isterse genellikle 0000 veya 1234'dür. Sonra "proje.apk" uygulamsını telefonunuza kurun ve uygulamada "Eve Bağlan" butonuna basın. Karşınıza telefonunuzla daha önce eşleşmiş cihazların listesi çıkacak, burada az önce eşleştirdiğiniz modülü seçin. Genellikle HC-05 veya HC-06 olur.

**2.YOL:** Bu yöntemi 1.yol ile bağlantı kuramadıysanız deneyin. 

- Appinventora **"android/proje_v2.aia"** dosyasını yükleyin (üstte anlattığım şekide).

- Sağdaki "Blocks" butonuna basın.

<img src="https://raw.githubusercontent.com/bedirdemir/Akilli_Ev_Arduino/master/resimler/t3.jpg"></img>

- Soldan "Screen2" ye geçin.

<img src="https://raw.githubusercontent.com/bedirdemir/Akilli_Ev_Arduino/master/resimler/t4.jpg"></img>

- Her bluetooth modülünün mac adresi farklıdır. Siz kendi elinizdeki modülün mac adresini öğrenip altta gösterdiğim yerdeki adres ile değiştirin. Format şöyle olmalıdır ([MACADRESİ][boşluk][BLUETOOTHADI]). Bluetooth adı genelde HC-05 veya HC-06 olur. Modüllerin mac adresleri ve adları genelde üzerlerinde yazar. Eğer yazmıyorsa şunun gibi uygulamalarla öğrenebilirsiniz. > https://play.google.com/store/apps/details?id=codetivelab.macfinder.bluetooth.bluetoothmacfinder

<img src="https://raw.githubusercontent.com/bedirdemir/Akilli_Ev_Arduino/master/resimler/t5.jpg"></img>

Üstte de belirttiğim gibi, 2.yolu 1.yol işe yaramazsa uygulayın.

Kartı beslerken 9V 2A adaptör kullanmanızı öneririm.

Soru, görüş ve önerileriniz için mail gönderebilirsiniz: bedirzanademir+destek@gmail.com
## Proje Dosyalarını İndir
<a href="https://github.com/BedirDemir/AKILLI_EV_ARDUINO/archive/master.zip">Akıllı-Ev-Projesi-Arduino-Download</a>
## Devre Şeması
<img src="https://raw.githubusercontent.com/BedirDemir/AKILLI_EV_ARDUINO/master/devre/akilli_ev_devre_bb.png"></img>
## Görseller
<img src="https://raw.githubusercontent.com/BedirDemir/AKILLI_EV_ARDUINO/master/resimler/5.JPG"></img>

<img src="https://raw.githubusercontent.com/BedirDemir/AKILLI_EV_ARDUINO/master/resimler/1.jpg"></img>

<img src="https://raw.githubusercontent.com/BedirDemir/AKILLI_EV_ARDUINO/master/resimler/2.jpg"></img>

<img src="https://raw.githubusercontent.com/BedirDemir/AKILLI_EV_ARDUINO/master/resimler/3.jpg"></img>

<img src="https://raw.githubusercontent.com/BedirDemir/AKILLI_EV_ARDUINO/master/resimler/_20180418_194428.JPG"></img>
