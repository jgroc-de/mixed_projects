package com.tower;

import com.misc.Coordinates;

public class WeatherTower extends TowerObserver {
    public String getWeather(Coordinates coordinates) {
        return WeatherSingleton.getInstance().getCurrentWeather(coordinates);
    }

    void changeWeather() {
        //lol
    }

    public void simulate(int simulationCount) {
        while (simulationCount-- > 0) {
            System.out.println("\n ** turns left: " + simulationCount + "\n");
            this.conditionsChanged();
        }
    }
}