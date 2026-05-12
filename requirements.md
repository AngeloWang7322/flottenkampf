## Flottenkampf - Stufe 1
Zwei Flotten, bestehend aus verschiedenen Schiffen, bekämpfen sich gegenseitig rundenweise.
Dabei soll der Computer die Flotten automatisiert gegeneinander antreten lassen, nachdem
die Flotten von Personen erstellt wurden. Jedes Ereignis soll über die Konsole ausgegeben
werden.
Flotten bestehen aus ein bis neun Schiffen, es gibt drei verschiedene Arten von Schiffen:
Jäger, Zerstörer und Kreuzer.
Vor dem Kampf soll es möglich sein, die Flotten zusammenzustellen. Alle Schiffe haben
folgende Eigenschaften: einen Hüllenwert, einen Größenwert und einen Schadenswert. Die
Spezifikationen der Schiffsarten sind folgende, wobei Sie die Werte beliebig anpassen können,
um eine andere Balance zu erhalten: <br>
Schiffstyp | Hülle | Größe | Schaden | Spezial</br>
Jäger | 75 | 4 | 30 | Kritische Treffer <br>
Zerstörer | 150 | 6 | 60 | Zielsuchend <br>
Kreuzer | 250 | 8 | 50 | Bombardement <br>
Die Spezialregeln werden im Folgenden noch erklärt.
Nachdem die Flotten erstellt wurden, treten sie gegeneinander an. Die folgende Abfolge
von Aktionen wird so lange abwechselnd wiederholt, bis eine Flotte vernichtet wurde und das
Spiel endet:
1. Ein Schiff der eigenen Flotte wird gewählt und ein Schiff der gegnerischen Flotte als
Ziel deklariert.
2. Zuerst wird ein zehnseitiger Würfel geworfen (die Trefferprobe), wenn dessen Ergebnis
gleich oder größer dem Größenwert des attackierten Schiffs ist, war der Angriff erfolgreich. Ansonsten wird der Angriff an dieser Stelle abgebrochen und die andere Person
führt einen Angriff aus
3. War der Angriff erfolgreich, wird der Schadenswert des angreifenden Schiffs vom
Hüllenwert des angegriffenen Schiffs abgezogen. Sinkt der Hüllenwert dadurch unter 1, wird das Schiff zerstört und aus der Flotte entfernt.
Greift zum Beispiel ein Jäger einen Kreuzer an, wird zuerst eine Trefferprobe auf 8+ abgehandelt (da der Kreuzer einen Größenwert von 8 hat). Wenn das Ergebnis eines zehnseitigen
Würfelwurfs also 8 oder mehr ist, trifft der Angriff des Jägers und der Hüllenwert des Kreuzers
wird um 30 verringert.
Folgende Spezialregeln gelten für die verschiedenen Schiffe:
• Kritische Treffer: Jäger verursachen doppelten Schaden, wenn das Ergebnis der Trefferprobe 9 oder 10 war.
• Bombardement: Kreuzer dürfen einen weiteren Angriff durchführen, wenn der erste
erfolgreich war. Dieser Effekt kann beliebig oft in einer Aktion ausgelöst werden.
• Zielsuchend: Trefferproben sind um 2 erleichtert.

## Flottenkampf - Stufe 2
Erweitern Sie das Spiel nun um eine zweidimensionale Spielwelt, in der sich die Schiffe bewegen können und dann über eine Distanz hinweg angreifen müssen. Über größere Distanzen 
sollen die Angriffe weniger Schaden verursachen. Geben Sie nach jeder Aktion den neuen
Zustand der Spielwelt aus.

## Flottenkampf - Stufe 3
Ermöglichen Sie Schiffen, Erfahrungspunkte zu sammeln und nach dem Erreichen einer gewissen Anzahl zusätzliche Fähigkeiten freizuschalten, implementieren Sie dazu für jeden Schiffstyp noch mindestens zwei weitere Fähigkeiten.
Anforderungen Flottenkampf
• Implementierung einer klaren Klassenstruktur mit Vererbung und Polymorphismus
• Fehlerüberprüfung der Inputs
• Erstellung eines UML-Diagramms, welches die Klassenstruktur darstellt
• Stufe 1
– Dynamische Erstellung von Flotten und Schiffen durch User
– Ausgabe von Ereignissen
– Erstellung einer einfachen Angriffslogik
• Stufe 2
– Implementierung einer 2D-Spielwelt
– Ausgabe der Spielwelt und Schiffe
– Implementierung der Bewegungs- und Angriffslogik der Schiffe
• Stufe 3
– Implementierung von Erfahrungspunkten
– Freischalten von neuen Fähigkeiten bei genügend Erfahrungspunkten
– Erweiterung von jedem Schiffstyp um mindestens zwei zusätzliche Fähigkeiten