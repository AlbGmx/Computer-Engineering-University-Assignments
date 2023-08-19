package com.gomez.starbuzz;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class FoodActivity extends AppCompatActivity {
    public static final String EXTRA_FOODID = "foodId";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_food);

        //Get the drink from the intent
        int foodId = (Integer) getIntent().getExtras().get(EXTRA_FOODID);

        // Create a cursor
        SQLiteOpenHelper starbuzzDatabaseHelper = new StarbuzzDatabaseHelper(this);
        try {
            SQLiteDatabase db = starbuzzDatabaseHelper.getReadableDatabase();
            Cursor cursor = db.query("FOOD",
                    new String[] {"NAME", "DESCRIPTION", "IMAGE_RESOURCE_ID"}, "_id = ?",
                    new String[] {Integer.toString(foodId)}, null, null, null);

            // Move to the first record in the cursor
            if (cursor.moveToFirst()) {

                // Get the food details from the cursor
                String nameText = cursor.getString(0);
                String descriptionText = cursor.getString(1);
                int photoId = cursor.getInt(2);

                //Populate the food name
                TextView name = (TextView) findViewById(R.id.name);
                name.setText(nameText);

                //Populate the food description
                TextView description = (TextView) findViewById(R.id.description);
                description.setText(descriptionText);

                //Populate the food image
                ImageView photo = (ImageView) findViewById(R.id.photo);
                photo.setImageResource(photoId);
                photo.setContentDescription(nameText);
            }
            cursor.close();
            db.close();

        } catch (SQLiteException e){
            Toast toast = Toast.makeText(this, "Database unavailable", Toast.LENGTH_SHORT);
            toast.show();
        }
    }
}