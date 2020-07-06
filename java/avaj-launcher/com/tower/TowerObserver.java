package com.tower;

import java.util.ArrayList;
import com.flyables.FlyableInterface;

public class TowerObserver {
    private ArrayList<FlyableInterface> observers = new ArrayList<>();

    public void register(FlyableInterface flyable) {
        this.observers.add(flyable);
        System.out.println(this.getBaseMessage(flyable) + "registered to weather tower. gl&hf **");
    }

    public void unregister(FlyableInterface flyable) {
        System.out.println(this.getBaseMessage(flyable) + "UNregistered to weather tower. gg wp --");
        this.observers.remove(flyable);
    }

    protected void conditionsChanged() {
        ArrayList<FlyableInterface> toRemove = new ArrayList<>();

        for (FlyableInterface flyable: this.observers) {
            flyable.updateConditions();
            if (flyable.isLanded()) {
                toRemove.add(flyable);
            }
        }

        for (FlyableInterface flyable: toRemove) {
            this.unregister(flyable);
        }
    }

    private String getBaseMessage(FlyableInterface flyable) {
        return "Tower says: " + flyable.getType() + "#" + flyable.getName() + "(" + flyable.getId() + ")";
    }
}