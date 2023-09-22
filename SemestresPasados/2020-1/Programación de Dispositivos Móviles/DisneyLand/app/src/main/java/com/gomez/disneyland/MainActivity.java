package com.gomez.disneyland;

import android.app.Activity;
import android.content.Intent;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends Activity {
    private SQLiteDatabase db;
    private Cursor cursor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try{
            SQLiteOpenHelper disneylandDatabaseHelper = new DisneylandDatabaseHelper(this);
            db = disneylandDatabaseHelper.getReadableDatabase();
            cursor = db.query("PARKS",
                    new String[]{"_id","NAME"}, null, null, null, null, null);
        } catch (SQLiteException e){
            System.out.println(e);
            Toast toast = Toast.makeText(this, "Parks Database unavailable", Toast.LENGTH_SHORT);
            toast.show();
        }

        Button startButton = findViewById(R.id.button_intro);

        startButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, RegionSelectorActivity.class);
                startActivity(intent);
            }
        });

        Button randomButton = findViewById(R.id.button_random);

        randomButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, ParkActivity.class);
                intent.putExtra(ParkActivity.EXTRA_PARKID, (int) (Math.random() * 5) + 1);
                startActivity(intent);
            }
        });
    }

}