package src.weather_tower;

import java.util.ArrayList;
import src.flyables.Flyable;
import src.lib.IO;

public class Tower {
    private ArrayList<Flyable> observers = new ArrayList<>();

    public void register(Flyable flyable) {
        this.observers.add(flyable);
        IO.writeAndSave(this.getBaseMessage(flyable) + "registered to weather tower. gl&hf **");
    }

    public void unregister(Flyable flyable) {
        IO.writeAndSave(this.getBaseMessage(flyable) + "UNregistered to weather tower. gg wp --");
        this.observers.remove(flyable);
    }

    protected void conditionsChanged() {
        ArrayList<Flyable> toRemove = new ArrayList<>();

        for (Flyable flyable: this.observers) {
            flyable.updateConditions();
            if (flyable.isLanded()) {
                toRemove.add(flyable);
            }
        }

        for (Flyable flyable: toRemove) {
            this.unregister(flyable);
        }
    }

    private String getBaseMessage(Flyable flyable) {
        return "Tower says: " + flyable.getType() + "#" + flyable.getName() + "(" + flyable.getId() + ")";
    }
}
