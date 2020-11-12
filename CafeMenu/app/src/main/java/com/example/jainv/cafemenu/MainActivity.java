    package com.example.jainv.cafemenu;

    import android.content.Intent;
    import android.net.Uri;
    import android.os.Bundle;
    import android.support.v7.app.AppCompatActivity;
    import android.util.Log;
    import android.view.View;
    import android.widget.CheckBox;
    import android.widget.EditText;
    import android.widget.TextView;
    import android.widget.Toast;

    import java.text.NumberFormat;

    /**
     * This app displays an order form to order coffee.
     */
    public class MainActivity extends AppCompatActivity {

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_main);
        }

        /**
         * This method is called when the order button is clicked.
         */
        int c=0;
        boolean res=false;
        boolean res2=false;
        String name="", msg="";
        public void submitOrder(View view) {
            CheckBox whcr=(CheckBox) findViewById(R.id.checkBox);
            res=whcr.isChecked();
            CheckBox choco=(CheckBox) findViewById(R.id.choc);
            res2=choco.isChecked();
            int price=calculate_price(c);
            EditText txt=(EditText) findViewById(R.id.name);
            name=txt.getText().toString();
            msg="Name: "+ name+ "\n Quantity: "+ c +" coffees \n Added Whipped Cream: "+ res + "\n Added Chocolate: "+ res2 + " \n Total Price: Rs " + price + " \n Thank You!";
            orderSummary(price);
            display(c);
               }
        public void sendOrder(View view) {
            Intent intent = new Intent(Intent.ACTION_SENDTO);
            intent.setData(Uri.parse("mailto:")); // only email apps should handle this
            intent.putExtra(Intent.EXTRA_SUBJECT, "Order Summary for " + name);
            intent.putExtra(Intent.EXTRA_TEXT, msg);
            if (intent.resolveActivity(getPackageManager()) != null) {
                startActivity(intent);
            }

        }
        public void increase(View view) {
            if (c==100)
            {Toast.makeText(this,"You cannot have coffee more than 100", Toast.LENGTH_SHORT).show();
            return;}
            c++;
            display(c);
            }
        public void decrease(View view) {
            if (c==0 || c==1)
            {Toast.makeText(this,"You cannot have coffee less than 1", Toast.LENGTH_SHORT).show();
                return;}
            c--;
            display(c);
            }


        /**
         * This method displays the given quantity value on the screen.
         */
        private void display(int number) {
            TextView quantityTextView = (TextView) findViewById(R.id.quantity_text_view);
            quantityTextView.setText("" + number);
        }
        private int calculate_price(int qty)
        {
            int total=qty*5;
            if (res==true)
                total=total+(qty*1);
            if(res2==true)
                total=total+(qty*2);
            return total;
        }
        private void orderSummary(int price)
        {
            TextView orderTextView = (TextView) findViewById(R.id.order_text_view);
            orderTextView.setText("Total price for order: "+ price);
        }
    }