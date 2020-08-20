package src.flyables;

import java.util.HashMap;

import src.lib.Coordinates;
import src.weather_tower.WeatherTower;

public class JetPlane extends Aircraft implements Flyable {
    protected String type = "JetPlane";
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
        messages.put("SUN", "I will need a cap");
        messages.put("RAIN", "I will need an umbrella");
        messages.put("FOG", "I will need a light");
        messages.put("SNOW", "I will need a scarf");
    }

    JetPlane(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        String weather;
        
        weather = this.updateCoordinates(this.weatherTower, JetPlane.weatherCases);
        this.printState(JetPlane.messages.get(weather), weather, this.type);
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
