package com.flyables;

import java.util.HashMap;
import com.misc.Coordinates;
import com.tower.WeatherTower;

public class Aircraft {
    protected Long id;
    protected String name;
    protected Coordinates coordinates;
    private static Long idCounter = 0L;

    protected Aircraft(String name, Coordinates coordinates) {
        this.id = this.nextId();
        this.name = name;
        this.coordinates = coordinates;
    }

    private Long nextId() {
        long currentId = Aircraft.idCounter;
        Aircraft.incrementId();

        return currentId;
    }

    private static void incrementId() {
        ++Aircraft.idCounter;
    }

    public long getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public boolean isLanded() {
        return this.coordinates.getHeight() <= 0;
    }

    protected String updateCoordinates(WeatherTower weatherTower, HashMap<String, Coordinates> weatherCase) {
        String weather;
        Coordinates coordinate;

        weather = weatherTower.getWeather(this.coordinates);
        coordinate = weatherCase.get(weather);
        this.coordinates.add(coordinate);

        return weather;
    }

    protected void printState(String message, String weather) {
        System.out.println(message + " - weather: " + weather + " - sum: " + this.coordinates.sum());

    }
}