# Lem-in

Projet d'Algorithmies Elémentaires: recherche de chemin le plus court

## extrait du sujet

Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière par n fourmis

le sujet complet est disponible dans le fichier lem-in.fr.pdf

## la solution

La recherche de tous les chemins possibles est faites grace à un backtracking. Ce n'est effectivement pas optimal. Il permet néanmoins  d'avoir la liste totale des chemins ce qui est nécessaire pour pouvoir distribuer les fourmis sur plusieurs chemins. Un BFS (parcours en largueur) aurait été évidemmentun meilleur choix pour ce probleme (c'est quelquepart dans ma to-do list).

## utilisation

Pour compiler le programme (avec gcc, dans un terminal)

```bash
git clone https://github.com/jgroc-de/lem-in.git && cd lem-in && make
```

faire un test (en utilisant les fichiers fournis dans le dossier test):
```bash
./lem-in < test/simple3
```

le dossier test contient entre autre un certain nombre de fichiers éronnés ayant pour but de tester le comportement du parser et de l'algo (notamment sur ds boucles).
