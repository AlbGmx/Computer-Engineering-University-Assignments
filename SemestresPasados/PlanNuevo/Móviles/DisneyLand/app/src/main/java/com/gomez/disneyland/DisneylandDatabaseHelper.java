package com.gomez.disneyland;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DisneylandDatabaseHelper extends SQLiteOpenHelper {

    private static final String DB_NAME = "disney"; //the name of our database
    private static final int DB_VERSION = 1; //the version of the database
    private final Context context;

    public DisneylandDatabaseHelper(Context context){
        super(context, DB_NAME, null, DB_VERSION);
        this.context = context;
    }

    @Override
    public void onCreate(SQLiteDatabase db){
        updateMyDatabase(db, 0, DB_VERSION);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
        db.execSQL("DROP TABLE IF EXISTS PARKS");
        updateMyDatabase(db, oldVersion, newVersion);
    }

    private static void insertDb(SQLiteDatabase db, String name, String description,
                                 String openingDate, int region, int resourceId){
        ContentValues dbValues = new ContentValues();
        dbValues.put("NAME", name);
        dbValues.put("DESCRIPTION", description);
        dbValues.put("OPENING", openingDate);
        dbValues.put("REGION", region);
        dbValues.put("IMAGE_RESOURCE_ID", resourceId);
        db.insert("PARKS", null, dbValues);
    }

    private void updateMyDatabase(SQLiteDatabase db, int oldVersion, int newVersion){
        if (oldVersion < 1) {
            db.execSQL("CREATE TABLE PARKS ("
                    + "_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    + "NAME TEXT, "
                    + "DESCRIPTION TEXT, "
                    + "OPENING TEXT, "
                    + "REGION INTEGER, "
                    + "IMAGE_RESOURCE_ID INTEGER,"
                    + "VISITED NUMERIC);");

            insertDb(db, context.getString(R.string.na_california_name), context.getString(R.string.na_california_desc), context.getString(R.string.na_california_date), 1, R.drawable.disneyland_california);
            insertDb(db, context.getString(R.string.na_florida_name), context.getString(R.string.na_florida_desc), context.getString(R.string.na_florida_date), 1, R.drawable.disneyland_florida);
            insertDb(db, context.getString(R.string.eu_france_name), context.getString(R.string.eu_france_desc), context.getString(R.string.eu_france_date), 2, R.drawable.disneyland_paris);
            insertDb(db, context.getString(R.string.as_hongkong_name), context.getString(R.string.as_hongkong_desc), context.getString(R.string.as_hongkong_date), 3, R.drawable.disneyland_hongkong);
            insertDb(db, context.getString(R.string.as_japan_name), context.getString(R.string.as_japan_desc), context.getString(R.string.as_japan_date), 3, R.drawable.disneyland_japan);
        }
        if (oldVersion < 2) {
            db.execSQL("ALTER TABLE PARKS ADD COLUMN FAVORITE NUMERIC");
        }
    }
}