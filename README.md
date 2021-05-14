# HarkkaRepo
 Käyttöjärjestelmät ja systeemiohjelmointi projektit

## Projekti1:
* Ohjelmalle voi antaa kaksi komentoriviparametriä, joista ensimmäinen on input-tiedosto ja toinen on output-tiedosto. Ohjelma toimii myös vähemmällä määrällä parametrejä (yhdellä tulostaen ruudulle ja 0 pyytäen käyttäjältä syötteen, joka tulostetaan ruudulle).

 ## Projekti2:
### my-cat:
* Ohjelma on kopio UNIXin cat-komennosta, joka avaa ja tulostaa tiedoston käyttäjälle. Ohjelma käännetään komennolla gcc -o my-cat my-cat.c -Wall -Werror, mikä luo binääritiedoston. Tämän tiedoston voi ajaa komennolla ./my-cat main.c.

### my-grep:
* Ohjelma on kopio UNIXin grep-komennosta, jolla voidaan hakea sanoja tiettyä avainta käyttäen. Tämän jälkeen löydetyt sanat tulostetaan ruudulle. My-grep käyttää aina vähintään 1 komentoriviparametriä (ylärajaa ei ole). Ensimmäinen annettu parametri on avain jota haetaan sanoista ja kaikki seuraavat parametrit ovat läpikäytäviä tiedostoja. Jos parametrejä annetaan vain 1, on tämä silloin avain jota käytetään käyttäjän antamaan inputtiin.

### my-zip:
* Ohjelma, joka pakkaa tekstitiedostossa olevat merkit binäärimuodossa toiseen tiedostoon. Komentoriviparametrinä annetaan 1 tai useampi tiedosto, jotka täytyy pakata ja perään laitetaan putkitus, jolla määritellään ulostulotiedosto (eli zip-tiedosto). Ajetaan tyylillä ./my-zip file.txt > file.z

### my-unzip:
* Ohjelma, joka toimii parina ylempänä mainitulle my-zip ohjelmalle. Toimii my-zipin peilikuvana, eli purkaa pakatusta tiedostosta binääritietoa ja tulostaa sen käyttäjälle ruudulle näkyviin.

## Projekti4:
* Ohjelma myprogram.c tulostaa sen hetkisten tehtyjen järjestelmäkutsujen määrän konsoliin.
