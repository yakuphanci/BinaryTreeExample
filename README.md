![image](https://user-images.githubusercontent.com/61211736/122619117-600cf380-d098-11eb-9f92-56d33a51fa5f.png)

Geçen ödevde liste yapısında tuttuğumuz öğrencileri bu kez ağaç
yapısında tutarak bir takım ağaç yapısına özgü fonksiyonlarla listeleme,
silme, ekleme, aratma işlevlerini gerçekleştireceğiz. Farklı sıralamada
olan üç farklı öğrenci datalarını ağaç yapısına ekleyip dosyadaki
sıralamanın ağaç yapısının dengesini ne şekilde etkilediğini
inceleyeceğiz.


Ama önce ekran görüntülerine bir bakalım.


![image](https://user-images.githubusercontent.com/61211736/122619180-8337a300-d098-11eb-9c1a-5356dd730ffc.png)

![image](https://user-images.githubusercontent.com/61211736/122619196-8b8fde00-d098-11eb-9212-8442d6ea80ac.png)

![image](https://user-images.githubusercontent.com/61211736/122619225-a2363500-d098-11eb-8d62-1ae7933c1bfe.png)

Görüldüğü üzere normal sıralı listelemede
24’üncü sırada olan *GÖKHAN KAYA* ağaç yapısının avantajlarından
yararlanıldığı zaman sadece 7 işlem sonrasında bulunduğu yerden silinmiş
oluyor.

![image](https://user-images.githubusercontent.com/61211736/122619251-afebba80-d098-11eb-8e16-bede6ed92ea0.png)


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

![image](https://user-images.githubusercontent.com/61211736/122619265-b5e19b80-d098-11eb-953a-1e862b42851c.png)

![image](https://user-images.githubusercontent.com/61211736/122619267-b9752280-d098-11eb-98f7-d24b47f330dc.png)

![image](https://user-images.githubusercontent.com/61211736/122619273-bda14000-d098-11eb-9b2d-36aa4b1531eb.png)

![image](https://user-images.githubusercontent.com/61211736/122619282-c134c700-d098-11eb-8886-7c5a77f7bb25.png)

![image](https://user-images.githubusercontent.com/61211736/122619292-c85bd500-d098-11eb-9338-96265e8b6ea6.png)

![image](https://user-images.githubusercontent.com/61211736/122619296-cbef5c00-d098-11eb-887a-5f4ec3caf1fa.png)

Görüldüğü üzere sıralı datalarda ağacın dengesi bozulup bağlantılı liste
yapısına dönüşmüştür.

Sırasız datada ise ağaç daha dengeli dağılmıştır.

Tüm merak edilenler için kaynak kod ve açıklamaları .ZİP dosyasının
içerisinde mevcut.
