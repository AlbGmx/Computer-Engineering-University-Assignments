package com.example.cafeoverflow.Domain;

public class Product {
    private String name;
    private String productId;
    private int imageResourceId;

    public Product(String name, String productId, int imageResourceId) {
        this.name = name;
        this.productId = productId;
        this.imageResourceId = imageResourceId;
    }

    public String getName() {
        return name;
    }

    public String getProductId() {
        return productId;
    }
    public int getImageResourceId() {
        return imageResourceId;
    }
}