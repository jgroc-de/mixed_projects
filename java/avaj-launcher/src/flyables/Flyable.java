package src.flyables;

import src.weather_tower.WeatherTower;

public interface Flyable {
    public void updateConditions();

    public void registerTower(WeatherTower weatherTower);

    public String getType();
    public String getName();
    public long getId();
    public boolean isLanded();
}
