package com.example.cafeoverflow.Domain;

public class ProductDomain {
    private String productName;
    private String pic;

    public ProductDomain(String productName, String pic){
        this.productName = productName;
        this.pic = pic;
    }

    public String getProductName() {
        return productName;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public String getPic() {
        return pic;
    }

    public void setPic(String pic) {
        this.pic = pic;
    }
}
