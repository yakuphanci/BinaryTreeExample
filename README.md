![](media/image1.jpeg){width="1.8777777777777778in"
height="1.8777777777777778in"}

Geçen ödevde liste yapısında tuttuğumuz öğrencileri bu kez ağaç
yapısında tutarak bir takım ağaç yapısına özgü fonksiyonlarla listeleme,
silme, ekleme, aratma işlevlerini gerçekleştireceğiz. Farklı sıralamada
olan üç farklı öğrenci datalarını ağaç yapısına ekleyip dosyadaki
sıralamanın ağaç yapısının dengesini ne şekilde etkilediğini
inceleyeceğiz.

![](media/image2.png){width="5.222222222222222in"
height="2.2319444444444443in"} Ama önce ekran görüntülerine bir bakalım.

![](media/image3.png){width="5.2875in" height="4.2243055555555555in"}

![](media/image4.png){width="5.3375in" height="2.6131944444444444in"}

![](media/image5.png){width="5.309027777777778in"
height="2.5444444444444443in"} Görüldüğü üzere normal sıralı listelemede
24’üncü sırada olan *GÖKHAN KAYA* ağaç yapısının avantajlarından
yararlanıldığı zaman sadece 7 işlem sonrasında bulunduğu yerden silinmiş
oluyor.

Ve yine ağaç yapısının verdiği gereksiz dallara bakmama avantajı
sayesinde listede olmayan bir veriyi silmeye kalkıştığımızda tüm listeyi
adım adım *-68 adım-* gezmek yerine sadece bulunma ihtimalinin bulunduğu
yere kadar bakar eğer oralarda yoksa listede olmadığı kanısına varılır
ve sadece 10 adımda listede olmadığı anlaşılır.

Hazır konu açılmışken ağaç yapısının arama işlemlerinde bize sağladığı
hızdan da bahsedelim. Projede ikili ağaç yapısı için arama işlemlerinde
kullandığımız iki tür arama fonksiyonu var. Bunlar *ilk derinlik arama
(DFS)* ve *ilk genişlik arama (BFS)*. DFS önce derinlemesine inerek köke
uzak olma ihtimali olan verileri ararken hız kazandırır, BFS ise önce
genişlemesine yani kökün tüm komşularına öncelik vererek arama işlemini
yürütür önce komşuların tümüne bakmasından da anlayacağınız üzere BFS
köke yakın olması muhtemel verileri aratırken bize hız kazandırır.

Üç adet verimiz olduğunu söylemiştik data1.txt dosyasında veriler sıralı
bir şekilde tutulur, data2.txt dosyasında ise tam tersi yani ters sıralı
olarak tutulurlar. Data3.txt de ise veriler tamamen rastgele tutuluyor.

Verilerin sıralı tutulması ağaç yapısı için iyi değil. Şimdi
diyeceksiniz ki neden iyi değil? Sıralı tutulan veriler ağaç yapısının
dengesini bozmaktadır. Sıralı verileri ağaç yapısına eklerken birtakım
önlemler alınmalıdır. Medyan bulma ve döndürme bunlardan bazıları.
Verilerin sıralanışındaki rastgelelik ağaç yapısının daha dengeli ve
daha çok ağaç görünümünü andırmasını sağlar.

![](media/image6.png){width="5.498113517060368in"
height="2.636936789151356in"}

![](media/image7.png){width="5.4959208223972in"
height="2.6698108048993876in"}

![](media/image8.png){width="5.847916666666666in"
height="2.782638888888889in"}

![](media/image9.png){width="5.782638888888889in"
height="2.782638888888889in"}

![](media/image10.png){width="5.81875in" height="2.7625in"}

![](media/image11.png){width="5.668055555555555in"
height="2.6881944444444446in"}

Görüldüğü üzere sıralı datalarda ağacın dengesi bozulup bağlantılı liste
yapısına dönüşmüştür.

Sırasız datada ise ağaç daha dengeli dağılmıştır.

Tüm merak edilenler için kaynak kod ve açıklamaları .ZİP dosyasının
içerisinde mevcut.
