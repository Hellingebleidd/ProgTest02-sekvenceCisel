Úkolem je vytvořit program, který bude zpracovávat binární čísla v zadaném intervalu hodnot.

Na vstupu programu jsou dvě celá čísla. Tato čísla definují uzavřený interval hodnot < lo ; hi >. Představme si celá čísla z tohoto intervalu postupně zapsaná ve dvojkové soustavě vedle sebe. Takto zapsaná čísla vytvoří sekvenci nul a jedniček. Podle zadání na vstupu má program má za úkol jedno z následujících:

- vypočítat celkovou délku této sekvence (počet cifer),
- určit počet nul v této sekvenci,
- určit nejdelší kontinuální posloupnost nul v této sekvenci.

Například pro interval <10;20> by vypadala sekvence takto:

  1010 1011 1100 1101 1110 1111 10000 10001 10010 10011 10100
  
Tedy taková sekvence má celkem 49 cifer, z toho 22 nul a nejdelší kontinuální sekvence nul má délku 4.
  
Vstupem programu jsou dvě nezáporná celá desítková čísla (tj. přípustná jsou kladná celá čísla a nula). Čísla jsou zadaná v lomených závorkách a oddělená středníkem. První zadané číslo je dolní mezí intervalu, druhé je horní mezí. Dolní mez musí být menší nebo rovná horní mezi. Za zadáním intervalu je jeden znak určující požadovaný výpočet. Znak může být:

- l pro výpočet celkové délky sekvence (počtu cifer),
- z pro výpočet počtu nul v sekvenci,
- s pro výpočet nejdelší kontinuální sekvence nul.

Výstupem programu je vypočtená informace podle zadaného vstupu. Přesný formát výpisu je vidět v ukázkovém běhu programu.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:
- nečíselné zadání mezí intervalu (neplatné číslo),
- mez intervalu je záporné číslo,
- dolní mez intervalu je větší než horní mez,
- požadovaná operace není žádná z l, z, s,
- chybí nebo přebývá nějaký oddělovač (lomená závorka, středník).

###Ukázka práce programu:

Zadejte interval:
<0;11> l
Cifer: 34

Zadejte interval:
<0;11> z
Nul: 14

Zadejte interval:
<0;11> s
Sekvence: 3

Zadejte interval:
<10;20> l
Cifer: 49

Zadejte interval:
 < 10 ; 20 > z
Nul: 22

Zadejte interval:
<10;20>s
Sekvence: 4

Zadejte interval:
<1492;2018> l
Cifer: 5797

Zadejte interval:
<1123;2000> z
Nul: 4319

Zadejte interval:
<1683;1999> s
Sekvence: 8

Zadejte interval:
<4;4> l
Cifer: 3

Zadejte interval:
<0;3> z
Nul: 2

Zadejte interval:
<255;255> s
Sekvence: 0

Zadejte interval:
<47;16> l
Nespravny vstup.

Zadejte interval:
<23;asdf> z
Nespravny vstup.

Poznámky:
Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
Úlohu lze vyřešit bez použití funkcí. Pokud ale správně použijete funkce, bude program přehlednější a bude se snáze ladit.
Pro zvládnutí úlohy v povinných a nepovinných testech postačuje naivní algoritmus. Algoritmus prochází zadaný interval hodnot a analyzuje jednotlivá čísla. Pro implementaci tohoto algoritmu potřebujete pouze podmínky, cykly a několik proměnných typu celé číslo. Nejsou potřeba řetězce ani pole. Určitě není vhodné (a není ani potřeba) v paměti programu vytvářet řetězec s celou vygenerovanou binární sekvencí. Naopak, vytvoření této sekvence program pouze zkomplikuje a velmi zpomalí jeho běh.
Test rychlosti #1 počítá pouze celkovou délku sekvence, ale pro velmi dlouhé intervaly. Naivní algoritmus zde nestačí, implementace překročí maximální dobu běhu. Pro zvládnutí tohoto testu je potřeba efektivnější algoritmus výpočtu celkové délky sekvence. Takový algoritmus nebude procházet všechna čísla ze zadaného intervalu, ale dokáže určit výsledek rovnou z mezí zadaného intervalu. Ostatní algoritmy (počet nul, nejdelší kontinuální sekvence nul) v tomto testu postačují naivní. Tento test je bonusový. Pokud Vaše implementace zvládnete tento test, bude odměněna body navíc (nad nominálních 100%).
Test rychlosti #2 počítá všechna zadání (celková délka sekvence, počet nul i kontinuální sekvence nul) pro velmi dlouhé intervaly. Naivní algoritmus zde nestačí, implementace překročí maximální dobu běhu. Efektivní algoritmus je potřeba pro všechny tři zadávané problémy. Při implementaci se pak hodí několik malých polí (velikosti cca 100 prvků) pro uložení hodnot mezivýsledků. Test je opět bonusový, jeho zvládnutí přinese body navíc nad nominálních 100%.
Číselné vstupní hodnoty jsou zadávané tak, aby se vešly do rozsahu datového typu int. Pro zvládnutí povinných a nepovinných testů postačuje datový typ int i pro ukládání výsledků. V bonusových testech jsou zadávané velké intervaly hodnot, tam již datový typ int nestačí. Pokud chcete řešit úlohu i s bonusovými testy, použijte pro reprezentaci výsledků datový typ long long int.
Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (materiály -> cvičebnice -> video tutoriály), jak testovací data použít a jak testování zautomatizovat.
Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti (ale tato úloha by ani s jedním omezením neměla mít problém). Testovací prostředí dále zakazuje používat některé "nebezpečné funkce" -- funkce pro spouštění programu, pro práci se sítí, ... Pokud jsou tyto funkce použité, program se nespustí. Možná ve svém programu používáte volání:

  int main ( int argc, char * argv [] )
  {
   
    ...
       
    system ( "pause" ); /* aby se nezavrelo okno programu */
    return 0;
  }
  
Toto nebude v testovacím prostředí fungovat - je zakázáno spouštění jiného programu. (I pokud by se program spustil, byl by odmítnut. Nebyl by totiž nikdo, kdo by pauzu "odmáčkl", program by čekal věčně a překročil by tak maximální dobu běhu.) Pokud tedy chcete zachovat pauzu pro testování na Vašem počítači a zároveň chcete mít jistotu, že program poběží správně, použijte následující trik:

  int main ( int argc, char * argv [] )
  {
   
    ...
  
  #ifndef __PROGTEST__
    system ( "pause" ); /* toto progtest "nevidi" */
  #endif /* __PROGTEST__ */
    return 0;
  } 
  
Slovní popis struktury platných vstupních dat není zcela exaktní. Proto připojujeme i formální popis vstupního jazyka v EBNF:
    input      ::= { whiteSpace } '<' { whiteSpace } integer { whiteSpace } ';' 
                   { whiteSpace } integer { whiteSpace } '>' { whiteSpace } operation { whiteSpace }
    whiteSpace ::= ' ' | '\t' | '\n' | '\r'
    operation  ::= 'l' | 'z' | 's'
    integer    ::= digit { digit }
    digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'