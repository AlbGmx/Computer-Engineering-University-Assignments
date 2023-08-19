package com.gomez.disneyland;

import android.app.Activity;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class ParkSelectorActivity extends Activity {
    public static final String EXTRA_REGIONID = "regionId";

    private SQLiteDatabase db;
    private Cursor cursor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_park_selector);

        int regionId = (Integer) getIntent().getExtras().get(EXTRA_REGIONID);

        ListView listParks = findViewById(R.id.list_parks);

        try{
            SQLiteOpenHelper disneylandDatabaseHelper = new DisneylandDatabaseHelper(this);
            db = disneylandDatabaseHelper.getReadableDatabase();
            cursor = db.query("PARKS",
                    new String[]{"_id","NAME"},
                    "REGION="+regionId,//null,
                    null, null, null, null);

            ArrayList<String> parks = new ArrayList<>();
            cursor.moveToFirst();
            while(!cursor.isAfterLast()) {
                parks.add(cursor.getString(1)); // index 1 = NAME
                cursor.moveToNext();
            }
            listParks.setAdapter(new ArrayAdapter<String>(this, R.layout.list_items, R.id.list_content, parks));
        } catch (SQLiteException e){
            System.out.println(e);
            Toast toast = Toast.makeText(this, "DisneyLand Parks Database unavailable", Toast.LENGTH_SHORT);
            toast.show();
        }

        //Create the listener
        AdapterView.OnItemClickListener itemClickListener = new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> listDrinks, View view, int position, long id) {
                //Pass the drink the user clicks on to DrinkActivity
                Intent intent = new Intent(ParkSelectorActivity.this, ParkActivity.class);
                id += (regionId == 0) ? 0 : regionId;
                intent.putExtra(ParkActivity.EXTRA_PARKID, (int) id + 1);
                startActivity(intent);
            }
        };
        //Assign the listener to the list view
        listParks.setOnItemClickListener(itemClickListener);
    }

    @Override
    public void onDestroy(){
        super.onDestroy();
        cursor.close();
        db.close();
    }
}