import java.util.ArrayList;

public class CustomObject {

	private String customProperty;

    public CustomObject(String property) {
        this.customProperty = property;
    }

    public String getCustomProperty() {
        return this.customProperty;
    }

    public static void main(String[] args) {

        ArrayList<CustomObject> list = new ArrayList<>();
        list.add(new CustomObject("Z"));
        list.add(new CustomObject("A"));
        list.add(new CustomObject("B"));
        list.add(new CustomObject("X"));
        list.add(new CustomObject("Aa"));

        list.sort((o1, o2) -> o1.getCustomProperty().compareTo(o2.getCustomProperty()));

        for (CustomObject obj : list) {
            System.out.println(obj.getCustomProperty());
        }
    }
}
