package com.flyables;

import com.tower.WeatherTower;

public interface FlyableInterface {
    public void updateConditions();

    public void registerTower(WeatherTower weatherTower);

    public String getType();
    public String getName();
    public long getId();
    public boolean isLanded();
}