# Specifications <a href="./SPECIFICATIONS.md">French version</a>

## Introduction
You have been proposed this little assignment in order to check how you can address and tackle tasks that have been asked to you. Consider there is no exact answer to the problem nor only one way of doing. The goal of this exercise is to map your strengths and weaknesses. It will allow us to use your code as a discussion support during your technical interview.

## Instruction

### Scenario
We want to develop a new HTTP API that allow our consumers to book different kind of resources like hotel rooms, meeting rooms, cars, jet packs, etc.


**Example**

Let's say that we have a resource #1 :

```json
{
  "id": 1,
  "name" : "Meeting room Albert Einstein"
}
```

I can book this resource at 2019-03-18 from 14:00 to 19:30. If another person attempts to book this same resource between 07:00 and 14:30, then the API will return an error message.

### Your deliverable

You have to expose a set of endpoints to achieve these features :

#### Create a booking

**Request** POST http://localhost:8080/bookings

Body
```json
{
  "resource_id" : "int OR string",
  "start_date" : "date time format Y-m-dTH:i:s",
  "end_date" : "date time format Y-m-dTH:i:s"
}
```
**Response**

Body
```json
{
  "booking_id": "int OR string",
  "resource_id" : "int OR string",
  "start_date" : "date time format Y-m-dTH:i:s",
  "end_date" : "date time format Y-m-dTH:i:s"
}
```

HTTP Codes
* 201 Created : in case of success
* 403 Forbidden : in case of unavailable resource


#### Get availabilities
**Request** GET http://localhost:8080/availbilities/resource_id

**Response**

Body
```json
[
    {
      "resource_id" : "int OR string",
      "start_date" : "date time format Y-m-dTH:i:s",
      "end_date" : "date time format Y-m-dTH:i:s"
    },
    {
      "resource_id" : "int OR string",
      "start_date" : "date time format Y-m-dTH:i:s",
      "end_date" : "date time format Y-m-dTH:i:s"
    }
]

```
## To go further

If you want to go deeper and improve your booking API, here are some topics you might want to cover :

* Add different kind of tests (unit, api)
* Error message, and HTTP codes
* Improve the provided CI by adding some useful jobs (linting, running tests, ...)


## Submit your work

When you are done with the exercise, please submit the edited project in your own namespace on Gitlab.
