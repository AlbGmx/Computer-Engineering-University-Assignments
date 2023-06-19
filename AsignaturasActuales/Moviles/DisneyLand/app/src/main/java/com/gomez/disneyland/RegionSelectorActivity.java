package com.gomez.disneyland;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class RegionSelectorActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_region_selector);

        setupOptionsListView();
    }

    private void setupOptionsListView() {
        AdapterView.OnItemClickListener itemClickListener = (listView, itemView, position, id) -> {
            Intent intent = new Intent(RegionSelectorActivity.this, ParkSelectorActivity.class);
            intent.putExtra(ParkSelectorActivity.EXTRA_REGIONID, (int) id+1);
            startActivity(intent);
        };
        //Add the listener to the list view
        ListView listView = findViewById(R.id.list_options);
        listView.setAdapter(new ArrayAdapter<>(this, R.layout.list_items, R.id.list_content, new String[]{"North America", "Europe", "Asia"}));
        listView.setOnItemClickListener(itemClickListener);
    }
}