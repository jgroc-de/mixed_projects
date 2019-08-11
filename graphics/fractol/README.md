# Fractol

Ceci est un générateur de fractals, preparez votre sac à vomi!
Projet de la branche infographie

![phoenix](./assets/phoenix2.gif)

## Included

- libft (libc-like)
- GNL (kind of gets) (if (gnl() == 1) !!!! (et pas -1! pour le retour du 0, noob!)
- ft_printf (printf-like)

## About

8 fractales différentes sont disponibles:
- [mandelbrot](https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot)
- [julia](https://fr.wikipedia.org/wiki/Ensemble_de_Julia)
- [newton](https://fr.wikipedia.org/wiki/Fractale_de_Newton)
- [burning ship](https://fr.m.wikipedia.org/wiki/Fractale_burning_ship)
- [phoenix](https://www.ultrafractal.com/help/index.html?/help/formulas/standard/phoenix.html)
- et 3 fractales un peu random fait en alignant une formule fathématique un peu au pif (rm1/2/3)
le point commun de toutes ces fractales est d'utiliser des maths identiques (nombres imaginaires) et d'avoir une implémentation tres similaire,
visible dans le dossier project/fractals

## particularité technique

- utilisation de la librairie pthread pour du multi threading
- pas de fuite mémoire (comme d'hab)
- mon projet le plus propre en C au moment ou j'écrit ces lignes

## Subject (fr)

[pdf](./fract_ol.fr.pdf)

## Installation & Usage: (linux/ubuntu or mac of 42 school)

Modifier le fichier Makefile du dossier project selon votre OS (voir les commentaires dans ce fichier).
Puis,à la racine du dossier fractol

```bash
make
```

pour les options possibles pour ce programme
```bash
./fractol
```

Par contre, les touches sont probablement en mode bépo… (dommages collatérals on va dire)

## What does it looks like

![julia](./assets/julia2.gif)
![mandelbrot](./assets/mandelbrot.gif)
