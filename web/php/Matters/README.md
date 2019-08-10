# Matters (technical test)

this is a technical test made in 4h a sunday afternoon…
made in symfony 4, it is just an api

# Projet de réservation de ressources (Exercice technique back) <a href="./README.en.md">English version</a>

## Procédure d'installation

### Installation avec docker et docker-compose

#### Prérequis

Vous devez avoir [docker](https://docs.docker.com/install/) et [docker-compose](https://docs.docker.com/compose/install/) installé sur votre machine.

#### Installation

- installer les dépendances: `make install`
- lancer le server: `make start`

### Installation sans docker

#### Prérequis

Vous devez avoir `php` installé sur votre machine. Il vous faudra également le package manager `composer`.
Vous devez avoir également une connexion à une base de données de votre choix.

#### Installation

- Cloner le projet: `git clone https://gitlab.matters.tech/entretien-templates/exercice-back-php.git`
- Installer les dépendences : `composer install`
- Modifier la valeur de la variable DATABASE_URL dans .env pour vous connecter à la base données de votre choix
- Créer la base de données `bin/console doctrine:database:create`
- Exécuter les scripts de migration `bin/console doctrine:migrations:migrate`
- Lancer le projet : `php -S localhost:8080 public/index.php`

### Verifications de l'installation

L'installation est un succès si la commande `curl localhost:8080/resources` doit renvoyer `[{"id":1,"name":"Jetpack Fortnite X10298"}]`

## Commencer l'exercice

**Maintenant que vous êtes prêt(e), vous pouvez consulter les consignes de l'exercice [ici](./SPECIFICATIONS.md).**
