package com.example.cafeoverflow.Activity;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.example.cafeoverflow.Adapter.ProductAdapt;
import com.example.cafeoverflow.Domain.ProductDomain;
import com.example.cafeoverflow.R;

import java.util.ArrayList;

public class HomeScreen extends AppCompatActivity implements RecyclerViewProductsInterface{
    public enum ProviderType {
        BASIC
    }

    private RecyclerView.Adapter adapter;
    private RecyclerView recyclerViewCategoryList;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home_screen);

        //  Setup
        Bundle bundle = getIntent().getExtras();
        String email = (bundle != null) ? bundle.getString("email") : "";
        String provider = (bundle != null) ? bundle.getString("provider") : "";
        setUp(email, provider);
        recyclerViewCategory();
    }

    private void setUp(String email, String provider) {
        TextView userEmail = findViewById(R.id.userEmail);
        userEmail.setText(email);
    }

    private void recyclerViewCategory() {
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false);
        recyclerViewCategoryList = findViewById(R.id.recyclerViewProducts);
        recyclerViewCategoryList.setLayoutManager(linearLayoutManager);

        ArrayList<ProductDomain> product= new ArrayList<>();
        product.add(new ProductDomain("BEBIDAS CALIENTES", "cat_1"));
        product.add(new ProductDomain("FRAPPE", "cat_2"));
        product.add(new ProductDomain("EN LAS ROCAS", "cat_3"));
        product.add(new ProductDomain("POSTRES", "cat_4"));
        //product.add(new ProductDomain("SODAS ITALINAS", "cat_5"));


        adapter=new ProductAdapt(product, this);
        recyclerViewCategoryList.setAdapter(adapter);
    }

    public void onCart(View view){
        //Toast.makeText(getApplicationContext(), "Hello", Toast.LENGTH_LONG).show();
        Intent intent = new Intent(this, CartActivity.class);
        //Intent intent = new Intent(this, ProductsSubMenu.class);
        //intent.putExtra("position", 0);
        startActivity(intent);
    }

    @Override
    public void onProductClick(int position) {
        //Toast.makeText(getApplicationContext(), "Hello", Toast.LENGTH_LONG).show();
        //Log.v("DelayedMessageService","Hello");

        Intent intent = new Intent(this, ProductsSubMenu.class);
        intent.putExtra("position", position);
        startActivity(intent);
    }
}