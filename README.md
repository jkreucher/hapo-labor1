# Labor 1: Ansteuerung eines 7‐Segment‐Displays

HAPO Labor bei Prof. Dr.‐Ing. Jens Altenburg an der TH-Bingen

## Aufgabenstellung:
Das Velleman‐Multifunction‐Shield ist mit einer vierstelligen 7‐Segmentanzeige, drei Tasten und vier LEDs ausgestattet. Aufgabe dieses Laborversuches ist es, die grundlegende Abfrage der Tasten bzw. die Ansteuerung der Anzeigen zu programmieren. Bei der Tastenabfrage besteht die Problematik darin, die Entprellung und die Implementierung unterschiedlich langer Tastendrücke zu realisieren. Die 7‐Segmentanzeige wird über ein Schieberegister angesteuert und erlaubt die Anzeige von vier Stellen. Da immer nur ein Digit (Digit = Anzeigeposition der Stelle) aktiv ist, muss eine Möglichkeit geschaffen werden alle Digitpositionen auszuwählen. Die vier LDs werden als Bargraph konfiguriert und sollen mittels Taste den Anzeigebalken (Bargraph) variieren.

## Durchführung:
Die Taste S1 ändert die Anzeige des ausgewählten Digits von 0 ... F bei kurzem Tastendruck in aufsteigender Folge (0, 1, 2, ...) und bei langem Tastendruck in absteigender Richtung. Die Taste S2 verschieb die Anzeigeposition der 7‐Segmentanzeige bei kurzem Tastendruck zur jeweils nächsten Digitposition. S3 kontrolliert den Bargraph.

## Vorbereitung:
Der Besuch der „Laborvorlesung (LV)“ ist äußerst hilfreich. Die Teilnahme an der ersten LV ist Pflicht. Bei diesem Termin findet eine Belehrung zum Verhalten während des Laborbetriebs statt. Die Belehrung ist zwingend vorgeschrieben. Bei krankheitsbedingtem Fernbleiben ist ein ärztliches Attest im Sekretariat zu hinterlegen. Bei unbegründeter Abwesenheit ist keine Nachbelehrung möglich und eine Teilnahme am Labor wird nicht zugelassen.

Ein Softwaretemplate ist auf der Online‐Plattform mbed.com zum Download in den eigenen Workspace verfügbar. In diesem Template sind nützliche Programmfunktionen enthalten. Weitere Erläuterungen finden während der LV statt. Ein Skript der LV wird nicht auf OLAT hochgeladen.

Die Laborversuche werden in Zweiergruppen durchgeführt. Zur Vorbereitung der Versuche erhält jede Gruppe die Versuchshardware. Zum Labortermin wird die jeweilige Lösung präsentiert und bei erfolgreicher Vorführung wird das Testat erteilt.