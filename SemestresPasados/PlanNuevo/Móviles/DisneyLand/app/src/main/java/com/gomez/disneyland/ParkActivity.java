package com.gomez.disneyland;

import android.app.Activity;
import android.content.ContentValues;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class ParkActivity extends Activity {
    public static final String EXTRA_PARKID = "parkId";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_park);

        Button googleMapsButton = findViewById(R.id.map);
        googleMapsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openGoogleMaps();
            }
        });

        //send whatsapp
        Button submit = findViewById(R.id.share);

        //Get the drink from the intent
        int parkId = (Integer) getIntent().getExtras().get(EXTRA_PARKID);

        //Create a cursor
        SQLiteOpenHelper disneylandDatabaseHelper = new DisneylandDatabaseHelper(this);
        try{
            SQLiteDatabase db = disneylandDatabaseHelper.getReadableDatabase();

            Cursor cursor = db.query("PARKS", new String[] {"NAME", "DESCRIPTION", "OPENING", "REGION", "IMAGE_RESOURCE_ID", "VISITED"},
                    "_id = "+parkId, null,null, null, null);

            if(cursor.moveToFirst()){
                String[] regions = getResources().getStringArray(R.array.regions);
                String nameText = cursor.getString(0);
                String descriptionText = cursor.getString(1);
                String openingText = cursor.getString(2);
                int regionInt = cursor.getInt(3);
                int photoId = cursor.getInt(4);
                boolean isVisited = (cursor.getInt(5) == 1);

                TextView name = (TextView) findViewById(R.id.name);
                name.setText(nameText);

                TextView description = (TextView) findViewById(R.id.description);
                description.setText(descriptionText);

                //Opening date
                TextView opening = (TextView) findViewById(R.id.opening);
                opening.setText("Opening date:" + openingText);

                //Region
                TextView region = (TextView) findViewById(R.id.region);
                String regionText = (regionInt >= 1 && regionInt <= regions.length) ? regions[regionInt-1] : "Unknown Region";
                region.setText("Region: " + regionText);

                //Resource ID
                ImageView photo = (ImageView) findViewById(R.id.photo);
                photo.setImageResource(photoId);
                photo.setContentDescription(nameText);

                //Visited
                CheckBox favorite = (CheckBox)findViewById(R.id.visited);
                favorite.setChecked(isVisited);

                submit.setOnClickListener(
                        new View.OnClickListener() {
                            @Override
                            public void onClick(View view)
                            {

                                // Getting the text
                                // from edit text
                                String message = "We should visit " + nameText;

                                // Calling the function
                                // to send message
                                sendMessage(message);
                            }
                        });

            }
            cursor.close();
            db.close();
        } catch (SQLiteException e){
            Toast toast = Toast.makeText(this, "Database not available", Toast.LENGTH_SHORT);
            toast.show();
        }
    }

    private void openGoogleMaps() {
        Uri gmmIntentUri = Uri.parse("geo:0,0"  + "?q=" + Uri.encode(getParkNameFromDatabase()));
        Intent mapIntent = new Intent(Intent.ACTION_VIEW, gmmIntentUri);
        mapIntent.setPackage("com.google.android.apps.maps");
        if (mapIntent.resolveActivity(getPackageManager()) != null) {
            startActivity(mapIntent);
        } else {
            Toast.makeText(this, "Google Maps app is not installed", Toast.LENGTH_SHORT).show();
        }
    }

    // Update the database when the checkbox is clicked
    public void onVisitedClicked(View view){
        int parkId = (Integer) getIntent().getExtras().get(EXTRA_PARKID);
        new UpdateParkTask().execute(parkId);
    }

    private String getParkNameFromDatabase() {
        String parkName = "";
        SQLiteOpenHelper disneylandDatabaseHelper = new DisneylandDatabaseHelper(ParkActivity.this);

        SQLiteDatabase db = disneylandDatabaseHelper.getReadableDatabase();

        String[] projection = { "NAME" };

        int parkId = getIntent().getIntExtra(EXTRA_PARKID, 1);

        // Build the selection criteria
        String selection = "_id = ?";
        String[] selectionArgs = { String.valueOf(parkId) };

        // Execute the query
        Cursor cursor = db.query("PARKS", projection, selection, selectionArgs, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            int nameColumnIndex = cursor.getColumnIndex("NAME");
            parkName = cursor.getString(nameColumnIndex);
            cursor.close();
        }

        return parkName;
    }


    private class UpdateParkTask extends AsyncTask<Integer, Void, Boolean> {
        private ContentValues parkValues;

        protected void onPreExecute() {
            CheckBox visited = findViewById(R.id.visited);
            parkValues = new ContentValues();
            parkValues.put("VISITED", visited.isChecked());
        }

        protected Boolean doInBackground(Integer...parks) {
            int parkId = parks[0];
            SQLiteOpenHelper disneylandDatabaseHelper = new DisneylandDatabaseHelper(ParkActivity.this);
            try {
                SQLiteDatabase db = disneylandDatabaseHelper.getWritableDatabase();
                db.update("PARKS", parkValues,
                        "_id = ?", new String[] {Integer.toString(parkId)});
                db.update("PARKS", parkValues,
                        "_id = ?", new String[] {Integer.toString(parkId)});
                db.close();
                return true;
            } catch (SQLiteException e){
                return false;
            }
        }
    }

    public void sendMessage(String message){
        PackageManager pm=getPackageManager();
        try {

            Intent waIntent = new Intent(Intent.ACTION_SEND);
            waIntent.setType("text/plain");

            PackageInfo info=pm.getPackageInfo("com.whatsapp", PackageManager.GET_META_DATA);
            //Check if package exists or not. If not then code
            //in catch block will be called
            waIntent.setPackage("com.whatsapp");

            waIntent.putExtra(Intent.EXTRA_TEXT, message);
            startActivity(Intent.createChooser(waIntent, "Share with"));

        } catch (PackageManager.NameNotFoundException e) {
            Toast.makeText(this, "WhatsApp not Installed", Toast.LENGTH_SHORT)
                    .show();
        }
    }



}