package com;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import com.flyables.AircraftFactory;
import com.flyables.FlyableInterface;
import com.misc.IncorrectFlyableTypeException;
import com.tower.WeatherTower;

class Application {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Error: accept one and only one argument");
            return;
        }
        String file = args[0];
        String[] data;
        String line;
        WeatherTower weatherTower = new WeatherTower();
        int simulationCount;
        AircraftFactory factory = new AircraftFactory();
        
        File myObj = new File(file);
        try (
            Scanner myReader = new Scanner(myObj);
        ) {
            if (myReader.hasNextLine()) {
                simulationCount = Application.getSimulationCount(myReader.nextLine());
                if (simulationCount <= 0) {
                    System.out.println("Error: missing simulation count on line 1");
                    return;
                }
            } else {
                System.out.println("Error: empty file");
                return;
            }

            while (myReader.hasNextLine()) {
                line = myReader.nextLine();
                data = line.split(" ");
                if (data.length != 5) {
                    System.out.println("Error: in " + line);
                    return;
                }
                Application.createAndRegisterFlyable(data, factory, weatherTower);
            }
            weatherTower.simulate(simulationCount);
        } catch (FileNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    private static boolean createAndRegisterFlyable(String[] data, AircraftFactory factory, WeatherTower weatherTower) {
        FlyableInterface flyable;
        int latitude;
        int longitude;
        int height;

        try {
            longitude = Integer.parseInt(data[2]);
            latitude =  Integer.parseInt(data[3]);
            height = Integer.parseInt(data[4]);
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage());
            return false;
        }
        try {
            flyable = factory.newAircraft(
                data[0],
                data[1],
                longitude,
                latitude,
                height
            );
            flyable.registerTower(weatherTower);
            return true;
        } catch (IncorrectFlyableTypeException e) {
            System.out.println(data[0] + ": " + e.getMessage());
            return false;
        }
    }

    private static int getSimulationCount(String line) {
        try {
            return Integer.parseInt(line);
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage() + "is not a number");
            return -1;
        }
    }
}