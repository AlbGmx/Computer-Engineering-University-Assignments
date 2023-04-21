package com.gomez.starbuzz;

import android.content.ContentValues;
import android.database.sqlite.SQLiteOpenHelper;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;


public class StarbuzzDatabaseHelper extends SQLiteOpenHelper {

    private static final String DB_NAME = "starbuzz";   // the name of our database
    private static final int DB_VERSION = 1;            // the version of the database

    StarbuzzDatabaseHelper(Context context){
        super(context, DB_NAME, null, DB_VERSION);
    }
    @Override
    public void onCreate(SQLiteDatabase db){
        updateMyDatabase(db, 0, DB_VERSION);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
        updateMyDatabase(db, 0, DB_VERSION);
    }

    public void updateMyDatabase(SQLiteDatabase db, int oldVersion, int newVersion){
        if(oldVersion < 1) {
            db.execSQL("CREATE TABLE DRINK ("
                    + "_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    + "NAME TEXT, "
                    + "DESCRIPTION TEXT, "
                    + "IMAGE_RESOURCE_ID INTEGER); ");

            db.execSQL("CREATE TABLE FOOD ("
                    + "_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    + "NAME TEXT, "
                    + "DESCRIPTION TEXT, "
                    + "IMAGE_RESOURCE_ID INTEGER); ");

            db.execSQL("CREATE TABLE STORE ("
                    + "_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    + "NAME TEXT, "
                    + "DESCRIPTION TEXT, "
                    + "IMAGE_RESOURCE_ID INTEGER); ");

            insertTo(db, "drink", "Latte", "Espresso and steamed milk.", R.drawable.latte);
            insertTo(db, "drink", "Cappuccino", "Hot milk and steamed milk-foam.", R.drawable.cappuccino);
            insertTo(db, "drink", "Filter", "our best drip coffee.", R.drawable.filter);
            insertTo(db, "food", "Pizza", "Italian dish with dough, sauce, cheese, toppings", R.drawable.pizza);
            insertTo(db, "food", "Sushi", "Japanese dish with seasoned rice, seaweed, raw fish.", R.drawable.sushi);
            insertTo(db, "food", "Tacos", "Mexican dish with folded tortilla, filling, toppings.", R.drawable.tacos);
            insertTo(db, "store", "\nTecate Store\n\nAvenida Revolución #1234, Zona Centro, Tijuana, Baja California, México 22000", "Opens daily from 6:00 am to 9:00pm", R.drawable.tecate);
            insertTo(db, "store", "\nTijuana Store\n\nCalle Hidalgo #567, Zona Centro, Tecate, Baja California, México 21400", "Opens weekdays 6:00 am to 7:00 pm and weekends from 6:00 am to 5:00 pm", R.drawable.tijuana);
            insertTo(db, "store", "\nMexicali Store\n\nCallejon Coahuila #345, Zona Centro, Mexicali, Baja California, México 21000", "Opens from monday to saturday 6:00 am to 6:00 pm",  R.drawable.mexicali);

        } if (oldVersion < 2 ) db.execSQL("ALTER TABLE DRINK ADD COLUMN FAVORITE NUMERIC;");
    }

    private static void insertTo(SQLiteDatabase db, String table, String name, String description,
                                    int resourceId){

        ContentValues dbValues = new ContentValues();
        dbValues.put("NAME", name);
        dbValues.put("DESCRIPTION", description);
        dbValues.put("IMAGE_RESOURCE_ID", resourceId);
        db.insert(table, null, dbValues);
    }
}
