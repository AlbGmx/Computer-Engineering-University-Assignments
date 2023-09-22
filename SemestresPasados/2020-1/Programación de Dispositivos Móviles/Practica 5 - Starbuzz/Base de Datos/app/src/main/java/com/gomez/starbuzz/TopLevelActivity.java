package com.gomez.starbuzz;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

public class TopLevelActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_top_level);

        // Create an OnItemClickListener
        AdapterView.OnItemClickListener itemClickListener = new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> listView, View v, int position, long id) {
                Intent intent;
                switch(position){
                    case 0:
                        intent = new Intent(TopLevelActivity.this, DrinkCategoryActivity.class);
                        startActivity(intent);
                        break;
                    case 1:
                        intent = new Intent(TopLevelActivity.this, FoodCategoryActivity.class);
                        startActivity(intent);
                        break;
                    case 2:
                        intent = new Intent(TopLevelActivity.this, StoreCategoryActivity.class);
                        startActivity(intent);
                        break;
                }

            }
        };
        // Add the listener to the list view
        ListView listView = (ListView) findViewById(R.id.list_options);
        listView.setOnItemClickListener(itemClickListener);
    }
}