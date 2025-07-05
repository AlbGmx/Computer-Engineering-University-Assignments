package com.example.cafeoverflow.Activity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import com.example.cafeoverflow.Activity.HomeScreen.ProviderType;
import com.example.cafeoverflow.R;
import com.google.firebase.analytics.FirebaseAnalytics;
import com.google.firebase.auth.FirebaseAuth;

public class LoginActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        // Analytics Event
        FirebaseAnalytics analytics = FirebaseAnalytics.getInstance(this);
        Bundle bundle = new Bundle();
        bundle.putString("message", "Firebase Integration completed");
        analytics.logEvent("InitScreen", bundle);
    }

    public void registrarUser(View view) {
        EditText emailEditText = findViewById(R.id.emailEditText);
        EditText passwordEditText = findViewById(R.id.passwordEditText);

        if (emailEditText.getText().length() > 0 && passwordEditText.getText().length() > 0) {
            FirebaseAuth.getInstance().createUserWithEmailAndPassword(
                    emailEditText.getText().toString(),
                    passwordEditText.getText().toString())
                    .addOnCompleteListener(task -> {
                if (task.isSuccessful()) {
                    showHome(task.getResult().getUser().getEmail(), ProviderType.BASIC);
                } else {
                    showAlert();
                }
            });
        }
    }

    public void loginUser(View view) {
        EditText emailEditText = findViewById(R.id.emailEditText);
        EditText passwordEditText = findViewById(R.id.passwordEditText);

        if (emailEditText.getText().length() > 0 && passwordEditText.getText().length() > 0) {
            FirebaseAuth.getInstance().signInWithEmailAndPassword(
                    emailEditText.getText().toString(),
                    passwordEditText.getText().toString())
                    .addOnCompleteListener(task -> {
                if (task.isSuccessful()) {
                    showHome(task.getResult().getUser().getEmail(), ProviderType.BASIC);
                } else {
                    showAlert();
                }
            });
        }
    }

    private void showAlert() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("ERROR");
        builder.setMessage("Se ha producido un error autenticando al usuario");
        builder.setPositiveButton("Aceptar", null);
        AlertDialog dialog = builder.create();
        dialog.show();
    }

    private void showHome(String email, ProviderType provider) {
        Intent homeIntent = new Intent(this, HomeScreen.class);
        homeIntent.putExtra("email", email);
        homeIntent.putExtra("provider", provider.name());
        startActivity(homeIntent);
    }
}
