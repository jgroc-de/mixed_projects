# Spécifications <a href="./SPECIFICATIONS.en.md">Version anglaise</a>

## Introduction

Le but de cet exercice est de découvrir comment vous abordez un problème et de cartographier vos forces et faiblesses.
Il n'existe pas de réponse exacte ou de manière unique de traiter le problème proposé.
Nous pourrons par la suite nous servir de votre code comme support de discussion lors de votre entretien technique : il n'est donc pas nécessaire d'aller jusqu'au bout de toutes les questions.

## Instruction

IMPORTANT : il n'est pas obligatoire d'atteindre la fin de l'exercice.

### Scenario

Nous voulons implémenter une nouvelle API HTTP qui permet de réserver différents types de resource comme des chambres d'hotel, des salles de réunions, des jetpacks, etc.

**Example**

Prenons par exemple la ressource #1 ci-dessous.

```json
{
  "id": 1,
  "name": "Meeting room Albert Einstein"
}
```

Je dois pouvoir réserver cette salle de réunion le 2019-03-18 de 14:00 to 19:30. Si une autre personne tente de réserver cette salle entre 07:00 et 14:30, alors l'API retournera un message d'erreur.

Je dois pouvoir savoir quand cette salle de réunion est disponible.

### LIVRABLES

Vous devez exposer un ensemble d'endpoints qui permettent de :

#### 1 - Créer une réservation

**Request** POST http://localhost:8080/bookings

Body

```json
{
  "resource_id": "int OR string",
  "start_date": "date time format Y-m-dTH:i:s",
  "end_date": "date time format Y-m-dTH:i:s"
}
```

**Response**

Body

```json
{
  "id": "int OR string",
  "resource_id": "int OR string",
  "start_date": "date time format Y-m-dTH:i:s",
  "end_date": "date time format Y-m-dTH:i:s"
}
```

HTTP Codes

- 201 Created : en cas de succès
- 403 Forbidden : en cas d'indisponibilité de la ressource

#### [FACULTATIF] - 2 - Rechercher des disponibilités

Cet endpoint renvoit les disponibilitées d'une resource donnée. Une disponibilité est une plage horaire où la resource donné n'a pas de reservation
_Note: ce second endpoint est optionel pour les candidats qui auraient très vite finis le premier endpoint. Ne vous sentez obligé de finir celui ci._

**Request** GET http://localhost:8080/resources/{resource_id}/availabilities

**Response**

Body

```json
[
  {
    "resource_id": "int OR string",
    "start_date": "date time format Y-m-dTH:i:s",
    "end_date": "date time format Y-m-dTH:i:s"
  },
  {
    "resource_id": "int OR string",
    "start_date": "date time format Y-m-dTH:i:s",
    "end_date": "date time format Y-m-dTH:i:s"
  }
]
```

### Pour aller plus loin

Si vous voulez creuser et améliorer votre projet, voici quelques pistes d'améliorations possibles :

- Rajouter des tests (unitaires, api, etc)
- Intégrer une gestion d'erreurs : Codes HTTP
- ...

### Soumettre votre travail

Quand vous pensez avoir fini l'exercice, merci d'ouvrir une pull-request :)
