package src.weather_tower;

import src.lib.Coordinates;
import src.lib.IO;

public class WeatherTower extends Tower {
    public String getWeather(Coordinates coordinates) {
        WeatherProvider instance = WeatherProvider.getInstance();
        
        return instance.getCurrentWeather(coordinates);
    }

    void changeWeather() {
        this.conditionsChanged();
    }

    public void simulate(int simulationCount) {
        while (simulationCount-- > 0) {
            IO.writeAndSave("\n ** turns left: " + simulationCount + "\n");
            this.changeWeather();
        }
    }
}
