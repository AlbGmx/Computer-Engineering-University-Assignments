package com.example.cafeoverflow.Activity;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.RadioGroup;

import com.example.cafeoverflow.R;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;

public class ProductDetailActivity extends AppCompatActivity {
    private TextView addToCartBtn;
    private TextView titleTextView, descriptionTextView, priceTextView, amountTextView, totalTextView;
    private ImageView plusB, minB, imageFood;
    int priceV = 0, cant = 1, total = 0, priceE = 0;

    private RadioGroup select;
    private FirebaseFirestore db = FirebaseFirestore.getInstance();

    String productName;
    String productId ;
    int productImage, flag = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_product_detail);

         productName = getIntent().getStringExtra("productName");
         productId = getIntent().getStringExtra("productId");
         productImage = getIntent().getIntExtra("productImage", 0);

        initView();
        loadProductDetails(productName, productId, productImage);
        select.check(R.id.chico);
        // Añadir el listener al RadioGroup
        select.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                RadioButton selectedRadioButton = findViewById(checkedId);
                String selectedText = selectedRadioButton.getText().toString();

                switch (selectedText) {
                    case "12oz":
                        priceE = 0; // Precio adicional correspondiente al tamaño chico
                        break;
                    case "16oz":
                        priceE = 5; // Precio adicional correspondiente al tamaño mediano
                        break;
                }

                updateTotalPrice(); // Llamar a la función para actualizar el precio total
            }
        });
    }

    private void updateTotalPrice() {
        total = (priceV + priceE) * cant; // Actualizar el precio total considerando el precio original y el adicional por tamaño
        totalTextView.setText("Total: $" + String.valueOf(total)); // Mostrar el precio total actualizado
    }


    private void loadProductDetails(String productName, String productId, int productImage) {
        db.collection("product").document(productId).get().addOnSuccessListener(documentSnapshot -> {
            descriptionTextView.setText((String) documentSnapshot.get("description"));
            priceV = documentSnapshot.getLong("unitaryPrice").intValue();
            titleTextView.setText((String) documentSnapshot.get("productName"));
            priceTextView.setText(String.valueOf("Precio: $"+ priceV));
            totalTextView.setText("Total: $" + String.valueOf(priceV));

            String categoryType = (String) documentSnapshot.get("categoryType");
            if (categoryType != null && categoryType.equals("Dessert")&&flag == 0) {
                // Si es postre, actualiza la vista según el otro diseño
                setContentView(R.layout.activity_product_detail2);
                initViewForDessert(); // Inicializa vistas específicas del diseño para postres
                flag = 1;
                loadProductDetails(productName, productId, productImage);

            }
        });

        amountTextView.setText(String.valueOf(cant));
        imageFood.setImageResource(productImage);
        plusB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                cant = cant + 1;
                total = priceV * cant + priceE;
                amountTextView.setText(String.valueOf(cant));
                totalTextView.setText("Total: $" + String.valueOf(total));

            }
        });

        minB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(cant > 1){
                    cant = cant - 1;
                }
                total = priceV * cant + priceE;
                amountTextView.setText(String.valueOf(cant));
                totalTextView.setText("Total: $" + String.valueOf(total));
            }
        });
    }

    private void initView(){
        addToCartBtn = findViewById(R.id.cartBtn);
        titleTextView = findViewById(R.id.title);
        descriptionTextView = findViewById(R.id.descrip);
        priceTextView = findViewById(R.id.price);
        amountTextView = findViewById(R.id.amount);
        totalTextView = findViewById(R.id.total);
        plusB = findViewById(R.id.max);
        minB = findViewById(R.id.min);
        imageFood = findViewById(R.id.image);
        select = findViewById(R.id.Tamaños);
    }

    private void initViewForDessert(){
        addToCartBtn = findViewById(R.id.cartBtn);
        titleTextView = findViewById(R.id.title);
        descriptionTextView = findViewById(R.id.descrip);
        priceTextView = findViewById(R.id.price);
        amountTextView = findViewById(R.id.amount);
        totalTextView = findViewById(R.id.total);
        plusB = findViewById(R.id.max);
        minB = findViewById(R.id.min);
        imageFood = findViewById(R.id.image);
    }

}