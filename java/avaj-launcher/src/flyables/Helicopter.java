package src.flyables;

import java.util.HashMap;

import src.lib.Coordinates;
import src.weather_tower.WeatherTower;

public class Helicopter extends Aircraft implements Flyable {
    protected String type = "Hellicopter";
    private WeatherTower weatherTower;
    private static final HashMap<String, Coordinates> weatherCases;
    private static final HashMap<String, String> messages;
    static {
        weatherCases = new HashMap<>();
        weatherCases.put("SUN", new Coordinates(10, 0, 2));
        weatherCases.put("RAIN", new Coordinates(5, 0, 0));
        weatherCases.put("FOG", new Coordinates(1, 0, 0));
        weatherCases.put("SNOW", new Coordinates(0, 0, -12));
        messages = new HashMap<>();
        messages.put("SUN", "My raybans are so cool");
        messages.put("RAIN", "My rayBans are so useless");
        messages.put("FOG", "My rayBans are so dirty");
        messages.put("SNOW", "My rayBans are freezing");
    }

    Helicopter(String name, Coordinates coordinates) {
        super(name, coordinates);
    }

    public void updateConditions() {
        String weather;
        
        weather = this.updateCoordinates(this.weatherTower, Helicopter.weatherCases);
        this.printState(Helicopter.messages.get(weather), weather, this.type);
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
