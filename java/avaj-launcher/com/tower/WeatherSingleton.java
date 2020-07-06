package com.tower;

import com.misc.Coordinates;

public class WeatherSingleton {
    private static WeatherSingleton weatherSingleton;
    private static String[] weathers = {"SUN", "RAIN", "SNOW", "FOG"};

    private WeatherSingleton() {
        //constructor
    }

    public static WeatherSingleton getInstance() {
        if (weatherSingleton == null) {
            weatherSingleton = new WeatherSingleton();
        }
        return weatherSingleton;
    }

    public String getCurrentWeather(Coordinates coordinates) {
        int sum;
        
        sum = coordinates.getHeight() + coordinates.getLatitude() + coordinates.getLongitude();
        return WeatherSingleton.weathers[this.abs(sum) % 4];
    }

    private int abs(int sum) {
        if (sum < 0) {
            return -sum;
        }

        return sum;
    }
}