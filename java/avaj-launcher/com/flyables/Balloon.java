package com.flyables;

import java.util.HashMap;

import com.misc.Coordinates;
import com.tower.WeatherTower;

public class Balloon extends Aircraft implements FlyableInterface {
    protected String type = "Balloon";
    private WeatherTower weatherTower;
    private static final HashMap<String, Coordinates> weatherCases;
    private static final HashMap<String, String> messages;
    static {
        weatherCases = new HashMap<>();
        weatherCases.put("SUN", new Coordinates(0, 10, 2));
        weatherCases.put("RAIN", new Coordinates(0, 5, 0));
        weatherCases.put("FOG", new Coordinates(0, 1, 0));
        weatherCases.put("SNOW", new Coordinates(0, 0, -7));
        messages = new HashMap<>();
        messages.put("SUN", "I need a cap");
        messages.put("RAIN", "I need an umbrella");
        messages.put("FOG", "I need a light");
        messages.put("SNOW", "I need a scarf");
    }

    Balloon(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        String weather;
        
        weather = this.updateCoordinates(this.weatherTower, Balloon.weatherCases);
        this.printState(Balloon.messages.get(weather), weather);
    }

    public void registerTower(WeatherTower weatherTower) {
        if (this.coordinates.getHeight() != 0) {
            this.weatherTower = weatherTower;
            this.weatherTower.register(this);
        }
    }

    public String getType() {
        return this.type;
    }
}