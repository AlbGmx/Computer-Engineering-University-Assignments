package com.gomez.beeradvisor;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends Activity {
    private final BeerExpert expert = new BeerExpert();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_find_beer);
    }
    public void onClickMyButton(View v){
        TextView txtText = (TextView) findViewById(R.id.brands);
        Spinner color = (Spinner) findViewById(R.id.color) ;
        String beerType = String.valueOf(color.getSelectedItem());
        List<String> brandList = expert.getBrands(beerType);
        StringBuilder brandsFormatted = new StringBuilder();
        for (String brand : brandList){
            brandsFormatted.append(brand).append('\n');
        }
        txtText.setText(brandsFormatted);
    }
}