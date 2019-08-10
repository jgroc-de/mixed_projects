# Resource Booking project (Backend technical exercise) <a href="./README.md">Version française</a>

## Project setup

### With docker and docker-compose

#### Requirements

Install [docker](https://docs.docker.com/install/) and [docker-compose](https://docs.docker.com/compose/install/)

#### Setup

- install dependencies: `make install`
- launch server: `make start`

### Without docker

#### Requirements

To run the app you must have `php` installed on your computer. `composer` is also mandatory.

#### Setup

- Install dependencies: `cd exercice-back-php` and `composer install`
- Update `DATABASE_URL` in your .env file to connect to a database of your choice
- Create database: `bin/console doctrine:database:create`
- Execute migration scripts: `bin/console doctrine:migrations:migrate`
- Start project: `php -S localhost:8080 public/index.php`)

### Installation check

Installation was succesful if running `curl localhost:8080/resources` returns `[{"id":1,"name":"Jetpack Fortnite X10298"}]`

## Start

**Now that you are ready, let's explore exercise's specifications [here](./SPECIFICATIONS.en.md).**
