
# Duomenų apdorojimas  
![version][version-badge]  
## Programos paskirtis  
Programa simuliuoja studentų pažymių sistemą.   
  
Vartotojas gali pasirinkti, ar studentus su pažymiais nuskaitys iš failo, ar ranka.  
  
### Įrašymas ranka  
Pasirinkus įrašymą ranka, prašoma suvesti studento duomenis (vardą, pavardę, pažymius, egzamino pažymį ir t. t.). Viską užpildžius, į failą gaunama lentelė su studentų rezultatais.  
  
### Pažymių generavimas  
Galima pasirinkti pažymius sugeneruoti. Tokiu atveju prašoma įvesti, kiek pažymių generuoti.  
  
### Įrašymas iš failo  
Failas, į kurį vartotojas gali surašyti studentus bei jų pažymius, pavadinimu – "kursiokai.txt".  
Iš jo nuskaitomi studentai.  
  
### Rezultatai  
Rezultatai skaičiuojami pagal formulę:   
  
```shell   
galutinis = 0.4 * dauginamasis + 0.6 * egzaminas  
```  
"dauginamasis" gali būti pažymių vidurkis arba mediana. Atspausdinami abudu variantai.  
  
Taip pat yra galimybė pasirinkti, jog pažymiai būtų sugeneruoti atsitiktinai.  
  
### Greičio matavimas  
Taip pat galima pasirinkti sugeneruoti failus:  
- kursiokai10.txt – turintis 10 studentų  
  
- kursiokai100.txt – turintis 100 studentų  
  
- kursiokai1000.txt – turintis 1000 studentų  
  
- kursiokai10000.txt – turintis 10000 studentų  
  
- kursiokai100000.txt – turintis 100000 studentų  
  
  Su šiais tekstiniais failais atliekama greičio analizė, naudojant [std::chrono](https://en.cppreference.com/w/cpp/chrono) biblioteką. Programai baigus darbą, į konsolę atspausdinama lentelė su laikais:  
  
```shell  
Ar norite atlikti programos veikimo greičio (spartos) analizę? (1 - taip, 0 - ne) 1  

Darbas su "kursiokai10.txt" užtruko: 0.015957 s
Darbas su "kursiokai100.txt" užtruko: 0.016956 s
Darbas su "kursiokai1000.txt" užtruko: 0.059678 s
Darbas su "kursiokai10000.txt" užtruko: 0.320595 s
Darbas su "kursiokai100000.txt" užtruko: 3.16505 s
```  
  
### Konteinerių testavimas  
  
Testuojami šie konteineriai  
  
- std::vector  
- std::list  
- std::deque  
  
#### Rezultatas  
  
```shell  
...  
Ar norite atlikti konteinerių testavimą? (1 - taip, 0 - ne)  
1  
  
Pradedamas darbas naudojant vector konteinerį...
Nuskaitymas iš failo truko: 0.000997 s
Studentų filtravimas (skirstymas) truko: 0.000997 s
Įrašymas į failą truko: 0.006982 s
Darbas su "kursiokai10.txt" užtruko: 0.009972 s

Nuskaitymas iš failo truko: 0.001994 s
Studentų filtravimas (skirstymas) truko: 0 s
Įrašymas į failą truko: 0.007985 s
Darbas su "kursiokai100.txt" užtruko: 0.010971 s

Nuskaitymas iš failo truko: 0.01496 s
Studentų filtravimas (skirstymas) truko: 0.003988 s
Įrašymas į failą truko: 0.020971 s
Darbas su "kursiokai1000.txt" užtruko: 0.042885 s

Nuskaitymas iš failo truko: 0.130704 s
Studentų filtravimas (skirstymas) truko: 0.058843 s
Įrašymas į failą truko: 0.11871 s
Darbas su "kursiokai10000.txt" užtruko: 0.311194 s

Nuskaitymas iš failo truko: 1.28657 s
Studentų filtravimas (skirstymas) truko: 0.698146 s
Įrašymas į failą truko: 1.10906 s
Darbas su "kursiokai100000.txt" užtruko: 3.1057 s
Darbas su STD::VECTOR konteineriu užtruko: 3.48375 s

Pradedamas darbas naudojant deque konteinerį...
Nuskaitymas iš failo truko: 0 s
Studentų filtravimas (skirstymas) truko: 0 s
Įrašymas į failą truko: 0.002998 s
Darbas su "kursiokai10.txt" užtruko: 0.005105 s

Nuskaitymas iš failo truko: 0.001024 s
Studentų filtravimas (skirstymas) truko: 0 s
Įrašymas į failą truko: 0.005987 s
Darbas su "kursiokai100.txt" užtruko: 0.009667 s

Nuskaitymas iš failo truko: 0.011997 s
Studentų filtravimas (skirstymas) truko: 0.004963 s
Įrašymas į failą truko: 0.020948 s
Darbas su "kursiokai1000.txt" užtruko: 0.040909 s

Nuskaitymas iš failo truko: 0.125647 s
Studentų filtravimas (skirstymas) truko: 0.06583 s
Įrašymas į failą truko: 0.115613 s
Darbas su "kursiokai10000.txt" užtruko: 0.311072 s

Nuskaitymas iš failo truko: 1.24068 s
Studentų filtravimas (skirstymas) truko: 0.808832 s
Įrašymas į failą truko: 1.10605 s
Darbas su "kursiokai100000.txt" užtruko: 3.17158 s
Darbas su STD::DEQUE konteineriu užtruko: 3.54129 s

Pradedamas darbas naudojant list konteinerį...
Nuskaitymas iš failo truko: 0.000998 s
Studentų filtravimas (skirstymas) truko: 0 s
Įrašymas į failą truko: 0.004084 s
Darbas su "kursiokai10.txt" užtruko: 0.005082 s

Nuskaitymas iš failo truko: 0.001987 s
Studentų filtravimas (skirstymas) truko: 0 s
Įrašymas į failą truko: 0.005984 s
Darbas su "kursiokai100.txt" užtruko: 0.007971 s

Nuskaitymas iš failo truko: 0.012965 s
Studentų filtravimas (skirstymas) truko: 0.000994 s
Įrašymas į failą truko: 0.018977 s
Darbas su "kursiokai1000.txt" užtruko: 0.035907 s

Nuskaitymas iš failo truko: 0.127655 s
Studentų filtravimas (skirstymas) truko: 0.010305 s
Įrašymas į failą truko: 0.120679 s
Darbas su "kursiokai10000.txt" užtruko: 0.264203 s

Nuskaitymas iš failo truko: 1.26362 s
Studentų filtravimas (skirstymas) truko: 0.103772 s
Įrašymas į failą truko: 1.10804 s
Darbas su "kursiokai100000.txt" užtruko: 2.49341 s
Darbas su STD::LIST konteineriu užtruko: 2.80754 s
```  
  
### Atspausdintas pavyzdys  
```shell  
Vardas       Pavardė      Galutinis (Vid.)       Galutinis (Med.)         
------------------------------------------------------------------------  
Aleksandras  Pavardė13    3.47                   3.80  
Austėja      Pavardė16    5.20                   4.80  
Emilija      Pavardė6     5.73                   5.60  
Emilis       Pavardė9     2.20                   2.00  
Gabija       Pavardė15    5.80                   5.80  
Giedrius     Pavardė17    7.93                   8.40  
Giedrė       Pavardė18    3.40                   3.20     
```  
  
## :exclamation: PAPILDOMA UŽDUOTIS KITAME BRANCH'E :exclamation:
  
## Programos paleidimas  
Paleisti programą galima keliais būdais.  
- `git clone git@github.com:zygisau/Duomenu-apdorojimas.git` <-- jei naudojate SSH key  
- `git clone https://github.com/zygisau/Duomenu-apdorojimas.git` <-- kitu atveju  
- `cd Duomenu-apdorojimas`  
- Jei naudojate CMAKE, naudoti reikia CMakeLists.txt failą.
Yra du *executables*:
  - Duomenu_apdorojimas <-- pasirinkite, jei norite paleisti programą, kuri naudoja konteinerius
  - Duomenu_apdorojimas_masyvai <-- pasirinkite, jei norite paleisti programą, kuri naudoja dinaminį masyvą
  
  
## Versijų istorija (changelog)  
  
 ### [v0.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.1) - (2019-02-17)  
  **Koreguota**  
  
 - Sutvarkytas README.md failas.  
 - Papildytas .gitignore failas.  
  
   **Pridėta**  
  
 - Sukurtos dvi programos. Viena veikia, remiantis C masyvais, kita - vector.  
 - Sukurtas makefile.  
  
 ### [v0.2](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.2) - (2019-02-17)  
  
  **Koreguota**  
  
 - README.md faile pridėtas versijos aprašymas.  
  
   **Pridėta**  
  
 - Pakeista source_vektoriai.cpp programa taip, jog galima būtų duomenis kelti iš failo bei pakeistas vaizdavimo būdas.  
 - Sukurtas duomenų apie studentus failas "kursiokai.txt".  
  
### [v0.3](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.3) - (2019-02-23)  
  
  **Koreguota**  
  
 - Perkurta programos struktūra.  
 - Pakoreguotas "READ_ME.md" failas.  
  
   **Pridėta**  
  
 - Pridėti headers failai.  
  
### [v0.4](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.4) - (2019-03-03)  
  
  **Koreguota**  
  
 - Pridėta galimybė atlikti spartos analizę bei generuoti tekstinius failus.  
 - Pakoreguotas "READ_ME.md" failas.  
  
   **Pridėta**  
  
 - Pridėtas CMakeLists.txt failas.  
  
### [v0.4.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.4.1) - (2019-03-04)  
  
  **Koreguota**  
  
 - Pridėta biblioteka "numeric", naudojama funkcijoje. Programa veiks naudojant visus kompiliatorius.  
  
### [v0.5](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.5) - (2019-03-11)  
  
  **Koreguota**  
  
- Pakoreguotas "READ_ME.md" failas.  
  
   **Pridėta**  
  
- Pridėtas konteinerių testavimas.  
  
### [v0.5.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.5.1) - (2019-03-13)  
  
  **Koreguota**  
- Pridėta apsauga, jei duomenų faile būtų pateiktas ne skaičius arba per mažai pažymių.  
  
### [v1.0](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v1.0) - (2019-03-17)  
  
  **Koreguota**  
  
- Pakoreguotas "READ_ME.md" failas.  
- Pakeistas studentų filtravimas, kai naudojamas std::vector konteineris. Dabar veikia greičiau.
- Pridėta galimybė paleisti iš CMake failo abidvi programos realizacijas
- Ištrintas makefile (CMake universalesnis).
  
### [v1.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v1.1) - (2019-03-23)  
  
  **Koreguota**  
- Sutvarkytas pažymių generavimas ir lygiavimas.

[version-badge]: https://img.shields.io/badge/version-1.1-yellow.svg
