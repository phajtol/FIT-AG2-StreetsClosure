# FIT-AG2-StreetsClosure

This is a project created as a homework for subject Algorithms and Graphs 2 (BI-AG2 - Algoritmy a grafy 2) at FIT CTU.

Full assignment in Czech language is below.

##### Summary of the assignment:
Based on input graph (that represents streets in a city), calculate:
- number of edges that connect different components,
- number of sources in a condensed input graph and
- number of sinks in a condensed input graph.

---

My solution is in file `solution.cpp`, text files contain test data for basic scenarios with reference solutions.

My solution has received maximum points (including big data test).

# Assignment

Jen chvíli poté co po zimě vykoukly první sluneční paprsky, započalo v Praze období mnohočetných oprav vozovky. Letošní mrazy sice nebyly tuhé, ale vzhledem k tomu, jak se hustota provozu projevuje na stavu povrchu vozovky, je i tak potřeba opravit spoustu silnic. Opravy se bohužel nepovedlo dostatečně zkoordinovat, a všechny práce započaly prakticky ve stejný čas. To vedlo k totálnímu kolapsu dopravy po celém městě. Z toho důvodu se magistrát rozhodl přijmout krizové opatření, které pomůže tuto situaci vyřešit.

Smyslem opatření je, aby byl jasně definovaný tok dopravy a nestávalo se, že dojde k ucpání zúžené ulice protisměrnými proudy vozidel. Proto je základním bodem tohoto opatření to, že se všechny ulice staly jednosměrnými ve směru určeném magistrátem. Tímto magistrát opravdu dopravu odlehčil, nicméně zjednosměrnění ulic se sebou nese i negativní důsledky. Jedním takovým důsledkem je to, že může existovat jednosměrná ulice z místa `x` do místa `y`, po jejímž projetí se již nepůjde dostat zpět do místa `x` (v rámci uvažované silniční sítě). Takovéto ulice nazveme kriticky jednosměrné. Další negativní důsledek se týká městských oblastí, což jsou uskupení míst a ulic mezi nimi. Dvě místa jsou ve stejné oblasti, pokud se z jednoho do druhého dá dostat bez použití kriticky jednosměrných ulic. Po zjednosměrnění ulic se bohužel ukázalo, že v Praze vznikly oblasti, do kterých se z žádné jiné oblasti vůbec nedá dostat. Stejně tak vznikly i oblasti, ze kterých se do žádné jiné oblasti dostat nedá, což vede k nadměrné kumulaci aut a tím pádem i extrémní absenci parkovacích míst. Ani jeden ze zmíněných důsledků nepotěšil místní rezidenty, a tak se magistrát rozhodl nechat si vypracovat analýzu o negativních dopadech přijatých opatření. Cílem analýzy je pro zadanou silniční síť zjistit, kolik v ní existuje kriticky jednosměrných ulic a kolik v ní existuje oblastí, do kterých se z žádné jiné oblasti nedá dostat a oblastí, ze kterých se do žádné jiné oblasti nedá dostat.

Pražská silniční síť se skládá z míst a ulic a popisuje, mezi kterými dvěma místy vede v současnosti jednosměrná ulice. Před zjednosměrněním ulic se bylo možné dostat z každého místa do libovolného jiného. Mezi dvěma místy mohou existovat až dvě jednosměrné ulice; v každém směru však maximálně jedna. Jednotlivé ulice nejsou propojené nikde jinde než v zadaných místech. Žádná ulice nespojuje místo samo se sebou.

##### Formát vstupu:

- Na prvním řádku jsou dvě čísla `N` a `M`. Číslo `N` udává počet míst a číslo `M` udává počet ulic v silniční síti.
- Místa jsou číslována od nuly, mají tedy čísla `0`, `1`, ..., `N - 1`.
- Poté následuje `M` řádků, každý obsahující dvě čísla `x` a `y` `(0 ≤ x, y < N, x ≠ y)`, která popisují jednosměrnou ulici z místa `x` do místa `y`.
- Žádná ulice není ve vstupu uvedena vícekrát.
- Síť obsahuje vždy alespoň jedno místo, ale nemusí obsahovat žádnou ulici.

##### Formát výstupu:

Výstup sestává ze tří mezerami oddělených čísel na jediném řádku.
- První číslo udává počet kriticky jednosměrných ulic v dané silniční síti.
- Druhé číslo udává počet oblastí, do kterých se v rámci dané silniční sítě nedá dostat z žádné jiné oblasti.
- Třetí číslo udává počet oblastí, ze kterých se v rámci dané silniční sítě nedá dostat do žádné jiné oblasti.

##### Bodové podmínky:

Pro splnění povinných testů (test základními a malými daty) je zapotřebí, aby program fungoval korektně pro silniční sítě s nejvýše 300 místy a 3 000 ulicemi.
Pro splnění testu velkými daty musí program splnit časový a paměťový limit pro silniční sítě s nejvýše 50 000 místy a 500 000 ulicemi.
